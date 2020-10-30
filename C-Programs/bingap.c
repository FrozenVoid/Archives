//Bingap v1.16 by FrozenVoid
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <x86intrin.h>
#include <limits.h>
#define MAX_BITS 64
#define BENCH 1 //benchmark
typedef long long int i64;
typedef unsigned long long int u64;
typedef unsigned int u32;
/*

 Output of gcc -Ofast -march=native -mtune=native for bingap function:
00000000000013f0 <bingap>:
00000000000013e0 <bingap_old>:
bingap_old():
    13e0:	31 d2                	xor    %edx,%edx
    13e2:	31 c0                	xor    %eax,%eax
    13e4:	48 c7 c6 ff ff ff ff 	mov    $0xffffffffffffffff,%rsi
    13eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    13f0:	39 d0                	cmp    %edx,%eax
    13f2:	0f 4c c2             	cmovl  %edx,%eax
    13f5:	48 0f bc cf          	bsf    %rdi,%rcx
    13f9:	48 0f 44 ce          	cmove  %rsi,%rcx
    13fd:	48 ff c1             	inc    %rcx
    1400:	48 d3 ef             	shr    %cl,%rdi
    1403:	48 0f bc cf          	bsf    %rdi,%rcx
    1407:	48 d3 ef             	shr    %cl,%rdi
    140a:	89 ca                	mov    %ecx,%edx
    140c:	48 85 ff             	test   %rdi,%rdi
    140f:	75 df                	jne    13f0 <bingap_old+0x10>
    1411:	c3                   	retq   
    1412:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1419:	00 00 00 00 
    141d:	0f 1f 00             	nopl   (%rax)

0000000000001420 <bingap_115>:
bingap_115():
    1420:	48 0f bc cf          	bsf    %rdi,%rcx
    1424:	31 d2                	xor    %edx,%edx
    1426:	31 c0                	xor    %eax,%eax
    1428:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    142f:	00 
    1430:	39 d0                	cmp    %edx,%eax
    1432:	0f 4c c2             	cmovl  %edx,%eax
    1435:	48 d3 ef             	shr    %cl,%rdi
    1438:	48 89 f9             	mov    %rdi,%rcx
    143b:	48 f7 d1             	not    %rcx
    143e:	48 0f bc c9          	bsf    %rcx,%rcx
    1442:	48 d3 ef             	shr    %cl,%rdi
    1445:	48 0f bc cf          	bsf    %rdi,%rcx
    1449:	89 ca                	mov    %ecx,%edx
    144b:	48 85 ff             	test   %rdi,%rdi
    144e:	75 e0                	jne    1430 <bingap_115+0x10>
    1450:	c3                   	retq   
    1451:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1458:	00 00 00 00 
    145c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001460 <bingap>:
bingap():
    1460:	48 0f bc cf          	bsf    %rdi,%rcx
    1464:	31 d2                	xor    %edx,%edx
    1466:	31 c0                	xor    %eax,%eax
    1468:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    146f:	00 
    1470:	48 d3 ef             	shr    %cl,%rdi
    1473:	48 89 f9             	mov    %rdi,%rcx
    1476:	48 f7 d1             	not    %rcx
    1479:	48 0f bc c9          	bsf    %rcx,%rcx
    147d:	48 d3 ef             	shr    %cl,%rdi
    1480:	39 d0                	cmp    %edx,%eax
    1482:	0f 4c c2             	cmovl  %edx,%eax
    1485:	48 0f bc cf          	bsf    %rdi,%rcx
    1489:	89 ca                	mov    %ecx,%edx
    148b:	48 85 ff             	test   %rdi,%rdi
    148e:	75 e0                	jne    1470 <bingap+0x10>
    1490:	c3                   	retq   
    1491:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1498:	00 00 00 00 
    149c:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000014a0 <bingap32_dc>:
bingap32_dc():
    14a0:	0f bc cf             	bsf    %edi,%ecx
    14a3:	31 d2                	xor    %edx,%edx
    14a5:	31 c0                	xor    %eax,%eax
    14a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    14ae:	00 00 
    14b0:	d3 ef                	shr    %cl,%edi
    14b2:	89 f9                	mov    %edi,%ecx
    14b4:	f7 d1                	not    %ecx
    14b6:	0f bc c9             	bsf    %ecx,%ecx
    14b9:	d3 ef                	shr    %cl,%edi
    14bb:	39 d0                	cmp    %edx,%eax
    14bd:	0f 4c c2             	cmovl  %edx,%eax
    14c0:	0f bc d7             	bsf    %edi,%edx
    14c3:	89 d1                	mov    %edx,%ecx
    14c5:	85 ff                	test   %edi,%edi
    14c7:	75 e7                	jne    14b0 <bingap32_dc+0x10>
    14c9:	c3                   	retq   
    14ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000014d0 <bingap32>:
bingap32():
    14d0:	0f bc cf             	bsf    %edi,%ecx
    14d3:	31 d2                	xor    %edx,%edx
    14d5:	31 c0                	xor    %eax,%eax
    14d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    14de:	00 00 
    14e0:	39 d0                	cmp    %edx,%eax
    14e2:	0f 4c c2             	cmovl  %edx,%eax
    14e5:	d3 ef                	shr    %cl,%edi
    14e7:	89 f9                	mov    %edi,%ecx
    14e9:	f7 d1                	not    %ecx
    14eb:	0f bc c9             	bsf    %ecx,%ecx
    14ee:	d3 ef                	shr    %cl,%edi
    14f0:	0f bc d7             	bsf    %edi,%edx
    14f3:	89 d1                	mov    %edx,%ecx
    14f5:	85 ff                	test   %edi,%edi
    14f7:	75 e7                	jne    14e0 <bingap32+0x10>
    14f9:	c3                   	retq   
    14fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

*/

