#include "lib.h"

int main(){
	int a[NUM];
	void *handle;
	void (*f1)();
	int (*f2)(), (*f3)();
	char *error;

	handle = dlopen("/home/ouy/a/linuxprogram/week6/code/dynamiclib/libdyna.so", RTLD_LAZY);

	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	f1= dlsym(handle, "cre_table");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	f2= dlsym(handle, "max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	
	f3= dlsym(handle, "sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	
	f1(a, NUM);
	printf("MAX=%d\n", f2(a, NUM));
	printf("SUM=%d\n", f3(a, NUM));
	if(dlclose(handle)<0){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	return 0;
}
