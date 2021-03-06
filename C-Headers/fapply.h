
	#ifndef FAPPLY_H_ADDED__
	#define FAPPLY_H_ADDED__
	#include "argcount.h"//www.reddit.com/r/frozenvoid/wiki/void2/argcount_h
	/*  fapply.h  Multi-Functional apply( 1024 args max) 
	v1.04 by FrozenVoid: License:Affero GPL 3.0 -> www.gnu.org/licenses/agpl-3.0.en.html
	Internal header:
	Exported Macro: fapply(f,t,a)  func(func,tuple_parameters,tuple_args)  
	*/
	#define fapply(f,t,a)  fapplyfunc(f,t,a)
	#define fapply_merge1(a,b) a##b
	#define fapply_merge(a,b) fapply_merge1(a,b)
	#define fapplyfunc(f,t,a)  fapply_merge(fa,argcount a)(f,t,a)
	// fapply(func,parm_tuple,arg_tuple)
	//--------------Implementation ------------------------

	#define fa0(...)  
	#define fa1(f,t,a) f(f,t,a)
	#define fa2(f,t,a) f(f,t,a)
	#define fa3(f,t,a) f(f,t,a)
	#define fa4(f,t,a) f(f,t,a)
	#define fa5(f,t,a) f(f,t,a)
	#define fa6(f,t,a) f(f,t,a)
	#define fa7(f,t,a) f(f,t,a)
	#define fa8(f,t,a) f(f,t,a)
	#define fa9(f,t,a) f(f,t,a)
	#define fa10(f,t,a) f(f,t,a)
	#define fa11(f,t,a) f(f,t,a)
	#define fa12(f,t,a) f(f,t,a)
	#define fa13(f,t,a) f(f,t,a)
	#define fa14(f,t,a) f(f,t,a)
	#define fa15(f,t,a) f(f,t,a)
	#define fa16(f,t,a) f(f,t,a)
	#define fa17(f,t,a) f(f,t,a)
	#define fa18(f,t,a) f(f,t,a)
	#define fa19(f,t,a) f(f,t,a)
	#define fa20(f,t,a) f(f,t,a)
	#define fa21(f,t,a) f(f,t,a)
	#define fa22(f,t,a) f(f,t,a)
	#define fa23(f,t,a) f(f,t,a)
	#define fa24(f,t,a) f(f,t,a)
	#define fa25(f,t,a) f(f,t,a)
	#define fa26(f,t,a) f(f,t,a)
	#define fa27(f,t,a) f(f,t,a)
	#define fa28(f,t,a) f(f,t,a)
	#define fa29(f,t,a) f(f,t,a)
	#define fa30(f,t,a) f(f,t,a)
	#define fa31(f,t,a) f(f,t,a)
	#define fa32(f,t,a) f(f,t,a)
	#define fa33(f,t,a) f(f,t,a)
	#define fa34(f,t,a) f(f,t,a)
	#define fa35(f,t,a) f(f,t,a)
	#define fa36(f,t,a) f(f,t,a)
	#define fa37(f,t,a) f(f,t,a)
	#define fa38(f,t,a) f(f,t,a)
	#define fa39(f,t,a) f(f,t,a)
	#define fa40(f,t,a) f(f,t,a)
	#define fa41(f,t,a) f(f,t,a)
	#define fa42(f,t,a) f(f,t,a)
	#define fa43(f,t,a) f(f,t,a)
	#define fa44(f,t,a) f(f,t,a)
	#define fa45(f,t,a) f(f,t,a)
	#define fa46(f,t,a) f(f,t,a)
	#define fa47(f,t,a) f(f,t,a)
	#define fa48(f,t,a) f(f,t,a)
	#define fa49(f,t,a) f(f,t,a)
	#define fa50(f,t,a) f(f,t,a)
	#define fa51(f,t,a) f(f,t,a)
	#define fa52(f,t,a) f(f,t,a)
	#define fa53(f,t,a) f(f,t,a)
	#define fa54(f,t,a) f(f,t,a)
	#define fa55(f,t,a) f(f,t,a)
	#define fa56(f,t,a) f(f,t,a)
	#define fa57(f,t,a) f(f,t,a)
	#define fa58(f,t,a) f(f,t,a)
	#define fa59(f,t,a) f(f,t,a)
	#define fa60(f,t,a) f(f,t,a)
	#define fa61(f,t,a) f(f,t,a)
	#define fa62(f,t,a) f(f,t,a)
	#define fa63(f,t,a) f(f,t,a)
	#define fa64(f,t,a) f(f,t,a)
	#define fa65(f,t,a) f(f,t,a)
	#define fa66(f,t,a) f(f,t,a)
	#define fa67(f,t,a) f(f,t,a)
	#define fa68(f,t,a) f(f,t,a)
	#define fa69(f,t,a) f(f,t,a)
	#define fa70(f,t,a) f(f,t,a)
	#define fa71(f,t,a) f(f,t,a)
	#define fa72(f,t,a) f(f,t,a)
	#define fa73(f,t,a) f(f,t,a)
	#define fa74(f,t,a) f(f,t,a)
	#define fa75(f,t,a) f(f,t,a)
	#define fa76(f,t,a) f(f,t,a)
	#define fa77(f,t,a) f(f,t,a)
	#define fa78(f,t,a) f(f,t,a)
	#define fa79(f,t,a) f(f,t,a)
	#define fa80(f,t,a) f(f,t,a)
	#define fa81(f,t,a) f(f,t,a)
	#define fa82(f,t,a) f(f,t,a)
	#define fa83(f,t,a) f(f,t,a)
	#define fa84(f,t,a) f(f,t,a)
	#define fa85(f,t,a) f(f,t,a)
	#define fa86(f,t,a) f(f,t,a)
	#define fa87(f,t,a) f(f,t,a)
	#define fa88(f,t,a) f(f,t,a)
	#define fa89(f,t,a) f(f,t,a)
	#define fa90(f,t,a) f(f,t,a)
	#define fa91(f,t,a) f(f,t,a)
	#define fa92(f,t,a) f(f,t,a)
	#define fa93(f,t,a) f(f,t,a)
	#define fa94(f,t,a) f(f,t,a)
	#define fa95(f,t,a) f(f,t,a)
	#define fa96(f,t,a) f(f,t,a)
	#define fa97(f,t,a) f(f,t,a)
	#define fa98(f,t,a) f(f,t,a)
	#define fa99(f,t,a) f(f,t,a)
	#define fa100(f,t,a) f(f,t,a)
	#define fa101(f,t,a) f(f,t,a)
	#define fa102(f,t,a) f(f,t,a)
	#define fa103(f,t,a) f(f,t,a)
	#define fa104(f,t,a) f(f,t,a)
	#define fa105(f,t,a) f(f,t,a)
	#define fa106(f,t,a) f(f,t,a)
	#define fa107(f,t,a) f(f,t,a)
	#define fa108(f,t,a) f(f,t,a)
	#define fa109(f,t,a) f(f,t,a)
	#define fa110(f,t,a) f(f,t,a)
	#define fa111(f,t,a) f(f,t,a)
	#define fa112(f,t,a) f(f,t,a)
	#define fa113(f,t,a) f(f,t,a)
	#define fa114(f,t,a) f(f,t,a)
	#define fa115(f,t,a) f(f,t,a)
	#define fa116(f,t,a) f(f,t,a)
	#define fa117(f,t,a) f(f,t,a)
	#define fa118(f,t,a) f(f,t,a)
	#define fa119(f,t,a) f(f,t,a)
	#define fa120(f,t,a) f(f,t,a)
	#define fa121(f,t,a) f(f,t,a)
	#define fa122(f,t,a) f(f,t,a)
	#define fa123(f,t,a) f(f,t,a)
	#define fa124(f,t,a) f(f,t,a)
	#define fa125(f,t,a) f(f,t,a)
	#define fa126(f,t,a) f(f,t,a)
	#define fa127(f,t,a) f(f,t,a)
	#define fa128(f,t,a) f(f,t,a)
	#define fa129(f,t,a) f(f,t,a)
	#define fa130(f,t,a) f(f,t,a)
	#define fa131(f,t,a) f(f,t,a)
	#define fa132(f,t,a) f(f,t,a)
	#define fa133(f,t,a) f(f,t,a)
	#define fa134(f,t,a) f(f,t,a)
	#define fa135(f,t,a) f(f,t,a)
	#define fa136(f,t,a) f(f,t,a)
	#define fa137(f,t,a) f(f,t,a)
	#define fa138(f,t,a) f(f,t,a)
	#define fa139(f,t,a) f(f,t,a)
	#define fa140(f,t,a) f(f,t,a)
	#define fa141(f,t,a) f(f,t,a)
	#define fa142(f,t,a) f(f,t,a)
	#define fa143(f,t,a) f(f,t,a)
	#define fa144(f,t,a) f(f,t,a)
	#define fa145(f,t,a) f(f,t,a)
	#define fa146(f,t,a) f(f,t,a)
	#define fa147(f,t,a) f(f,t,a)
	#define fa148(f,t,a) f(f,t,a)
	#define fa149(f,t,a) f(f,t,a)
	#define fa150(f,t,a) f(f,t,a)
	#define fa151(f,t,a) f(f,t,a)
	#define fa152(f,t,a) f(f,t,a)
	#define fa153(f,t,a) f(f,t,a)
	#define fa154(f,t,a) f(f,t,a)
	#define fa155(f,t,a) f(f,t,a)
	#define fa156(f,t,a) f(f,t,a)
	#define fa157(f,t,a) f(f,t,a)
	#define fa158(f,t,a) f(f,t,a)
	#define fa159(f,t,a) f(f,t,a)
	#define fa160(f,t,a) f(f,t,a)
	#define fa161(f,t,a) f(f,t,a)
	#define fa162(f,t,a) f(f,t,a)
	#define fa163(f,t,a) f(f,t,a)
	#define fa164(f,t,a) f(f,t,a)
	#define fa165(f,t,a) f(f,t,a)
	#define fa166(f,t,a) f(f,t,a)
	#define fa167(f,t,a) f(f,t,a)
	#define fa168(f,t,a) f(f,t,a)
	#define fa169(f,t,a) f(f,t,a)
	#define fa170(f,t,a) f(f,t,a)
	#define fa171(f,t,a) f(f,t,a)
	#define fa172(f,t,a) f(f,t,a)
	#define fa173(f,t,a) f(f,t,a)
	#define fa174(f,t,a) f(f,t,a)
	#define fa175(f,t,a) f(f,t,a)
	#define fa176(f,t,a) f(f,t,a)
	#define fa177(f,t,a) f(f,t,a)
	#define fa178(f,t,a) f(f,t,a)
	#define fa179(f,t,a) f(f,t,a)
	#define fa180(f,t,a) f(f,t,a)
	#define fa181(f,t,a) f(f,t,a)
	#define fa182(f,t,a) f(f,t,a)
	#define fa183(f,t,a) f(f,t,a)
	#define fa184(f,t,a) f(f,t,a)
	#define fa185(f,t,a) f(f,t,a)
	#define fa186(f,t,a) f(f,t,a)
	#define fa187(f,t,a) f(f,t,a)
	#define fa188(f,t,a) f(f,t,a)
	#define fa189(f,t,a) f(f,t,a)
	#define fa190(f,t,a) f(f,t,a)
	#define fa191(f,t,a) f(f,t,a)
	#define fa192(f,t,a) f(f,t,a)
	#define fa193(f,t,a) f(f,t,a)
	#define fa194(f,t,a) f(f,t,a)
	#define fa195(f,t,a) f(f,t,a)
	#define fa196(f,t,a) f(f,t,a)
	#define fa197(f,t,a) f(f,t,a)
	#define fa198(f,t,a) f(f,t,a)
	#define fa199(f,t,a) f(f,t,a)
	#define fa200(f,t,a) f(f,t,a)
	#define fa201(f,t,a) f(f,t,a)
	#define fa202(f,t,a) f(f,t,a)
	#define fa203(f,t,a) f(f,t,a)
	#define fa204(f,t,a) f(f,t,a)
	#define fa205(f,t,a) f(f,t,a)
	#define fa206(f,t,a) f(f,t,a)
	#define fa207(f,t,a) f(f,t,a)
	#define fa208(f,t,a) f(f,t,a)
	#define fa209(f,t,a) f(f,t,a)
	#define fa210(f,t,a) f(f,t,a)
	#define fa211(f,t,a) f(f,t,a)
	#define fa212(f,t,a) f(f,t,a)
	#define fa213(f,t,a) f(f,t,a)
	#define fa214(f,t,a) f(f,t,a)
	#define fa215(f,t,a) f(f,t,a)
	#define fa216(f,t,a) f(f,t,a)
	#define fa217(f,t,a) f(f,t,a)
	#define fa218(f,t,a) f(f,t,a)
	#define fa219(f,t,a) f(f,t,a)
	#define fa220(f,t,a) f(f,t,a)
	#define fa221(f,t,a) f(f,t,a)
	#define fa222(f,t,a) f(f,t,a)
	#define fa223(f,t,a) f(f,t,a)
	#define fa224(f,t,a) f(f,t,a)
	#define fa225(f,t,a) f(f,t,a)
	#define fa226(f,t,a) f(f,t,a)
	#define fa227(f,t,a) f(f,t,a)
	#define fa228(f,t,a) f(f,t,a)
	#define fa229(f,t,a) f(f,t,a)
	#define fa230(f,t,a) f(f,t,a)
	#define fa231(f,t,a) f(f,t,a)
	#define fa232(f,t,a) f(f,t,a)
	#define fa233(f,t,a) f(f,t,a)
	#define fa234(f,t,a) f(f,t,a)
	#define fa235(f,t,a) f(f,t,a)
	#define fa236(f,t,a) f(f,t,a)
	#define fa237(f,t,a) f(f,t,a)
	#define fa238(f,t,a) f(f,t,a)
	#define fa239(f,t,a) f(f,t,a)
	#define fa240(f,t,a) f(f,t,a)
	#define fa241(f,t,a) f(f,t,a)
	#define fa242(f,t,a) f(f,t,a)
	#define fa243(f,t,a) f(f,t,a)
	#define fa244(f,t,a) f(f,t,a)
	#define fa245(f,t,a) f(f,t,a)
	#define fa246(f,t,a) f(f,t,a)
	#define fa247(f,t,a) f(f,t,a)
	#define fa248(f,t,a) f(f,t,a)
	#define fa249(f,t,a) f(f,t,a)
	#define fa250(f,t,a) f(f,t,a)
	#define fa251(f,t,a) f(f,t,a)
	#define fa252(f,t,a) f(f,t,a)
	#define fa253(f,t,a) f(f,t,a)
	#define fa254(f,t,a) f(f,t,a)
	#define fa255(f,t,a) f(f,t,a)
	#define fa256(f,t,a) f(f,t,a)
	#define fa257(f,t,a) f(f,t,a)
	#define fa258(f,t,a) f(f,t,a)
	#define fa259(f,t,a) f(f,t,a)
	#define fa260(f,t,a) f(f,t,a)
	#define fa261(f,t,a) f(f,t,a)
	#define fa262(f,t,a) f(f,t,a)
	#define fa263(f,t,a) f(f,t,a)
	#define fa264(f,t,a) f(f,t,a)
	#define fa265(f,t,a) f(f,t,a)
	#define fa266(f,t,a) f(f,t,a)
	#define fa267(f,t,a) f(f,t,a)
	#define fa268(f,t,a) f(f,t,a)
	#define fa269(f,t,a) f(f,t,a)
	#define fa270(f,t,a) f(f,t,a)
	#define fa271(f,t,a) f(f,t,a)
	#define fa272(f,t,a) f(f,t,a)
	#define fa273(f,t,a) f(f,t,a)
	#define fa274(f,t,a) f(f,t,a)
	#define fa275(f,t,a) f(f,t,a)
	#define fa276(f,t,a) f(f,t,a)
	#define fa277(f,t,a) f(f,t,a)
	#define fa278(f,t,a) f(f,t,a)
	#define fa279(f,t,a) f(f,t,a)
	#define fa280(f,t,a) f(f,t,a)
	#define fa281(f,t,a) f(f,t,a)
	#define fa282(f,t,a) f(f,t,a)
	#define fa283(f,t,a) f(f,t,a)
	#define fa284(f,t,a) f(f,t,a)
	#define fa285(f,t,a) f(f,t,a)
	#define fa286(f,t,a) f(f,t,a)
	#define fa287(f,t,a) f(f,t,a)
	#define fa288(f,t,a) f(f,t,a)
	#define fa289(f,t,a) f(f,t,a)
	#define fa290(f,t,a) f(f,t,a)
	#define fa291(f,t,a) f(f,t,a)
	#define fa292(f,t,a) f(f,t,a)
	#define fa293(f,t,a) f(f,t,a)
	#define fa294(f,t,a) f(f,t,a)
	#define fa295(f,t,a) f(f,t,a)
	#define fa296(f,t,a) f(f,t,a)
	#define fa297(f,t,a) f(f,t,a)
	#define fa298(f,t,a) f(f,t,a)
	#define fa299(f,t,a) f(f,t,a)
	#define fa300(f,t,a) f(f,t,a)
	#define fa301(f,t,a) f(f,t,a)
	#define fa302(f,t,a) f(f,t,a)
	#define fa303(f,t,a) f(f,t,a)
	#define fa304(f,t,a) f(f,t,a)
	#define fa305(f,t,a) f(f,t,a)
	#define fa306(f,t,a) f(f,t,a)
	#define fa307(f,t,a) f(f,t,a)
	#define fa308(f,t,a) f(f,t,a)
	#define fa309(f,t,a) f(f,t,a)
	#define fa310(f,t,a) f(f,t,a)
	#define fa311(f,t,a) f(f,t,a)
	#define fa312(f,t,a) f(f,t,a)
	#define fa313(f,t,a) f(f,t,a)
	#define fa314(f,t,a) f(f,t,a)
	#define fa315(f,t,a) f(f,t,a)
	#define fa316(f,t,a) f(f,t,a)
	#define fa317(f,t,a) f(f,t,a)
	#define fa318(f,t,a) f(f,t,a)
	#define fa319(f,t,a) f(f,t,a)
	#define fa320(f,t,a) f(f,t,a)
	#define fa321(f,t,a) f(f,t,a)
	#define fa322(f,t,a) f(f,t,a)
	#define fa323(f,t,a) f(f,t,a)
	#define fa324(f,t,a) f(f,t,a)
	#define fa325(f,t,a) f(f,t,a)
	#define fa326(f,t,a) f(f,t,a)
	#define fa327(f,t,a) f(f,t,a)
	#define fa328(f,t,a) f(f,t,a)
	#define fa329(f,t,a) f(f,t,a)
	#define fa330(f,t,a) f(f,t,a)
	#define fa331(f,t,a) f(f,t,a)
	#define fa332(f,t,a) f(f,t,a)
	#define fa333(f,t,a) f(f,t,a)
	#define fa334(f,t,a) f(f,t,a)
	#define fa335(f,t,a) f(f,t,a)
	#define fa336(f,t,a) f(f,t,a)
	#define fa337(f,t,a) f(f,t,a)
	#define fa338(f,t,a) f(f,t,a)
	#define fa339(f,t,a) f(f,t,a)
	#define fa340(f,t,a) f(f,t,a)
	#define fa341(f,t,a) f(f,t,a)
	#define fa342(f,t,a) f(f,t,a)
	#define fa343(f,t,a) f(f,t,a)
	#define fa344(f,t,a) f(f,t,a)
	#define fa345(f,t,a) f(f,t,a)
	#define fa346(f,t,a) f(f,t,a)
	#define fa347(f,t,a) f(f,t,a)
	#define fa348(f,t,a) f(f,t,a)
	#define fa349(f,t,a) f(f,t,a)
	#define fa350(f,t,a) f(f,t,a)
	#define fa351(f,t,a) f(f,t,a)
	#define fa352(f,t,a) f(f,t,a)
	#define fa353(f,t,a) f(f,t,a)
	#define fa354(f,t,a) f(f,t,a)
	#define fa355(f,t,a) f(f,t,a)
	#define fa356(f,t,a) f(f,t,a)
	#define fa357(f,t,a) f(f,t,a)
	#define fa358(f,t,a) f(f,t,a)
	#define fa359(f,t,a) f(f,t,a)
	#define fa360(f,t,a) f(f,t,a)
	#define fa361(f,t,a) f(f,t,a)
	#define fa362(f,t,a) f(f,t,a)
	#define fa363(f,t,a) f(f,t,a)
	#define fa364(f,t,a) f(f,t,a)
	#define fa365(f,t,a) f(f,t,a)
	#define fa366(f,t,a) f(f,t,a)
	#define fa367(f,t,a) f(f,t,a)
	#define fa368(f,t,a) f(f,t,a)
	#define fa369(f,t,a) f(f,t,a)
	#define fa370(f,t,a) f(f,t,a)
	#define fa371(f,t,a) f(f,t,a)
	#define fa372(f,t,a) f(f,t,a)
	#define fa373(f,t,a) f(f,t,a)
	#define fa374(f,t,a) f(f,t,a)
	#define fa375(f,t,a) f(f,t,a)
	#define fa376(f,t,a) f(f,t,a)
	#define fa377(f,t,a) f(f,t,a)
	#define fa378(f,t,a) f(f,t,a)
	#define fa379(f,t,a) f(f,t,a)
	#define fa380(f,t,a) f(f,t,a)
	#define fa381(f,t,a) f(f,t,a)
	#define fa382(f,t,a) f(f,t,a)
	#define fa383(f,t,a) f(f,t,a)
	#define fa384(f,t,a) f(f,t,a)
	#define fa385(f,t,a) f(f,t,a)
	#define fa386(f,t,a) f(f,t,a)
	#define fa387(f,t,a) f(f,t,a)
	#define fa388(f,t,a) f(f,t,a)
	#define fa389(f,t,a) f(f,t,a)
	#define fa390(f,t,a) f(f,t,a)
	#define fa391(f,t,a) f(f,t,a)
	#define fa392(f,t,a) f(f,t,a)
	#define fa393(f,t,a) f(f,t,a)
	#define fa394(f,t,a) f(f,t,a)
	#define fa395(f,t,a) f(f,t,a)
	#define fa396(f,t,a) f(f,t,a)
	#define fa397(f,t,a) f(f,t,a)
	#define fa398(f,t,a) f(f,t,a)
	#define fa399(f,t,a) f(f,t,a)
	#define fa400(f,t,a) f(f,t,a)
	#define fa401(f,t,a) f(f,t,a)
	#define fa402(f,t,a) f(f,t,a)
	#define fa403(f,t,a) f(f,t,a)
	#define fa404(f,t,a) f(f,t,a)
	#define fa405(f,t,a) f(f,t,a)
	#define fa406(f,t,a) f(f,t,a)
	#define fa407(f,t,a) f(f,t,a)
	#define fa408(f,t,a) f(f,t,a)
	#define fa409(f,t,a) f(f,t,a)
	#define fa410(f,t,a) f(f,t,a)
	#define fa411(f,t,a) f(f,t,a)
	#define fa412(f,t,a) f(f,t,a)
	#define fa413(f,t,a) f(f,t,a)
	#define fa414(f,t,a) f(f,t,a)
	#define fa415(f,t,a) f(f,t,a)
	#define fa416(f,t,a) f(f,t,a)
	#define fa417(f,t,a) f(f,t,a)
	#define fa418(f,t,a) f(f,t,a)
	#define fa419(f,t,a) f(f,t,a)
	#define fa420(f,t,a) f(f,t,a)
	#define fa421(f,t,a) f(f,t,a)
	#define fa422(f,t,a) f(f,t,a)
	#define fa423(f,t,a) f(f,t,a)
	#define fa424(f,t,a) f(f,t,a)
	#define fa425(f,t,a) f(f,t,a)
	#define fa426(f,t,a) f(f,t,a)
	#define fa427(f,t,a) f(f,t,a)
	#define fa428(f,t,a) f(f,t,a)
	#define fa429(f,t,a) f(f,t,a)
	#define fa430(f,t,a) f(f,t,a)
	#define fa431(f,t,a) f(f,t,a)
	#define fa432(f,t,a) f(f,t,a)
	#define fa433(f,t,a) f(f,t,a)
	#define fa434(f,t,a) f(f,t,a)
	#define fa435(f,t,a) f(f,t,a)
	#define fa436(f,t,a) f(f,t,a)
	#define fa437(f,t,a) f(f,t,a)
	#define fa438(f,t,a) f(f,t,a)
	#define fa439(f,t,a) f(f,t,a)
	#define fa440(f,t,a) f(f,t,a)
	#define fa441(f,t,a) f(f,t,a)
	#define fa442(f,t,a) f(f,t,a)
	#define fa443(f,t,a) f(f,t,a)
	#define fa444(f,t,a) f(f,t,a)
	#define fa445(f,t,a) f(f,t,a)
	#define fa446(f,t,a) f(f,t,a)
	#define fa447(f,t,a) f(f,t,a)
	#define fa448(f,t,a) f(f,t,a)
	#define fa449(f,t,a) f(f,t,a)
	#define fa450(f,t,a) f(f,t,a)
	#define fa451(f,t,a) f(f,t,a)
	#define fa452(f,t,a) f(f,t,a)
	#define fa453(f,t,a) f(f,t,a)
	#define fa454(f,t,a) f(f,t,a)
	#define fa455(f,t,a) f(f,t,a)
	#define fa456(f,t,a) f(f,t,a)
	#define fa457(f,t,a) f(f,t,a)
	#define fa458(f,t,a) f(f,t,a)
	#define fa459(f,t,a) f(f,t,a)
	#define fa460(f,t,a) f(f,t,a)
	#define fa461(f,t,a) f(f,t,a)
	#define fa462(f,t,a) f(f,t,a)
	#define fa463(f,t,a) f(f,t,a)
	#define fa464(f,t,a) f(f,t,a)
	#define fa465(f,t,a) f(f,t,a)
	#define fa466(f,t,a) f(f,t,a)
	#define fa467(f,t,a) f(f,t,a)
	#define fa468(f,t,a) f(f,t,a)
	#define fa469(f,t,a) f(f,t,a)
	#define fa470(f,t,a) f(f,t,a)
	#define fa471(f,t,a) f(f,t,a)
	#define fa472(f,t,a) f(f,t,a)
	#define fa473(f,t,a) f(f,t,a)
	#define fa474(f,t,a) f(f,t,a)
	#define fa475(f,t,a) f(f,t,a)
	#define fa476(f,t,a) f(f,t,a)
	#define fa477(f,t,a) f(f,t,a)
	#define fa478(f,t,a) f(f,t,a)
	#define fa479(f,t,a) f(f,t,a)
	#define fa480(f,t,a) f(f,t,a)
	#define fa481(f,t,a) f(f,t,a)
	#define fa482(f,t,a) f(f,t,a)
	#define fa483(f,t,a) f(f,t,a)
	#define fa484(f,t,a) f(f,t,a)
	#define fa485(f,t,a) f(f,t,a)
	#define fa486(f,t,a) f(f,t,a)
	#define fa487(f,t,a) f(f,t,a)
	#define fa488(f,t,a) f(f,t,a)
	#define fa489(f,t,a) f(f,t,a)
	#define fa490(f,t,a) f(f,t,a)
	#define fa491(f,t,a) f(f,t,a)
	#define fa492(f,t,a) f(f,t,a)
	#define fa493(f,t,a) f(f,t,a)
	#define fa494(f,t,a) f(f,t,a)
	#define fa495(f,t,a) f(f,t,a)
	#define fa496(f,t,a) f(f,t,a)
	#define fa497(f,t,a) f(f,t,a)
	#define fa498(f,t,a) f(f,t,a)
	#define fa499(f,t,a) f(f,t,a)
	#define fa500(f,t,a) f(f,t,a)
	#define fa501(f,t,a) f(f,t,a)
	#define fa502(f,t,a) f(f,t,a)
	#define fa503(f,t,a) f(f,t,a)
	#define fa504(f,t,a) f(f,t,a)
	#define fa505(f,t,a) f(f,t,a)
	#define fa506(f,t,a) f(f,t,a)
	#define fa507(f,t,a) f(f,t,a)
	#define fa508(f,t,a) f(f,t,a)
	#define fa509(f,t,a) f(f,t,a)
	#define fa510(f,t,a) f(f,t,a)
	#define fa511(f,t,a) f(f,t,a)
	#define fa512(f,t,a) f(f,t,a)
	#define fa513(f,t,a) f(f,t,a)
	#define fa514(f,t,a) f(f,t,a)
	#define fa515(f,t,a) f(f,t,a)
	#define fa516(f,t,a) f(f,t,a)
	#define fa517(f,t,a) f(f,t,a)
	#define fa518(f,t,a) f(f,t,a)
	#define fa519(f,t,a) f(f,t,a)
	#define fa520(f,t,a) f(f,t,a)
	#define fa521(f,t,a) f(f,t,a)
	#define fa522(f,t,a) f(f,t,a)
	#define fa523(f,t,a) f(f,t,a)
	#define fa524(f,t,a) f(f,t,a)
	#define fa525(f,t,a) f(f,t,a)
	#define fa526(f,t,a) f(f,t,a)
	#define fa527(f,t,a) f(f,t,a)
	#define fa528(f,t,a) f(f,t,a)
	#define fa529(f,t,a) f(f,t,a)
	#define fa530(f,t,a) f(f,t,a)
	#define fa531(f,t,a) f(f,t,a)
	#define fa532(f,t,a) f(f,t,a)
	#define fa533(f,t,a) f(f,t,a)
	#define fa534(f,t,a) f(f,t,a)
	#define fa535(f,t,a) f(f,t,a)
	#define fa536(f,t,a) f(f,t,a)
	#define fa537(f,t,a) f(f,t,a)
	#define fa538(f,t,a) f(f,t,a)
	#define fa539(f,t,a) f(f,t,a)
	#define fa540(f,t,a) f(f,t,a)
	#define fa541(f,t,a) f(f,t,a)
	#define fa542(f,t,a) f(f,t,a)
	#define fa543(f,t,a) f(f,t,a)
	#define fa544(f,t,a) f(f,t,a)
	#define fa545(f,t,a) f(f,t,a)
	#define fa546(f,t,a) f(f,t,a)
	#define fa547(f,t,a) f(f,t,a)
	#define fa548(f,t,a) f(f,t,a)
	#define fa549(f,t,a) f(f,t,a)
	#define fa550(f,t,a) f(f,t,a)
	#define fa551(f,t,a) f(f,t,a)
	#define fa552(f,t,a) f(f,t,a)
	#define fa553(f,t,a) f(f,t,a)
	#define fa554(f,t,a) f(f,t,a)
	#define fa555(f,t,a) f(f,t,a)
	#define fa556(f,t,a) f(f,t,a)
	#define fa557(f,t,a) f(f,t,a)
	#define fa558(f,t,a) f(f,t,a)
	#define fa559(f,t,a) f(f,t,a)
	#define fa560(f,t,a) f(f,t,a)
	#define fa561(f,t,a) f(f,t,a)
	#define fa562(f,t,a) f(f,t,a)
	#define fa563(f,t,a) f(f,t,a)
	#define fa564(f,t,a) f(f,t,a)
	#define fa565(f,t,a) f(f,t,a)
	#define fa566(f,t,a) f(f,t,a)
	#define fa567(f,t,a) f(f,t,a)
	#define fa568(f,t,a) f(f,t,a)
	#define fa569(f,t,a) f(f,t,a)
	#define fa570(f,t,a) f(f,t,a)
	#define fa571(f,t,a) f(f,t,a)
	#define fa572(f,t,a) f(f,t,a)
	#define fa573(f,t,a) f(f,t,a)
	#define fa574(f,t,a) f(f,t,a)
	#define fa575(f,t,a) f(f,t,a)
	#define fa576(f,t,a) f(f,t,a)
	#define fa577(f,t,a) f(f,t,a)
	#define fa578(f,t,a) f(f,t,a)
	#define fa579(f,t,a) f(f,t,a)
	#define fa580(f,t,a) f(f,t,a)
	#define fa581(f,t,a) f(f,t,a)
	#define fa582(f,t,a) f(f,t,a)
	#define fa583(f,t,a) f(f,t,a)
	#define fa584(f,t,a) f(f,t,a)
	#define fa585(f,t,a) f(f,t,a)
	#define fa586(f,t,a) f(f,t,a)
	#define fa587(f,t,a) f(f,t,a)
	#define fa588(f,t,a) f(f,t,a)
	#define fa589(f,t,a) f(f,t,a)
	#define fa590(f,t,a) f(f,t,a)
	#define fa591(f,t,a) f(f,t,a)
	#define fa592(f,t,a) f(f,t,a)
	#define fa593(f,t,a) f(f,t,a)
	#define fa594(f,t,a) f(f,t,a)
	#define fa595(f,t,a) f(f,t,a)
	#define fa596(f,t,a) f(f,t,a)
	#define fa597(f,t,a) f(f,t,a)
	#define fa598(f,t,a) f(f,t,a)
	#define fa599(f,t,a) f(f,t,a)
	#define fa600(f,t,a) f(f,t,a)
	#define fa601(f,t,a) f(f,t,a)
	#define fa602(f,t,a) f(f,t,a)
	#define fa603(f,t,a) f(f,t,a)
	#define fa604(f,t,a) f(f,t,a)
	#define fa605(f,t,a) f(f,t,a)
	#define fa606(f,t,a) f(f,t,a)
	#define fa607(f,t,a) f(f,t,a)
	#define fa608(f,t,a) f(f,t,a)
	#define fa609(f,t,a) f(f,t,a)
	#define fa610(f,t,a) f(f,t,a)
	#define fa611(f,t,a) f(f,t,a)
	#define fa612(f,t,a) f(f,t,a)
	#define fa613(f,t,a) f(f,t,a)
	#define fa614(f,t,a) f(f,t,a)
	#define fa615(f,t,a) f(f,t,a)
	#define fa616(f,t,a) f(f,t,a)
	#define fa617(f,t,a) f(f,t,a)
	#define fa618(f,t,a) f(f,t,a)
	#define fa619(f,t,a) f(f,t,a)
	#define fa620(f,t,a) f(f,t,a)
	#define fa621(f,t,a) f(f,t,a)
	#define fa622(f,t,a) f(f,t,a)
	#define fa623(f,t,a) f(f,t,a)
	#define fa624(f,t,a) f(f,t,a)
	#define fa625(f,t,a) f(f,t,a)
	#define fa626(f,t,a) f(f,t,a)
	#define fa627(f,t,a) f(f,t,a)
	#define fa628(f,t,a) f(f,t,a)
	#define fa629(f,t,a) f(f,t,a)
	#define fa630(f,t,a) f(f,t,a)
	#define fa631(f,t,a) f(f,t,a)
	#define fa632(f,t,a) f(f,t,a)
	#define fa633(f,t,a) f(f,t,a)
	#define fa634(f,t,a) f(f,t,a)
	#define fa635(f,t,a) f(f,t,a)
	#define fa636(f,t,a) f(f,t,a)
	#define fa637(f,t,a) f(f,t,a)
	#define fa638(f,t,a) f(f,t,a)
	#define fa639(f,t,a) f(f,t,a)
	#define fa640(f,t,a) f(f,t,a)
	#define fa641(f,t,a) f(f,t,a)
	#define fa642(f,t,a) f(f,t,a)
	#define fa643(f,t,a) f(f,t,a)
	#define fa644(f,t,a) f(f,t,a)
	#define fa645(f,t,a) f(f,t,a)
	#define fa646(f,t,a) f(f,t,a)
	#define fa647(f,t,a) f(f,t,a)
	#define fa648(f,t,a) f(f,t,a)
	#define fa649(f,t,a) f(f,t,a)
	#define fa650(f,t,a) f(f,t,a)
	#define fa651(f,t,a) f(f,t,a)
	#define fa652(f,t,a) f(f,t,a)
	#define fa653(f,t,a) f(f,t,a)
	#define fa654(f,t,a) f(f,t,a)
	#define fa655(f,t,a) f(f,t,a)
	#define fa656(f,t,a) f(f,t,a)
	#define fa657(f,t,a) f(f,t,a)
	#define fa658(f,t,a) f(f,t,a)
	#define fa659(f,t,a) f(f,t,a)
	#define fa660(f,t,a) f(f,t,a)
	#define fa661(f,t,a) f(f,t,a)
	#define fa662(f,t,a) f(f,t,a)
	#define fa663(f,t,a) f(f,t,a)
	#define fa664(f,t,a) f(f,t,a)
	#define fa665(f,t,a) f(f,t,a)
	#define fa666(f,t,a) f(f,t,a)
	#define fa667(f,t,a) f(f,t,a)
	#define fa668(f,t,a) f(f,t,a)
	#define fa669(f,t,a) f(f,t,a)
	#define fa670(f,t,a) f(f,t,a)
	#define fa671(f,t,a) f(f,t,a)
	#define fa672(f,t,a) f(f,t,a)
	#define fa673(f,t,a) f(f,t,a)
	#define fa674(f,t,a) f(f,t,a)
	#define fa675(f,t,a) f(f,t,a)
	#define fa676(f,t,a) f(f,t,a)
	#define fa677(f,t,a) f(f,t,a)
	#define fa678(f,t,a) f(f,t,a)
	#define fa679(f,t,a) f(f,t,a)
	#define fa680(f,t,a) f(f,t,a)
	#define fa681(f,t,a) f(f,t,a)
	#define fa682(f,t,a) f(f,t,a)
	#define fa683(f,t,a) f(f,t,a)
	#define fa684(f,t,a) f(f,t,a)
	#define fa685(f,t,a) f(f,t,a)
	#define fa686(f,t,a) f(f,t,a)
	#define fa687(f,t,a) f(f,t,a)
	#define fa688(f,t,a) f(f,t,a)
	#define fa689(f,t,a) f(f,t,a)
	#define fa690(f,t,a) f(f,t,a)
	#define fa691(f,t,a) f(f,t,a)
	#define fa692(f,t,a) f(f,t,a)
	#define fa693(f,t,a) f(f,t,a)
	#define fa694(f,t,a) f(f,t,a)
	#define fa695(f,t,a) f(f,t,a)
	#define fa696(f,t,a) f(f,t,a)
	#define fa697(f,t,a) f(f,t,a)
	#define fa698(f,t,a) f(f,t,a)
	#define fa699(f,t,a) f(f,t,a)
	#define fa700(f,t,a) f(f,t,a)
	#define fa701(f,t,a) f(f,t,a)
	#define fa702(f,t,a) f(f,t,a)
	#define fa703(f,t,a) f(f,t,a)
	#define fa704(f,t,a) f(f,t,a)
	#define fa705(f,t,a) f(f,t,a)
	#define fa706(f,t,a) f(f,t,a)
	#define fa707(f,t,a) f(f,t,a)
	#define fa708(f,t,a) f(f,t,a)
	#define fa709(f,t,a) f(f,t,a)
	#define fa710(f,t,a) f(f,t,a)
	#define fa711(f,t,a) f(f,t,a)
	#define fa712(f,t,a) f(f,t,a)
	#define fa713(f,t,a) f(f,t,a)
	#define fa714(f,t,a) f(f,t,a)
	#define fa715(f,t,a) f(f,t,a)
	#define fa716(f,t,a) f(f,t,a)
	#define fa717(f,t,a) f(f,t,a)
	#define fa718(f,t,a) f(f,t,a)
	#define fa719(f,t,a) f(f,t,a)
	#define fa720(f,t,a) f(f,t,a)
	#define fa721(f,t,a) f(f,t,a)
	#define fa722(f,t,a) f(f,t,a)
	#define fa723(f,t,a) f(f,t,a)
	#define fa724(f,t,a) f(f,t,a)
	#define fa725(f,t,a) f(f,t,a)
	#define fa726(f,t,a) f(f,t,a)
	#define fa727(f,t,a) f(f,t,a)
	#define fa728(f,t,a) f(f,t,a)
	#define fa729(f,t,a) f(f,t,a)
	#define fa730(f,t,a) f(f,t,a)
	#define fa731(f,t,a) f(f,t,a)
	#define fa732(f,t,a) f(f,t,a)
	#define fa733(f,t,a) f(f,t,a)
	#define fa734(f,t,a) f(f,t,a)
	#define fa735(f,t,a) f(f,t,a)
	#define fa736(f,t,a) f(f,t,a)
	#define fa737(f,t,a) f(f,t,a)
	#define fa738(f,t,a) f(f,t,a)
	#define fa739(f,t,a) f(f,t,a)
	#define fa740(f,t,a) f(f,t,a)
	#define fa741(f,t,a) f(f,t,a)
	#define fa742(f,t,a) f(f,t,a)
	#define fa743(f,t,a) f(f,t,a)
	#define fa744(f,t,a) f(f,t,a)
	#define fa745(f,t,a) f(f,t,a)
	#define fa746(f,t,a) f(f,t,a)
	#define fa747(f,t,a) f(f,t,a)
	#define fa748(f,t,a) f(f,t,a)
	#define fa749(f,t,a) f(f,t,a)
	#define fa750(f,t,a) f(f,t,a)
	#define fa751(f,t,a) f(f,t,a)
	#define fa752(f,t,a) f(f,t,a)
	#define fa753(f,t,a) f(f,t,a)
	#define fa754(f,t,a) f(f,t,a)
	#define fa755(f,t,a) f(f,t,a)
	#define fa756(f,t,a) f(f,t,a)
	#define fa757(f,t,a) f(f,t,a)
	#define fa758(f,t,a) f(f,t,a)
	#define fa759(f,t,a) f(f,t,a)
	#define fa760(f,t,a) f(f,t,a)
	#define fa761(f,t,a) f(f,t,a)
	#define fa762(f,t,a) f(f,t,a)
	#define fa763(f,t,a) f(f,t,a)
	#define fa764(f,t,a) f(f,t,a)
	#define fa765(f,t,a) f(f,t,a)
	#define fa766(f,t,a) f(f,t,a)
	#define fa767(f,t,a) f(f,t,a)
	#define fa768(f,t,a) f(f,t,a)
	#define fa769(f,t,a) f(f,t,a)
	#define fa770(f,t,a) f(f,t,a)
	#define fa771(f,t,a) f(f,t,a)
	#define fa772(f,t,a) f(f,t,a)
	#define fa773(f,t,a) f(f,t,a)
	#define fa774(f,t,a) f(f,t,a)
	#define fa775(f,t,a) f(f,t,a)
	#define fa776(f,t,a) f(f,t,a)
	#define fa777(f,t,a) f(f,t,a)
	#define fa778(f,t,a) f(f,t,a)
	#define fa779(f,t,a) f(f,t,a)
	#define fa780(f,t,a) f(f,t,a)
	#define fa781(f,t,a) f(f,t,a)
	#define fa782(f,t,a) f(f,t,a)
	#define fa783(f,t,a) f(f,t,a)
	#define fa784(f,t,a) f(f,t,a)
	#define fa785(f,t,a) f(f,t,a)
	#define fa786(f,t,a) f(f,t,a)
	#define fa787(f,t,a) f(f,t,a)
	#define fa788(f,t,a) f(f,t,a)
	#define fa789(f,t,a) f(f,t,a)
	#define fa790(f,t,a) f(f,t,a)
	#define fa791(f,t,a) f(f,t,a)
	#define fa792(f,t,a) f(f,t,a)
	#define fa793(f,t,a) f(f,t,a)
	#define fa794(f,t,a) f(f,t,a)
	#define fa795(f,t,a) f(f,t,a)
	#define fa796(f,t,a) f(f,t,a)
	#define fa797(f,t,a) f(f,t,a)
	#define fa798(f,t,a) f(f,t,a)
	#define fa799(f,t,a) f(f,t,a)
	#define fa800(f,t,a) f(f,t,a)
	#define fa801(f,t,a) f(f,t,a)
	#define fa802(f,t,a) f(f,t,a)
	#define fa803(f,t,a) f(f,t,a)
	#define fa804(f,t,a) f(f,t,a)
	#define fa805(f,t,a) f(f,t,a)
	#define fa806(f,t,a) f(f,t,a)
	#define fa807(f,t,a) f(f,t,a)
	#define fa808(f,t,a) f(f,t,a)
	#define fa809(f,t,a) f(f,t,a)
	#define fa810(f,t,a) f(f,t,a)
	#define fa811(f,t,a) f(f,t,a)
	#define fa812(f,t,a) f(f,t,a)
	#define fa813(f,t,a) f(f,t,a)
	#define fa814(f,t,a) f(f,t,a)
	#define fa815(f,t,a) f(f,t,a)
	#define fa816(f,t,a) f(f,t,a)
	#define fa817(f,t,a) f(f,t,a)
	#define fa818(f,t,a) f(f,t,a)
	#define fa819(f,t,a) f(f,t,a)
	#define fa820(f,t,a) f(f,t,a)
	#define fa821(f,t,a) f(f,t,a)
	#define fa822(f,t,a) f(f,t,a)
	#define fa823(f,t,a) f(f,t,a)
	#define fa824(f,t,a) f(f,t,a)
	#define fa825(f,t,a) f(f,t,a)
	#define fa826(f,t,a) f(f,t,a)
	#define fa827(f,t,a) f(f,t,a)
	#define fa828(f,t,a) f(f,t,a)
	#define fa829(f,t,a) f(f,t,a)
	#define fa830(f,t,a) f(f,t,a)
	#define fa831(f,t,a) f(f,t,a)
	#define fa832(f,t,a) f(f,t,a)
	#define fa833(f,t,a) f(f,t,a)
	#define fa834(f,t,a) f(f,t,a)
	#define fa835(f,t,a) f(f,t,a)
	#define fa836(f,t,a) f(f,t,a)
	#define fa837(f,t,a) f(f,t,a)
	#define fa838(f,t,a) f(f,t,a)
	#define fa839(f,t,a) f(f,t,a)
	#define fa840(f,t,a) f(f,t,a)
	#define fa841(f,t,a) f(f,t,a)
	#define fa842(f,t,a) f(f,t,a)
	#define fa843(f,t,a) f(f,t,a)
	#define fa844(f,t,a) f(f,t,a)
	#define fa845(f,t,a) f(f,t,a)
	#define fa846(f,t,a) f(f,t,a)
	#define fa847(f,t,a) f(f,t,a)
	#define fa848(f,t,a) f(f,t,a)
	#define fa849(f,t,a) f(f,t,a)
	#define fa850(f,t,a) f(f,t,a)
	#define fa851(f,t,a) f(f,t,a)
	#define fa852(f,t,a) f(f,t,a)
	#define fa853(f,t,a) f(f,t,a)
	#define fa854(f,t,a) f(f,t,a)
	#define fa855(f,t,a) f(f,t,a)
	#define fa856(f,t,a) f(f,t,a)
	#define fa857(f,t,a) f(f,t,a)
	#define fa858(f,t,a) f(f,t,a)
	#define fa859(f,t,a) f(f,t,a)
	#define fa860(f,t,a) f(f,t,a)
	#define fa861(f,t,a) f(f,t,a)
	#define fa862(f,t,a) f(f,t,a)
	#define fa863(f,t,a) f(f,t,a)
	#define fa864(f,t,a) f(f,t,a)
	#define fa865(f,t,a) f(f,t,a)
	#define fa866(f,t,a) f(f,t,a)
	#define fa867(f,t,a) f(f,t,a)
	#define fa868(f,t,a) f(f,t,a)
	#define fa869(f,t,a) f(f,t,a)
	#define fa870(f,t,a) f(f,t,a)
	#define fa871(f,t,a) f(f,t,a)
	#define fa872(f,t,a) f(f,t,a)
	#define fa873(f,t,a) f(f,t,a)
	#define fa874(f,t,a) f(f,t,a)
	#define fa875(f,t,a) f(f,t,a)
	#define fa876(f,t,a) f(f,t,a)
	#define fa877(f,t,a) f(f,t,a)
	#define fa878(f,t,a) f(f,t,a)
	#define fa879(f,t,a) f(f,t,a)
	#define fa880(f,t,a) f(f,t,a)
	#define fa881(f,t,a) f(f,t,a)
	#define fa882(f,t,a) f(f,t,a)
	#define fa883(f,t,a) f(f,t,a)
	#define fa884(f,t,a) f(f,t,a)
	#define fa885(f,t,a) f(f,t,a)
	#define fa886(f,t,a) f(f,t,a)
	#define fa887(f,t,a) f(f,t,a)
	#define fa888(f,t,a) f(f,t,a)
	#define fa889(f,t,a) f(f,t,a)
	#define fa890(f,t,a) f(f,t,a)
	#define fa891(f,t,a) f(f,t,a)
	#define fa892(f,t,a) f(f,t,a)
	#define fa893(f,t,a) f(f,t,a)
	#define fa894(f,t,a) f(f,t,a)
	#define fa895(f,t,a) f(f,t,a)
	#define fa896(f,t,a) f(f,t,a)
	#define fa897(f,t,a) f(f,t,a)
	#define fa898(f,t,a) f(f,t,a)
	#define fa899(f,t,a) f(f,t,a)
	#define fa900(f,t,a) f(f,t,a)
	#define fa901(f,t,a) f(f,t,a)
	#define fa902(f,t,a) f(f,t,a)
	#define fa903(f,t,a) f(f,t,a)
	#define fa904(f,t,a) f(f,t,a)
	#define fa905(f,t,a) f(f,t,a)
	#define fa906(f,t,a) f(f,t,a)
	#define fa907(f,t,a) f(f,t,a)
	#define fa908(f,t,a) f(f,t,a)
	#define fa909(f,t,a) f(f,t,a)
	#define fa910(f,t,a) f(f,t,a)
	#define fa911(f,t,a) f(f,t,a)
	#define fa912(f,t,a) f(f,t,a)
	#define fa913(f,t,a) f(f,t,a)
	#define fa914(f,t,a) f(f,t,a)
	#define fa915(f,t,a) f(f,t,a)
	#define fa916(f,t,a) f(f,t,a)
	#define fa917(f,t,a) f(f,t,a)
	#define fa918(f,t,a) f(f,t,a)
	#define fa919(f,t,a) f(f,t,a)
	#define fa920(f,t,a) f(f,t,a)
	#define fa921(f,t,a) f(f,t,a)
	#define fa922(f,t,a) f(f,t,a)
	#define fa923(f,t,a) f(f,t,a)
	#define fa924(f,t,a) f(f,t,a)
	#define fa925(f,t,a) f(f,t,a)
	#define fa926(f,t,a) f(f,t,a)
	#define fa927(f,t,a) f(f,t,a)
	#define fa928(f,t,a) f(f,t,a)
	#define fa929(f,t,a) f(f,t,a)
	#define fa930(f,t,a) f(f,t,a)
	#define fa931(f,t,a) f(f,t,a)
	#define fa932(f,t,a) f(f,t,a)
	#define fa933(f,t,a) f(f,t,a)
	#define fa934(f,t,a) f(f,t,a)
	#define fa935(f,t,a) f(f,t,a)
	#define fa936(f,t,a) f(f,t,a)
	#define fa937(f,t,a) f(f,t,a)
	#define fa938(f,t,a) f(f,t,a)
	#define fa939(f,t,a) f(f,t,a)
	#define fa940(f,t,a) f(f,t,a)
	#define fa941(f,t,a) f(f,t,a)
	#define fa942(f,t,a) f(f,t,a)
	#define fa943(f,t,a) f(f,t,a)
	#define fa944(f,t,a) f(f,t,a)
	#define fa945(f,t,a) f(f,t,a)
	#define fa946(f,t,a) f(f,t,a)
	#define fa947(f,t,a) f(f,t,a)
	#define fa948(f,t,a) f(f,t,a)
	#define fa949(f,t,a) f(f,t,a)
	#define fa950(f,t,a) f(f,t,a)
	#define fa951(f,t,a) f(f,t,a)
	#define fa952(f,t,a) f(f,t,a)
	#define fa953(f,t,a) f(f,t,a)
	#define fa954(f,t,a) f(f,t,a)
	#define fa955(f,t,a) f(f,t,a)
	#define fa956(f,t,a) f(f,t,a)
	#define fa957(f,t,a) f(f,t,a)
	#define fa958(f,t,a) f(f,t,a)
	#define fa959(f,t,a) f(f,t,a)
	#define fa960(f,t,a) f(f,t,a)
	#define fa961(f,t,a) f(f,t,a)
	#define fa962(f,t,a) f(f,t,a)
	#define fa963(f,t,a) f(f,t,a)
	#define fa964(f,t,a) f(f,t,a)
	#define fa965(f,t,a) f(f,t,a)
	#define fa966(f,t,a) f(f,t,a)
	#define fa967(f,t,a) f(f,t,a)
	#define fa968(f,t,a) f(f,t,a)
	#define fa969(f,t,a) f(f,t,a)
	#define fa970(f,t,a) f(f,t,a)
	#define fa971(f,t,a) f(f,t,a)
	#define fa972(f,t,a) f(f,t,a)
	#define fa973(f,t,a) f(f,t,a)
	#define fa974(f,t,a) f(f,t,a)
	#define fa975(f,t,a) f(f,t,a)
	#define fa976(f,t,a) f(f,t,a)
	#define fa977(f,t,a) f(f,t,a)
	#define fa978(f,t,a) f(f,t,a)
	#define fa979(f,t,a) f(f,t,a)
	#define fa980(f,t,a) f(f,t,a)
	#define fa981(f,t,a) f(f,t,a)
	#define fa982(f,t,a) f(f,t,a)
	#define fa983(f,t,a) f(f,t,a)
	#define fa984(f,t,a) f(f,t,a)
	#define fa985(f,t,a) f(f,t,a)
	#define fa986(f,t,a) f(f,t,a)
	#define fa987(f,t,a) f(f,t,a)
	#define fa988(f,t,a) f(f,t,a)
	#define fa989(f,t,a) f(f,t,a)
	#define fa990(f,t,a) f(f,t,a)
	#define fa991(f,t,a) f(f,t,a)
	#define fa992(f,t,a) f(f,t,a)
	#define fa993(f,t,a) f(f,t,a)
	#define fa994(f,t,a) f(f,t,a)
	#define fa995(f,t,a) f(f,t,a)
	#define fa996(f,t,a) f(f,t,a)
	#define fa997(f,t,a) f(f,t,a)
	#define fa998(f,t,a) f(f,t,a)
	#define fa999(f,t,a) f(f,t,a)
	#define fa1000(f,t,a) f(f,t,a)
	#define fa1001(f,t,a) f(f,t,a)
	#define fa1002(f,t,a) f(f,t,a)
	#define fa1003(f,t,a) f(f,t,a)
	#define fa1004(f,t,a) f(f,t,a)
	#define fa1005(f,t,a) f(f,t,a)
	#define fa1006(f,t,a) f(f,t,a)
	#define fa1007(f,t,a) f(f,t,a)
	#define fa1008(f,t,a) f(f,t,a)
	#define fa1009(f,t,a) f(f,t,a)
	#define fa1010(f,t,a) f(f,t,a)
	#define fa1011(f,t,a) f(f,t,a)
	#define fa1012(f,t,a) f(f,t,a)
	#define fa1013(f,t,a) f(f,t,a)
	#define fa1014(f,t,a) f(f,t,a)
	#define fa1015(f,t,a) f(f,t,a)
	#define fa1016(f,t,a) f(f,t,a)
	#define fa1017(f,t,a) f(f,t,a)
	#define fa1018(f,t,a) f(f,t,a)
	#define fa1019(f,t,a) f(f,t,a)
	#define fa1020(f,t,a) f(f,t,a)
	#define fa1021(f,t,a) f(f,t,a)
	#define fa1022(f,t,a) f(f,t,a)
	#define fa1023(f,t,a) f(f,t,a)
	#define fa1024(f,t,a) f(f,t,a)
	#define fa1025(f,t,a) f(f,t,a)
	#define fa1026(f,t,a) f(f,t,a)
	#endif
