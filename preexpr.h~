#ifndef	_PREEXPR_H_
#define _PREEXPR_H_

#include"fraction.h"
int get_prio(char a);
int cmp_op(char a,char b);
/*将pre_op栈顶弹出到pre_expr*/
void to_pre(char *a);/*中缀转前缀 mid->pre*/
void oper(fraction *a,fraction *b,char op); /*result will store at b*/
void get_pre_val(fraction *r,char *a);
void get_mid_val(fraction *r,char *a); /*a will be changed,so backup a at call it.a:mid->pre*/


#endif
