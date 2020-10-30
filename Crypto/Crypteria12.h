#pragma once 
//Crypteria12 stegocipher header by FrozenVoid licensed under https://www.gnu.org/licenses/agpl.html
/* General encryption process
1. password is converted to secret key(with const salt)
2. an array 64 times larger than input is seeded with random data
3. input bits are set to array bits, with gaps between input bits derived from 1+xorshift()&63 [1-64 gap length]
4. array is rotated as 64bit ints, using rotate data from xorshift()&63
5. 3 passes of differently seeded xorshift() are applied to result with xor,add,substract as reversible operations.
6.Decryption runs the 2-5 stages in reverse.
note:the algorithm is named after Krypteria(the symphonic metal band) not Crypteria(metal band).*/
#include <stdint.h>//int sizes
#include <stdlib.h>//malloc
#include <stdio.h>//fopen, fread,fwrite,sprintf,perror
#include <string.h>//strlen
#include <x86intrin.h>//__rdtsc()
#include <inttypes.h> 
static uint64_t xorseed[2];
static const  uint64_t salt=0x1234567887654321ULL;//each implementation can use a unique salt(changes algo)
//Partial Decryption STRENGTH(changes algo: form 1<<N)
#define CRYPTERIA_PD_STRENGTH (1<<12) //amount of precomputed xorshifts

static uint64_t rhash(uint8_t* input,size_t len){
uint64_t seed[2]={0x1234567887654321ULL,0x2345678876543211ULL};uint64_t rnds1,rnds0,result=0;
uint64_t* data=(uint64_t*)input;
for(size_t i=0;i<(len/8);i++){
rnds0 = seed[0]^data[i];
rnds1 = seed[1];
result = rnds0 + rnds1;
rnds1 ^= rnds0;//rotl(rnds0, 55)
seed[0] = ( (rnds0 << 55) | (rnds0 >> (64 - 55)) ) ^ rnds1 ^ (rnds1 << 14); //rotl(rnds1, 36)
seed[1] =( (rnds1 << 36) | (rnds1 >> (64 - 36)) ); 
}
for(size_t i=(len/8)<<3;i<len;i++){
rnds0 = seed[0]^((uint64_t)input[i]<<(8*(i&7)));
rnds1 = seed[1];
result = rnds0 + rnds1;
rnds1 ^= rnds0;//rotl(rnds0, 55)
seed[0] = ( (rnds0 << 55) | (rnds0 >> (64 - 55)) ) ^ rnds1 ^ (rnds1 << 14); //rotl(rnds1, 36)
seed[1] =( (rnds1 << 36) | (rnds1 >> (64 - 36)) ); }
const char rsalt[]="Crypteria is a strong stego-cipher based on classic ideas of Confusion and Diffusion by Claude Shannon";
uint64_t* salt8=(uint64_t*)&rsalt;
    for(size_t i=0;i<(sizeof(rsalt)/8);i++){
rnds0 = seed[0]^salt8[i];rnds1 = seed[1];
result = rnds0 + rnds1;rnds1 ^= rnds0;
seed[0] = ( (rnds0 << 55) | (rnds0 >> (64 - 55)) ) ^ rnds1 ^ (rnds1 << 14); 
seed[1] =( (rnds1 << 36) | (rnds1 >> (64 - 36)) ); }
result = seed[0] + seed[1];
return result;}

static uint64_t rhash64(uint64_t xseed){
uint64_t t=xseed; return rhash((uint8_t*)&t,8);}
static inline uint64_t rotl(const uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));}

static inline void setxorseed(uint64_t a,uint64_t b){xorseed[0]=rhash64(rhash64(a));xorseed[1]=rhash64(rhash64(b));}

static inline uint64_t xoroshiro128plus(void) {
     //Source:xoroshiro.di.unimi.it/xoroshiro128plus.c
    const uint64_t s0 = xorseed[0];
    uint64_t s1 = xorseed[1];
    const uint64_t result = s0 + s1; s1 ^= s0;
    xorseed[0] = rotl(s0, 55) ^ s1 ^ (s1 << 14); 
    xorseed[1] = rotl(s1, 36); 
    return result;}

//secret key from password(max useful chars:16)
typedef union Pwseed{uint64_t s[2];char text[16];} pwseed;
static pwseed secret;
static inline uint64_t clearbit(uint64_t v,uint8_t loc){    return v&(~ (1ULL<<loc));    }
static inline uint64_t setbit(uint64_t v,uint8_t loc,uint64_t bit){    return v|((bit<<loc));    }
static inline uint64_t getbit64(uint64_t v,uint8_t loc){    return (v&((1ULL<<loc)))>>loc;    }
static inline uint64_t getbit8(uint8_t v,uint8_t loc){    return (v&((1<<loc)))>>loc;    }
 
