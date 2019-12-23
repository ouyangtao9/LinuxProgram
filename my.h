#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<limits.h>
#include<assert.h>
#include<err_exit.h>

#define check_error(return_val, msg)
{
  if(return_val != 0)
  {
    fprintf(stderr, "%s:%s\n", msg, strerror(return_val));
  }
}

#define LOOP 10000000
#define NUM 4
#define NI 100