#if BENCH
static inline uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}


static uint64_t xoseed[4]={123,~456,789,~101};

uint64_t xo(void) {
	const uint64_t result = rotl(xoseed[1] * 5, 7) * 9;

	const uint64_t t = xoseed[1] << 17;

	xoseed[2] ^= xoseed[0];
	xoseed[3] ^= xoseed[1];
	xoseed[1] ^= xoseed[2];
	xoseed[0] ^= xoseed[3];

	xoseed[2] ^= t;

	xoseed[3] = rotl(xoseed[3], 45);

	return result;
}
#endif

int bingap_old(u64 N){// a faster pure C bingap using GCC intrinsics
int maxGap=0,gap=0;////3854590245 cycles (v1.14 for comparison)
do{
maxGap=gap>maxGap?gap:maxGap;//if N has bits set maxGap(initial iteration does nothing)
N>>=__builtin_ffsll(N);//strip trailing ones  
gap=__builtin_ctzll(N);//count trailing zeros 
N>>=gap;//strip trailing zeros (Maxgap set at next iteration)
}while(N);
return maxGap;
}

 int bingap_115(u64 N){// a faster pure C bingap using GCC intrinsics
//1836062413 cycles  v1.15 for comparison 
int maxGap=0,gap=0;
do{
maxGap=gap>maxGap?gap:maxGap;//if N has bits set maxGap(initial iteration does nothing)
N>>=__builtin_ctzll(N);//strip trailing zeros
N>>=__builtin_ctzll(~N);//strip trailing ones
gap=__builtin_ctzll(N);//count trailing zeros 
}while(N);
return maxGap;
}

int naive(unsigned int N) {
    int longestGap = 0;//3589309352 cycles from  https://codesays.com/2014/solution-to-binary-gap-by-codility/
    int gap = 0;
    int ones = 0; // number of 1's detected
    // count longest gap by checking each bit of N
    while( N != 0){
        // check if LSB(N) = 0 or 1
        if(N & 0x01) ones++;
        else if(ones) gap++;
        // Gap is found for every two 1's  detected
        if(ones == 2) {
            ones = 1;
            longestGap = gap>longestGap?gap:longestGap;
            gap = 0; // reset gap
        }
        N >>= 1;
    }
    return longestGap;
}

