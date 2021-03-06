    #ifndef GENARGS_H_ADDED__
    #define GENARGS_H_ADDED__
    /*  genargs.h  create N args 
    v1.00 by FrozenVoid: License:Affero GPL 3.0 -> www.gnu.org/licenses/agpl-3.0.en.html

    Macros:
    repargs(n,args...) repeat arguments N times:
    arguments are returned as tuples: (1,2,3),(1,2,3),...

    swap2args(a,b) swaps arg/tuple order b,a
    genargs(n,arg) repeat 1 arg N times-> arg,arg,arg...
    dummyargs(n) repeat N zero's 0,0,0,... 


    */
    #define genargs_merge1(a,b) a##b
    #define genargs_merge(a,b) genargs_merge1(a,b)
    #define repargs(n,args...) genargs(n,(args))
    #define swap2args(a,b) b,a
    //geberate N args f(4,1)-> 1,1,1,1
    #define genargs(n,arg)   genargs_merge(loopargs,n)(arg)
    #define dummyargs(n) genargs(n,0)



    //------------loop arguments------------------
    #define loopargs0(...) 
    #define loopargs1(arg) arg
    #define loopargs2(arg) arg,loopargs1(arg) 
    #define loopargs3(arg) arg,loopargs2(arg) 
    #define loopargs4(arg) arg,loopargs3(arg) 
    #define loopargs5(arg) arg,loopargs4(arg) 
    #define loopargs6(arg) arg,loopargs5(arg) 
    #define loopargs7(arg) arg,loopargs6(arg) 
    #define loopargs8(arg) arg,loopargs7(arg) 
    #define loopargs9(arg) arg,loopargs8(arg) 
    #define loopargs10(arg) arg,loopargs9(arg) 
    #define loopargs11(arg) arg,loopargs10(arg) 
    #define loopargs12(arg) arg,loopargs11(arg) 
    #define loopargs13(arg) arg,loopargs12(arg) 
    #define loopargs14(arg) arg,loopargs13(arg) 
    #define loopargs15(arg) arg,loopargs14(arg) 
    #define loopargs16(arg) arg,loopargs15(arg) 
    #define loopargs17(arg) arg,loopargs16(arg) 
    #define loopargs18(arg) arg,loopargs17(arg) 
    #define loopargs19(arg) arg,loopargs18(arg) 

    #define loopargs20(arg) arg,loopargs19(arg) 
    #define loopargs21(arg) arg,loopargs20(arg) 
    #define loopargs22(arg) arg,loopargs21(arg) 
    #define loopargs23(arg) arg,loopargs22(arg) 
    #define loopargs24(arg) arg,loopargs23(arg) 
    #define loopargs25(arg) arg,loopargs24(arg) 
    #define loopargs26(arg) arg,loopargs25(arg) 
    #define loopargs27(arg) arg,loopargs26(arg) 
    #define loopargs28(arg) arg,loopargs27(arg) 
    #define loopargs29(arg) arg,loopargs28(arg) 
    #define loopargs30(arg) arg,loopargs29(arg) 
    #define loopargs31(arg) arg,loopargs30(arg) 
    #define loopargs32(arg) arg,loopargs31(arg) 
    #define loopargs33(arg) arg,loopargs32(arg) 
    #define loopargs34(arg) arg,loopargs33(arg) 
    #define loopargs35(arg) arg,loopargs34(arg) 
    #define loopargs36(arg) arg,loopargs35(arg) 
    #define loopargs37(arg) arg,loopargs36(arg) 
    #define loopargs38(arg) arg,loopargs37(arg) 
    #define loopargs39(arg) arg,loopargs38(arg) 
    #define loopargs40(arg) arg,loopargs39(arg) 
    #define loopargs41(arg) arg,loopargs40(arg) 
    #define loopargs42(arg) arg,loopargs41(arg) 
    #define loopargs43(arg) arg,loopargs42(arg) 
    #define loopargs44(arg) arg,loopargs43(arg) 
    #define loopargs45(arg) arg,loopargs44(arg) 
    #define loopargs46(arg) arg,loopargs45(arg) 
    #define loopargs47(arg) arg,loopargs46(arg) 
    #define loopargs48(arg) arg,loopargs47(arg) 
    #define loopargs49(arg) arg,loopargs48(arg) 
    #define loopargs50(arg) arg,loopargs49(arg) 
    #define loopargs51(arg) arg,loopargs50(arg) 
    #define loopargs52(arg) arg,loopargs51(arg) 
    #define loopargs53(arg) arg,loopargs52(arg) 
    #define loopargs54(arg) arg,loopargs53(arg) 
    #define loopargs55(arg) arg,loopargs54(arg) 
    #define loopargs56(arg) arg,loopargs55(arg) 
    #define loopargs57(arg) arg,loopargs56(arg) 
    #define loopargs58(arg) arg,loopargs57(arg) 
    #define loopargs59(arg) arg,loopargs58(arg) 
    #define loopargs60(arg) arg,loopargs59(arg) 
    #define loopargs61(arg) arg,loopargs60(arg) 
    #define loopargs62(arg) arg,loopargs61(arg) 
    #define loopargs63(arg) arg,loopargs62(arg) 
    #define loopargs64(arg) arg,loopargs63(arg) 
    #define loopargs65(arg) arg,loopargs64(arg) 
    #define loopargs66(arg) arg,loopargs65(arg) 
    #define loopargs67(arg) arg,loopargs66(arg) 
    #define loopargs68(arg) arg,loopargs67(arg) 
    #define loopargs69(arg) arg,loopargs68(arg) 
    #define loopargs70(arg) arg,loopargs69(arg) 
    #define loopargs71(arg) arg,loopargs70(arg) 
    #define loopargs72(arg) arg,loopargs71(arg) 
    #define loopargs73(arg) arg,loopargs72(arg) 
    #define loopargs74(arg) arg,loopargs73(arg) 
    #define loopargs75(arg) arg,loopargs74(arg) 
    #define loopargs76(arg) arg,loopargs75(arg) 
    #define loopargs77(arg) arg,loopargs76(arg) 
    #define loopargs78(arg) arg,loopargs77(arg) 
    #define loopargs79(arg) arg,loopargs78(arg) 
    #define loopargs80(arg) arg,loopargs79(arg) 
    #define loopargs81(arg) arg,loopargs80(arg) 
    #define loopargs82(arg) arg,loopargs81(arg) 
    #define loopargs83(arg) arg,loopargs82(arg) 
    #define loopargs84(arg) arg,loopargs83(arg) 
    #define loopargs85(arg) arg,loopargs84(arg) 
    #define loopargs86(arg) arg,loopargs85(arg) 
    #define loopargs87(arg) arg,loopargs86(arg) 
    #define loopargs88(arg) arg,loopargs87(arg) 
    #define loopargs89(arg) arg,loopargs88(arg) 
    #define loopargs90(arg) arg,loopargs89(arg) 
    #define loopargs91(arg) arg,loopargs90(arg) 
    #define loopargs92(arg) arg,loopargs91(arg) 
    #define loopargs93(arg) arg,loopargs92(arg) 
    #define loopargs94(arg) arg,loopargs93(arg) 
    #define loopargs95(arg) arg,loopargs94(arg) 
    #define loopargs96(arg) arg,loopargs95(arg) 
    #define loopargs97(arg) arg,loopargs96(arg) 
    #define loopargs98(arg) arg,loopargs97(arg) 
    #define loopargs99(arg) arg,loopargs98(arg) 
    #define loopargs100(arg) arg,loopargs99(arg) 
    #define loopargs101(arg) arg,loopargs101(arg) 
    #define loopargs102(arg) arg,loopargs101(arg) 
    #define loopargs103(arg) arg,loopargs102(arg) 
    #define loopargs104(arg) arg,loopargs103(arg) 
    #define loopargs105(arg) arg,loopargs104(arg) 
    #define loopargs106(arg) arg,loopargs105(arg) 
    #define loopargs107(arg) arg,loopargs106(arg) 
    #define loopargs108(arg) arg,loopargs107(arg) 
    #define loopargs109(arg) arg,loopargs108(arg) 
    #define loopargs110(arg) arg,loopargs109(arg) 
    #define loopargs111(arg) arg,loopargs110(arg) 
    #define loopargs112(arg) arg,loopargs111(arg) 
    #define loopargs113(arg) arg,loopargs112(arg) 
    #define loopargs114(arg) arg,loopargs113(arg) 
    #define loopargs115(arg) arg,loopargs114(arg) 
    #define loopargs116(arg) arg,loopargs115(arg) 
    #define loopargs117(arg) arg,loopargs116(arg) 
    #define loopargs118(arg) arg,loopargs117(arg) 
    #define loopargs119(arg) arg,loopargs118(arg) 

    #define loopargs120(arg) arg,loopargs119(arg) 
    #define loopargs121(arg) arg,loopargs120(arg) 
    #define loopargs122(arg) arg,loopargs121(arg) 
    #define loopargs123(arg) arg,loopargs122(arg) 
    #define loopargs124(arg) arg,loopargs123(arg) 
    #define loopargs125(arg) arg,loopargs124(arg) 
    #define loopargs126(arg) arg,loopargs125(arg) 
    #define loopargs127(arg) arg,loopargs126(arg) 
    #define loopargs128(arg) arg,loopargs127(arg) 
    #define loopargs129(arg) arg,loopargs128(arg) 
    #define loopargs130(arg) arg,loopargs129(arg) 
    #define loopargs131(arg) arg,loopargs130(arg) 
    #define loopargs132(arg) arg,loopargs131(arg) 
    #define loopargs133(arg) arg,loopargs132(arg) 
    #define loopargs134(arg) arg,loopargs133(arg) 
    #define loopargs135(arg) arg,loopargs134(arg) 
    #define loopargs136(arg) arg,loopargs135(arg) 
    #define loopargs137(arg) arg,loopargs136(arg) 
    #define loopargs138(arg) arg,loopargs137(arg) 
    #define loopargs139(arg) arg,loopargs138(arg) 
    #define loopargs140(arg) arg,loopargs139(arg) 
    #define loopargs141(arg) arg,loopargs140(arg) 
    #define loopargs142(arg) arg,loopargs141(arg) 
    #define loopargs143(arg) arg,loopargs142(arg) 
    #define loopargs144(arg) arg,loopargs143(arg) 
    #define loopargs145(arg) arg,loopargs144(arg) 
    #define loopargs146(arg) arg,loopargs145(arg) 
    #define loopargs147(arg) arg,loopargs146(arg) 
    #define loopargs148(arg) arg,loopargs147(arg) 
    #define loopargs149(arg) arg,loopargs148(arg) 
    #define loopargs150(arg) arg,loopargs149(arg) 
    #define loopargs151(arg) arg,loopargs150(arg) 
    #define loopargs152(arg) arg,loopargs151(arg) 
    #define loopargs153(arg) arg,loopargs152(arg) 
    #define loopargs154(arg) arg,loopargs153(arg) 
    #define loopargs155(arg) arg,loopargs154(arg) 
    #define loopargs156(arg) arg,loopargs155(arg) 
    #define loopargs157(arg) arg,loopargs156(arg) 
    #define loopargs158(arg) arg,loopargs157(arg) 
    #define loopargs159(arg) arg,loopargs158(arg) 
    #define loopargs160(arg) arg,loopargs159(arg) 
    #define loopargs161(arg) arg,loopargs160(arg) 
    #define loopargs162(arg) arg,loopargs161(arg) 
    #define loopargs163(arg) arg,loopargs162(arg) 
    #define loopargs164(arg) arg,loopargs163(arg) 
    #define loopargs165(arg) arg,loopargs164(arg) 
    #define loopargs166(arg) arg,loopargs165(arg) 
    #define loopargs167(arg) arg,loopargs166(arg) 
    #define loopargs168(arg) arg,loopargs167(arg) 
    #define loopargs169(arg) arg,loopargs168(arg) 
    #define loopargs170(arg) arg,loopargs169(arg) 
    #define loopargs171(arg) arg,loopargs170(arg) 
    #define loopargs172(arg) arg,loopargs171(arg) 
    #define loopargs173(arg) arg,loopargs172(arg) 
    #define loopargs174(arg) arg,loopargs173(arg) 
    #define loopargs175(arg) arg,loopargs174(arg) 
    #define loopargs176(arg) arg,loopargs175(arg) 
    #define loopargs177(arg) arg,loopargs176(arg) 
    #define loopargs178(arg) arg,loopargs177(arg) 
    #define loopargs179(arg) arg,loopargs178(arg) 
    #define loopargs180(arg) arg,loopargs179(arg) 
    #define loopargs181(arg) arg,loopargs180(arg) 
    #define loopargs182(arg) arg,loopargs181(arg) 
    #define loopargs183(arg) arg,loopargs182(arg) 
    #define loopargs184(arg) arg,loopargs183(arg) 
    #define loopargs185(arg) arg,loopargs184(arg) 
    #define loopargs186(arg) arg,loopargs185(arg) 
    #define loopargs187(arg) arg,loopargs186(arg) 
    #define loopargs188(arg) arg,loopargs187(arg) 
    #define loopargs189(arg) arg,loopargs188(arg) 
    #define loopargs190(arg) arg,loopargs189(arg) 
    #define loopargs191(arg) arg,loopargs190(arg) 
    #define loopargs192(arg) arg,loopargs191(arg) 
    #define loopargs193(arg) arg,loopargs192(arg) 
    #define loopargs194(arg) arg,loopargs193(arg) 
    #define loopargs195(arg) arg,loopargs194(arg) 
    #define loopargs196(arg) arg,loopargs195(arg) 
    #define loopargs197(arg) arg,loopargs196(arg) 
    #define loopargs198(arg) arg,loopargs197(arg) 
    #define loopargs199(arg) arg,loopargs198(arg) 

    #define loopargs200(arg) arg,loopargs199(arg) 
    #define loopargs201(arg) arg,loopargs200(arg) 
    #define loopargs202(arg) arg,loopargs201(arg) 
    #define loopargs203(arg) arg,loopargs202(arg) 
    #define loopargs204(arg) arg,loopargs203(arg) 
    #define loopargs205(arg) arg,loopargs204(arg) 
    #define loopargs206(arg) arg,loopargs205(arg) 
    #define loopargs207(arg) arg,loopargs206(arg) 
    #define loopargs208(arg) arg,loopargs207(arg) 
    #define loopargs209(arg) arg,loopargs208(arg) 
    #define loopargs210(arg) arg,loopargs209(arg) 
    #define loopargs211(arg) arg,loopargs210(arg) 
    #define loopargs212(arg) arg,loopargs211(arg) 
    #define loopargs213(arg) arg,loopargs212(arg) 
    #define loopargs214(arg) arg,loopargs213(arg) 
    #define loopargs215(arg) arg,loopargs214(arg) 
    #define loopargs216(arg) arg,loopargs215(arg) 
    #define loopargs217(arg) arg,loopargs216(arg) 
    #define loopargs218(arg) arg,loopargs217(arg) 
    #define loopargs219(arg) arg,loopargs218(arg) 

    #define loopargs220(arg) arg,loopargs219(arg) 
    #define loopargs221(arg) arg,loopargs220(arg) 
    #define loopargs222(arg) arg,loopargs221(arg) 
    #define loopargs223(arg) arg,loopargs222(arg) 
    #define loopargs224(arg) arg,loopargs223(arg) 
    #define loopargs225(arg) arg,loopargs224(arg) 
    #define loopargs226(arg) arg,loopargs225(arg) 
    #define loopargs227(arg) arg,loopargs226(arg) 
    #define loopargs228(arg) arg,loopargs227(arg) 
    #define loopargs229(arg) arg,loopargs228(arg) 
    #define loopargs230(arg) arg,loopargs229(arg) 
    #define loopargs231(arg) arg,loopargs230(arg) 
    #define loopargs232(arg) arg,loopargs231(arg) 
    #define loopargs233(arg) arg,loopargs232(arg) 
    #define loopargs234(arg) arg,loopargs233(arg) 
    #define loopargs235(arg) arg,loopargs234(arg) 
    #define loopargs236(arg) arg,loopargs235(arg) 
    #define loopargs237(arg) arg,loopargs236(arg) 
    #define loopargs238(arg) arg,loopargs237(arg) 
    #define loopargs239(arg) arg,loopargs238(arg) 
    #define loopargs240(arg) arg,loopargs239(arg) 
    #define loopargs241(arg) arg,loopargs240(arg) 
    #define loopargs242(arg) arg,loopargs241(arg) 
    #define loopargs243(arg) arg,loopargs242(arg) 
    #define loopargs244(arg) arg,loopargs243(arg) 
    #define loopargs245(arg) arg,loopargs244(arg) 
    #define loopargs246(arg) arg,loopargs245(arg) 
    #define loopargs247(arg) arg,loopargs246(arg) 
    #define loopargs248(arg) arg,loopargs247(arg) 
    #define loopargs249(arg) arg,loopargs248(arg) 
    #define loopargs250(arg) arg,loopargs249(arg) 
    #define loopargs251(arg) arg,loopargs250(arg) 
    #define loopargs252(arg) arg,loopargs251(arg) 
    #define loopargs253(arg) arg,loopargs252(arg) 
    #define loopargs254(arg) arg,loopargs253(arg) 
    #define loopargs255(arg) arg,loopargs254(arg) 
    #define loopargs256(arg) arg,loopargs255(arg) 
    #define loopargs257(arg) arg,loopargs256(arg) 
    #define loopargs258(arg) arg,loopargs257(arg) 

    #endif

