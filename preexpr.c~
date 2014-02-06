#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"preexpr.h"
#include"fraction.h"
#define MAXL 2000
#define MAXN 300


int get_prio(char a)
{
	switch (a) {
		case '+':
		case '-':return 0;
		case '*':
		case '/':return 1;
		case '^':return 2;
	}
}

int cmp_op(char a,char b)
{
	return get_prio(a)-get_prio(b);
}

struct {
	char stack[MAXL];
	int r;
}pre_op;
struct {
	char stack[MAXL];
	int r;
}pre_expr;
struct {
	fraction stack[MAXN];
	int r;
}expr_val;

void eject_to()/*将pre_op栈顶弹出到pre_expr*/
{
	pre_expr.stack[pre_expr.r++] = pre_op.stack[--pre_op.r];
}

void put_num(char **a)
{
	pre_expr.stack[pre_expr.r++] = ' ';
	do {
		pre_expr.stack[pre_expr.r++] = **a;
		*a = (*a)-1;
	} while (isdigit(**a));
}

void to_pre(char *a)/*中缀转前缀 mid->pre*/
{
	char *b;
	b = strlen(a)+a-1;
	pre_op.r = pre_expr.r = 0;
	while (b >= a) {
		if ((*b) == '(') {
			while (pre_op.stack[pre_op.r-1] != ')')
				eject_to();
			pre_op.r--; b--;
		} else if ((*b) == ')') {
			pre_op.stack[pre_op.r++] = *b--;
		} else if (isdigit(*b)) {
			put_num(&b);
		} else {
			do {
				if ((pre_op.r == 0) || (pre_op.stack[pre_op.r-1] == ')') ||
						(cmp_op(*b,pre_op.stack[pre_op.r-1]) >= 0)) {
					pre_op.stack[pre_op.r++] = *b--;
					break;
				} else {
					eject_to();
				}
			}while(1); /*当*b还未入栈*/
		}
	}
	while (pre_op.r)
		eject_to();
	/*弹出pre_op栈中所有的元素到pre_expr*/
	/*反转pre_expr栈中的元素*/
	while (pre_expr.r)
		*a++ = pre_expr.stack[--pre_expr.r];
}

void oper(fraction *a,fraction *b,char op) /*result will store at b*/
{
	switch (op) {
		case '+':fra_add(b,*a,*b); return;
		case '-':fra_minus(b,*a,*b); return;
		case '*':fra_mlt(b,*a,*b); return;
		case '/':fra_div(b,*a,*b); return;
		case '^':return;
		default:return;
	};
}

int get_num(char **a)
{
	int static tmp,time;
	time = 1;
	*a = (*a)-1; tmp = 0;
	while (isdigit(**a)) {
		tmp = tmp+((**a)-'0')*time;
		time *= 10;
		*a = (*a)-1;
	};
	return tmp;
}

void get_pre_val(fraction *r,char *a)
{
	char *b;
	b = strlen(a)+a-1;
	expr_val.r = 0;
	while(b >= a) {
		if ((*b) == ' ') {
			expr_val.stack[expr_val.r].numerator = get_num(&b);
			expr_val.stack[expr_val.r++].denominator = 1;
		} else {
			oper(&expr_val.stack[expr_val.r-1],&expr_val.stack[expr_val.r-2],*b);
			expr_val.r--; b--;
		}
	};
	memcpy(r,expr_val.stack,sizeof(fraction));
}

void get_mid_val(fraction *r,char *a) /*a will be changed,so backup a at call it.a:mid->pre*/
{
	to_pre(a);
	get_pre_val(r,a);
}
