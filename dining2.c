#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#define NUM 5

sem_t fork[NUM];
time_t start, end;
double result;
// 8960, 21992, 17794, 30456, 9790
void pick_up(int fork_n) { sem_wait(&fork[fork_n % NUM]); }
void put_down(int fork_n) { sem_post(&fork[fork_n % NUM]); }
void eating(int phil_n) { printf("philosopher %d is eating\n", phil_n); }
void thinking(int phil_n) { printf("philosopher %d is thinking\n", phil_n); }

void *philosopher(void *arg) {
  int phil_num = (int)arg;
  int N = 100;
  start = clock();
  while (N--) {
    if (phil_num == 4) {
      pick_up(phil_num + 1);
      printf("phil %d picks up fork %d\n", phil_num, (phil_num + 1) % NUM);
      pick_up(phil_num);
      printf("phil %d picks up fork %d\n", phil_num, phil_num);
    } else {
      pick_up(phil_num);
      printf("phil %d picks up fork %d\n", phil_num, phil_num);
      pick_up(phil_num + 1);
      printf("phil %d picks up fork %d\n", phil_num, (phil_num + 1) % NUM);
    }
    eating(phil_num);
    put_down(phil_num);
    printf("phil %d puts down fork %d\n", phil_num, phil_num);
    put_down(phil_num + 1);
    printf("phil %d puts down fork %d\n", phil_num, (phil_num + 1) % NUM);
    thinking(phil_num);
    end = clock();
    result = (double)(end - start);
    printf("time: %f", result);
  }

  pthread_exit(0);
}

int main() {
  pthread_t phil[NUM];

  for (int i = 0; i < 5; i++)
    sem_init(&fork[i], 0, 1);

  for (int i = 0; i < 5; i++)
    pthread_create(&phil[i], NULL, philosopher, (void *)i);

  for (int i = 0; i < 5; i++)
    pthread_join(&phil[i], NULL);

  return 0;
}