static inline void setsecret(pwseed* ssecret,char* pass,uint64_t pwlen){
ssecret->s[0]=rhash64(rhash64(salt+rhash((uint8_t*)pass,pwlen)));
ssecret->s[1]=rhash64(salt^(~rhash64(ssecret->s[0])));}
//================+++++ENCRYPT++++===============
/* encrypt
Input: data, password, data length, password length
Output: returned encrypted array, 
result size is passed to data_len pointer.*/
//xor vector for diffused bitlocations
static uint8_t xordata[CRYPTERIA_PD_STRENGTH];
//xor vector for reversible transforms
static uint64_t xordata2[CRYPTERIA_PD_STRENGTH];

//=============SET XORSHIFT ARRAYS
static inline void setxordata(void){
for(size_t i=0;i<CRYPTERIA_PD_STRENGTH;i++){
xordata[CRYPTERIA_PD_STRENGTH-i-1]=1+((xoroshiro128plus()>>3)&63);}}

static inline void setxordata2(void){
//forced random skip 
size_t skip=(secret.s[0]&(CRYPTERIA_PD_STRENGTH-1))^((secret.s[1]>>16)&(CRYPTERIA_PD_STRENGTH-1));
for(size_t i=0;i<skip;i++){xoroshiro128plus();}
for(size_t i=0;i<CRYPTERIA_PD_STRENGTH;i++){xordata2[CRYPTERIA_PD_STRENGTH-i-1]=xoroshiro128plus();}}

//depends on CRYPTERIA_PD_STRENGTH being 1<<n
static inline uint8_t getgapval(size_t distance){
size_t gap=(distance&(CRYPTERIA_PD_STRENGTH-1));
if(gap==0){setxordata();};return xordata[gap];}

static inline uint64_t getxorval(size_t distance){
size_t place=(distance&(CRYPTERIA_PD_STRENGTH-1));
if(place==0){setxordata2();};return xordata2[place];}
//==============+++++ENCRYPT+++++==========
uint64_t* encrypt(uint8_t* data, char* password, uint64_t* data_len, uint64_t* password_len){
//STAGE0:create random array,align8
const size_t maxressize=(((*data_len)|7)*64);
const size_t bytesize=(*data_len);//real size;
const size_t pwlen=*password_len;

uint64_t* result=malloc(maxressize+16);//add 8bytes for filesize store.
size_t resultsize=(maxressize/8);//size in elems of result array
uint64_t xor1,xor2;

//create password variables (max useful pass len is 16 bytes;
uint64_t timeseed=__rdtsc();
//STAGE1:
setsecret(&secret,password,pwlen);
//file size value as first data;shift pos +1, -1 at end
result[0]=bytesize;result++;
//fill the result with random data via timeseed/pass
setxorseed(__rdtsc(),~__rdtsc());
for(size_t i=0;i<(maxressize/8);i++){result[i]=xoroshiro128plus();}

//STAGE2:spray bits from data into result array,gap_len 0-63 from xorshift
setxorseed((secret.s[0]+secret.s[1]),(secret.s[1]-secret.s[0]));
// data_len*8 bits -> sprayed between gaps [d atabit1] i gap [d atabit2]
size_t i=0,d=0,lsti=0;//avoid 3 lower bits of xorshift
setxordata();
for(i=0,d=0;d<(maxressize/8);){
//position of next source databit "d"
uint64_t srcbit=getbit8(data[(d/8)],(d&7));
//sprayed location i, mask with bit set to srcbit
result[(i/64)]=clearbit(result[(i/64)],i&63);
result[(i/64)]=setbit(result[(i/64)],i&63,srcbit);
//advance to next location(i+gap)
d++;lsti=i;i+=getgapval(d);}
*data_len=((lsti|7)/8)+8;//useful data lenghth+filesize

//STAGE3:rotations of result array
setxorseed((secret.s[0]+salt),(secret.s[1]-salt));
for(i=0;i<(maxressize/8);i++){
result[i]=rotl(result[i],getgapval(i));}

//STAGE4:xor pass by adding layer of xorshift data 1
setxorseed((secret.s[0]-salt),(secret.s[1]+salt));
for(i=0;i<(maxressize/8);i++){
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
result[i]^=xor1;
result[i]-=xor2;}

//STAGE5:xor pass by xorshift with negated pass+salt rotated 
setxorseed((rotl((~secret.s[1])+salt,secret.s[0]&63)),(rotl(secret.s[0]+salt,secret.s[1]&63)));
for(i=0;i<(maxressize/8);i++){
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
result[i]-=xor1;result[i]^=xor2;}

//STAGE6:xor pass by xorshift with negated pass rotated
setxorseed((rotl(secret.s[0],secret.s[1]&63)),(rotl(~secret.s[1],secret.s[0]&63)));
for(i=0;i<(maxressize>>3);i++){
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
result[i]^=xor1;
result[i]+=xor2;}
return --result;}

