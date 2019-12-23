#include "my.h"

pthread_rwlock_t rwlock;
pthread_mutex_t mutex= PTHREAD_MUTeX-INITIALIZER;
int g=0;
void *fun(void *param)
{
  int i;
  pthread_rwlock_rdlock(&rwlock);
  for()
  {
    pthread_mutex_lock(&mutex);
    g++;
    pthread_mutex_unlock(&mutex);
  }
  pthread_rwlock_unlock(&rwlock);
  return NULL;
}

int main()
{
  pthread_t tid[NUM];
  int i, ret;
  
}
