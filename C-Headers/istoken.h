    #ifndef ISTOKEN_H_ADDED__
    #define ISTOKEN_H_ADDED__
    #include "boolean.h"//www.reddit.com/r/frozenvoid/wiki/void2/boolean_h
    #include "isdefined.h"//www.reddit.com/r/frozenvoid/wiki/void2/isdefined_h
    #include "argcount.h"//www.reddit.com/r/frozenvoid/wiki/void2/argcount_h
    /*  istoken.h detect numbers in tokens, returning token 1:0
    v1.01 by FrozenVoid: License:Affero GPL 3.0 -> www.gnu.org/licenses/agpl-3.0.en.html

    Exported macro: istoken(tok,val) //limit:(val=0 val=9)
    returns token '1' if 'tok'(0-9) token is equal to 'val'(0-9)
    Example: istoken(9,9) =>1 //returns literal token '1'
    istoken(9,1) =>0 //returns literal token '0'

    Exported macro: istokenin(tok,tokens...) //limit:(min=0 max=9)
    returns token '1' if 'tok' literal is in tokens

    Examples:
    istokenin(1, 2,3,4) =>0
    istokenin(1, 2,1,4) =>1
    istokenin(3, 5,1,8) =>0
    istokenin(3, 0,1,3) =>1

    Exported macro:istokennotin(n,elements...)
    // if n is in {elements} return 0, else return 1
    // examples:istokennotin(6, 2,3,4)=>1 istokennotin(3, 2,3,4)=>0 



    */
    #define istokenmerge_(a,b) a##b 
    #define istokenmerge(a,b)  istokenmerge_(a,b) 
    #define istoken(n,x) istokenmerge(isdefined,x)(n)
    #define istokenin(n,tokens...) istokenmerge(istokenin,argcount(tokens))(n,tokens)

    #define istokenin0(n,tokens...) 0
    #define istokenin1(n,t1) istoken(n,t1)
    #define istokenin2(n,t1,t2) bool_or(istoken(n,t1),istoken(n,t2))
    #define istokenin3(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin4(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin5(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin6(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin7(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin8(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))
    #define istokenin9(n,t1,tokens...) bool_or(istoken(n,t1),istokenmerge(istokenin,argcount(tokens))(n,tokens))


    #define istokennotin(n,tokens...) bool_neg(istokein(n,elements))






    #endif

