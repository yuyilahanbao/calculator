#ifndef	_FRACTION_H_
#define _FRACTION_H_

typedef struct{
	int numerator;
	int denominator;
	/*keep gdb(numerator,denominator)=1*/
}fraction;
/*fraction in lowest terms*/

void rdctn_cmmn(fraction *a,fraction *b);
void fra_rdctn(fraction *a);
int gdb(int a,int b);

void init_fra(fraction *a);
void fra_to_deci(char *s,fraction *a);
void fra_print(fraction *a);
/*the s must be large enough to store the answer.*/

void fra_add(fraction *r,fraction a,fraction b);
void fra_minus(fraction *r,fraction a,fraction b);
void fra_mlt(fraction *r,fraction a,fraction b);
void fra_div(fraction *r,fraction a,fraction b);

#endif
