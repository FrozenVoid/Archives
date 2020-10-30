#pragma once 
	//Crypteria11 stegocipher header by FrozenVoid licensed under https://www.gnu.org/licenses/agpl.html
	/* General encryption process
	1. password is converted to secret key(with const salt)
	2. an array 64 times larger than input is seeded with random data
	3. input bits are set to array bits, with gaps between input bits derived from 1+xorshift()&63 [1-64 gap length]
	4. array is rotated as 64bit ints, using rotate data from xorshift()&63
	5. 3 passes of differently seeded xorshift() are applied to result with xor,add,substract as reversible operations.
	6.Decryption runs the 2-5 stages in reverse.
	
	note:the algorithm is named after Krypteria(the symphonic metal band) not Crypteria(metal band).
	*/
	
	//show timing info
	//#define CRYPTERIA_TIMING 1
	
	
	
	#include <stdint.h>//int sizes
	
	#include <stdlib.h>//malloc
	#include <stdio.h>//fopen, fread,fwrite,sprintf,perror
	#include <string.h>//strlen
	#include <x86intrin.h>//__rdtsc()
	#ifdef CRYPTERIA_TIMING
	#include <inttypes.h> //print timing type u64
	static uint64_t timing_stages[8]={0};
	static uint64_t timing_func[8]={0};
	#endif
	static uint64_t xorseed[2];
	static const  uint64_t salt=0x1234567887654321ULL;//each implementation can use a unique salt(changes algo)
	//Partial Decryption STRENGTH(changes algo: form 1<<N)
	#define CRYPTERIA_PD_STRENGTH (1<<12) //amount of precomputed xorshifts
	static inline uint64_t rotl(const uint64_t x, int k) {
		return (x << k) | (x >> (64 - k));}
	
	static inline void setxorseed(uint64_t a,uint64_t b){xorseed[0]=a;xorseed[1]=b;}
	
	static inline uint64_t xoroshiro128plus(void) {//pseudo-random number stream
	     //Source:xoroshiro.di.unimi.it/xoroshiro128plus.c
		const uint64_t s0 = xorseed[0];
		uint64_t s1 = xorseed[1];
		const uint64_t result = s0 + s1;
	
		s1 ^= s0;
		xorseed[0] = rotl(s0, 55) ^ s1 ^ (s1 << 14); // a, b
		xorseed[1] = rotl(s1, 36); // c
	
		return result;
	}
	
	
	
	//secret key from password(max useful chars:16)
	typedef union Pwseed{uint64_t s[2];char text[16];} pwseed;
	static pwseed secret;
	static inline uint64_t clearbit(uint64_t v,uint8_t loc){
	return v&(~ (1ULL<<loc));
	}
	static inline uint64_t setbit(uint64_t v,uint8_t loc,uint64_t bit){
	return v|((bit<<loc));
	}
	static inline uint64_t getbit64(uint64_t v,uint8_t loc){
	return (v&((1ULL<<loc)))>>loc;
	}
	static inline uint64_t getbit8(uint8_t v,uint8_t loc){
	return (v&((1<<loc)))>>loc;
	}
	
	
	static inline void revarr(char* arr,size_t size){
   	for(size_t i=0;i<(size/2);i++){char temp=arr[i];arr[i]=arr[(size/2)+i];arr[(size/2)+i]=temp;}
	}	
	static inline void setsecret(pwseed* secret, uint64_t salt,char* pass,uint64_t pwlen){
	//sets encryption keys s[0] and s[1] for xorshift rounds(reversible)
	//a password is created from pass string(repeated to fill 16 bytes)
	for(size_t ipw=0,ipa=0;ipw<16;ipw++){if(ipa>pwlen)ipa=0;secret->text[ipw]=pass[ipa++];};
	//add salt(xored)  
	secret->s[0]+=(salt^secret->s[1]);
	secret->s[1]-=(salt^secret->s[0]);
	//xor salt neg
	secret->s[0]^=((~salt)-secret->s[1]);
	secret->s[1]^=((~salt)-secret->s[0]);
	}
	
	
	//================+++++ENCRYPT++++===============
	/* encrypt
	Input: data, password, data length, password length
	Output: returned encrypted array, 
	result size is passed to data_len pointer.
	
	*/
	
	static uint8_t xordata[CRYPTERIA_PD_STRENGTH];//xor vector for diffused bits
	static uint8_t xordatab[CRYPTERIA_PD_STRENGTH];//xor vector for diffused bits
	static uint64_t xordata2[CRYPTERIA_PD_STRENGTH];//xor vector for reversible transforms
	static uint64_t xordata2b[CRYPTERIA_PD_STRENGTH];//xor vector for reversible transforms
	 
	//x4 slower
	static inline int compareu64(const void * a, const void * b){
	const uint64_t* A=(uint64_t*)a;
	const uint64_t* B=(uint64_t*)b;
	return (*A==*B)?0:(*A<*B?-1:1);
	
	}
	
	//=============SET XORSHIFT ARRAYS
	static inline void setxordata(void){
	#ifdef CRYPTERIA_TIMING
	timing_func[0]=__rdtsc();
	#endif
	//size_t skip=(secret.s[0]&(CRYPTERIA_PD_STRENGTH-1))^((secret.s[1]>>16)&(CRYPTERIA_PD_STRENGTH-1));//forced random skip 
	//for(size_t i=0;i<skip;i++){xoroshiro128plus();}
	
	for(size_t i=0;i<CRYPTERIA_PD_STRENGTH;i++){
	xordata[CRYPTERIA_PD_STRENGTH-i-1]=1+((xoroshiro128plus()>>3)&63);
	}
	//
	//u64sort(( uint64_t*)xordata,( uint64_t*)xordatab,CRYPTERIA_PD_STRENGTH-1);
	#ifdef CRYPTERIA_TIMING
	timing_func[1]+=(__rdtsc()-timing_func[0]);
	#endif
	}
	static inline void  setxordata2(void){
	#ifdef CRYPTERIA_TIMING
	timing_func[0]=__rdtsc();
	#endif
	
	size_t skip=(secret.s[0]&(CRYPTERIA_PD_STRENGTH-1))^((secret.s[1]>>16)&(CRYPTERIA_PD_STRENGTH-1));//forced random skip 
	for(size_t i=0;i<skip;i++){xoroshiro128plus();}
	
	for(size_t i=0;i<CRYPTERIA_PD_STRENGTH;i++){xordata2[CRYPTERIA_PD_STRENGTH-i-1]=xoroshiro128plus();}
	
	#ifdef CRYPTERIA_TIMING
	timing_func[2]+=(__rdtsc()-timing_func[0]);
	timing_func[0]=__rdtsc();
	#endif
	//qsort ( xordata2, (CRYPTERIA_PD_STRENGTH-1), 8,compareu64);
	//very slow 90% of overhead
	//revarr(xordata,CRYPTERIA_PD_STRENGTH);	
	//u64sort(( uint64_t*)xordata2,( uint64_t*)xordata2b,(CRYPTERIA_PD_STRENGTH-1)*8);
	#ifdef CRYPTERIA_TIMING
	timing_func[3]+=(__rdtsc()-timing_func[0]);
	#endif
	
	}
	
	//depends on CRYPTERIA_PD_STRENGTH being 1<<n
	static inline uint8_t getgapval(size_t distance){
	size_t gap=(distance&(CRYPTERIA_PD_STRENGTH-1));
	if(gap==0){setxordata();}
	//if(gap==(CRYPTERIA_PD_STRENGTH-1)){setxordata();};
	return xordata[gap];}
	
	static inline uint64_t getxorval(size_t distance){
	size_t place=(distance&(CRYPTERIA_PD_STRENGTH-1));
	if(place==0){setxordata2();}
	return xordata2[place];}
	
	
	
	//===================+++++ENCRYPT+++++======================
	uint64_t* encrypt(uint8_t* data, char* password, uint64_t* data_len, uint64_t* password_len){
	#ifdef CRYPTERIA_TIMING
	timing_stages[0]=__rdtsc();
	#endif
	
	//STAGE0:
	//create result array,align8
	const size_t maxressize=(((*data_len)|7)*64);
	const size_t bytesize=(*data_len);//real size;
	const size_t pwlen=*password_len;
	
	uint64_t* result=malloc(maxressize+16);//add 8bytes for filesize store.
	size_t resultsize=(maxressize/8);//size in elems of result array
	uint64_t xor1,xor2;
	
	//create password variables (max useful pass len is 16 bytes;
	
	uint64_t timeseed=__rdtsc();
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[1]=__rdtsc();
	#endif
	
	//STAGE1:
	setsecret(&secret,salt,password,pwlen);
	//file size value as first data;shift pos +1, -1 at end
	result[0]=bytesize;result++;
	
	//fill the result with random data via timeseed/pass, creating initial array of garbage data.
	setxorseed((timeseed)^(secret.s[0]),(secret.s[1])^(~timeseed));
	for(size_t i=0;i<(maxressize/8);i++){result[i]=xoroshiro128plus();}
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[2]=__rdtsc();
	#endif
	
	//STAGE2:
	//spray bits from data into result array,gap_len 0-63 from xorshift
	setxorseed(secret.s[0]+secret.s[1],secret.s[1]-secret.s[0]);
	// data_len*8 bits -> sprayed between gaps [d atabit1] i gap [d atabit2]
	size_t i=0,d=0,lsti=0;//avoid 3 lower bits of xorshift
	// i+=((xoroshiro128plus()>>3)&63) is the gap period
	setxordata();
	for(i=0,d=0;d<(maxressize/8);){
	//position of next source databit "d"
	uint64_t srcbit=getbit8(data[(d/8)],(d&7));
	//sprayed location i, mask with bit set to srcbit
	//result[(i/64)]&=(~(1ULL<<(i&63)));//clear the bit
	result[(i/64)]=clearbit(result[(i/64)],i&63);
	result[(i/64)]=setbit(result[(i/64)],i&63,srcbit);
	//result[(i/64)]|=(srcbit<<(i&63));//set the databit d
	d++;lsti=i;
	i+=getgapval(d);
	}
	*data_len=((lsti|7)/8)+8;//useful data lenghth+filesize
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[3]=__rdtsc();
	#endif
	
	//STAGE3:
	//rotations of result array
	setxorseed(secret.s[0]+salt,secret.s[1]-salt);
	for(i=0;i<(maxressize/8);i++){
	result[i]=rotl(result[i],getgapval(i));}
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[4]=__rdtsc();
	#endif
	
	//STAGE4:
	//encryption xor pass by adding layer of xorshift data 1
	setxorseed(secret.s[0]-salt,secret.s[1]+salt);
	for(i=0;i<(maxressize/8);i++){
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	result[i]^=xor1;
	result[i]-=xor2;}
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[5]=__rdtsc();
	#endif
	
	//STAGE5:
	//encryption xor pass by xorshift with negated pass+salt rotated 
	setxorseed(rotl((~secret.s[1])+salt,secret.s[0]&63),rotl(secret.s[0]+salt,secret.s[1]&63));
	for(i=0;i<(maxressize/8);i++){
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	result[i]-=xor1;result[i]^=xor2;}
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[6]=__rdtsc();
	#endif
	
	//STAGE6:
	//encryption xor pass by xorshift with negated pass rotated
	setxorseed(rotl(secret.s[0],secret.s[1]&63),rotl(~secret.s[1],secret.s[0]&63));
	for(i=0;i<(maxressize>>3);i++){
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	result[i]^=xor1;
	result[i]+=xor2;}
	#ifdef CRYPTERIA_TIMING
	timing_stages[7]=__rdtsc();
	#endif
	
	return --result;
	}
	
	
	//==============+++++DECRYPT++++++=============================
	uint8_t* decrypt(uint8_t* data, char* password, uint64_t* data_len, uint64_t* password_len){
	#ifdef CRYPTERIA_TIMING
	timing_stages[0]=__rdtsc();
	#endif
	
	
	//STAGE0;
	//create result array
	const size_t maxressize=(*data_len);
	const size_t pwlen=*password_len;
	uint64_t* result=malloc(maxressize);
	memcpy(result,data,maxressize);
	size_t final_size=result[0];result++;
	uint8_t* result2=calloc(1,maxressize+8);
	*data_len=final_size; //useful data lenghth
	//create password variables (max useful pass len is 16 bytes;
	;size_t i=0,d=0;
	
	setsecret(&secret,salt,password,pwlen);
	uint64_t xor1,xor2;
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[1]=__rdtsc();
	#endif
	
	//STAGE1<6:
	//decrypt xor pass by xorshift with negated pass rotated
	setxorseed(rotl(secret.s[0],secret.s[1]&63),rotl(~secret.s[1],secret.s[0]&63));
	for( i=0;i<(maxressize/8);i++){
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	;result[i]-=xor2;result[i]^=xor1;}
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[2]=__rdtsc();
	#endif
	
	//STAGE2<5:
	//decrypt xor pass by xorshift with negated pass+salt rotated 
	setxorseed(rotl((~secret.s[1])+salt,secret.s[0]&63),rotl(secret.s[0]+salt,secret.s[1]&63));
	for( i=0;i<(maxressize/8);i++){
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	result[i]^=xor2;result[i]+=xor1;}
	
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[3]=__rdtsc();
	#endif
	
	//STAGE3<4:
	//decrypt xor pass by adding layer of xorshift data 1
	setxorseed(secret.s[0]-salt,secret.s[1]+salt);
	for(i=0;i<(maxressize/8);i++){//^1-2 +1^2
	xor1=getxorval((i<<1));
	xor2=getxorval((i<<1)+1);
	result[i]+=xor2;
	result[i]^=xor1;}
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[4]=__rdtsc();
	#endif
	
	//STAGE4<3:
	//reverse rotations of result array
	setxorseed(secret.s[0]+salt,secret.s[1]-salt);
	for(i=0;i<(maxressize/8);i++){
	result[i]=rotl(result[i],64-(getgapval(i)));}
	
	#ifdef CRYPTERIA_TIMING
	timing_stages[5]=__rdtsc();
	#endif
	
	//STAGE5<2:
	//recov bits from data into result array,gap_len 0-63 from xorshift
	setxorseed(secret.s[0]+secret.s[1],secret.s[1]-secret.s[0]);
	// data_len*8 bits -> sprtayed between gaps [d atabit1] i gap [d atabit2]
	//i+=((xoroshiro128plus()>>3)&63)
	setxordata();
	for(i=0,d=0;i<(maxressize*8)&& (d<(final_size*8));){
	result2[(d/8)]=setbit(result2[(d/8)],d&7,getbit64(result[(i/64)],(i&63)));
	d++;i+=getgapval(d);
	
	
	
	//set result byte
	//result2[(d/8)]=databyte;
	//setbit(result2[(d/64)], (d&63),srcbit);//set the databit d
	//if((d&63) ==0 )printf("%8s\n",(char*)&result[d/64]);
	
	
	}
	#ifdef CRYPTERIA_TIMING
	timing_stages[6]=__rdtsc();
	#endif
	
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
	#ifdef CRYPTERIA_TIMING
	uint64_t time_start=__rdtsc();
	#endif
	uint64_t* res=encrypt(data,password,&size,&pwlen);
	#ifdef CRYPTERIA_TIMING
	uint64_t time_end=__rdtsc();
	printf("\nEncryption time:%"PRIu64" cycles\n",time_end-time_start);
	printf("setxordata:%"PRIu64" cycles\n",timing_func[1]);
	printf("setxordata2[without rev]:%"PRIu64" cycles\n",timing_func[2]);
	printf("setxordata2[rev]:%"PRIu64" cycles\n",timing_func[3]);
	printf("setxordata2[rev->Radix3]:%"PRIu64" cycles for %"PRIu64" rounds\n",timing_func[5],timing_func[4]);
	printf("Stage0:%"PRIu64" cycles\n",timing_stages[1]-timing_stages[0]);
	printf("Stage1:%"PRIu64" cycles\n",timing_stages[2]-timing_stages[1]);
	printf("Stage2:%"PRIu64" cycles\n",timing_stages[3]-timing_stages[2]);
	printf("Stage3:%"PRIu64" cycles\n",timing_stages[4]-timing_stages[3]);
	printf("Stage4:%"PRIu64" cycles\n",timing_stages[5]-timing_stages[4]);
	printf("Stage5:%"PRIu64" cycles\n",timing_stages[6]-timing_stages[5]);
	printf("Stage6:%"PRIu64" cycles\n",timing_stages[7]-timing_stages[6]);
	
	#endif
	fwrite(res,size,1,out);
	
	return 0;//success
	}
	
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
	#ifdef CRYPTERIA_TIMING
	uint64_t time_start=__rdtsc();
	#endif
	uint8_t* res=decrypt(data,password,&size,&pwlen);
	#ifdef CRYPTERIA_TIMING
	uint64_t time_end=__rdtsc();
	printf("\nDecryption time:%"PRIu64" cycles\n",time_end-time_start);
	printf("setxordata:%"PRIu64" cycles\n",timing_func[1]);
	printf("setxordata2[without sort]:%"PRIu64" cycles\n",timing_func[2]);
	printf("setxordata2[sort]:%"PRIu64" cycles\n",timing_func[3]);
	printf("setxordata2[sort->Radix3]:%"PRIu64" cycles for %"PRIu64" rounds\n",timing_func[5],timing_func[4]);
	printf("Stage0:%"PRIu64" cycles\n",timing_stages[1]-timing_stages[0]);
	printf("Stage1<6enc:%"PRIu64" cycles\n",timing_stages[2]-timing_stages[1]);
	printf("Stage2<5enc:%"PRIu64" cycles\n",timing_stages[3]-timing_stages[2]);
	printf("Stage3<4enc:%"PRIu64" cycles\n",timing_stages[4]-timing_stages[3]);
	printf("Stage4<3enc:%"PRIu64" cycles\n",timing_stages[5]-timing_stages[4]);
	printf("Stage5<2enc:%"PRIu64" cycles\n",timing_stages[6]-timing_stages[5]);
	
	#endif
	fwrite(res,size,1,out);
	
	return 0;//success
	}
	
	
	/*
	reference implementation,:
	#include "crypteria11.h"
	int main(int argc,char**argv){return console_main(argc,argv);}
	*/
	int console_main(int argc,char**argv){
	if(argc!=4){puts("Syntax:cr [e|d] filename password\n e=encrypt d=decrypt\n");return 11;}
	if(argv[1][0]=='e'){return filename_encrypt(argv[2],argv[3]);}else{return filename_decrypt(argv[2],argv[3]);}}
	#undef CRYPTERIA_PD_STRENGTH
	
	
	//=============================END==================
