#include<>
int main()
{
	int v=99;
	pid_t pid;
	pid=vfork();
	if (pid<0)
	{
		perror("vfork failed!\n");
		exit(-1);	
	}
	else if(pid==0)
}


