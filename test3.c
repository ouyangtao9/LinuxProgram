#include"my.h"
void init_daemon(void);
int main()
{
	FILE *fp;
	time_t t;
	init_daemon();
	while(1)
	{
		sleep(10);
		if((fp=fopen("6-8.log", "a"))>=0)
		{
			t=time(0);
			fprintf(fp, "protect proc is running now, time is: %s", asctime(localtime(&t)));
			fclose(fp);
		}
	}
	return 0;
}

void init_daemon(void)
{
	pid_t child1, child2;
	int i;
	child1=fork();
	if(child1>0)
	{
		exit(0);	
	}
	else if(child1<0)
	{
		perror("failed to create child proc!");	
		exit(1);
	}
	setsid();
	chdir("/temp");
	umask(0);
	for(i=0; i<NOFILE; ++i);
	close(i);
	return;
}

