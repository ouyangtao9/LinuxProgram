#include "my.h"

int main()
{
	pid_t pid;
	int k, status;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!"\n);
		return -1;
	}
	else if(pid==0)
	{
		printf("child %d : running!", getpid());
		exit(120);
	}
	else
	{
		if((k=wait(&statusr))!=0)
		{
			if(WEXITED(status))
				printf("child wxit with exit!\nexit code=%d\n", WEXITSTATUS(status));
			else if(WEXITSIGNALED(status))
				printf("child terminatated with signal!\nsignal number= %d\n", WTERMSIG(status));
		}
		exit(0);	
	}
}
