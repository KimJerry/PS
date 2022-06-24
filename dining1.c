#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#define NUM 5

sem_t fork[NUM];
sem_t once;
time_t start, end;
double result;
void pick_up(int fork_n) { sem_wait(&fork[fork_n % NUM]); }
void put_down(int fork_n) { sem_post(&fork[fork_n % NUM]); }
void eating(int phil_n) { printf("philosopher %d is eating\n", phil_n); }
void thinking(int phil_n) { printf("philosopher %d is thinking\n", phil_n); }
// 37581, 21017, 8874, 15575, 13187
void *philosopher(void *arg) {
  int phil_num = (int)arg;
  int N = 1000;
  start = clock();
  while (N--) {
    sem_wait(&once);
    pick_up(phil_num);
    printf("phil %d picks up fork %d\n", phil_num, phil_num);
    pick_up(phil_num + 1);
    printf("phil %d picks up fork %d\n", phil_num, (phil_num + 1) % NUM);
    sem_post(&once);
    eating(phil_num);
    put_down(phil_num);
    printf("phil %d puts down fork %d\n", phil_num, phil_num);
    put_down(phil_num + 1);
    printf("phil %d puts down fork %d\n", phil_num, (phil_num + 1) % NUM);
    end = clock();
    result = (double)(end - start);
    printf("time: %f", result);
    thinking(phil_num);
  }

  pthread_exit(0);
}

int main() {
  pthread_t phil[NUM];

  for (int i = 0; i < 5; i++)
    sem_init(&fork[i], 0, 1);
  sem_init(&once, 0, 1);

  for (int i = 0; i < 5; i++)
    pthread_create(&phil[i], NULL, philosopher, (void *)i);

  for (int i = 0; i < 5; i++)
    pthread_join(&phil[i], NULL);

  return 0;
}