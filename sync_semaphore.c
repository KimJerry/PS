/**
 * 학번: 12181679
 * 이름: 정기은
 * 학과: 컴퓨터공학과
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define ITER 30

void *thread_increment(void *arg);
void *thread_decrement(void *arg);

int x;
sem_t s, empty, fill;

int main() {
  pthread_t tid1, tid2;
  sem_init(&s, 0, 1);
  sem_init(&empty, 0, 30);
  sem_init(&fill, 0, 0);
  pthread_create(&tid1, NULL, thread_increment, NULL);
  pthread_create(&tid2, NULL, thread_decrement, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  if (x != 0)
    printf("Boom! counter %d\n", x);
  else
    printf("OK counter = %d\n", x);

  sem_destroy(&s);
  sem_destroy(&empty);
  sem_destroy(&fill);
}

void *thread_increment(void *arg) {
  int i, val;
  for (i = 0; i < ITER; i++) {
    sem_wait(&empty);
    sem_wait(&s);
    val = x;
    printf("%u:     %d\n", (unsigned int)pthread_self(), val);
    x = val + 1;
    sem_post(&s);
    sem_post(&fill);
  }
  pthread_exit(NULL);
}

void *thread_decrement(void *arg) {
  int i, val;
  for (i = 0; i < ITER; i++) {
    sem_wait(&fill);
    sem_wait(&s);
    val = x;
    printf("%u:     %d\n", (unsigned int)pthread_self(), val);
    x = val - 1;
    sem_post(&s);
    sem_post(&empty);
  }
  pthread_exit(NULL);
}