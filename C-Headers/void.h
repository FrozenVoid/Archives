
    #pragma once   //VOID.H C HEADER
    #define __USE_MINGW_ANSI_STDIO 1
    #define _FILE_OFFSET_BITS 64
    #define _THREAD_SAFE 1
    #define _LARGEFILE_SOURCE 1
    #define MINGW_HAS_SECURE_API  1


    //v2.2.1 by FrozenVoid :combined


    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <inttypes.h>
    #include <math.h>
    #include <fenv.h>
    #include <float.h>
    #include <malloc.h>
    #include <assert.h>
    #include <errno.h>
    #include <ctype.h>
    #include <limits.h>
    #include <math.h>
    #include <setjmp.h>
    #include <signal.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <time.h>
    #include <stdarg.h>   
    #include <stdnoreturn.h>

    #ifdef THREADS
    //#include <omp.h>
    #include <pthread.h>
    #include <pthread_time.h>
    #endif

    //os
    #ifdef WIN32
    #include <windows.h>
    #include <conio.h>
    #define sleepsec _sleep
    #define sleepms Sleep
    #define sleepus usleep
    #else //unix
    #include <unistd.h>
    #include <curses.h>
    #include <sys/param.h>
    #include <sys/file.h>
    #include <sys/time.h>
    #include <sys/signal.h>

    #define closesocket close
    #define sockerrno errno
    #define sleepsec sleep
    #define sleepms(x) usleep((x)*1000)
    #define sleepus usleep
    //#define netstart ;struct hostent *hostentry; 
    #endif







    //msize
    #ifdef WIN32
     #define msize _msize
    #else
     #ifdef __APPLE__
      #define msize malloc_size
     #else//assume Linux-compatible
       #define msize malloc_usable_size
     #endif
    #endif

    //Optional
    #ifdef NO_UNPORTABLE
    #else
    #include <intrin.h>
    #endif


    #ifdef USE_BIGNUM
    #include <gmp.h>
    #include <mpfr.h>
    #endif








      



    #ifndef true
    #ifndef false
    #define true 1
    #define false 0
    #endif
    #endif
     
    typedef void v0 ;//void

    typedef char c1;//text char %c
    typedef long unsigned int uc4;
    typedef long int c4;

    //arithmethic signed types
    typedef int8_t s1 ;
    typedef int16_t s2;
    typedef int32_t s4 ;
    typedef int64_t s8 ;
    //natural unsigned types
    typedef uint8_t u1;
    typedef uint16_t u2 ;
    typedef uint32_t u4 ;
    typedef uint64_t u8 ;

    //Floating point
    typedef float_t f4;
    typedef double_t f8;
    typedef long double f10;


    //pointers to types

    typedef v0* vp;//cast to raw pointer
    typedef c1* c1p;//character string
    typedef c4* c4p;//long int 
    typedef uc4* uc4p;

    typedef s1* s1p ;
    typedef s2* s2p;
    typedef s4* s4p ;
    typedef s8* s8p ;
    typedef u1* u1p;
    typedef u2* u2p ;
    typedef u4* u4p ;
    typedef u8* u8p ;
    typedef f4* f4p;
    typedef f8* f8p;
    typedef f10* f10p;
    //limits
    #define u1min ((u1)0)
    #define u2min ((u2)0)
    #define uc4min ((u4)0)
    #define u4min ((u4)0)
    #define u8min ((u8)0)


    #define u1max UINT8_MAX
    #define u2max UINT16_MAX

    #define uc4max UINT32_MAX
    #define u4max UINT32_MAX

    #define u8max UINT64_MAX

    #define c1max INT8_MAX
    #define s1max INT8_MAX
    #define s2max INT16_MAX

    #define c4max INT32_MAX
    #define s4max INT32_MAX
    #define s8max INT64_MAX

    #define c1min INT8_MIN
    #define s1min INT8_MIN

    #define s2min INT16_MIN

    #define c4min INT32_MIN
    #define s4min INT32_MIN
    #define s8min INT64_MIN

    #define f4min FLT_MIN
    #define f8min  DBL_MIN
    #define f10min  LDBL_MIN
    #define f4max FLT_MAX
    #define f8max  DBL_MAX
    #define f10max  LDBL_MAX

    #define whattype2(x) tostring(x)
    #define whattype(x) typeselect(x,whattype2)
    #define auto __auto_type
    #define istype(a,b) __builtin_types_compatible_p(typeof(a),typeof(b))
    #define eqtype(a, b) _Generic((a),b:1, default:0)
         //select type and run func on the typedef
    #define basictypes  u1,u2,u4,u8,s1,s2,s4,s8,c1,c4,uc4,f4,f8,f10
    #define inttypes  u1,u2,u4,u8,s1,s2,s4,s8,c1,c4,uc4
    #define floattypes  f4,f8,f10
    #define unsignedtypes uc4,u1,u2,u4,u8



    #define arraytypes  u1[],u2[],u4[],u8[],s1[],s2[],s4[],s8[],c1[],c4[],uc4[],f4[],f8[],f10[]
    #define ptrtypes u1p,u2p,u4p,u8p,s1p,s2p,s4p,s8p,c1p,c4p,uc4p,f4p,f8p,f10p,vp
    #define ptr2types u1p*,u2p*,u4p*,u8p*,s1p*,s2p*,s4p*,s8p*,c1p*,c4p*,uc4p*,f4p*,f8p*,f10p*,vp*
    #define ptr3types u1p**,u2p**,u4p**,u8p**,s1p**,s2p**,s4p**,s8p**,c1p**,c4p**,uc4p**,f4p**,f8p**,f10p**,vp**

    #define commontypes basictypes,arraytypes,ptrtypes
    #define tsel(var,arg1,arg2) ch(istype(var,arg1),arg1,arg2)
    #define typeselect2(x,func) func(varreapply(x,tsel,commontypes))
    #define typeselect(x,func) gn((x),uc4:func(u4),c4:func(c4),c1p:func(c1p),vp:func(vp),c1:func(c1),f4:func(f4),f8:func(f8),f10:func(f10),u1:func(u1),u2:func(u2),u4:func(u4),u8:func(u8),s1:func(s1),s2:func(s2),s4:func(s4),s8:func(s8),u1p:func(u1p),s1p:func(s1p),f4p:func(f4p),f8p:func(f8p),f10p:func(f10p),u2p:func(u2p),u4p:func(u4p),u8p:func(u8p),s2p:func(s2p),s4p:func(s4p),s8p:func(s8p))

    #define basictypeselect(x,func) gn((x),uc4:func(u4),c4:func(s4),c1:func(u1),f4:func(f4),f8:func(f8),f10:func(f10),u1:func(u1),u2:func(u2),u4:func(u4),u8:func(u8),s1:func(s1),s2:func(s2),s4:func(s4),s8:func(s8))


    #define typecheck(x,args) sum(varapply(x,istype,args))
    #define isarray(x) typecheck(x,arraytypes)
    #define isbasic(x)  typecheck(x,basictypes)
    #define isint(x)  typecheck(x,inttypes)
    #define isfloat(x)  typecheck(x,floattypes)
    #define isptr(x)  typecheck(x,ptrtypes)
    #define isptr2(x)  typecheck(x,ptr2types)
    #define isptr3(x)  typecheck(x,ptr3types)
    #define isptrtype(x)  (isptr(x)|isptr2(x)|isptr3(x))
    #define isstring(x) istype(x,c1p)
    #define isunsigned(x) typecheck(x,unsignedtypes)
    #define istrue(x)  (!!(x))
    #define isfalse(x)  (!(x))
    #define ptrto(x) ((isbasic(x))?&x:x)  

    #define strto(str,var) sm typeof(var) res=(typeof(var))(isfloat(var)?strtold(str,NULL):((isptrtype(var)||isunsigned(var))?(strtoull(str,NULL,10)):(strtoll(str,NULL,10))));res; em 

    //TypeMax example typemax(u8)==u8max
    #define typemax(x) merge(x,max)
    #define typemin(x) merge(x,min)

    //ValueMax example: tmax(1LL)==s8max
    #define vmax(x) basictypeselect(x,typemax)
    #define vmin(x) basictypeselect(x,typemin)



    #define STDSTART int main(int argc,char** argv){;;
    #define STDEND ;;return EXIT_SUCCESS;}
    #define NOUSE __attribute__((unused))
    #define pr printf
    #define fpr fprintf
    #define br break
    #define td typedef
    #define ts typedef struct
    #define tu typedef union
    #define re return
    #define inl inline
    //start/end macro
    #define sm ({;
    #define em ;})


    #define crlf "\n"
    #define empty {0}
    #define once do{;
    #define endonce ;}while(0);;
    #define tostring2(x) #x
    #define tostring(x) tostring2(x)
    #define tsc __rdtsc
    #define timing(...) ({u8 clock_start=tsc();sdt(__VA_ARGS__);tsc()-clock_start;})
    #define times(...) apply(timing,__VA_ARGS__)
    #define sa _Static_assert
    #define gn _Generic
    #define ch __builtin_choose_expr
    #define isconst __builtin_constant_p
    #define pfetch __builtin_prefetch
    //!!mingw64: broken aligned(1)    use #pragma(pack,1)
    #define PACKED  __attribute__ ((aligned (1)))
    #define ALIGNED   __attribute__ ((aligned))
    #define swap(a,b) ({auto temp__=a;a=b;b=temp__;})
    #define condswap(x,y,sw) ({typeof(x) a[2]={x,y};x=a[sw];y=a[1-(sw)];})
    #define forever for(;;)

    #define likely(x) __builtin_expect(!!(x), 1)
    #define unlikely(x) __builtin_expect(!!(x), 0)



        


    #define pcs " %s"
    #define pc1p " %s"
    #define ps1p " %s"
    #define pu1p " %s"


    #define pc1ph " %p"
    #define pf4p  " %p"
    #define pf4ph " %p"
    #define pf8p  " %p"
    #define pf8ph " %p"
    #define pf10p  " %p"
    #define pf10ph " %p"
    #define pu2p " %p"
    #define ps2p " %p"
    #define pu2ph " %p"
    #define ps2ph " %p"
    #define pu4p " %p"
    #define ps4p " %p"
    #define pu4ph " %p"
    #define ps4ph " %p"
    #define pu8p " %p"
    #define ps8p " %p"
    #define pu8ph " %p"
    #define ps8ph " %p"


    #define pcsh " %s"
    #define pvp " %p"
    #define pvph " %p"

    #define pu1ph " %p"
     #define ps1ph " %p"  
    #define pu8ph " %p"
    #define pu4ph " %p"
    #define pu2ph " %p"
    #define ps8ph " %p"
    #define ps4ph " %p"
    #define ps2ph " %p"
    #define pf10ph " %p"
    #define pf8ph " %p"
    #define pf4ph " %p"



    #define pb0 " %.1d"
    #define pb0h " %.1X"

    #define px8 " %.16llX"
    #define pu8 " %llu"
    #define ps8 " %lld"
    #define pc8 " %lli"

    #define px8h " %.16llX"
    #define pu8h " %.16llX"
    #define ps8h " %.16llX"
    #define pc8h " %.16llX"

    #define px4 " %.8X"
    #define pu4 " %u"
    #define ps4 " %d"
    #define pc4 " %li"
    #define puc4 " %lu"


    #define px4h " %.8X"
    #define pu4h " %.8X"

    #define ps4h " %.8X"
    #define pc4h " %.8lX"
    #define puc4h   " %.8lX"

    #define px2 " %.4X"
    #define pu2 " %u"
    #define ps2 " %d"
    #define pc2 " %i"
    #define px2h " %.4X"
    #define pu2h " %.4X"
    #define ps2h " %.4X"
    #define pc2h " %.4X"


    #define px1 " %.2X"
    #define pu1 " %u"
    #define ps1 " %d"
    #define pc1 " %c"

    #define px1h " %.2X"
    #define pu1h " %.2X"
    #define ps1h " %.2X"
    #define pc1h " %.2X"


    #define pf10 " %.18LG "
    #define pf8 " %.15lG "
    #define pf4 " %.6G "
    #define pf10h " %.36LA " //hex float
    #define pf8h " %.30A "
    #define pf4h " %.12a "




    //scanf formats " %"
    #define sx8 " %llx"
    #define su8 " %llu"
    #define ss8 " %lld"
    #define sx4 " %x"
    #define su4 " %u"
    #define ss4 " %d"
    #define sx2 " %hx"
    #define su2 " %hu"
    #define ss2 " %hd"
    #define sx1 " %hhx"
    #define su1 " %hhu"
    #define ss1 " %hhd"

    #define sc4 " %d"
    #define suc4 " %d"
    #define sf10 " %Lg"
    #define sf8 " %lg"
    #define sf4 " %g"

    #define sf10h " %LA"//hex float
    #define sf8h " %lA"
    #define sf4h " %A"
    #define sc1p " %s"
    #define su1p " %p"
    #define ss1p " %p"
    #define su2p " %p"
    #define ss2p " %p"
    #define su4p " %p"
    #define ss4p " %p"
    #define su8p " %p"
    #define ss8p " %p"
    #define sf4p " %p"
    #define sf8p " %p"
    #define sf10p " %p"

    #define sc1 " %c"
    #define svp " %p"



    //{ Variadic Macros


    //Variadic macro argument selector
    //stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
    //wrap returns its arguments as arglist

    #define wrap(...) __VA_ARGS__
    //converts arglist to tuple-like entity
    #define tuple(...) (__VA_ARGS__)
    //original value enclosed in parens
    #define original(x) x
    //strips parens from tuple, restoring arglist
    #define detuple(...) wrap __VA_ARGS__

      
    #define nargs(...) NARG_I_(__VA_ARGS__,reverse_push_seq_N)

    #define NARG_I_(...) ARG_N(__VA_ARGS__)
    #define ARG_N( \
    _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
    _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
    _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
    _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
    _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
    _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
    _61,_62,_63,N,...) N
    #define reverse_push_seq_N \
    63,62,61,60, \
    59,58,57,56,55,54,53,52,51,50, \
    49,48,47,46,45,44,43,42,41,40, \
    39,38,37,36,35,34,33,32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
    9,8,7,6,5,4,3,2,1,0

    // general definition for any function name

    #define _VFUNC(name, n) proxy(merge)(name, n)
    #define VFUNC(func, ...) _VFUNC(func, nargs(__VA_ARGS__))(__VA_ARGS__)

    // definition for FOO
    //#define FOO(...) VFUNC(FOO, __VA_ARGS__)
    //}





     //example: p(eval(p("sum:",'a'+'b'),'a'+'b'));
    #define merge1(x,y) x##y
    #define merge2(x,y) merge1(x,y)
    #define merge3(x,y) merge2(x,y)


    #define merge(x,y) merge2(x,y)
    #define tvalswap0 1
    #define tvalswap1 0


      //reduce args(0-64) to false0,1:true2+


    #define reduce1arg0 0
    #define reduce1arg1 0
    #define reduce1arg2 1
    #define reduce1arg3 1
    #define reduce1arg4 1
    #define reduce1arg5 1
    #define reduce1arg6 1
    #define reduce1arg7 1
    #define reduce1arg8 1
    #define reduce1arg9 1
    #define reduce1arg10 1

    #define reduce1arg11 1
    #define reduce1arg12 1
    #define reduce1arg13 1
    #define reduce1arg14 1
    #define reduce1arg15 1
    #define reduce1arg16 1
    #define reduce1arg17 1
    #define reduce1arg18 1
    #define reduce1arg19 1
    #define reduce1arg20 1
    #define reduce1arg21 1
    #define reduce1arg22 1
    #define reduce1arg23 1
    #define reduce1arg24 1
    #define reduce1arg25 1
    #define reduce1arg26 1
    #define reduce1arg27 1
    #define reduce1arg28 1
    #define reduce1arg29 1
    #define reduce1arg30 1
    #define reduce1arg31 1
    #define reduce1arg32 1
    #define reduce1arg33 1
    #define reduce1arg34 1
    #define reduce1arg35 1
    #define reduce1arg36 1
    #define reduce1arg37 1
    #define reduce1arg38 1
    #define reduce1arg39 1
    #define reduce1arg40 1
    #define reduce1arg41 1
    #define reduce1arg42 1
    #define reduce1arg43 1
    #define reduce1arg44 1
    #define reduce1arg45 1
    #define reduce1arg46 1
    #define reduce1arg47 1
    #define reduce1arg48 1
    #define reduce1arg49 1
    #define reduce1arg50 1
    #define reduce1arg51 1
    #define reduce1arg52 1
    #define reduce1arg53 1
    #define reduce1arg54 1
    #define reduce1arg55 1
    #define reduce1arg56 1
    #define reduce1arg57 1
    #define reduce1arg58 1
    #define reduce1arg59 1
    #define reduce1arg60 1
    #define reduce1arg61 1
    #define reduce1arg62 1
    #define reduce1arg63 1
    #define reduce1arg64 1
    #define reduce1arg65 1
    #define reduce1arg66 1
    #define reduce1arg67 1
    #define reduce1arg68 1
    #define reduce1arg69 1
    #define reduce1arg70 1
    #define reduce1arg71 1
    #define reduce1arg72 1
    #define reduce1arg73 1
    #define reduce1arg74 1
    #define reduce1arg75 1
    #define reduce1arg76 1
    #define reduce1arg77 1
    #define reduce1arg78 1
    #define reduce1arg79 1
    #define reduce1arg80 1
    #define reduce1arg81 1
    #define reduce1arg82 1
    #define reduce1arg83 1
    #define reduce1arg84 1
    #define reduce1arg85 1
    #define reduce1arg86 1
    #define reduce1arg87 1
    #define reduce1arg88 1
    #define reduce1arg89 1

    #define reduce1arg(arg) _VFUNC(reduce1arg,arg)
    //reduce0arg false0:true1+

    #define reduce0arg0 0
    #define reduce0arg1 1
    #define reduce0arg2 1
    #define reduce0arg3 1
    #define reduce0arg4 1
    #define reduce0arg5 1
    #define reduce0arg6 1
    #define reduce0arg7 1
    #define reduce0arg8 1
    #define reduce0arg9 1
    #define reduce0arg10 1

    #define reduce0arg11 1
    #define reduce0arg12 1
    #define reduce0arg13 1
    #define reduce0arg14 1
    #define reduce0arg15 1
    #define reduce0arg16 1
    #define reduce0arg17 1
    #define reduce0arg18 1
    #define reduce0arg19 1
    #define reduce0arg20 1
    #define reduce0arg21 1
    #define reduce0arg22 1
    #define reduce0arg23 1
    #define reduce0arg24 1
    #define reduce0arg25 1
    #define reduce0arg26 1
    #define reduce0arg27 1
    #define reduce0arg28 1
    #define reduce0arg29 1
    #define reduce0arg30 1
    #define reduce0arg31 1
    #define reduce0arg32 1
    #define reduce0arg33 1
    #define reduce0arg34 1
    #define reduce0arg35 1
    #define reduce0arg36 1
    #define reduce0arg37 1
    #define reduce0arg38 1
    #define reduce0arg39 1
    #define reduce0arg40 1
    #define reduce0arg41 1
    #define reduce0arg42 1
    #define reduce0arg43 1
    #define reduce0arg44 1
    #define reduce0arg45 1
    #define reduce0arg46 1
    #define reduce0arg47 1
    #define reduce0arg48 1
    #define reduce0arg49 1
    #define reduce0arg50 1
    #define reduce0arg51 1
    #define reduce0arg52 1
    #define reduce0arg53 1
    #define reduce0arg54 1
    #define reduce0arg55 1
    #define reduce0arg56 1
    #define reduce0arg57 1
    #define reduce0arg58 1
    #define reduce0arg59 1
    #define reduce0arg60 1
    #define reduce0arg61 1
    #define reduce0arg62 1
    #define reduce0arg63 1
    #define reduce0arg64 1
    #define reduce0arg65 1
    #define reduce0arg66 1
    #define reduce0arg67 1
    #define reduce0arg68 1
    #define reduce0arg69 1
    #define reduce0arg(arg) _VFUNC(reduce0arg,arg)
    //reduce2arg false0,1,2:true3+

    #define reduce2arg0 0
    #define reduce2arg1 0
    #define reduce2arg2 0
    #define reduce2arg3 1
    #define reduce2arg4 1
    #define reduce2arg5 1
    #define reduce2arg6 1
    #define reduce2arg7 1
    #define reduce2arg8 1
    #define reduce2arg9 1
    #define reduce2arg10 1

    #define reduce2arg11 1
    #define reduce2arg12 1
    #define reduce2arg13 1
    #define reduce2arg14 1
    #define reduce2arg15 1
    #define reduce2arg16 1
    #define reduce2arg17 1
    #define reduce2arg18 1
    #define reduce2arg19 1
    #define reduce2arg20 1
    #define reduce2arg21 1
    #define reduce2arg22 1
    #define reduce2arg23 1
    #define reduce2arg24 1
    #define reduce2arg25 1
    #define reduce2arg26 1
    #define reduce2arg27 1
    #define reduce2arg28 1
    #define reduce2arg29 1
    #define reduce2arg30 1
    #define reduce2arg31 1
    #define reduce2arg32 1
    #define reduce2arg33 1
    #define reduce2arg34 1
    #define reduce2arg35 1
    #define reduce2arg36 1
    #define reduce2arg37 1
    #define reduce2arg38 1
    #define reduce2arg39 1
    #define reduce2arg40 1
    #define reduce2arg41 1
    #define reduce2arg42 1
    #define reduce2arg43 1
    #define reduce2arg44 1
    #define reduce2arg45 1
    #define reduce2arg46 1
    #define reduce2arg47 1
    #define reduce2arg48 1
    #define reduce2arg49 1
    #define reduce2arg50 1
    #define reduce2arg51 1
    #define reduce2arg52 1
    #define reduce2arg53 1
    #define reduce2arg54 1
    #define reduce2arg55 1
    #define reduce2arg56 1
    #define reduce2arg57 1
    #define reduce2arg58 1
    #define reduce2arg59 1
    #define reduce2arg60 1
    #define reduce2arg61 1
    #define reduce2arg62 1
    #define reduce2arg63 1
    #define reduce2arg64 1
    #define reduce2arg65 1
    #define reduce2arg66 1
    #define reduce2arg67 1
    #define reduce2arg68 1
    #define reduce2arg69 1
    #define reduce2arg(arg) _VFUNC(reduce2arg,arg)

    #define zeroargs(...) zeropush2(1,##__VA_ARGS__)
    #define zeropush2(...) merge(tvalswap,reduce1arg(nargs(__VA_ARGS__)))   

    //from CheckArgumentsNonNil in  bbs.progrider.org/prog/read/1452950345
    #define validargs(args...) !(sum(apply(zeroargs,args)))
    //http://stackoverflow.com/questions/12447557/can-we-have-recursive-macros
    #define emptyaction(...)
    #define defer(...) __VA_ARGS__ emptyaction()
    #define obstruct(...) __VA_ARGS__( defer(emptyaction)())
    #define expand(...) __VA_ARGS__
    #define expand2(...) expand(expand(expand(__VA_ARGS__)))
    #define expand3(...) expand2(expand2(expand2(__VA_ARGS__)))
    #define expand4(...) expand3(expand3(expand3(__VA_ARGS__)))
    #define expand5(...) expand4(expand4(expand4(__VA_ARGS__)))
    //force to evaluate function multiple times
    #define recur(...)   expand5(expand5(expand5(__VA_ARGS__)))

    #define proxy recur





    //exports: apply2(func,arg1,arg2,args...)
    // varreapply(var,func,arg1,...)  func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    // varapply(var,func,arg1,...)   (_VFUNC(varapply,nargs(var,func,arg1,__VA_ARGS__)))(var,func,arg1,__VA_ARGS__)
    //  opapply(operator,func,...)  (_VFUNC(opapply,nargs(operator,func,__VA_ARGS__)))(operator,func,__VA_ARGS__)  

    //Apply2.h apply functions with(2 args)
    //{APPLY2 apply func to 2arguments at once
      #define n2apply1(arg1) arg1
      //case when called with 1
      #define n2apply2(func,arg1) func(arg1)
                 //_VFUNC(pv, nargs(__VA_ARGS__))(__VA_ARGS__)
    #define n2apply3(func,arg1,arg2) func(arg1,arg2)
    #define n2apply4(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply5(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply6(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply7(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply8(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply9(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

    #define n2apply10(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply11(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply12(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply13(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply14(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply15(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply16(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply17(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply18(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply19(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define n2apply20(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply21(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply22(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply23(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply24(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply25(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply26(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply27(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply28(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply29(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define n2apply30(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply31(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply32(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply33(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply34(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply35(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply36(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply37(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply38(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply39(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     #define n2apply40(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply41(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply42(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply43(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply44(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply45(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply46(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply47(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply48(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply49(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    \
    #define n2apply50(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply51(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply52(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply53(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply54(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply55(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply56(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply57(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply58(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply59(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     #define n2apply60(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply61(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply62(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply63(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define n2apply64(func,arg1,arg2,...) func(arg1,arg2),_VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     
     
    #define apply2(func,...) _VFUNC(n2apply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)


    //recur. apply    with var


    #define varreapply4(var,func,arg1,arg2) func(var,arg1,arg2)
    #define varreapply5(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply6(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply7(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply8(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply9(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))

    #define varreapply10(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply11(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply12(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply13(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply14(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply15(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply16(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply17(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply18(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply19(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
     
    #define varreapply20(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply21(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply22(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply23(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply24(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply25(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply26(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply27(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply28(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply29(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
     
    #define varreapply30(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply31(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply32(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply33(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply34(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply35(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply36(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply37(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply38(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply39(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))

     #define varreapply40(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply41(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply42(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply43(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply44(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply45(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply46(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply47(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply48(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply49(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    \
    #define varreapply50(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply51(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply52(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply53(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply54(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply55(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply56(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply57(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply58(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply59(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))


     #define varreapply60(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply61(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply62(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply63(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))
    #define varreapply64(var,func,arg1,...) func(var,arg1,_VFUNC(varreapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__))


    #define varreapply(var,func,arg1,...)     _VFUNC(varreapply,nargs(var,func,arg1,__VA_ARGS__))(var,func,arg1,__VA_ARGS__)



    //{varapply same as apply but var is used as first argument for func,  func(commonvar,argN)

    #define varapply3(var,func,arg1) func(var,arg1) 
    #define varapply4(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply5(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply6(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply7(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply8(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply9(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)

    #define varapply10(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply11(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply12(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply13(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply14(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply15(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply16(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply17(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply18(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply19(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
     
    #define varapply20(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply21(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply22(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply23(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply24(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply25(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply26(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply27(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply28(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply29(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
     
    #define varapply30(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply31(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply32(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply33(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply34(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply35(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply36(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply37(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply38(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply39(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)

     #define varapply40(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply41(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply42(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply43(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply44(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply45(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply46(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply47(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply48(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply49(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    \
    #define varapply50(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply51(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply52(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply53(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply54(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply55(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply56(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply57(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply58(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply59(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)


     #define varapply60(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply61(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply62(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply63(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)
    #define varapply64(var,func,arg1,...) func(var,arg1) ,_VFUNC(varapply,nargs(var,func,__VA_ARGS__))(var,func,__VA_ARGS__)


    #define varapply(var,func,arg1,...)   _VFUNC(varapply,nargs(var,func,arg1,__VA_ARGS__))(var,func,arg1,__VA_ARGS__)


    //OPAPPLY:same as apply but use custom "operator" glue macro instead of comma

                 //_VFUNC(pv, nargs(__VA_ARGS__))(__VA_ARGS__)
    #define opapply3(operator,func,arg1) func(arg1) 
    #define opapply4(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply5(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply6(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply7(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply8(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply9(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)

    #define opapply10(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply11(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply12(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply13(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply14(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply15(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply16(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply17(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply18(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply19(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
     
    #define opapply20(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply21(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply22(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply23(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply24(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply25(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply26(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply27(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply28(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply29(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
     
    #define opapply30(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply31(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply32(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply33(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply34(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply35(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply36(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply37(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply38(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply39(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)

     #define opapply40(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply41(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply42(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply43(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply44(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply45(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply46(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply47(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply48(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply49(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    \
    #define opapply50(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply51(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply52(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply53(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply54(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply55(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply56(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply57(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply58(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply59(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)


     #define opapply60(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply61(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply62(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply63(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)
    #define opapply64(operator,func,arg1,...) func(arg1) operator _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)



    #define opapply(operator,func,...)  _VFUNC(opapply,nargs(operator,func,__VA_ARGS__))(operator,func,__VA_ARGS__)  



    //macro applicators

    //{APPLY apply func to arguments,one by one
      #define napply1(func) func
      #define napply2(func,arg1) func(arg1)
                 //_VFUNC(pv, nargs(__VA_ARGS__))(__VA_ARGS__)
    #define napply3(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply4(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply5(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply6(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply7(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply8(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply9(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

    #define napply10(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply11(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply12(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply13(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply14(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply15(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply16(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply17(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply18(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply19(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define napply20(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply21(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply22(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply23(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply24(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply25(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply26(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply27(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply28(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply29(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define napply30(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply31(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply32(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply33(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply34(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply35(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply36(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply37(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply38(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply39(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     #define napply40(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply41(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply42(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply43(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply44(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply45(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply46(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply47(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply48(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply49(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    \
    #define napply50(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply51(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply52(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply53(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply54(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply55(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply56(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply57(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply58(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply59(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)


     #define napply60(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply61(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply62(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply63(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define napply64(func,arg1,...) func(arg1),_VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     
     
    #define apply(func,...) _VFUNC(napply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)


    //}


    //}


    //}
    //recur. apply

    #define reapply3(func,arg1,arg2) func(arg1,arg2)
    #define reapply4(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply5(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply6(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply7(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply8(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply9(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))

    #define reapply10(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply11(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply12(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply13(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply14(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply15(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply16(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply17(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply18(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply19(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
     
    #define reapply20(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply21(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply22(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply23(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply24(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply25(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply26(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply27(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply28(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply29(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
     
    #define reapply30(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply31(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply32(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply33(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply34(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply35(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply36(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply37(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply38(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply39(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))

     #define reapply40(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply41(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply42(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply43(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply44(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply45(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply46(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply47(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply48(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply49(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    \
    #define reapply50(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply51(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply52(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply53(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply54(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply55(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply56(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply57(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply58(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply59(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))


     #define reapply60(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply61(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply62(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply63(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define reapply64(func,arg1,...) func(arg1,_VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))


    #define reapply(func,...)     _VFUNC(reapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)



    //filter args by condition (preprocessor token which expands to 0 for exclude argument,1 include argument)

    #define arginclude0(arg1,...) __VA_ARGS__  
    #define arginclude1(arg1,...) arg1,__VA_ARGS__
    #define argfilter(cond,arg1,arg2) merge(arginclude,cond(arg1))(arg1,arg2)
    #define filtargs(cond,...) varreapply(cond,argfilter,__VA_ARGS__) 

    //chain apply (func,func2,func3,arg1,arg2,arg3) ->     func(func2(func3( 

    #define capply0(...)  __VA_ARGS__
    #define capply1(func1,...)  func1(__VA_ARGS__)
    #define capply2(func1,...)  func1(capply1(__VA_ARGS__))
    #define capply3(func1,...)  func1(capply2(__VA_ARGS__))
    #define capply4(func1,...)  func1(capply3(__VA_ARGS__))
    #define capply5(func1,...)  func1(capply4(__VA_ARGS__))
    #define capply6(func1,...)  func1(capply5(__VA_ARGS__))
    #define capply7(func1,...)  func1(capply6(__VA_ARGS__))
    #define capply8(func1,...)  func1(capply7(__VA_ARGS__))
    #define capply9(func1,...)  func1(capply8(__VA_ARGS__))

    #define capply10(func1,...)  func1(capply9(__VA_ARGS__))
    #define capply11(func1,...)  func1(capply10(__VA_ARGS__))
    #define capply12(func1,...)  func1(capply11(__VA_ARGS__))
    #define capply13(func1,...)  func1(capply12(__VA_ARGS__))
    #define capply14(func1,...)  func1(capply13(__VA_ARGS__))
    #define capply15(func1,...)  func1(capply14(__VA_ARGS__))
    #define capply16(func1,...)  func1(capply15(__VA_ARGS__))
    #define capply17(func1,...)  func1(capply16(__VA_ARGS__))
    #define capply18(func1,...)  func1(capply17(__VA_ARGS__))
    #define capply19(func1,...)  func1(capply18(__VA_ARGS__))


    #define capply20(func1,...)  func1(capply19(__VA_ARGS__))
    #define capply21(func1,...)  func1(capply20(__VA_ARGS__))
    #define capply22(func1,...)  func1(capply21(__VA_ARGS__))
    #define capply23(func1,...)  func1(capply22(__VA_ARGS__))
    #define capply24(func1,...)  func1(capply23(__VA_ARGS__))
    #define capply25(func1,...)  func1(capply24(__VA_ARGS__))
    #define capply26(func1,...)  func1(capply25(__VA_ARGS__))
    #define capply27(func1,...)  func1(capply26(__VA_ARGS__))
    #define capply28(func1,...)  func1(capply27(__VA_ARGS__))
    #define capply29(func1,...)  func1(capply28(__VA_ARGS__))


    #define capply30(func1,...)  func1(capply29(__VA_ARGS__))
    #define capply31(func1,...)  func1(capply30(__VA_ARGS__))
    #define capply32(func1,...)  func1(capply31(__VA_ARGS__))
    #define capply33(func1,...)  func1(capply32(__VA_ARGS__))
    #define capply34(func1,...)  func1(capply33(__VA_ARGS__))
    #define capply35(func1,...)  func1(capply34(__VA_ARGS__))
    #define capply36(func1,...)  func1(capply35(__VA_ARGS__))
    #define capply37(func1,...)  func1(capply36(__VA_ARGS__))
    #define capply38(func1,...)  func1(capply37(__VA_ARGS__))
    #define capply39(func1,...)  func1(capply38(__VA_ARGS__))



    #define capply40(func1,...)  func1(capply39(__VA_ARGS__))
    #define capply41(func1,...)  func1(capply40(__VA_ARGS__))
    #define capply42(func1,...)  func1(capply41(__VA_ARGS__))
    #define capply43(func1,...)  func1(capply42(__VA_ARGS__))
    #define capply44(func1,...)  func1(capply43(__VA_ARGS__))
    #define capply45(func1,...)  func1(capply44(__VA_ARGS__))
    #define capply46(func1,...)  func1(capply45(__VA_ARGS__))
    #define capply47(func1,...)  func1(capply46(__VA_ARGS__))
    #define capply48(func1,...)  func1(capply47(__VA_ARGS__))
    #define capply49(func1,...)  func1(capply48(__VA_ARGS__))


    #define capply50(func1,...)  func1(capply49(__VA_ARGS__))
    #define capply51(func1,...)  func1(capply50(__VA_ARGS__))
    #define capply52(func1,...)  func1(capply51(__VA_ARGS__))
    #define capply53(func1,...)  func1(capply52(__VA_ARGS__))
    #define capply54(func1,...)  func1(capply53(__VA_ARGS__))
    #define capply55(func1,...)  func1(capply54(__VA_ARGS__))
    #define capply56(func1,...)  func1(capply55(__VA_ARGS__))
    #define capply57(func1,...)  func1(capply56(__VA_ARGS__))
    #define capply58(func1,...)  func1(capply57(__VA_ARGS__))
    #define capply59(func1,...)  func1(capply58(__VA_ARGS__))


    #define capply60(func1,...)  func1(capply59(__VA_ARGS__))
    #define capply61(func1,...)  func1(capply60(__VA_ARGS__))
    #define capply62(func1,...)  func1(capply61(__VA_ARGS__))
    #define capply63(func1,...)  func1(capply62(__VA_ARGS__))
    #define capply64(func1,...)  func1(capply63(__VA_ARGS__))
    #define capply65(func1,...)  func1(capply64(__VA_ARGS__))
    #define capply66(func1,...)  func1(capply65(__VA_ARGS__))
    #define capply67(func1,...)  func1(capply66(__VA_ARGS__))
    #define capply68(func1,...)  func1(capply67(__VA_ARGS__))
    #define capply69(func1,...)  func1(capply68(__VA_ARGS__))


    #define capply(num,...) _VFUNC(capply,num)(__VA_ARGS__)
    //apply functions to arguments
    #define fapply(fapply_funcs,fapply_args)  capply(nargs(fapply_funcs),fapply_funcs,fapply_args)



    #define joinapply3(func,arg1,arg2) _VFUNC(func(arg1),func(arg2)) 
    #define joinapply4(func,arg1,...) _VFUNC(func(arg1),_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define joinapply5(func,arg1,...) _VFUNC(func(arg1),_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__))
    #define joinapply6(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply7(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply8(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply9(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

    #define joinapply10(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply11(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply12(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply13(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply14(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply15(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply16(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply17(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply18(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply19(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define joinapply20(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply21(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply22(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply23(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply24(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply25(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply26(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply27(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply28(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply29(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
     
    #define joinapply30(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply31(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply32(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply33(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply34(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply35(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply36(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply37(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply38(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply39(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)

     #define joinapply40(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply41(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply42(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply43(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply44(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply45(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply46(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply47(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply48(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply49(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    \
    #define joinapply50(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply51(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply52(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply53(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply54(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply55(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply56(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply57(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply58(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply59(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)


     #define joinapply60(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply61(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply62(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply63(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)
    #define joinapply64(func,arg1,...) func(arg1)""_VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)



    #define joinapply(func,...)  _VFUNC(joinapply,nargs(func,__VA_ARGS__))(func,__VA_ARGS__)  

    //argument manipulation/selection
    //generate arglist
    #define genargs0 0
    #define genargs1 genargs0,1
    #define genargs2 genargs1,2
    #define genargs3 genargs2,3
    #define genargs4 genargs3,4
    #define genargs5 genargs4,5
    #define genargs6 genargs5,6
    #define genargs7 genargs6,7
    #define genargs8 genargs7,8
    #define genargs9 genargs8,9
    #define genargs10 genargs9,10 
    #define genargs11 genargs10,11
    #define genargs12 genargs11,12
    #define genargs13 genargs12,13
    #define genargs14 genargs13,14
    #define genargs15 genargs14,15
    #define genargs16 genargs15,16
    #define genargs17 genargs16,17
    #define genargs18 genargs17,18
    #define genargs19 genargs18,19
    #define genargs20 genargs19,20 
    #define genargs21 genargs20,21
    #define genargs22 genargs21,22
    #define genargs23 genargs22,23
    #define genargs24 genargs23,24
    #define genargs25 genargs24,25
    #define genargs26 genargs25,26
    #define genargs27 genargs26,27
    #define genargs28 genargs27,28
    #define genargs29 genargs28,29
    #define genargs30 genargs29,30 
    #define genargs31 genargs30,31
    #define genargs32 genargs31,32
    #define genargs33 genargs32,33
    #define genargs34 genargs33,34
    #define genargs35 genargs34,35
    #define genargs36 genargs35,36
    #define genargs37 genargs36,37
    #define genargs38 genargs37,38
    #define genargs39 genargs38,39
    #define genargs40 genargs39,40 
    #define genargs41 genargs40,41
    #define genargs42 genargs41,42
    #define genargs43 genargs42,43
    #define genargs44 genargs43,44
    #define genargs45 genargs44,45
    #define genargs46 genargs45,46
    #define genargs47 genargs46,47
    #define genargs48 genargs47,48
    #define genargs49 genargs48,49
    #define genargs50 genargs49,50 
    #define genargs51 genargs50,51
    #define genargs52 genargs51,52
    #define genargs53 genargs52,53
    #define genargs54 genargs53,54
    #define genargs55 genargs54,55
    #define genargs56 genargs55,56
    #define genargs57 genargs56,57
    #define genargs58 genargs57,58
    #define genargs59 genargs58,59
    #define genargs60 genargs59,60
    #define genargs61 genargs60,61
    #define genargs62 genargs61,62
    #define genargs63 genargs62,63
    #define genargs64 genargs63,64
    #define genargs65 genargs64,65
    #define genargs66 genargs65,66
    #define genargs67 genargs66,67
    #define genargs68 genargs67,68
    #define genargs69 genargs68,69
    #define genargs70 genargs69,70
    #define genargs71 genargs70,71
    #define genargs72 genargs71,72
    #define genargs73 genargs72,73
    #define genargs74 genargs73,74
    #define genargs75 genargs74,75
    #define genargs76 genargs75,76
    #define genargs77 genargs76,77
    #define genargs78 genargs77,78
    #define genargs79 genargs78,79
    #define genargs80 genargs79,80



    #define genargs(n)   proxy(wrap)(_VFUNC(genargs,n))

    //compose and execute arguments
     
    //macro chain,fail to terminate
    #define mch(func,args...) opapply(&&,func,args)
    //first to complete
    #define fch(func,args...) opapply(||,func,args)
    //assign all chain
    #define ech(func,args...) opapply(=,func,args)
    //true all chain
    #define tch(func,args...) opapply(==,func,args)

     //return Nth arg
    #define front0(...) 
    #define front1(arg1,...) arg1
    #define front2(arg1,...) front1(__VA_ARGS__)
    #define front3(arg1,...) front2(__VA_ARGS__)
    #define front4(arg1,...) front3(__VA_ARGS__) 
    #define front5(arg1,...) front4(__VA_ARGS__) 
    #define front6(arg1,...) front5(__VA_ARGS__) 
    #define front7(arg1,...) front6(__VA_ARGS__) 
    #define front8(arg1,...) front7(__VA_ARGS__) 
    #define front9(arg1,...) front8(__VA_ARGS__) 
    #define front10(arg1,...) front9(__VA_ARGS__) 
    #define front11(arg1,...) front10(__VA_ARGS__)
    #define front12(arg1,...) front11(__VA_ARGS__)
    #define front13(arg1,...) front12(__VA_ARGS__)
    #define front14(arg1,...) front13(__VA_ARGS__) 
    #define front15(arg1,...) front14(__VA_ARGS__) 
    #define front16(arg1,...) front15(__VA_ARGS__) 
    #define front17(arg1,...) front16(__VA_ARGS__) 
    #define front18(arg1,...) front17(__VA_ARGS__) 
    #define front19(arg1,...) front18(__VA_ARGS__) 
    #define front20(arg1,...) front19(__VA_ARGS__) 
    #define front21(arg1,...) front20(__VA_ARGS__)
    #define front22(arg1,...) front21(__VA_ARGS__)
    #define front23(arg1,...) front22(__VA_ARGS__)
    #define front24(arg1,...) front23(__VA_ARGS__) 
    #define front25(arg1,...) front24(__VA_ARGS__) 
    #define front26(arg1,...) front25(__VA_ARGS__) 
    #define front27(arg1,...) front26(__VA_ARGS__) 
    #define front28(arg1,...) front27(__VA_ARGS__) 
    #define front29(arg1,...) front28(__VA_ARGS__) 
    #define front30(arg1,...) front29(__VA_ARGS__) 
    #define front31(arg1,...) front30(__VA_ARGS__)
    #define front32(arg1,...) front31(__VA_ARGS__)
    #define front33(arg1,...) front32(__VA_ARGS__)
    #define front34(arg1,...) front33(__VA_ARGS__) 
    #define front35(arg1,...) front34(__VA_ARGS__) 
    #define front36(arg1,...) front35(__VA_ARGS__) 
    #define front37(arg1,...) front36(__VA_ARGS__) 
    #define front38(arg1,...) front37(__VA_ARGS__) 
    #define front39(arg1,...) front38(__VA_ARGS__) 
    #define front40(arg1,...) front39(__VA_ARGS__) 
    #define front41(arg1,...) front40(__VA_ARGS__)
    #define front42(arg1,...) front41(__VA_ARGS__)
    #define front43(arg1,...) front42(__VA_ARGS__)
    #define front44(arg1,...) front43(__VA_ARGS__) 
    #define front45(arg1,...) front44(__VA_ARGS__) 
    #define front46(arg1,...) front45(__VA_ARGS__) 
    #define front47(arg1,...) front46(__VA_ARGS__) 
    #define front48(arg1,...) front47(__VA_ARGS__) 
    #define front49(arg1,...) front48(__VA_ARGS__) 
    #define front50(arg1,...) front49(__VA_ARGS__) 
    #define front51(arg1,...) front50(__VA_ARGS__)
    #define front52(arg1,...) front51(__VA_ARGS__)
    #define front53(arg1,...) front52(__VA_ARGS__)
    #define front54(arg1,...) front53(__VA_ARGS__) 
    #define front55(arg1,...) front54(__VA_ARGS__) 
    #define front56(arg1,...) front55(__VA_ARGS__) 
    #define front57(arg1,...) front56(__VA_ARGS__) 
    #define front58(arg1,...) front57(__VA_ARGS__) 
    #define front59(arg1,...) front58(__VA_ARGS__) 
    #define front60(arg1,...) front59(__VA_ARGS__) 
    #define front61(arg1,...) front60(__VA_ARGS__)
    #define front62(arg1,...) front61(__VA_ARGS__)
    #define front63(arg1,...) front62(__VA_ARGS__)
    #define front64(arg1,...) front63(__VA_ARGS__) 
    #define front65(arg1,...) front64(__VA_ARGS__) 
    #define front66(arg1,...) front65(__VA_ARGS__) 
    #define front67(arg1,...) front66(__VA_ARGS__) 
    #define front68(arg1,...) front67(__VA_ARGS__) 
    #define front69(arg1,...) front68(__VA_ARGS__) 


     #define ntharg(n,...) _VFUNC(front,n)(__VA_ARGS__)
     
    //return Rest args after Ntharg (x,x,x,n,rest...)
     #define rest0(...) __VA_ARGS__
     #define rest1(arg1,...) __VA_ARGS__
     #define rest2(arg1,...) rest1(__VA_ARGS__)
    #define rest3(arg1,...) rest2(__VA_ARGS__)
    #define rest4(arg1,...) rest3(__VA_ARGS__) 
    #define rest5(arg1,...) rest4(__VA_ARGS__) 
    #define rest6(arg1,...) rest5(__VA_ARGS__) 
    #define rest7(arg1,...) rest6(__VA_ARGS__) 
    #define rest8(arg1,...) rest7(__VA_ARGS__) 
    #define rest9(arg1,...) rest8(__VA_ARGS__) 
    #define rest10(arg1,...) rest9(__VA_ARGS__) 
    #define rest11(arg1,...) rest10(__VA_ARGS__)
    #define rest12(arg1,...) rest11(__VA_ARGS__)
    #define rest13(arg1,...) rest12(__VA_ARGS__)
    #define rest14(arg1,...) rest13(__VA_ARGS__) 
    #define rest15(arg1,...) rest14(__VA_ARGS__) 
    #define rest16(arg1,...) rest15(__VA_ARGS__) 
    #define rest17(arg1,...) rest16(__VA_ARGS__) 
    #define rest18(arg1,...) rest17(__VA_ARGS__) 
    #define rest19(arg1,...) rest18(__VA_ARGS__) 
    #define rest20(arg1,...) rest19(__VA_ARGS__) 
    #define rest21(arg1,...) rest20(__VA_ARGS__)
    #define rest22(arg1,...) rest21(__VA_ARGS__)
    #define rest23(arg1,...) rest22(__VA_ARGS__)
    #define rest24(arg1,...) rest23(__VA_ARGS__) 
    #define rest25(arg1,...) rest24(__VA_ARGS__) 
    #define rest26(arg1,...) rest25(__VA_ARGS__) 
    #define rest27(arg1,...) rest26(__VA_ARGS__) 
    #define rest28(arg1,...) rest27(__VA_ARGS__) 
    #define rest29(arg1,...) rest28(__VA_ARGS__) 
    #define rest30(arg1,...) rest29(__VA_ARGS__) 
    #define rest31(arg1,...) rest30(__VA_ARGS__)
    #define rest32(arg1,...) rest31(__VA_ARGS__)
    #define rest33(arg1,...) rest32(__VA_ARGS__)
    #define rest34(arg1,...) rest33(__VA_ARGS__) 
    #define rest35(arg1,...) rest34(__VA_ARGS__) 
    #define rest36(arg1,...) rest35(__VA_ARGS__) 
    #define rest37(arg1,...) rest36(__VA_ARGS__) 
    #define rest38(arg1,...) rest37(__VA_ARGS__) 
    #define rest39(arg1,...) rest38(__VA_ARGS__) 
    #define rest40(arg1,...) rest39(__VA_ARGS__) 
    #define rest41(arg1,...) rest40(__VA_ARGS__)
    #define rest42(arg1,...) rest41(__VA_ARGS__)
    #define rest43(arg1,...) rest42(__VA_ARGS__)
    #define rest44(arg1,...) rest43(__VA_ARGS__) 
    #define rest45(arg1,...) rest44(__VA_ARGS__) 
    #define rest46(arg1,...) rest45(__VA_ARGS__) 
    #define rest47(arg1,...) rest46(__VA_ARGS__) 
    #define rest48(arg1,...) rest47(__VA_ARGS__) 
    #define rest49(arg1,...) rest48(__VA_ARGS__) 
    #define rest50(arg1,...) rest49(__VA_ARGS__) 
    #define rest51(arg1,...) rest50(__VA_ARGS__)
    #define rest52(arg1,...) rest51(__VA_ARGS__)
    #define rest53(arg1,...) rest52(__VA_ARGS__)
    #define rest54(arg1,...) rest53(__VA_ARGS__) 
    #define rest55(arg1,...) rest54(__VA_ARGS__) 
    #define rest56(arg1,...) rest55(__VA_ARGS__) 
    #define rest57(arg1,...) rest56(__VA_ARGS__) 
    #define rest58(arg1,...) rest57(__VA_ARGS__) 
    #define rest59(arg1,...) rest58(__VA_ARGS__) 
    #define rest60(arg1,...) rest59(__VA_ARGS__) 
    #define rest61(arg1,...) rest60(__VA_ARGS__)
    #define rest62(arg1,...) rest61(__VA_ARGS__)
    #define rest63(arg1,...) rest62(__VA_ARGS__)
    #define rest64(arg1,...) rest63(__VA_ARGS__) 
    #define rest65(arg1,...) rest64(__VA_ARGS__) 
    #define rest66(arg1,...) rest65(__VA_ARGS__) 
    #define rest67(arg1,...) rest66(__VA_ARGS__) 
    #define rest68(arg1,...) rest67(__VA_ARGS__) 
    #define rest69(arg1,...) rest68(__VA_ARGS__) 



    #define rest(n,...)  _VFUNC(rest,n)(__VA_ARGS__)

    //frontrest,return N first arguments
     #define frontrest0(...)  
     #define frontrest1(arg1,...) arg1
    #define frontrest2(arg1,...) arg1,frontrest1(__VA_ARGS__)
    #define frontrest3(arg1,...) arg1,frontrest2(__VA_ARGS__)
    #define frontrest4(arg1,...) arg1,frontrest3(__VA_ARGS__) 
    #define frontrest5(arg1,...) arg1,frontrest4(__VA_ARGS__) 
    #define frontrest6(arg1,...) arg1,frontrest5(__VA_ARGS__) 
    #define frontrest7(arg1,...) arg1,frontrest6(__VA_ARGS__) 
    #define frontrest8(arg1,...) arg1,frontrest7(__VA_ARGS__) 
    #define frontrest9(arg1,...) arg1,frontrest8(__VA_ARGS__) 
    #define frontrest10(arg1,...) arg1,frontrest9(__VA_ARGS__) 
    #define frontrest11(arg1,...) arg1,frontrest10(__VA_ARGS__)
    #define frontrest12(arg1,...) arg1,frontrest11(__VA_ARGS__)
    #define frontrest13(arg1,...) arg1,frontrest12(__VA_ARGS__)
    #define frontrest14(arg1,...) arg1,frontrest13(__VA_ARGS__) 
    #define frontrest15(arg1,...) arg1,frontrest14(__VA_ARGS__) 
    #define frontrest16(arg1,...) arg1,frontrest15(__VA_ARGS__) 
    #define frontrest17(arg1,...) arg1,frontrest16(__VA_ARGS__) 
    #define frontrest18(arg1,...) arg1,frontrest17(__VA_ARGS__) 
    #define frontrest19(arg1,...) arg1,frontrest18(__VA_ARGS__) 
    #define frontrest20(arg1,...) arg1,frontrest19(__VA_ARGS__) 
    #define frontrest21(arg1,...) arg1,frontrest20(__VA_ARGS__)
    #define frontrest22(arg1,...) arg1,frontrest21(__VA_ARGS__)
    #define frontrest23(arg1,...) arg1,frontrest22(__VA_ARGS__)
    #define frontrest24(arg1,...) arg1,frontrest23(__VA_ARGS__) 
    #define frontrest25(arg1,...) arg1,frontrest24(__VA_ARGS__) 
    #define frontrest26(arg1,...) arg1,frontrest25(__VA_ARGS__) 
    #define frontrest27(arg1,...) arg1,frontrest26(__VA_ARGS__) 
    #define frontrest28(arg1,...) arg1,frontrest27(__VA_ARGS__) 
    #define frontrest29(arg1,...) arg1,frontrest28(__VA_ARGS__) 
    #define frontrest30(arg1,...) arg1,frontrest29(__VA_ARGS__) 
    #define frontrest31(arg1,...) arg1,frontrest30(__VA_ARGS__)
    #define frontrest32(arg1,...) arg1,frontrest31(__VA_ARGS__)
    #define frontrest33(arg1,...) arg1,frontrest32(__VA_ARGS__)
    #define frontrest34(arg1,...) arg1,frontrest33(__VA_ARGS__) 
    #define frontrest35(arg1,...) arg1,frontrest34(__VA_ARGS__) 
    #define frontrest36(arg1,...) arg1,frontrest35(__VA_ARGS__) 
    #define frontrest37(arg1,...) arg1,frontrest36(__VA_ARGS__) 
    #define frontrest38(arg1,...) arg1,frontrest37(__VA_ARGS__) 
    #define frontrest39(arg1,...) arg1,frontrest38(__VA_ARGS__) 
    #define frontrest40(arg1,...) arg1,frontrest39(__VA_ARGS__) 
    #define frontrest41(arg1,...) arg1,frontrest40(__VA_ARGS__)
    #define frontrest42(arg1,...) arg1,frontrest41(__VA_ARGS__)
    #define frontrest43(arg1,...) arg1,frontrest42(__VA_ARGS__)
    #define frontrest44(arg1,...) arg1,frontrest43(__VA_ARGS__) 
    #define frontrest45(arg1,...) arg1,frontrest44(__VA_ARGS__) 
    #define frontrest46(arg1,...) arg1,frontrest45(__VA_ARGS__) 
    #define frontrest47(arg1,...) arg1,frontrest46(__VA_ARGS__) 
    #define frontrest48(arg1,...) arg1,frontrest47(__VA_ARGS__) 
    #define frontrest49(arg1,...) arg1,frontrest48(__VA_ARGS__) 
    #define frontrest50(arg1,...) arg1,frontrest49(__VA_ARGS__) 
    #define frontrest51(arg1,...) arg1,frontrest50(__VA_ARGS__)
    #define frontrest52(arg1,...) arg1,frontrest51(__VA_ARGS__)
    #define frontrest53(arg1,...) arg1,frontrest52(__VA_ARGS__)
    #define frontrest54(arg1,...) arg1,frontrest53(__VA_ARGS__) 
    #define frontrest55(arg1,...) arg1,frontrest54(__VA_ARGS__) 
    #define frontrest56(arg1,...) arg1,frontrest55(__VA_ARGS__) 
    #define frontrest57(arg1,...) arg1,frontrest56(__VA_ARGS__) 
    #define frontrest58(arg1,...) arg1,frontrest57(__VA_ARGS__) 
    #define frontrest59(arg1,...) arg1,frontrest58(__VA_ARGS__) 
    #define frontrest60(arg1,...) arg1,frontrest59(__VA_ARGS__) 
    #define frontrest61(arg1,...) arg1,frontrest60(__VA_ARGS__)
    #define frontrest62(arg1,...) arg1,frontrest61(__VA_ARGS__)
    #define frontrest63(arg1,...) arg1,frontrest62(__VA_ARGS__)
    #define frontrest64(arg1,...) arg1,frontrest63(__VA_ARGS__) 
    #define frontrest65(arg1,...) arg1,frontrest64(__VA_ARGS__) 
    #define frontrest66(arg1,...) arg1,frontrest65(__VA_ARGS__) 
    #define frontrest67(arg1,...) arg1,frontrest66(__VA_ARGS__) 
    #define frontrest68(arg1,...) arg1,frontrest67(__VA_ARGS__) 
    #define frontrest69(arg1,...) arg1,frontrest68(__VA_ARGS__) 

    #define frontrest(n,...) _VFUNC(frontrest,n)(__VA_ARGS__)

    //sliceargs(...,[start,x,x,x,last],...) 
    //get num args from start(counting from 0)
    #define sliceargs(start,num,...)  frontrest(num,rest(start,__VA_ARGS__))
    //reverse order of arguments
    #define revargs0() 
    #define revargs1(arg1) arg1
    #define revargs2(arg1,arg2) arg2,arg1
    #define revargs3(arg1,arg2,arg3)  arg3,arg2,arg1
    #define revargs4(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs5(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs6(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs7(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs8(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs9(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs10(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs11(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs12(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs13(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs14(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs15(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs16(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs17(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs18(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs19(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs20(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs21(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs22(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs23(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs24(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs25(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs26(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs27(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs28(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs29(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs30(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs31(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs32(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs33(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs34(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs35(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs36(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs37(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs38(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs39(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
     #define revargs40(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs41(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs42(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs43(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs44(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs45(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs46(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs47(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs48(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs49(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs50(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs51(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs52(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs53(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs54(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs55(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs56(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs57(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs58(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs59(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs60(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs61(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1

    #define revargs62(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs63(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs64(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs65(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs66(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs67(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs68(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs69(arg1,...)   _VFUNC(revargs,nargs(__VA_ARGS__))(__VA_ARGS__),arg1
    #define revargs(...) VFUNC(revargs,__VA_ARGS__)

    #define swap2args(a,b) revargs(a,b)

    //last Nth  arg       1=last 2=second to last,etc
    #define lastnth(n,...) ntharg(n,revargs(__VA_ARGS__))

    //replicates arguments N times
    #define repargs0(...) 
    #define repargs1(...)  __VA_ARGS__
    #define repargs2(...)  __VA_ARGS__,repargs1(__VA_ARGS__)
    #define repargs3(...)  __VA_ARGS__,repargs2(__VA_ARGS__)

    #define repargs4(...)  __VA_ARGS__,repargs3(__VA_ARGS__)
    #define repargs5(...)  __VA_ARGS__,repargs4(__VA_ARGS__)
    #define repargs6(...)  __VA_ARGS__,repargs5(__VA_ARGS__)
    #define repargs7(...)  __VA_ARGS__,repargs6(__VA_ARGS__)
    #define repargs8(...)  __VA_ARGS__,repargs7(__VA_ARGS__)
    #define repargs9(...)  __VA_ARGS__,repargs8(__VA_ARGS__)

    #define repargs10(...)   __VA_ARGS__,repargs9(__VA_ARGS__)
    #define repargs11(...) __VA_ARGS__,repargs10(__VA_ARGS__)
    #define repargs12(...)  __VA_ARGS__,repargs11(__VA_ARGS__)
    #define repargs13(...)  __VA_ARGS__,repargs12(__VA_ARGS__)

    #define repargs14(...)  __VA_ARGS__,repargs13(__VA_ARGS__)
    #define repargs15(...)  __VA_ARGS__,repargs14(__VA_ARGS__)
    #define repargs16(...)  __VA_ARGS__,repargs15(__VA_ARGS__)
    #define repargs17(...)  __VA_ARGS__,repargs16(__VA_ARGS__)
    #define repargs18(...)  __VA_ARGS__,repargs17(__VA_ARGS__)
    #define repargs19(...)  __VA_ARGS__,repargs18(__VA_ARGS__)

      
    #define repargs20(...)   __VA_ARGS__,repargs19(__VA_ARGS__)
    #define repargs21(...) __VA_ARGS__,repargs20(__VA_ARGS__)
    #define repargs22(...)  __VA_ARGS__,repargs21(__VA_ARGS__)
    #define repargs23(...)  __VA_ARGS__,repargs22(__VA_ARGS__)

    #define repargs24(...)  __VA_ARGS__,repargs23(__VA_ARGS__)
    #define repargs25(...)  __VA_ARGS__,repargs24(__VA_ARGS__)
    #define repargs26(...)  __VA_ARGS__,repargs25(__VA_ARGS__)
    #define repargs27(...)  __VA_ARGS__,repargs26(__VA_ARGS__)
    #define repargs28(...)  __VA_ARGS__,repargs27(__VA_ARGS__)
    #define repargs29(...)  __VA_ARGS__,repargs28(__VA_ARGS__)


    #define repargs30(...)   __VA_ARGS__,repargs29(__VA_ARGS__)
    #define repargs31(...) __VA_ARGS__,repargs30(__VA_ARGS__)
    #define repargs32(...)  __VA_ARGS__,repargs31(__VA_ARGS__)
    #define repargs33(...)  __VA_ARGS__,repargs32(__VA_ARGS__)

    #define repargs34(...)  __VA_ARGS__,repargs33(__VA_ARGS__)
    #define repargs35(...)  __VA_ARGS__,repargs34(__VA_ARGS__)
    #define repargs36(...)  __VA_ARGS__,repargs35(__VA_ARGS__)
    #define repargs37(...)  __VA_ARGS__,repargs36(__VA_ARGS__)
    #define repargs38(...)  __VA_ARGS__,repargs37(__VA_ARGS__)
    #define repargs39(...)  __VA_ARGS__,repargs38(__VA_ARGS__)


    #define repargs40(...)   __VA_ARGS__,repargs39(__VA_ARGS__)
    #define repargs41(...) __VA_ARGS__,repargs40(__VA_ARGS__)
    #define repargs42(...)  __VA_ARGS__,repargs41(__VA_ARGS__)
    #define repargs43(...)  __VA_ARGS__,repargs42(__VA_ARGS__)

    #define repargs44(...)  __VA_ARGS__,repargs43(__VA_ARGS__)
    #define repargs45(...)  __VA_ARGS__,repargs44(__VA_ARGS__)
    #define repargs46(...)  __VA_ARGS__,repargs45(__VA_ARGS__)
    #define repargs47(...)  __VA_ARGS__,repargs46(__VA_ARGS__)
    #define repargs48(...)  __VA_ARGS__,repargs47(__VA_ARGS__)
    #define repargs49(...)  __VA_ARGS__,repargs48(__VA_ARGS__)

      
    #define repargs50(...)   __VA_ARGS__,repargs49(__VA_ARGS__)
    #define repargs51(...) __VA_ARGS__,repargs50(__VA_ARGS__)
    #define repargs52(...)  __VA_ARGS__,repargs51(__VA_ARGS__)
    #define repargs53(...)  __VA_ARGS__,repargs52(__VA_ARGS__)

    #define repargs54(...)  __VA_ARGS__,repargs53(__VA_ARGS__)
    #define repargs55(...)  __VA_ARGS__,repargs54(__VA_ARGS__)
    #define repargs56(...)  __VA_ARGS__,repargs55(__VA_ARGS__)
    #define repargs57(...)  __VA_ARGS__,repargs56(__VA_ARGS__)
    #define repargs58(...)  __VA_ARGS__,repargs57(__VA_ARGS__)
    #define repargs59(...)  __VA_ARGS__,repargs58(__VA_ARGS__)


    #define repargs60(...)   __VA_ARGS__,repargs59(__VA_ARGS__)
    #define repargs61(...) __VA_ARGS__,repargs60(__VA_ARGS__)
    #define repargs62(...)  __VA_ARGS__,repargs61(__VA_ARGS__)
    #define repargs63(...)  __VA_ARGS__,repargs62(__VA_ARGS__)

    #define repargs64(...)  __VA_ARGS__,repargs63(__VA_ARGS__)
    #define repargs65(...)  __VA_ARGS__,repargs64(__VA_ARGS__)
    #define repargs66(...)  __VA_ARGS__,repargs65(__VA_ARGS__)
    #define repargs67(...)  __VA_ARGS__,repargs66(__VA_ARGS__)
    #define repargs68(...)  __VA_ARGS__,repargs67(__VA_ARGS__)
    #define repargs69(...)  __VA_ARGS__,repargs68(__VA_ARGS__)




    #define repargs(n,...) merge(repargs,n)(__VA_ARGS__)


    //joinargs as strings

    #define joinargs0(...) 
    #define joinargs1(arg1) arg1
    #define joinargs2(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs3(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs4(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs5(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs6(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs7(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs8(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs9(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs10(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs11(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs12(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs13(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs14(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs15(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs16(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs17(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs18(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs19(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs20(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs21(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs22(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs23(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs24(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs25(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs26(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs27(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs28(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs29(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs30(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs31(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs32(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs33(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs34(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs35(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs36(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs37(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs38(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs39(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs40(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs41(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs42(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs43(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs44(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs45(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs46(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs47(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs48(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs49(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)

     
    #define joinargs50(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs51(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs52(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs53(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs54(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs55(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs56(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs57(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs58(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs59(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs60(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs61(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
    #define joinargs62(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs63(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs64(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs65(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs66(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs67(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs68(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
    #define joinargs69(arg1,...) arg1""_VFUNC(joinargs,nargs(__VA_ARGS__))(__VA_ARGS__)
     
     
       #define joinstrargs(...) VFUNC(joinargs,__VA_ARGS__)

    //math transform args   
    #define product(...) (opapply( * ,original,__VA_ARGS__))
    #define sum(...) (opapply( +  ,original,__VA_ARGS__))
    #define substracted(...) (opapply( - ,original,__VA_ARGS__))
    #define divided(...) (opapply( / ,original,__VA_ARGS__))

    //newargs is treated as single unit, but can be passed as multiple args #define many a,b,c
    //argreplace:replace argument @place with newargs
    #define argrep(newargs,place,...) revargs(rest(1,revargs(frontrest(place,__VA_ARGS__)))),newargs,rest(place,__VA_ARGS__)



    //swap arguments inside the arglist
    #define argswap(place1,place2,...) argrep(ntharg(place1,__VA_ARGS__),place2,argrep(ntharg(place2,__VA_ARGS__),place1,__VA_ARGS__))
    //swap3 arguments inside arglist
    #define argswap3(place1,place2,place3,...) argrep(ntharg(place3,__VA_ARGS__),place2,argrep(ntharg(place2,__VA_ARGS__),place1,argrep(ntharg(place1,__VA_ARGS__),place3,__VA_ARGS__)))
    //rotate arglist N places to left /right
    #define argrotl(leftp,...)    rest(leftp,__VA_ARGS__),frontrest(leftp,__VA_ARGS__)
    #define argrotr(rightp,...)            revargs(argrotl(rightp,revargs(__VA_ARGS__)))


    // macros to placing arg+varargs
    #define prefixarg(arg1,...) arg1,__VA_ARGS__
    #define suffixarg(arg1,...) __VA_ARGS__,arg1
    //delete arg at placeN , insert arg at placeN N
    #define argdel(place,...) revargs(rest(1,revargs(frontrest(place,__VA_ARGS__)))),rest(place,__VA_ARGS__)

    #define argins(arg,place,...) frontrest(place,__VA_ARGS__),arg,rest(place,__VA_ARGS__)


    //tuple macros: arglist objects enclosed in parens and processed as one entity



    #define detuple1(tuplex...)  detuple(tuplex)
    #define detuple0(tuplex...)   tuplex
    #define istuple(tupletest...)  reduce1arg(nargs(detuple(tupletest))) 
    #define safedetuple(possibletuple...) _VFUNC(detuple,istuple(possibletuple))(possibletuple)
    #define safedetuple2(possibletuple...) _VFUNC(detuple,istuple(possibletuple))(possibletuple)
    #define safedetuple3(possibletuple...) _VFUNC(detuple,istuple(possibletuple))(possibletuple)
    #define safedetuple4(possibletuple...) _VFUNC(detuple,istuple(possibletuple))(possibletuple)
    #define sdt  safedetuple
    #define sdt2  safedetuple2
    #define sdt3  safedetuple3
    #define sdt4 safedetuple4

    #define unwrap(args...) apply(sdt,args)

    //generate vars and their optional init vals
    #define defvar0() ;  
    #define defvar1(arg1) ntharg(1,sdt(arg1))  merge(antype,__COUNTER__)
    #define defvar2(arg1) ntharg(1, sdt(arg1)) ntharg(2, sdt(arg1)) 
    #define defvar3(arg1) ntharg(1, sdt(arg1)) ntharg(2, sdt(arg1)) = ntharg(3, sdt(arg1)) 
    //define C variables
    #define defvar(tuplevar) _VFUNC(defvar,nargs(sdt(tuplevar)))( tuplevar )
    #define defvars(tuples...) opapply(;,defvar,tuples)


    #define defun0() ;;
    //assume void prototype
    #define defun1(arg1) void ntharg(1,sdt(arg1))()
    //typed prototype
    #define defun2(arg1)  ntharg(1, sdt4(arg1)) ntharg(2, sdt4(arg1))()
    //typed prototype with arguments
    #define defun3(arg1)  ntharg(1, sdt4(arg1)) ntharg(2, sdt4(arg1))(sdt4(ntharg(3, sdt4(arg1))))
    //full function
    #define defun4(arg1)  ntharg(1, sdt4(arg1)) ntharg(2, sdt4(arg1))(sdt4(ntharg(3, sdt4(arg1)))) { opapply(;,sdt3, sdt2(ntharg(4, sdt4(arg1)))); }

     

    //define C function
    #define defun(tuplefunc)     _VFUNC(defun,nargs(sdt(tuplefunc)))( tuplefunc )
    #define defuns(tuplefuncs...) opapply(;,defun,tuplefuncs)


    #define equate(arg,rhs...) arg=rhs
    //#define varmap(tuples,vals)
    //compile-time tuple selector:tuple format (condition(0=false,1-64=true),tupletrue,tuplefalse)
    #define incriftuple0 1
    #define incriftuple1 2
    #define incriftuple(x) merge(incriftuple,x)
    #define iftuple(texpr3)  ntharg( incriftuple(reduce0arg(ntharg(1,sdt(texpr3)))) ,revargs(sdt(texpr3))) 
    //runtime tuple selector() 
    #define iftcond(texpr) sm (ntharg(1,sdt(texpr)))?   sdt2(ntharg(2,sdt(texpr))):sdt2(ntharg(3,sdt(texpr)))   em 





    //unwraps tuple structures(max 64 per level)
    #define eval(tuples...) sm opapply( ; ,sdt,tuples) em
    #define evalf(func,args...) eval(apply(func,args))
    #define evals(func,args...) eval(func(args))
    //inline eval(doesn't contain into ({})
    #define evalinl(tuples...) opapply( ; ,sdt,tuples)
    #define evalfinl(func,args...) evalinl(apply(func,args))
    #define evalsinl(func,args...) evalinl(func(args))
    #define lispevalinl(tuples...)  opapply(;,tapplyf,tuples) 


     
    #define tapplyfunc0(func) func
    #define tapplyfunc1(func,args...) func(args)
    #define tapplyfunc(args...) _VFUNC(tapplyfunc,reduce1arg(nargs(args)))(args)

    #define tapplyf(t) tapplyfunc(sdt(t)) 
    #define lispeval(tuples...) sm opapply(;,tapplyf,tuples) em
    //slice2tuple:convert arglist-slice into tuple and insert it back(as tuple entity at place of first slice arg)
    #define slice2tuple(start,num,...) wrap(frontrest(start,__VA_ARGS__)),(sliceargs(start,num,__VA_ARGS__)),rest(num,rest(start,__VA_ARGS__))

                       //tuplify arglist
    //convert arglist to 3 tuples(like slice2tuple,with both ends tuplified)
    //start/num are middle tuple extents
    #define tuplify3(start,num,...) (frontrest(start,__VA_ARGS__)),(sliceargs(start,num,__VA_ARGS__)),(rest(num,rest(start,__VA_ARGS__)))
    #define tuplify2(start,...) (frontrest(start,__VA_ARGS__)),(rest(start,__VA_ARGS__))
    #define tuplify1 tuple
    //transforms arglist into tuple2 containers
    // arg1,arg2,arg3,arg4,arg5 --> (arg1,arg2),(arg3,arg4),(arg5)
    #define list2tuples(...)  apply2(tuple,__VA_ARGS__)

    //get first/last args from tuple
    #define tuplefirst(x) sliceargs(0,1,detuple(x))
    #define tuplelast(x) sliceargs(0,1,revargs(detuple(x))) 
    //slice from tuple
    #define tupleslice(start,num,x)  sliceargs(start,num,detuple(x))
    //create arglist from slice inside tuple
    #define tupleslice2(extent,x)  sliceargs(tuplefirst(extent),tuplelast(extent),detuple(x))
    //get slice from tuple and save it as new tuple
    #define tupleslice2tuple(extent,x)  tuple(sliceargs(tuplefirst(extent),tuplelast(extent),detuple(x)))

    //extract from tuple arglist to normal arglist
    #define tuplefronts(...) apply(tuplefirst,__VA_ARGS__)
    #define tupleends(...) apply(tuplelast,__VA_ARGS__)
    #define tupleslices(start,num,...) varapply((start,num),tupleslice2,__VA_ARGS__)
    #define tupleslices2tuples(start,num,...) varapply((start,num),tupleslice2tuple,__VA_ARGS__) 




    //size(x) size of object
    //size(objects...)=get size in bytes of objects
    //clone(object)=return complete copy,
    //elems(arg) number of array/ptr elements
    //foreach(iter,arr) loop through array/ptr
    //freeall(...) free all arguments
    //resize(object,newlen) resize object. alias: trdata
    //cat(...) concantenate objects/strings(strings detected as null-terminated char array and adjusted accordingly)
    //fcat(...) same as above,and free all args




    //{==========SIZE====================

    #define size1(arg1) ({u8 lensize=sizeof(arg1);\
    once;\
    if((lensize!=sizeof(vp)))break;\
    if(isarray(arg1)|isbasic(arg1)){;break;};\
    lensize=msize((vp)(u8)arg1);endonce;\
    ;lensize;})

    #define size(...) sum(apply(size1,__VA_ARGS__))

    //{elements in array/ptr,clone(obj)
    #define elems(arg) (size(arg)/sizeof(arg[0]))
    #define clone(arg)  memcpy(malloc(size(arg)),arg,size(arg))





    //}
    //{=========Resize
    #define resize(obj,nlen) ({typeof(obj) newdata=(typeof(obj))calloc(nlen,1);\
    u8 s=size(obj);\
    if(nlen<s){memcpy(newdata,obj,nlen);}else{memcpy(newdata,obj,s);}free(obj);obj=newdata;obj;})
    //truncate data,don't use realloc.http://blog.kowalczyk.info/article/2be/realloc-on-Windows-vs-Linux.html

    //}

    //{=======Foreach

    #define foreach(iter,arr) for(u8 iter=0,elms_##iter=elems(arr);iter<elms_##iter;iter++)//}





    //}
    //{==========FREEALL=========

    #define freesafe(x) ({if(isptr(x)&& x!=(typeof(x))NULL)free(x);;})
    #define freeall(...) apply(freesafe,__VA_ARGS__)
    //}

    //{cat(...) concantenate objects/strings(strings detected as null-terminated char array and adjusted accordingly)

    #define cat1(arg1) arg1
    #define cat2(arg1,arg2) ({u8 arg1s=size(arg1);u8 arg2s=size(arg2);\
    u1 mode=(arg1[arg1s-1]==0 && arg2[arg2s-1]==0);\
    u1p res=malloc((arg1s-mode)+(arg2s-mode)+mode);memcpy(res,arg1,(arg1s-mode));memcpy(res+(arg1s-mode),arg2,(arg2s-mode));if(mode)res[(arg1s-mode)+(arg2s-mode)]=0;res;})


    #define cat3(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat4(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat5(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat6(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat7(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat8(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat9(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat10(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat11(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat12(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat13(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat14(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat15(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat16(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat17(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat18(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat19(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat20(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat21(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat22(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat23(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat24(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat25(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat26(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat27(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat28(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat29(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat30(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat31(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat32(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat33(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat34(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat35(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat36(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat37(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat38(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat39(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat40(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat41(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat42(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat43(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat44(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat45(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat46(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat47(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat48(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat49(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat50(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat51(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat52(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat53(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat54(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat55(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat56(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat57(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat58(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat59(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat60(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat61(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat62(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat63(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})
    #define cat64(arg1,...) ({u1p res1=_VFUNC(cat, nargs(__VA_ARGS__))(__VA_ARGS__);u1p res=cat2(arg1,res1);free(res1);res;})

    #define cat(...) VFUNC(cat, __VA_ARGS__)

    //free all arguments after cat
    #define fcat(...) ({u1p res=cat(__VA_ARGS__);freeall(__VA_ARGS__);res;})
    //}

    //cat text strings without space
    #define scat(args...) sm c1p buf=malloc(size(args));\
    sprintf(buf,joinstrargs(repargs(nargs(args),"%s")),args); buf em



    //cat text strings with space separator
    #define scat2(args...) sm c1p buf=malloc(size(args)+nargs(args));\
    sprintf(buf,joinstrargs(repargs(nargs(args),"%s ")),args); buf em

    //cat text strings with custom separator string
    #define scat3(sep,args...) sm c1p buf=malloc(size(args)+(nargs(args)*size(sep)));\
    sprintf(buf,joinstrargs(repargs(nargs(args),"%s"sep)),args); buf em



    //{=====Apply function to array/pointer========
     #define fill(A,val) ({foreach(i,A)A[i]=val;})
    #define clear(a) fill(a,0)
     
      //apply func to A
    #define apmap(A,func) ({foreach(i,A)func(A[i]);})
    #define apmap2(A,func,var) ({foreach(i,A)func(A[i],var);})

    //inplace map
    #define mapi(A,func) ({foreach(i,A)A[i]=func(A[i]);})
    #define map(A,func) ({typeof(A[0])* res=malloc(size(A));foreach(i,A)res[i]=func(A[i]);res;})

    // filter
    #define filter(A,func) ({typeof(A[0])* res=malloc(size(A));u8 k=0;foreach(i,A){if(func(A[i]))res[k++]=(A[i]);};resize(res,k*sizeof(res[k]));res;})
    //how many matches for func on array mambers
    #define matches(A,func) ({u8 res=0;foreach(i,A){res+=func(A[i]);};res;})
    //array has every/some member that satisifies func
    #define every(A,func) ({u8 res=1;foreach(i,A){if(!func(A[i])){res=0;break;};};res;})
    #define some(A,func)  ({u8 res=0;foreach(i,A){if(func(A[i])){res=1;break;};};res;})
    //first matchnindex or -1 if none
    #define findi(A,val)   ({s8 res=-1;foreach(i,A){if(val==(A[i])){res=i;break;};};res;})
    //find value that first satisfies function or -1 if none
    #define find(A,func)    ({s8 res=-1;foreach(i,A){if(func(A[i])){res=i;break;};};res!=-1?A[res]:-1;})
    //three member fold func 
    //fold/reduce calculate the value of array  by func(accummulator,index)
    #define fold(A,func,val) ({foreach(i,A)val=func(val,A[i]);val;})
    //foldr reverse array order   (cache-unfriendly)
    #define foldr(A,func,val) ({for(u8 i=elems(A)-1;i!=0;i--)val=func(val,A[i]);val=func(val,A[0]);val;})
     //examples: sum array and multiply array
    #define addfold(sum,x) (sum+x) //index-1ignored
    #define foldsum(A,initval) fold(A,addfold,initval)
    #define multfold(sum,x) (sum*x)
    #define foldmult(A,initval) fold(A,multfold,initval)
                                  
    //reverse array
    #define reverse(A) ({u8 s=elems(A)-1,e=s/2;for(u8 i=0;i<=e;i++)swap(A[i],A[s-i]);})

    #define reversx(A,elmx)  ({u8 s=elmx?elmx-1:0,e=s/2;for(u8 i=0;i<=e;i++)swap(A[i],A[s-i]);})

    #define reversxy(A,elmx,elmy)  ({u8 s=elmy-elmx,e=s/2;for(u8 i=0;i<=e;i++)swap(A[elmx+i],A[elmy-i]);})
    //shuffle array
    #define shuffle(A) ({u8 e=elems(A)-1;foreach(i,A){u8 r=range(0,e);swap(A[i],A[r]);}})
                                  
    //}


    //random.h:
    //rng8fastseed() ,hash(u8 x,u8 y),gethash(string) 
    //range(u8 start,u8 end),namegen(str,min,max)
    //rngfill(array) fill array with random numbers.
    //rngset(x) get random number of type of x
    //***** Random Number generator - xorshift128plus
    #define rng8fastseed x128init
    #define rng8() x128() //8 bytes
    #define rng4() ((u4)(rng8()&u4max))
    #define rng2() ((u2)(rng8()&u2max))
    #define rng1() ((u1)(rng8()&u1max))
    //x128xorshiftplus generator
    u8 x128val0=0x87654321,x128val1=0x12345678,x128s1,x128s0;

    #define rndbit() (tsc()&1)
    #define x128() ({x128s1=x128val0; x128s0=x128val1;\
    x128val0=x128s0; x128s1^=(x128s1 << 23);\
    x128val1=(x128s1 ^ x128s0 ^ ( x128s1 >> 17 ) ^ ( x128s0 >> 26 ) );\
    x128val1 + x128s0;})

    #define x128init() x128val1=tsc()*(~(tsc()));x128val0=(tsc()*tsc());x128();x128();x128();
    //using xorshift128plus as hash(fast)
    #define hash(x,y) ({ u8 hash128val0=y,hash128val1=y,hash128s1=x,hash128s0=y;\
    hash128s1^=(hash128s1 << 23);hash128val1=(hash128s1 ^ hash128s0 ^ ( hash128s1 >> 17 ) ^ ( hash128s0 >> 26 ) );\
    hash128val1 + hash128s0;})
    //generate string hash(sequence of bytes->repeated hash of values)
    #define gethash(str) ({u8p qhash=(u8p)str;u8 s=size(str),qhashs=s/sizeof(u8);u8 tmp=~s,i;\
    for(i=0;i<qhashs;i++)tmp^=hash(tmp,~qhash[i])*hash(qhash[i],~tmp);\
    for(i=qhashs*sizeof(u8);i<s;i++)tmp^=hash(tmp,~((u8)str[i]))*hash(((u8)str[i]),~tmp);\
    ;tmp;})
          //2 variable hash
    #define gethash2(num,str) ({u8p qhash=(u8p)str;u8 s=size(str),qhashs=s/sizeof(u8);u8 tmp=num,i;\
    for(i=0;i<qhashs;i++)tmp^=hash(tmp,~qhash[i])*hash(qhash[i],~tmp);\
    for(i=qhashs*sizeof(u8);i<s;i++)tmp^=hash(tmp,~((u8)str[i]))*hash(((u8)str[i]),~tmp);\
    ;tmp;})

    //1 /long longmax multiplier = 0.
    #define RNG_LL_MULT1 (1.0l/((f10)(u8max)))
    //random float -long double range 0.0 - 1.0
    #define rngzeroone()  (f10)(((f10)rndtypeu8())*RNG_LL_MULT1)
    #define rngf10 rndtypef10 
    #define rngf8 rndtypef8
    #define rngf4 rndtypef4
    #define rngu8 rndtypeu8
    #define rngs8 rndtypes8
    #define rngu4 rndtypeu4
    #define rngs4 rndtypes4
    #define rngu2 rndtypeu2
    #define rngs2 rndtypes2
    #define rngu1 rndtypeu1
    #define rngs1 rndtypes1
    #define rngc1 rndtypeu1
    #define rngc4 rndtypes4
    #define rnguc4 rndtypeu4








    //result start=< range >=start+end
    #define range(start,end) ((rng8()%(end-start))+start)



    u1 rndtypeu1(){re (u1)rng8();}
    u2 rndtypeu2(){re (u2)rng8();}
    u4 rndtypeu4(){re (u4)rng8();}
    u8 rndtypeu8(){re rng8();}

    s1 rndtypes1(){u1 x=rndtypeu1();
    s1p c=(s1p)&x; re *c;}
    s2 rndtypes2(){u2 x=rndtypeu2();
    s2p c=(s2p)&x; re *c;}
    s4 rndtypes4(){u4 x=rndtypeu4();
    s4p c=(s4p)&x; re *c;}
    s8 rndtypes8(){u8 x=rndtypeu8();
    s8p c=(s8p)&x; re *c;}


    //1 0 > 2 0 > 1 -1


    f10 rndtypef10(){u2 z[sizeof(f10)/2];f10p r=(f10p)&z;do{
    for(u8 i=0;i<(sizeof(f10)/2);i++)z[i]=rndtypeu2();
     }while(!isfinite(*r)) ;;;
    re *r;}


    f8 rndtypef8(){u2 z[sizeof(f8)/2];f8p r=(f8p)&z;do{
    for(u8 i=0;i<(sizeof(f8)/2);i++)z[i]=rndtypeu2();
     }while(!isfinite(*r)) ;;;
    re *r;}
    f4 rndtypef4(){u2 z[sizeof(f4)/2];f4p r=(f4p)&z;do{
    for(u8 i=0;i<(sizeof(f4)/2);i++)z[i]=rndtypeu2();
     }while(!isfinite(*r)) ;;;
    re *r;}





    #define rndtype(x) rndtype##x
    #define rngset(x) x=basictypeselect(x,rndtype)() 
    #define rngfill1(arr) ({foreach(i,arr)arr[i]=rngset(arr[0]);;0;})
    #define rngfill(...) sm opapply(;,rngfill1,__VA_ARGS__) em
    //random set generic




    //create a unique name(null-terminated)from random bytes in sourcestring
    //frequency of bytes in srcstr ==frequncy of bytes in result
    #define namegen(srcstr,minbytes,maxbytes) ({u8 namelen=range(minbytes,maxbytes);\
    u8 s=size(srcstr);c1* res=malloc(namelen+1);foreach(i,res)res[i]=srcstr[range(0,s-1)];res[namelen]=0;res;})

    /* textio.h text functions
    p0() = print newline
    newline   = print newline
    p(...) = print arguments 
    fp(fileptr,...)= prints arguments into FILE*
    hex(...) =as above in hex
    fhex(...) =as above in hex into FILE*
    bin(...) =as above in binary
    fbin(...) =as above in binary into FILE*
    binsp(...) =as above with symbols "#":" "
     hexs(arr) print array elements as hex(...)
     decs(arr) print array elements as p(...)
     bins(arr) print array elements as bin(...) 
     binsps(arr) print array elements as binsp(...)
     prstruct(structname,fields...) prints structure info and  each field content and its offset from struct base
     dpr(...) prints arguments+last error name and its location if DEBUG defined
     quit(...) = prints arguments+last error name and its location+exit program
     scan(x) scan 1 variable via scanf
     sc(...) scan N variables
    */


    //p(varargs); print(calls (n) functions(arg[n]))
    #define p0() fputs("\n",stdout)
    #define newline ;p0();//



     //{printtype selector p+typename+spacing: u1->pu1->"%.3"PRIu8" "->"%.3""u"" "-> "%.3u "

    #define printprefix(x) p##x
    #define ptype(x) proxy(typeselect)(x,printprefix)
    #define printval(arg1) sm pr(ptype(arg1),arg1) ;"" em
    #define fprintval(fileptr,arg1) sm fpr(fileptr, ptype(arg1),arg1);"" em


    #define fp(fileptr,...) varapply(fileptr,fprintval,__VA_ARGS__)
    #define p(args...) apply(printval,args)
    //}



    //{ hex(...) print arguments as hex strings/values

    //#define hextypex(z) z:p##z##h
    #define hexprinttype(x) p##x##h
    #define htype(x) proxy(typeselect)(x,hexprinttype)
    #define fprinthex(fileptr,arg1) fpr(fileptr,htype(arg1),arg1)
    #define printhex(arg1) pr(htype(arg1),arg1)
    #define hex(...) apply(printhex,__VA_ARGS__)
    #define fhex(...) varapply(fileptr,fprinthex,__VA_ARGS__)

    //}


    //{print len bytes as bits:example:u4 x; bin(x,2) print 2 bytes from x



    //faster reduces printf delays
    static const u1 bittable[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};



    //file fprintbins
    void fprintbinu1(u1 b,FILE* file){fpr(file,"%s%s",bittable[(b>>4)&0xf],bittable[(b)&0xf]);} 

    void fprintbinu2(u2 b,FILE* file){fpr(file,"%s%s%s%s",bittable[(b>>12)&0xf],bittable[(b>>8)&0xf],bittable[(b>>4)&0xf],bittable[(b)&0xf]);} 

    void fprintbinu4(u4 b,FILE* file){fpr(file,"%s%s%s%s%s%s%s%s",bittable[(b>>28)&0xf],bittable[(b>>24)&0xf],bittable[(b>>20)&0xf],bittable[(b>>16)&0xf],bittable[(b>>12)&0xf],bittable[(b>>8)&0xf],bittable[(b>>4)&0xf],bittable[(b)&0xf]);}

    void fprintbinu8(u8 b,FILE* file){fpr(file,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",bittable[(b>>60)&0xf],bittable[(b>>56)&0xf],bittable[(b>>52)&0xf],bittable[(b>>48)&0xf],bittable[(b>>44)&0xf],bittable[(b>>40)&0xf],bittable[(b>>36)&0xf],bittable[(b>>32)&0xf],bittable[(b>>28)&0xf],bittable[(b>>24)&0xf],bittable[(b>>20)&0xf],bittable[(b>>16)&0xf],bittable[(b>>12)&0xf],bittable[(b>>8)&0xf],bittable[(b>>4)&0xf],bittable[(b)&0xf]);}



    void fprintbins8(s8 b,FILE* file){fprintbinu8((u8)b, file);}
    void fprintbins4(s4 b,FILE* file){fprintbinu4((u4)b, file);}
    void fprintbins2(s2 b,FILE* file){fprintbinu2((u2)b, file);}
    void fprintbins1(s1 b,FILE* file){fprintbinu1((u1)b, file);}
    void fprintbinc4(c4 b,FILE* file){fprintbinu4((u4)b, file);}
    void fprintbinc1(c1 b,FILE* file){fprintbinu1((u1)b, file);}

    void fprintbinc1p(c1p b,FILE* file){
    fputs(b,file);}
    void fprintbinu1p(u1p b,FILE* file){

    fprintbinu8((u8)b, file);}
    void fprintbins1p(c1p b,FILE* file){
    fputs(b,file);}
    void fprintbinu2p(c1p b,FILE* file){
    }
    void fprintbinu4p(c1p b,FILE* file){
    }
    void fprintbinu8p(c1p b,FILE* file){
    }
    void fprintbins2p(c1p b,FILE* file){
    }             
     void fprintbins4p(c1p b,FILE* file){
    }
    void fprintbins8p(c1p b,FILE* file){
    }
    void fprintbinf4p(c1p b,FILE* file){
    }
    void fprintbinf8p(c1p b,FILE* file){
    }
    void fprintbinf10p(c1p b,FILE* file){
    }









    void fprintbinuc4(uc4 b,FILE* file){fprintbinu4((u4)b, file);}

    void fprintbinf4(f4 b,FILE* file){f4 t=b;u4p z=(u4p)&t;  fprintbinu4(*z,file);}
    void fprintbinf8(f8 b,FILE* file){f8 t=b;u8p z=(u8p)&t;  fprintbinu8(*z,file);}
    void fprintbinf10(f10 b,FILE* file){f10 t=b;
    u8p z=(u8p)&t;u2p z2=(u2p)(&t+8);  fprintbinu8(*z,file); fprintbinu2(*z2,file);}
    void fprintbinvp(vp b,FILE* file){fprintbinu8((u8)b, file);}




    #define bit4r(x) bittable[(x)&0xf]
    #define fbinbyte(b,file) sm fputs(bit4r(b>>4),file);fputs(bit4r(b),file);em

    #define fbtype(x) fprintbin##x

    #define fbin2(file,x) ({u1p y=(u1p)ptrto(x);for(s4 i=(sizeof(x))-1;i>-1;i--)fbinbyte(y[i],file); })
    // fpr(file,strblen(x),strbin(x))
    #define fbin1(x,file) typeselect(x,fbtype)(x,file)
    #define bin1(x) typeselect(x,fbtype)(x,stdout)

    #define fbin(file,args...) varapply(file,fbin1,args)
    #define bin(args...) apply(bin1,args)


     //}
          //{Array print,hex,binary output
    #define hexs(arr) apmap(arr,hex)
    #define decs(arr) apmap(arr,p)
    #define bins(arr) apmap(arr,bin)

    #define fhexs(arr,file) apmap2(arr,fhex,file)
    #define fdecs(arr,file) apmap2(arr,fp,file)
    #define fbins(arr,file) apmap2(arr,fbin,file)
    //}
    //{print struct prstruct(structurename,...fieldnames)


    #define prstruct1(xstruct__,fieldval) sm   ;p(wrap(crlf,#fieldval,":",(xstruct__ . fieldval)," offset:",offsetof(typeof(xstruct__),fieldval))); em    
    #define prstruct(arg1,...)  p(crlf,"struct:",#arg1," size:",sizeof(typeof(arg1)),"bytes  aligned to:",__alignof__(arg1),"bytes");varapply(arg1,prstruct1,__VA_ARGS__) ;



    //}

    #define scantypestr(x) merge(s,x)
    #define scantype(x) typeselect(x,scantypestr)
    #define scanref(x) (gn((x),u1:&x,u2:&x,u4:&x,u8:&x,s1:&x,s2:&x,s4:&x,s8:&x,c1:&x,c4:&x,uc4:&x,f4:&x,f8:&x,f10:&x,default:x))




    #define scan(x) scanf(scantype(x),scanref(x)) 
    #define sc(inputs...) apply(scan,inputs)


    #ifdef DEBUG
    #ifdef VERBOSE

    #define dpr(...) ({perror("\nFILE:"__FILE__" LINE:"tostring(__LINE__)"::");\p("\n",__VA_ARGS__);})
    #define quit(...) ({perror("\nFILE:"__FILE__" LINE:"tostring(__LINE__)"::");p(crlf,__VA_ARGS__);exit(EXIT_FAILURE);})
    #else
    #define dpr(...) ({p("\n",__VA_ARGS__);})
    #define quit(...) ({p(crlf,__VA_ARGS__);exit(EXIT_FAILURE);})

    #endif
    #else
    #define dpr(...) ;;
    #define quit(...) ({;p(crlf,__VA_ARGS__);exit(EXIT_FAILURE);})
    #endif


    #define bitsin(x) (sizeof(x)<<3)
    #define bitpow1(x) (1ULL<<(x))
    #define bitpow2(x) (2ULL<<(x))

    //bitrange slice 
    //0-7=&0xff 8-15=           76543210 (x>>8)&(pow1(15-8=7)=1<<7=0b11111111)
    #define bitrange(x,start,end) (((x)>>start)&bitpow1(end-start))

    inline uint32_t rotl4 ( uint32_t x, uint8_t r ) { return (x << r) | (x >> (32 - r)); }
    inline uint64_t rotl8 ( uint64_t x, uint8_t r ) { return (x << r) | (x >> (64 - r)); }
    inline uint32_t rotr4 ( uint32_t x, uint8_t r ) { return (x >> r) | (x << (32 - r)); }
    inline uint64_t rotr8 ( uint64_t x, uint8_t r ) { return (x >> r) | (x << (64 - r)); }


    inline uint8_t rotl1 ( uint8_t x, uint8_t r ) { return (x << r) | (x >> (8 - r)); }
    inline uint16_t rotl2 ( uint16_t x, uint8_t r ) { return (x << r) | (x >> (16 - r)); }
    inline uint8_t rotr1 ( uint8_t x, uint8_t r ) { return (x >> r) | (x << (8 - r)); }
    inline uint16_t rotr2 ( uint16_t x, uint8_t r ) { return (x >> r) | (x << (16 - r)); }


    #define lxor(x,bits) (x^(x>>bits))
    #define rxor(x,bits) (x^(x<<bits))

    #define lrot(x,bits) (gn((x),u8:rotl8,u4:rotl4,u2:rotl2,u1:rotl1))(x,bits)
    #define rrot(x,bits) (gn((x),u8:rotr8,u4:rotr4,u2:rotr2,u1:rotr1))(x,bits)
    //swap bytes 1234=2143     host-to-network-int
    #define bswap(x) (gn((x),u8:__builtin_bswap64,u2: __builtin_bswap16 ,u4:__builtin_bswap32,s8:__builtin_bswap64,s4:__builtin_bswap32,s2:__builtin_bswap16 )(x))

     

    //set,clear,toggle,check bit of integer
    // www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/
    #define setb(o,pos) (o|=(1<<(pos))) //byte| 1<< pos
    #define clrb(o,pos) (o&=(~(1<<(pos)))) // byte | 11101111
    #define togb(o,pos) (o^=(1<<(pos)))
    #define chkb(o,pos) (((o)>>(pos))&1)
    //merge bit
    #define mbit(x,bit,pos) ({clrb(x,pos);x|=(bit<<pos);})
    //Turnoff rightmost bit
    #define offlast1(x) (x&(x-1))
    #define onlast0(x) (x|(x+1))
    #define last1(x) (x&(-x))
    #define last0(x) ((~x)&(x+1))
    #define signof(x) (x>>((sizeof(x)*8)-1)) //-1/0
    #define even(x) ((x&1)==0)
    #define odd(x) (x&1)

    //is power of 2
    #define is2pow(x) (x&&(!(x & (x - 1))))
    //Conditionally set or clear bits without branching
    #define scbits(x,bitmask,cond) (x&(~bitmask))|((-cond)&bitmask)
    //Conditional negation(if flag is true/1)
    #define condneg(x,flag) ((x^(-flag))+flag)
    //merge bits from x,y from bitmask:1=ybit,0=xbit
    #define mergebits(x,y,bitmask) (x^((x^y)&mask))
    #define haszero(v) (((v) - ((~((u8)0))/255)) & (~(v)) & ((u8)0x8080808080808080ULL))
    #define hasvalue(x,n) (haszero((x) ^ (((~((u8)0))/255) * (n))))

    //popcount,# of leading zeroes,# of trailing zeroes

    #define pcnt(x) (gn((x),u8:__builtin_popcountll,u4:__builtin_popcountl,default:__builtin_popcount))(x)
    #define clz(x) (gn((x),u8:__builtin_clzll,u4:__builtin_clzl,default:__builtin_clz))(x)
    #define ctz(x) (gn((x),u8:__builtin_ctzll,u4:__builtin_ctzl,default:__builtin_ctz))(x)
    //Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
    #define ffs(x) (gn((x),s8:__builtin_ffsll,s4:__builtin_ffsl,default:__builtin_ffs))(x)
    //Returns the number of leading redundant sign bits in x, i.e. the number of bits following the most significant bit that are identical to it
    #define clrsb(x) (gn((x),s8:__builtin_clrsbll,s4:__builtin_clrsbl,default:__builtin_clrsb))(x)

    //delta transition count
    #define bittrans(x) pcnt((x^(x>>1)))



    //cmp 3way select,memdiff(a,b) find byte that differs first

    //max maximum value integer/float
    //min minimum value integer/float
    //abs absolute value integer/float
    #ifdef abs
    #undef abs
    #endif
    #define abs(x) (x<0?-x:x)


    //inline functions(asm)
    #define absinl(x) (gn((x),f4:fabsf,f8:fabs,f10:fabsl,s8:llabs,s4:labs,s2:abs,s1:abs,u8:llabs,u4:labs,u2:abs,u1:abs,c1:abs))(x)

    //absmacro: no inline functions
    #define absm(x) gn((x),s1:absi((s1)x),s2:absi((s2)x),s4:absi((s4)x),s8:absi((s8)x),u1:x,u2:x,u4:x,u8:x,f10:absf10((f10)x),f8:absf8((f8)x),f4:absf4((f4)x),c4:absi((c4)x),uc4:x,c1:x)



    //www-graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
    #define absi(v)   ((v + (v >> ((sizeof(v) * CHAR_BIT) - 1))) ^ (v >> ((sizeof(v) * CHAR_BIT) - 1))) 
    #define absf10(s)  sm auto x=s; *((u1p)(((u8)(&x))+9))&=0b01111111;x em
    #define absf8(s)  sm auto x=s; *((u1p)(((u8)(&x))+7))&=0b01111111;x em
    #define absf4(s)  sm auto x=s;u1p k=((u1p)(((u8)(&x))+3));*k&=0b01111111;x em





    //memdiff(block1,block2)return loc of byte that differs,
    //return -1 if a[0]!=b[0] or size not equal
    //return 0 if no bytes differ
    #define mdiff(A,B) ({s8 res=0;u8 sza=size(A),szb=size(B);if(sza!=szb){res=-1;sza=0;szb=0;}\
    for(u8 i=0,minsz=min(sza,szb);i<minsz;i++){if(A[i]!=B[i]){res=i;break;}};res;})



    //(x<y)=-1 x>y=1 x==y =0 s
    #define cmp(x,y) ((x>y)-(x<y))
    #ifdef max
    #undef max
    #endif
    #ifdef min
    #undef min
    #endif
    #define max2(x,y) ({auto a=(x);auto b=(y);a>b?a:b;}) //
    #define min2(x,y) ({auto a=(x);auto b=(y);a<b?a:b;})
    //slower:
    #define maxswap2(x,y) sm typeof(x) a[2]={x,y};a[x<y] em
    #define minswap2(x,y) sm typeof(x) a[2]={x,y};a[x>y] em

    #define min(...) reapply(min2,__VA_ARGS__)
    #define max(...) reapply(max2,__VA_ARGS__)



    #define cmpp(x,y) ((cmp(x,y)+1)>>1)
         //memcmp 1 if first inqueal char is gt,-1 if less,0 if bot string  match to len of shortest string
    #define mcmp(A,B) ({s8 res=0;u8 sza=size(A),szb=size(B);\
    for(u8 i=0,minsz=min(sza,szb);i<minsz;i++){if(A[i]!=B[i]){res=cmp(A[i],B[i]);break;}};res;})
        //char test     ctypes.h replacement
    #define isdigit(c) ((c>='0')&(c<='9'))
    #define isupper(c) ((c>='A')&(c<='Z')) 
    #define islower(c) ((c>='a')&(c<='z')) 
    #define isalpha(c) (isupper(c)|islower(c))
    #define isalnum(c) (isalpha(c)|isdigit(c))
    #define isspace(c)  ((c==' ')|((c>=0x9)&(c<=0xd))) 
    #define iscr(c) (c=='\n')
    #define isblank(c) ((c==' ')|(c=='\t'))
    #define isprint(c)   ((c>= ' ')&(c<='~')) 
     #define isgraph(c)  ((c>= '!')&(c<='~'))      
     
     
    //quick test if adding a+b is overflow
    //if (a/2+b/2) > intmax(~0)/2
    #define isovadd(a,b) (( (a>>1)+(b>>1))>((~(typeof(a))0)>>1))
    //if number of leading bitzeros < bitwidth:probable overflow
    #define isovmul(a,b) ((__builtin_clz(a)+__builtin_clz(b))<(sizeof(a)<<3))


    //fileio.h:filesize(filename),u1* filecontent(filename)
    //write2file(buf,filename),getfilechunk(filename,startloc,len)
    #define fr(fileptr,bytes,dst) fread(dst,1,bytes,fileptr)
    #define fw(fileptr,bytes,src) fwrite(src,1,bytes,fileptr)


    #define filesize(filename) ({u8 res=0;\
    FILE* input=fopen(filename,"rb");\
    once if(!input){dpr("Filesize: Failed to open file:",filename);break;;}\
    if(fseek(input,0,SEEK_END)){fclose(input);dpr("Filesize:Fseek failure");break;; }\
    res=ftell(input);fclose(input);endonce\
    ;res;})





    #define filecontent(filename) ({u1* buf=NULL;\
    u8 insize=filesize(filename);once if(!insize){dpr("Filecontent:",filename," is 0 bytes or unavailable");break;;}\
    FILE* input=fopen(filename,"rb");if(!input){dpr("Filecontent:",filename," cannot be opened for reading");break;;}\
    buf=malloc(insize);\
    if(!buf){fclose(input);dpr("Filecontent:failed to malloc ",insize,"bytes for file",filename);break;}\
    u8 res=fr(input,insize,buf); fclose(input);\
    if(res!=insize){free(buf);dpr("Filecontent:file read mismatch: read ",res," bytes while ",insize,"bytes are available for reading");;buf=NULL;break;}\
    endonce;buf;})





    #define write2file(buf,filename) ({u8 writesize=0;\
    FILE* output=fopen(filename,"wb"); \
    once if(!output){dpr("write2file:cannot open",filename," for writing");break; } \
    u8 outsize=size(buf); \
    writesize=fw(output,outsize,buf); fclose(output); \
    if(outsize!=writesize){dpr("write2file:size mismatch",writesize,"bytes written while ",outsize," available for writing");writesize=0;break;} \
    endonce; writesize;})




    #define getfilechunk(filename,startloc,len) ({u1* res=NULL; FILE* input=fopen(filename,"rb");\
    once if(!input){dpr("Getfilechuck:failed to open :",filename," for reading");break;} res=malloc(len); if(!res){dpr("Getfilechunk: failed to malloc ",len," bytes for writing");;fclose(input);break;}; fseek(input,startloc,SEEK_SET);u8 readsize=fr(input,len,res);fclose(input); if(readsize!=len){free(res);res=NULL;break;} ; endonce;res;})



    //avg(arr) average of all values ;;serial(arr)serial correlation;;ent(arr) entropy(bytes)
    #define avg(arr) ({u8 s=elems(arr);f10 sum=0.0L;for(u8 i=0;i<s;i++){sum+=arr[i];};sum/((f10)s);})
    //serial correlation www.fourmilab.ch/random/ u1-u8
    #define serial(str) ({u8 s=elems(str);f10 scc=0.0L,sccun=0.0L,sccu0=0.0L,scclast=0.0L,scct1=0.0L,scct2=0.0L,scct3=0.0L;\
    ;u8 i=0;sccun=(f10)(str[0]);sccu0=sccun; scct2+=sccun;scct3+=sccun*sccun;scclast=sccun;\
    for(i=1;i<s;i++){ sccun=(f10)(str[i]); scct1+=scclast*sccun;; scct2+=sccun; scct3+=sccun*sccun;\
    scclast=sccun;}; scct1+=scclast*sccu0; scct2*=scct2; scc=((f10)s)*scct3-scct2;\
    if(scc==0.0L){scc=1.0L;}else{ scc=((((f10)s) * scct1) - scct2) / scc;\
    }; fabsl(scc);})

    #define ent(arr) ({u8 s=size(arr),i;\
    u1* prob=(u1*)&arr[0];f10 entropy=0.0L,d=1.0L/((f10)s);\
    f10 t;u8 ef[256]={0};;for(i=0;i<s;i++){;ef[prob[i]]++;;};\
    for(i=0;i<256;i++){if(!ef[i])continue;;t=ef[i]*d;;entropy-=log2l(t)*t;};\
    fabsl(entropy);})

    //minimum and maximum of array
    #define maxarr(arr) ({auto m=arr[0];u8 s=elems(arr);\
    for(u8 i=1;i<s;i++)m=max(arr[i],m);;;m;})
    #define minarr(arr) ({auto m=arr[0];u8 s=elems(arr);\
    for(u8 i=1;i<s;i++)m=min(arr[i],m);;;m;})




    // sequences:alnum,printable,punct(nonalnum printable)

    /*apply function to determine sequence boundary  count with xor: new^old sequence*/
    //count transitions in sequences:seqcond
    #define seq(A,seqcond) ({u8 tcount=0;\
    u8 state=0,old=1;foreach(i,A){state=seqcond(A[i]);tcount+=old^state;old=state;}\
    tcount>>=1;tcount;})
    #define cwords(A)   seq(A,isalnum)
    #define clines(A)   seq(A,iscr)
    #define cnonspace(A) seq(A,isgraph)


    //crypteria 8

    #define passxor(A,pass) ({u8 pwlen=size(pass);u8 chash=gethash(pass);foreach(i,A){A[i]^=(((pass[(i*pass[(i>>(1+(i&1)))%pwlen])%pwlen])*(chash^i)*hash(pwlen,i)*hash(pass[(i)%pwlen],i)*(~(i*3))^(9*~pwlen))&0xff);}})
    #define passdexor passxor

    #define xorarr(x,y) ({foreach(iter,x)x[iter]^=y[iter];})
    #define encformula(passx,i,pw,d) ({hash(passx,~i)^hash(i,d)^hash(d,~i)^hash(pw,~d)^hash(~i,~pw)^hash(pw,~passx)^hash(~passx,(pw^(~d)));})

    /*crypteria 7.2 outline
    1.create x8 bits of input and fill them with random data(xorshift128+ xored with another run of itself(which is randomized again(to erase the xor src content) and freed)
    2.for each bit of input:
    2.1.determine insertion point(gap 1 to 7 bits) by adding distance in bits to last insertion point. uses encformula to semi-randomly alter distance
    2.2.clear bit at insertion point and xor with target
    3.xor input with password with passxor()
    reverse steps to get input from encrypted data

    */

    #define encrypt(src,pass) ({u1p a=(u1p)src;u8 s=size(src),bitsize=s*8;\
    u8 bit=0,i=0,c=0,d=0,pwshift=0,srcbit=0,sp=size(pass);\
    ;u1p encdata=malloc(bitsize);rngfill(encdata);\
    u1p encdata2=malloc(bitsize);rng8fastseed();rngfill(encdata2);\
    xorarr(encdata,encdata2);rngfill(encdata2);free(encdata2);\
    for(i=0;i<bitsize;i++,pwshift+=hash((i*d),(~d))){srcbit=(a[i>>3]>>((i&7)))&1;\
    d++;d+=(encformula(pass[(i^d)%sp],i,pwshift,d))&7;;\
    mbit(encdata[d>>3],srcbit,d&7);;\
    };resize(encdata,(d>>3)+1);\
    passxor(encdata,pass);encdata;})

    #define decrypt(src,pass)({u1p a=(u1p)src;u8 s=size(src),bitsize=s*8;\
    u8 bit=0,i=0,c=0,d=0,pwshift=0,srcbit=0,sp=size(pass);\
    ;passdexor(a,pass);u1p decdata=calloc(s,1);\
    for(d=0;d<bitsize;pwshift+=hash((i*d),(~d))){d++;d+=(encformula(pass[(i^d)%sp],i,pwshift,d))&7;;\
    srcbit=(a[d>>3]>>((d&7)))&1;;\
    decdata[i>>3]|=srcbit<<(i&7);;\
    ;i++;\
    };resize(decdata,(i>>3));\
    ;decdata;})


     
    #define pause() ({p(crlf,"Press any key to continue:");getch();})



    #ifdef  WIN32
    #define textcolor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)
    #define gotoxy(x, y) ({COORD c={x,y}; SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE),c)       ; })
    #else   
    //untested:     assume ansi term
    #define textcolor(x) pr("\033[%dm",x)
    #define gotoxy(x,y) pr("\033[%d;%dH",y,x)

    #endif
     
    //Bitmap .bmp 32-bit pixel
    #pragma pack(push,1) 
    ts  {u2 magic ;	u4 filesize ;  u2 reserved1,  reserved2 ;u4 offset,headersize,width, height ;    u2 planes , bits ;
        u4 compression, imagesize, hpixelsmeter, vpixelsmeter , colors , colorsrequired ;u2 gap;}  BMPheader;
     
    #pragma pack(pop)
     
         
        
    #define bitmap32(name,w,h) BMPheader name={.magic='MB',\
        .offset=(56),\
         .width=(w),\
        .height=(h), \
        .imagesize=(w*h*4),\
        .filesize=(56+w*h*4),\
        .headersize=(40),\
        .planes=(1),\
        .bits=(32),\
        .compression=(0),.hpixelsmeter=(2835),.vpixelsmeter=(2835),\
        .colors=(0),\
        .colorsrequired=(0)};    



    #define prbitmapheader(x)  prstruct(x,magic,filesize,reserved1,reserved2,offset,headersize,width,height,planes,bits,compression,imagesize,hpixelsmeter,vpixelsmeter,colors,colorsrequired)     




    //Object macros
    //create structure from arguments
    #define structfield(x) typeof(x) merge(field,__COUNTER__)
    #define structure(name,...) struct{u8 fieldend;u8 numfields;opapply(;,structfield,__VA_ARGS__);}name={__COUNTER__,nargs(__VA_ARGS__),__VA_ARGS__};

           //associative array
    //usage assoca(name,tuple_list)
    /*
    assoca(blarg,(1,"a"),(2,"z"),(3,"c"));
    p(blarg.indexes[2],blarg.values[2]);
    */
    //merge 2 tuples members into tuple2 list

    #define assoca(name,...) struct{typeof(tuplefirst(front1(__VA_ARGS__))) indexes[nargs(__VA_ARGS__)];typeof(tuplelast(front1(__VA_ARGS__)))  values[nargs(__VA_ARGS__)];  }name={.indexes={tuplefronts(__VA_ARGS__)},.values={tupleends(__VA_ARGS__)}}



    //float pow int
    #define fpowi(x,y)  gn((x),f4: __builtin_powif,f8: __builtin_powi,f10:__builtin_powil )(y)


    //requires GMP
    //create integer
    #define mpz(x)  mpz_t x;mpz_init(x); 
    #define mpzall(args...) opapply(;,mpz,args)
    //get mpz from pointer(data)
    #define p2mpz(ptr,num) ({mpz_import(num, size(ptr),1, 1, 0,0,ptr);})
    //return raw ptr of data in mpz
    #define mpzraw(num) mpz_export(NULL, NULL , 1,1, 0,0,num)
    //invert all bits ~num and store to res
    #define mpzneg(res,num) mpz_com(res,num)
    //set x to y content
    #define mpzs(x,y) mpz_set(x,y);
    //delete int
    #define mpzd(x) mpz_clear(x)
    #define mpzp(x) mpz_popcount(x)
    #define mpzx(res,x,y) mpz_xor(res, x,y)
    //shift X right,store result
    #define shr(result,x,bits) mpz_tdiv_q_2exp(result, x, bits)

    //========Project Euler macros
    #define divischeck0(num,divarr) ({auto rnum=0;foreach(k,divarr){\
    if(!(num%(divarr[k]))){rnum=num;break;}};rnum;})
    #define sumofdivisibles(start,end,divisibles...) ({u8 res=0;u8 divs[nargs(divisibles)]={divisibles};;\
    for(u8 i=start;i<end;i++)res+=divischeck0(i,divs);;;res;})


    #define sumdivfibs(maxfibval,divisor)  ({u8 res=0;for(u8 i=1,k=2,sum=3;i<maxfibval;i=k,k=sum,sum=i+k){;res+=(i%divisor)?0:i;};res;})

    //0 if not prime
    //limit is 3<>z/n or ~sqrt(z)
    #define primefactor(z) sm u8 n=0,lim;once if(z<3)br;if((z&1)==0){n=2;br;};\
    for( n=3,lim=((u8)sqrt((f10)z))+1;n<lim;n+=2){ if((z%n)==0){br;}} endonce; n<lim?n:(n==2?2:0); em

    #define primefactors(z) sm u8 n=1,k=primefactor(z);\
    p("Number:",z,"is",k?"not-prime":"prime");\
    while(k){p("\nFactor",n++,":",k);z/=k;\
    k=primefactor(z);}p("\nFactor",n++,":",z);em








    //sorting macros
    //      string sort(via strcmp)

    #define strcombsort(A)  ({u8 i,j, tmp, gap=elems(A),len=gap;\
    while (gap>1){gap = gap<10 ? gap-1 : (gap*7)/9+1;\
    for (i=0,j=gap; j<len; i++,j++){tmp=mcmp(A[i],A[j])>0;condswap(A[i],A[j],tmp);}}})


        //fast sort for small arrays(inplace) no malloc
    #define combsort(A) ({u8 i,j, tmp, gap=elems(A),len=gap;\
    while (gap>1){gap = gap<10 ? gap-1 : (gap*7)/9+1;\
    for (i=0,j=gap; j<len; i++,j++){tmp=A[i]>A[j];condswap(A[i],A[j],tmp);}}})


    //multiple sort benchmarks 


     //allowed radixes:u1,u2,u4,u8,s1,s2,s4,s8,c1,c4,uc4,f4,f8,f10
    v0 u1sort(u1* arr){u8 count[256]={0};u8 c=0;
    foreach(i,arr)count[arr[i]]++;
    foreach(i,count){while(count[i]--)arr[c++]=i;}}
    v0 u2sort(u2* arr){u8 count[256*256]={0};u8 c=0;
    foreach(i,arr)count[arr[i]]++;
    foreach(i,count){while(count[i]--)arr[c++]=i;}}


    v0 s1sort(s1* arr){u8 count[256]={0};
    u8 c=0;
    foreach(i,arr)count[arr[i]+128]++;
    foreach(i,count){while(count[i]--)arr[c++]=i-128;}}
    v0 s2sort(s2* arr){u8 count[256*256]={0};
    u8 c=0;
    foreach(i,arr)count[arr[i]+(256*128)]++;
    foreach(i,count){while(count[i]--)arr[c++]=i-(256*128);}}




    #define extractu1(val,num) sm auto k=val;u1p z=(u1p)&k;u1 r=z[num];r em
    #define extracts1(val,num) sm auto k=val;s1p z=(s1p)&k;s1 r=z[num];r em

                    //signed f10

    //signed float
    #define radix3fs(byte,siz,A,TEMP)  sm ;;s8 i; s8 count[256]={0};s4 sh=byte*8;\
    for(i=0;i<siz;i++){\
    ;\
    count[((extracts1(A[i],byte))+128)]++;};\
    for(i=1;i<256;i++)count[i] +=count[i-1];\
    for(i=siz-1;i>-1;i--){;TEMP[(--count[extracts1(A[i],byte)+128])] = A[i];} ;; em 
       /*get the signed count vals and decrement the-m:--count[(a[i]>>x)&0xff]*/

    //00000000000000000000000000000000000000000000
    #define radix3f(byte,siz,A,TEMP)  sm ;;s8 i; s8 count[256]={0};s8 index;\
    for(i=0;i<siz;i++){\
    ;\
    count[extractu1(A[i],byte)]++;};\
    for(i=1;i<256;i++)count[i] +=count[i-1];\
    for(i=siz-1;i>-1;i--){\
    index=--count[extractu1(A[i],byte)];if(index<0)quit(i,byte,"indexfail");\
    TEMP[index] = A[i];} ;;; em 



    //

    //signed integer
    #define radix3s(byte,siz,A,TEMP)  sm ;;s8 i; s8 count[256]={0};s4 sh=byte*8;\
    for(i=0;i<siz;i++){\
    ;\
    count[(((A[i]>>sh)&255)+128)&0xff]++;};\
    for(i=1;i<256;i++)count[i] +=count[i-1];\
    for(i=siz-1;i>-1;i--){;TEMP[(--count[(((A[i] >> (byte<<3))&0xff)+128)&0xff])] = A[i];} ;; em 
       /*get the signed count vals and decrement the-m:--count[(a[i]>>x)&0xff]*/

    //00000000000000000000000000000000000000000000
    #define radix3(byte,siz,A,TEMP)  sm ;;s8 i; s8 count[256]={0};s4 sh=byte*8;\
    for(i=0;i<siz;i++){\
    ;\
    count[((A[i]>>sh)&255)]++;};\
    for(i=1;i<256;i++)count[i] +=count[i-1];\
    for(i=siz-1;i>-1;i--){;TEMP[(--count[((A[i] >> (byte<<3))&0xff)])] = A[i];} ;; em 

       /*get the count vals and decrement the-m:--count[(a[i]>>x)&0xff]*/





    v0  u4sort(u4p arr){ \
    u8 siz=elems(arr);      \
    u4p tarr=calloc(siz,4);\
    if(size(tarr)!=size(arr))quit("allocator failure");\
    radix3(0, siz,arr,tarr);                \
    radix3(1, siz,tarr,arr);       \
    radix3(2, siz,arr,tarr);  \
    radix3(3, siz,tarr,arr); \
    free(tarr); }                          

    v0 u8sort(u8p arr) { \
    u8 siz=elems(arr);      \
    u8p tarr=calloc(siz,8);\
    if(size(tarr)!=size(arr))quit("allocator failure");\
    radix3(0, siz,arr,tarr);                \
    radix3(1, siz,tarr,arr);       \
    radix3(2, siz,arr,tarr);  \
    radix3(3, siz,tarr,arr); \
    radix3(4, siz,arr,tarr);                \
    radix3(5, siz,tarr,arr);       \
    radix3(6, siz,arr,tarr);  \
    radix3(7, siz,tarr,arr); \
    free(tarr);  }

    v0  s4sort(s4p arr){ \
    u8 siz=elems(arr);      \
    s4p tarr=calloc(siz,4);\
    if(size(tarr)!=size(arr))quit("allocator failure");\
    radix3(0, siz,arr,tarr);                \
    radix3(1, siz,tarr,arr);       \
    radix3(2, siz,arr,tarr);  \
    radix3s(3, siz,tarr,arr); \
    free(tarr); }                          

    v0 s8sort(s8p arr) { \
    u8 siz=elems(arr);      \
    s8p tarr=calloc(siz,8);\
    if(size(tarr)!=size(arr))quit("allocator failure");\
    radix3(0, siz,arr,tarr);                \
    radix3(1, siz,tarr,arr);       \
    radix3(2, siz,arr,tarr);  \
    radix3(3, siz,tarr,arr); \
    radix3(4, siz,arr,tarr);                \
    radix3(5, siz,tarr,arr);       \
    radix3(6, siz,arr,tarr);  \
    radix3s(7, siz,tarr,arr); \
    free(tarr);  }


    v0 f4sort(f4p a){s4p arr=(s4p)a;s4sort(arr);
    ;u8 negelms=0;u8 siz=elems(a);
    for(u8 i=0;i<siz;i++){negelms+=(a[i]<0.0);};
    if(negelms>1)reversx(a,negelms);;}

    v0 f8sort(f8p a){s8p arr=(s8p)a;s8sort(arr);
    ;u8 negelms=0;u8 siz=elems(a);
    for(u8 i=0;i<siz;i++){negelms+=(a[i]<0.0);};
    if(negelms>1)reversx(a,negelms);;}

    #define f10sort  combsort
    /*
    v0 f10sort(f10p arr){
    ;u8 negelms=0;u8 siz=elems(arr);
    f10p tarr=calloc(size(arr),1);

    radix3f(0, siz,arr,tarr);                \
    radix3f(1, siz,tarr,arr);       \
    //radix3f(2, siz,arr,tarr);  \
    radix3f(3, siz,tarr,arr); \
    radix3f(4, siz,arr,tarr);                \
    radix3f(5, siz,tarr,arr);       \
    radix3f(6, siz,arr,tarr);  \
    radix3f(7, siz,tarr,arr);
    //radix3f(8, siz,arr,tarr);  \
    //radix3fs(9, siz,tarr,arr);
    //f10 data corrupted
    //reverse(arr);
    for(u8 i=0;i<siz;i++){negelms+=(arr[i]<0.0);};if(negelms>1)reversx(arr,negelms);;
    ;}

      */
    #define c1sort u1sort
    #define c4sort s4sort
    #define uc4sort u4sort


    v0  vpsort (vp A){;}  
    v0  c1psort (c1p A){}
    v0  s1psort (s1p A){}
    v0  s2psort (s2p A){}
    v0  s4psort (s4p A){}
    v0  s8psort (s8p A){}
    v0  u1psort (u1p A){}
    v0  u2psort (u2p A){}
    v0  u4psort (u4p A){}
    v0  u8psort (u8p A){}
    v0  f10psort (f10p A){}

    v0  f4psort (f4p A){}
    v0  f8psort (f8p A){}
     
     
     
    #define sortsuffix(x) merge(x,sort) 
    #define sort(A)  proxy(typeselect(A[0],sortsuffix)(A))


    #define memcmpgt(a,b) ({mcmp(a,b)>0;})
    //see object.h
    //sort assoca arrays
    #define osssocsort(A) ({u8 i,j, tmp, gap=(A . numfields ),len=gap;\
    while (gap>1){gap = gap<10 ? gap-1 : (gap*7)/9+1;\
    for (i=0,j=gap; j<len; i++,j++){\
    if(isbasic(A . values[0])){tmp= ( A . values[i] > A. values[j]);}else{tmp= memcmpgt( A . values[i],A. values[j]);};condswap(A. indexes[i],A. indexes[j],tmp);condswap(A .values[i],A . values[j],tmp);}};;})



    //
    //return 0 if found unsorted
    #define sortcheck(x) ({;u4 s=1;u8 elm=elems(x);for(u8 i=1;i<elm;i++){\
    if(x[i]<x[i-1]){dpr(crlf,"Mismatch at:",i,":[",x[i],"]vs[",x[i-1],"]\n");\
    s=0;break;}};s;})


    //string.h
    #define str2num(str,num)  gn((num),u8:strtoull,s8:strtoll,f8:strtod,f10:strtold,f4:strtof,u4:strtoul,s4:strtol,c4:strtol,uc4:strtoul,u2:strtoul,s2:strtol,u1:strtoul,s1:strtol,c1:strtol)(str,NULL,10)
    #define hstr2num(str,num) gn((num),u8:strtoull,s8:strtoll,f8:strtod,f10:strtold,f4:strtof,u4:strtoul,s4:strtol,c4:strtol,uc4:strtoul,u2:strtoul,s2:strtol,u1:strtoul,s1:strtol,c1:strtol)(str,NULL,16)



