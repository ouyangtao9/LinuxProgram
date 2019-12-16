#include"my.h"
static int sig_cnt[NSIG];
static volatile sig_atomic_ get_SIGINT=0;
void handler(int signo)
{
if(signo==SIGINT)
	get_SIGINT=1;
else
	sig_cnt[signo]++;
}

int main(int argc, char *argv[])
{
int i=0;
sigset_t blockall_mask;
sigset_t empty_mask;
printf("%s:PID is %d\n", argv[0], getpid());
printf("NSIG=%d\n", NSIG);

for(i=1; i<NSIG; i++)
{
if(i==SIGKILL || i==SIGSTOP || i==32 || i==33)
continue;
if(signal(i,&handler)==SIG_ERR)
fprintf(stderr, "signal for signo(%d) faild (%s)\n", strerror(errno));
}

if(argc>1)
{
int sleep_time=atoi(argv[1]);
sigfillset(&blockall_mask);
if(sigprocmask(SIG_SETMASK, &blockall_mask, NULL)==-1)
{
fprintf(stderr, "setprocmask to block all signal faied (%s)\n", strerror(errno));
return -2;
}
printf("I will sleep %d second\n", sleep_time);
sleep(sleep_time);
sigemptyset(&empty_mask);
if(sigprocmask(SIG_SETMASK, &empty_mask, NULL)==-1)
{
fprintf(stderr, "setprocmask to release all signal failed (%s)");
}
}


}
