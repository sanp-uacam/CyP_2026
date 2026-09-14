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
  pthread_t cocinero, mesero_1, mesero_2;

  sem_init(&sem1, 0, 0);

  pthread_create (&cocinero, NULL, *cocinar, NULL);
  pthread_create (&mesero_1, NULL, *servir, NULL);
  pthread_create (&mesero_2, NULL, *servir, NULL);

  pthread_join(cocinero, NULL);
  pthread_join(mesero_1, NULL);
  pthread_join(mesero_2, NULL);

  // printf("Contador %d \n", counter);

  return 0;
}

static void * cocinar(void* arg) {
  for (int i = 0; i < NR_LOOP; i++)
  {
    // sem_wait(&sem1);
    // sem_post(&sem1);
    counter++;
    printf("COCINERO: Comida preparada.Platillos en espera: %d \n", counter);
    sem_post(&sem1);
    usleep(500000);
  }
  
}

static void * servir(void* arg) {
  for (int i = 0; i < NR_LOOP/2; i++)
  {
    sem_wait(&sem1);
    counter--;
    printf("MESERO: Comida servida. Platillos en espera: %d \n", counter);
    sleep(2);
  }
  
}
