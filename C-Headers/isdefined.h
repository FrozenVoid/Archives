
	#ifndef ISDEFINED_H_ADDED__
	#define ISDEFINED_H_ADDED__
#include "macro.h"
	/*  isdefined.h detect if macro is defined to digit x
	v1.01 by FrozenVoid: License:Affero GPL 3.0 -> www.gnu.org/licenses/agpl-3.0.en.html ( source stackoverflow.com/questions/5464170/using-definedmacro-inside-the-c-if-statement )

	Macros: 

	if defined macro==token digit returns token '1',0 if not
	isdefined0(macroname) returns 1 if defined '0',0 if not 
	isdefined1(macroname) returns 1 if defined '1',0 if not 
	isdefined2(macroname) returns 1 if defined '2',0 if not 
	isdefined3(macroname) returns 1 if defined '3',0 if not 
	isdefined4(macroname) returns 1 if defined '4',0 if not 
	isdefined5(macroname) returns 1 if defined '5',0 if not 
	isdefined6(macroname) returns 1 if defined '6',0 if not 
	isdefined7(macroname) returns 1 if defined '7',0 if not 
	isdefined8(macroname) returns 1 if defined '8',0 if not 
	isdefined9(macroname) returns 1 if defined '9',0 if not 


	*/
	

             
	#define isdefined0(macro) isdefined0_(macro)
	#define isdefinedtest0_0 ,
	#define isdefined0_(value) isdefined0__(isdefinedtest0_##value)
	#define isdefined0__(comma) isdefined0___(comma 1, 0)
	#define isdefined0___(_, v, ...) v

	#define isdefined1(macro) isdefined1_(macro)
	#define isdefinedtest1_1 ,
	#define isdefined1_(value) isdefined1__(isdefinedtest1_##value)
	#define isdefined1__(comma) isdefined1___(comma 1, 0)
	#define isdefined1___(_, v, ...) v

	#define isdefined2(macro) isdefined2_(macro)
	#define isdefinedtest2_2 ,
	#define isdefined2_(value) isdefined2__(isdefinedtest2_##value)
	#define isdefined2__(comma) isdefined2___(comma 1, 0)
	#define isdefined2___(_, v, ...) v

	#define isdefined3(macro) isdefined3_(macro)
	#define isdefinedtest3_3 ,
	#define isdefined3_(value) isdefined3__(isdefinedtest3_##value)
	#define isdefined3__(comma) isdefined3___(comma 1, 0)
	#define isdefined3___(_, v, ...) v

	#define isdefined4(macro) isdefined4_(macro)
	#define isdefinedtest4_4 ,
	#define isdefined4_(value) isdefined4__(isdefinedtest4_##value)
	#define isdefined4__(comma) isdefined4___(comma 1, 0)
	#define isdefined4___(_, v, ...) v

	#define isdefined5(macro) isdefined5_(macro)
	#define isdefinedtest5_5 ,
	#define isdefined5_(value) isdefined5__(isdefinedtest5_##value)
	#define isdefined5__(comma) isdefined5___(comma 1, 0)
	#define isdefined5___(_, v, ...) v

	#define isdefined6(macro) isdefined6_(macro)
	#define isdefinedtest6_6 ,
	#define isdefined6_(value) isdefined6__(isdefinedtest6_##value)
	#define isdefined6__(comma) isdefined6___(comma 1, 0)
	#define isdefined6___(_, v, ...) v

	#define isdefined7(macro) isdefined7_(macro)
	#define isdefinedtest7_7 ,
	#define isdefined7_(value) isdefined7__(isdefinedtest7_##value)
	#define isdefined7__(comma) isdefined7___(comma 1, 0)
	#define isdefined7___(_, v, ...) v

	#define isdefined8(macro) isdefined8_(macro)
	#define isdefinedtest8_8 ,
	#define isdefined8_(value) isdefined8__(isdefinedtest8_##value)
	#define isdefined8__(comma) isdefined8___(comma 1, 0)
	#define isdefined8___(_, v, ...) v

	#define isdefined9(macro) isdefined9_(macro)
	#define isdefinedtest9_9 ,
	#define isdefined9_(value) isdefined9__(isdefinedtest9_##value)
	#define isdefined9__(comma) isdefined9___(comma 1, 0)
	#define isdefined9___(_, v, ...) v



	#endif