int bingap(u64 N){// a faster pure C bingap using GCC intrinsics
//1709464188 cycles v1.16 delayed cmove
int maxGap=0,gap=0;
do{
N>>=__builtin_ctzll(N);//strip trailing zeros
N>>=__builtin_ctzll(~N);//strip trailing ones
maxGap=gap>maxGap?gap:maxGap;//if N has bits set maxGap(initial iteration does nothing)
gap=__builtin_ctzll(N);//count trailing zeros 
}while(N);
return maxGap;
}
/*
 0 1 2 3 4 5 6 7 8 9 A B C D E F
{0,0,0,0,0,1,0,0,0,2,1,1,0,1,0,0
,0,3,2,2,1,1,1,1,0,2,1,1,0,1,0,0
,0,4,3,3,2,2,2,2,1,2,1,1,1,1,1,1
,0,3,2,2,1,1,1,1,0,2,1,1,0,1,0,0
,0,5,4,4,3,3,3,3,2,2,2,2,2,2,2,2
,1,3,2,2,1,1,1,1,1,2,1,1,1,1,1,1
,0,4,3,3,2,2,2,2,1,2,1,1,1,1,1,1
,0,3,2,2,1,1,1,1,0,2,1,1,0,1,0,0
,0,6,5,5,4,4,4,4,3,3,3,3,3,3,3,3
,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2
,1,4,3,3,2,2,2,2,1,2,1,1,1,1,1,1
,1,3,2,2,1,1,1,1,1,2,1,1,1,1,1,1
,0,5,4,4,3,3,3,3,2,2,2,2,2,2,2,2
,1,3,2,2,1,1,1,1,1,2,1,1,1,1,1,1
,0,4,3,3,2,2,2,2,1,2,1,1,1,1,1,1
,0,3,2,2,1,1,1,1,0,2,1,1,0,1,0,0}





}

*/
//=============================================

//delayed compare version
 int bingap32_dc(u32 N){// a faster pure C bingap using GCC intrinsics
int maxGap=0,gap=0;//905887818 cycles
do{
N>>=__builtin_ctz(N);//strip trailing zeros
N>>=__builtin_ctz(~N);//strip trailing ones
maxGap=gap>maxGap?gap:maxGap;//if N has bits set maxGap(initial iteration does nothing)
gap=__builtin_ctz(N);//count trailing zeros 
}while(N);

return maxGap;	
}


 int bingap32(u32 N){// a faster pure C bingap using GCC intrinsics
int maxGap=0,gap=0;// 925711873 cycles
do{
maxGap=gap>maxGap?gap:maxGap;//if N has bits set maxGap(initial iteration does nothing)
N>>=__builtin_ctz(N);//strip trailing zeros
N>>=__builtin_ctz(~N);//strip trailing ones
gap=__builtin_ctz(N);//count trailing zeros 
}while(N);
return maxGap;	
}




int main(int argc,char**argv){if(argc<2)return 0;

char s[MAX_BITS+1]={0};
strncpy(s,argv[1],MAX_BITS);
#define gaptype u64
#if BENCH
printf("RndSeed:%llx\n",(long long unsigned int)xo());
u64 sum=0;
u64 start=__rdtsc();
//for(int i=0;i<1;i++){
for(int i=0;i<10000000;i++){
//for(int i=0;i<1000000000;i++){

u64 r=xo();
//sum+=bingap(r);//64-bit
sum+=bingap32_dc((unsigned int)r);


}
u64 end=__rdtsc();
printf("Bench :%llu cycles sum:%llu\n",end-start,sum);
#endif
u64 y=strtoull((const char*)&s,NULL,10);u64 x=y;
for(int i=MAX_BITS-1;i>-1;i--){s[i]=x&1?'1':'0';x>>=1;};//binary
int res=bingap(y);
printf("Number:%llu\n",y);
printf("Hexnum:%llx\n",y);
printf("Binary:%.*s\n",MAX_BITS,s);
printf("Bingap:%d\n",res);
//printf("%d,",res);

return 0;}
