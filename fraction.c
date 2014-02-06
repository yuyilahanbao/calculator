#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"fraction.h"

void swap(void *a,void *b)
{
	int static t;
	t = *(int*)a;
	*(int*)a = *(int*)b;
	*(int*)b = t;
}

int max(int a,int b)
{
	if (a > b) return a; else return b;
}

void rdctn_cmmn(fraction *a,fraction *b)
{
	int max,t;
	max = gdb(a->denominator,b->denominator);

	t = b->denominator/max; max = a->denominator/max;
	a->numerator *= t; a->denominator *= t;

	t = max;
	b->numerator *= t; b->denominator *= t;
}

void fra_add(fraction *r,fraction a,fraction b)
{
	rdctn_cmmn(&a,&b);
	r->numerator = a.numerator+b.numerator;
	r->denominator = a.denominator;
	fra_rdctn(r);
}

void fra_minus(fraction *r,fraction a,fraction b)
{
	rdctn_cmmn(&a,&b);
	r->numerator = a.numerator-b.numerator;
	r->denominator = a.denominator;
	fra_rdctn(r);
}

void fra_mlt(fraction *r,fraction a,fraction b)
{
	swap(&a.denominator,&b.denominator);
	fra_rdctn(&a); fra_rdctn(&b);
	r->numerator = a.numerator*b.numerator;
	r->denominator = a.denominator*b.denominator;
}

void fra_div(fraction *r,fraction a,fraction b)
{
	swap(&a.denominator,&b.numerator);
	fra_rdctn(&a); fra_rdctn(&b);
	r->numerator = a.numerator*b.denominator;
	r->denominator = a.denominator*b.numerator;
}

int count(int a,int div)
{
	int num;
	num = 0;
	while (a%div == 0) {
		num++;
		a /= div;
	}
	return num;
}

void fra_to_deci(char *s,fraction *a) //the s must be large enough to store the answer.
{
	int div,b,num;
	b = a->numerator; div = a->denominator;
	sprintf(s,"%d",b/div); s += strlen(s);
	if ((b %= div) == 0) {
		*s = 0;
		return;
	}
	b *= 10;
	*s++ = '.';
	num = count(div,2); num = max(num,count(div,5));
	while (num) {
		num--;
		*s++ = b/div+'0';
		b = b%div*10;
	}
	if (b == 0) {
		*s = 0;
		return;
	}
	num = b; *s++ = '(';
	do {
		*s++ = b/div+'0';
		b = b%div*10;
	} while (num != b);
	*s++ = ')'; *s++ = 0;
}

void init_fra(fraction *a)
{
	scanf("%d %d",&a->numerator,&a->denominator);
	fra_rdctn(a);
}

int gdb(int a,int b)
{
	if (b) return gdb(b,a%b); else return a;
}

void fra_rdctn(fraction *a)
{
	int max;
	max = gdb(a->denominator,a->numerator);
	a->denominator /= max;
	a->numerator /= max;
}

void fra_print(fraction *a)
{
	if (abs(a->denominator) != 1)
		printf("%d/%d\n",a->numerator,a->denominator);
	else
		printf("%d\n",a->numerator/a->denominator);
}
