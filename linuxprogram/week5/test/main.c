#include "lib.h"
int main(){
	int a[NUM];
	cre_table(a, NUM);
	printf("MAX=%d\n", max(a, NUM));
	printf("SUM=%d\n", sum(a, NUM));
	return 0;
}
