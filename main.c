#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include"fraction.h"
#include"preexpr.h"

void print_help()
{
	system("cat README");
}

int main(int argc,char *argv[])
{
	fraction a;
	int flag;
	if ((argc == 2) && ((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"--help") == 0))) {
		print_help(); return 0;
	}
	char s[30000];
	scanf("%d",&flag);
	switch (flag){
		case 0:
			while (scanf("%s",s) == 1) {
				get_mid_val(&a,s);
				fra_print(&a);
			}
			break;
		case 1:
			init_fra(&a);
			fra_to_deci(s,&a);
			printf("%s",s);
			break;
	}
	return 0;
}