//==========+++++DECRYPT++++++=====
uint8_t* decrypt(uint8_t* data, char* password, uint64_t* data_len, uint64_t* password_len){
//STAGE0;create random data array
const size_t maxressize=(*data_len);
const size_t pwlen=*password_len;
uint64_t* result=malloc(maxressize);
memcpy(result,data,maxressize);
size_t final_size=result[0];result++;
uint8_t* result2=calloc(1,maxressize+8);
*data_len=final_size; //useful data lenghth
//create password variables 
;size_t i=0,d=0;uint64_t xor1,xor2;
setsecret(&secret,password,pwlen);
//STAGE1<6:xorshift with negated pass rotated
setxorseed((rotl(secret.s[0],secret.s[1]&63)),(rotl(~secret.s[1],secret.s[0]&63)));
for( i=0;i<(maxressize/8);i++){
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
;result[i]-=xor2;result[i]^=xor1;}

//STAGE2<5:xor pass by xorshift with negated pass+salt rotated 
setxorseed((rotl((~secret.s[1])+salt,secret.s[0]&63)),(rotl(secret.s[0]+salt,secret.s[1]&63)));
for( i=0;i<(maxressize/8);i++){
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
result[i]^=xor2;result[i]+=xor1;}

//STAGE3<4:xor pass by adding layer of xorshift data 1
setxorseed((secret.s[0]-salt),(secret.s[1]+salt));
for(i=0;i<(maxressize/8);i++){//^1-2 +1^2
xor1=getxorval((i<<1));
xor2=getxorval((i<<1)+1);
result[i]+=xor2;
result[i]^=xor1;}

//STAGE4<3:reverse rotations of result array
setxorseed((secret.s[0]+salt),(secret.s[1]-salt));
for(i=0;i<(maxressize/8);i++){
result[i]=rotl(result[i],64-(getgapval(i)));}

//STAGE5<2:recov bits from data into result array,gap_len 0-63 from xorshift
setxorseed((secret.s[0]+secret.s[1]),(secret.s[1]-secret.s[0]));setxordata();
for(i=0,d=0;i<(maxressize*8)&& (d<(final_size*8));){
result2[(d/8)]=setbit(result2[(d/8)],d&7,getbit64(result[(i/64)],(i&63)));
d++;i+=getgapval(d);}
return result2;}

//===============++FILE FUNCTIONS+++==================
//return 0 if error, else encrypt to filename.ext.enc
int filename_encrypt(char* filename,char* password){
size_t size,n,fname_size=strlen(filename),pwlen=strlen(password);
//get file size;
FILE* inp=fopen(filename,"rb");if(!inp){perror(filename);return 13;}
char* resname=malloc(fname_size+6);
sprintf(resname,"%s%s",filename,".enc");
FILE* out=fopen(resname,"wb");if(!inp){perror(resname);return 12;}
//get data size
fseek(inp,0,SEEK_END); size=ftell(inp);rewind(inp);
//encrypt
uint8_t* data=malloc(size);if(!data){perror("malloc data error");return 11;}
n=fread(data, size,1, inp);
uint64_t* res=encrypt(data,password,&size,&pwlen);
fwrite(res,size,1,out);
return 0;}

int filename_decrypt(char* filename,char* password){
size_t size,n,fname_size=strlen(filename),pwlen=strlen(password);
//get file size;
FILE* inp=fopen(filename,"rb");if(!inp){perror(filename);return 13;}
char* resname=malloc(fname_size+6);
sprintf(resname,"%s%s",filename,".dec");
FILE* out=fopen(resname,"wb");if(!inp){perror(resname);return 12;}
//get data size
fseek(inp,0,SEEK_END); size=ftell(inp);rewind(inp);
//encrypt
uint8_t* data=malloc(size);if(!data){perror("malloc data error");return 11;}
n=fread(data, size,1, inp);
uint8_t* res=decrypt(data,password,&size,&pwlen);
fwrite(res,size,1,out);
return 0;}//success

/*    reference implementation,:
#include "crypteria12.h"
 int main(int argc,char**argv){return console_main(argc,argv);} */
int console_main(int argc,char**argv){
if(argc!=4){puts("Syntax:cr [e|d] filename password\n e=encrypt d=decrypt\n");return 11;}
if(argv[1][0]=='e'){
return filename_encrypt(argv[2],argv[3]);
}else{return filename_decrypt(argv[2],argv[3]);}}
