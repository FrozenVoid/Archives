/* hofseq.c v1.05 by FrozenVoid  */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
//cached values for P < 256
//https://en.wikipedia.org/wiki/Hofstadter_sequence#Hofstadter_Figure-Figure_sequences
const 	uint_fast16_t lownum[]={3,3,7,12,18,26,35,45,56,69,83,98,114,131,150,170,191,213,236,260,
285,312,340,369,399,430,462,495,529,565,602,640,679,719,760,802,845,889,935,
982,1030,1079,1129,1180,1232,1285,1339,1394,1451,1509,1568,1628,1689,1751,1814,
1878,1943,2009,2076,2144,2214,2285,2357,2430,2504,2579,2655,2732,2810,2889,2969,
3050,3132,3216,3301,3387,3474,3562,3651,3741,3832,3924,4017,4111,4206,4302,4399,
4498,4598,4699,4801,4904,5008,5113,5219,5326,5434,5543,5653,5764,5876,5989,6104,
6220,6337,6455,6574,6694,6815,6937,7060,7184,7309,7435,7562,7690,7819,7949,8081,
8214,8348,8483,8619,8756,8894,9033,9173,9314,9456,9599,9743,9888,10034,10181,
10329,10478,10629,10781,10934,11088,11243,11399,11556,11714,11873,12033,12194,
12356,12519,12683,12848,13014,13181,13349,13518,13689,13861,14034,14208,14383,
14559,14736,14914,15093,15273,15454,15636,15819,16003,16188,16374,16561,16749,
16938,17128,17320,17513,17707,17902,18098,18295,18493,18692,18892,19093,19295,
19498,19702,19907,20113,20320,20528,20737,20947,21158,21370,21584,21799,22015,
22232,22450,22669,22889,23110,23332,23555,23779,24004,24230,24457,24685,24914,
25144,25375,25607,25840,26074,26309,26546,26784,27023,27263,27504,27746,27989,
28233,28478,28724,28971,29219,29468,29718,29969,30221,30474,30728,30983,31239,
31496,31754,32013,32274,32536,32799,33063,33328,33594,33861,34129,34398,34668,
34939,35211,35484,35758,36033,36309,36586};

uint64_t hofseq_ff(uint64_t N) {
    uint64_t R = 1, S = 2, P = 1, t = 0,Plast=0;

    for (uint64_t i = 1; i < N; i++) {
         R += S++; 
       if(Plast!=P){  t = P > 255 ? hofseq_ff(P) : lownum[P];  Plast=P; }
  
    if(S==t){S++;P++;}else {P+=S>t;}

     }
     return R;
}
uint64_t hofseq(uint64_t N){
    uint64_t R = 1, S = 2, P = 1, t = 0,Plast=0;

    for (uint64_t i = 1; i < N; i++) {
       printf("%" PRIu64 ",",R);
         R += S++; 
        if(Plast!=P){  t = P > 255 ? hofseq_ff(P) : lownum[P];  Plast=P; }
         if(S==t){S++;P++;}else {P+=S>t;}
     }
     return R;


}

int main(int argc, char**argv) {
// Syntax: hofseq Num1 [Num2]
//if second argument, print sequence up to Num2
if(argc==3){ hofseq( strtoull(argv[2], NULL, 10));}
//print hofseq Nth number(num1)
if(argc>=2){  printf("%" PRIu64 "", hofseq_ff(strtoull(argv[1], NULL, 10)));}


return 0;}