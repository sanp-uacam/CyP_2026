#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NR_LOOP 10
static void * cocinar(void* arg);
static void * servir(void* arg);

static int counter = 0;

sem_t sem1;

int main(void)
{
  pthread_t cocinero, mesero;

  sem_init(&sem1, 0, 0);

  pthread_create (&cocinero, NULL, *cocinar, NULL);
  pthread_create (&mesero, NULL, *servir, NULL);

  pthread_join(cocinero, NULL);
  pthread_join(mesero, NULL);

  printf("Contador %d \n", counter);

  return 0;
}

static void * cocinar(void* arg) {
  for (int i = 0; i < NR_LOOP; i++)
  {
    // sem_wait(&sem1);
    // counter++;
    // sem_post(&sem1);
    printf("COCINERO: Comida preparada \n");
    sem_post(&sem1);
    sleep(1);
  }
  
}

static void * servir(void* arg) {
  for (int i = 0; i < NR_LOOP; i++)
  {
    sem_wait(&sem1);
    printf("MESERO: Comida servida \n");
  }
  
}