
    #ifndef LAMBDA_H_ADDED__
    #define LAMBDA_H_ADDED__
    #include "typedefs.h"
    /*  lambda.h  create lambda functions from arguments
    v1.06 by FrozenVoid: License:Affero GPL 3.0 -> www.gnu.org/licenses/agpl-3.0.en.html
    Note: usually a few composed macros turn to be more useful:
    See Equivalent pure macro-> lines


    Macro: lam(rtype,argtuple,body) -> rtype fn(argtuple){body}(args) 
    Creates a lambda function with returntype:rtype, arguments:argtuple and internal code:body
    Equivalent pure macro-> #define :
    #define lambdaname100(args) body

    macro: defun(funcname,args,body) funcname args {body;}
    create funcname with (args) tuple as arguments and body.
    Equivalent pure macro-> #define :
    #define funcname100(args) body

    macro:compose(rtype,func1,func2,args1) create rtype lambda returning func1(func2(args1))
    Equivalent pure macro->  :
    #define mcompose(f,g,args...) f(g(args))
    #define mcompose_call(args...) f(g(args))


    macro:partial(rtype,argtuple,func,fixed_tuple,argtuple_names)
    js:    function partial(f, x) {
    return function(y) { return f(x, y);}}
    Create a variadic function from arguments:
    creates a rtype function with (argtuple) arguments
    which call func() with unwrapped (fixedvar_tuple),(argtuple_names)
    fixed_tuple -> (1,2,3) arguments which are constant
    argtuple_names -> (a,b,c,d) arguments names from argtuple(these are external arguments of constructed function)

    Equivalent pure macro-> 2 macros :
    #define partial_func(a,b) a+b 
    #define partial_add5(a) partial_func(a,5)
    #define partial_call(func,a) func(a,5) 
    // partial_call(partial_func,a)-> partial_func(a,5)
    ------------------------------------------------------
    examples:
    auto x=lam(double,(int a),return (double) a/2);
    printf("%f",x(9));//4.5000

    defun(double add_1,(double a),return a+a);
    defun(double mult_1,(double a,double b),return a*b);

    auto y=compose(double,(double a,double b),add_1,mult_1,(a,b));
    printf("%f",y(9,10));//91.000000

    for(int i=0;i<100;i++){
    printf("%d:",\
    lam(int,(int a,double b),return a+b)(i,2.0));}
    int adder_func(double b,double c,int a){return (int)((b/c)*a);}
    for(int i=0;i<100;i++){
    printf("%d:",\
    partial(int,(int a),adder_func,(2.0,3.0),(a))(i)  );}


    these can be nested:
    for(int i=0;i<100;i++){
    printf("%d:",\
    partial(int,(int az),\
    lam(int,(double b,double c,int a),return (int)((b/c)*a)),\
    (2.0,3.0),(az))(i)  );}


    */
    #define lam_merge2(a,b) a##b
    #define lam_merge(a,b) lam_merge2(a,b)
    #define lam_unwrap(a...) a 
    #define defun(funcname,args,body) funcname args {body;}
    #define lam(rtype,argtuple,body) ({\
    defun( rtype lam_merge(lambdaatline,__LINE__),argtuple,body);  lam_merge(lambdaatline,__LINE__);})

    #define partial(rtype,argtuple,func,fixed_tuple,argtuple_names) ({ defun(rtype lam_merge(partialatline,__LINE__),argtuple,return func(lam_unwrap fixed_tuple,lam_unwrap argtuple_names)) \
    ;lam_merge(partialatline,__LINE__); })


    #define compose(rtype,argtuple,func1,func2,argtuple_names) \
    ({    defun( rtype lam_merge(composeatline,__LINE__),argtuple,return func1(func2 argtuple_names));\
    lam_merge(composeatline,__LINE__); })

    #endif

