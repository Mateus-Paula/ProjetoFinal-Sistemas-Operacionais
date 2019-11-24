#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
// 64kB stack

#define MAXTHREAD 100

struct c {
int saldo;
};

typedef struct c conta;
conta from, to;

struct thread_data{
int thread_id;
int valor;
};

struct thread_data thread_data_array[MAXTHREAD];

//int valor;

// The child thread will execute this function
void *transferencia( void *arg)
{
struct thread_data *mydata;
mydata = (struct thread_data *)arg;

printf("Iniciando transferencia %d! ........\n ", mydata->thread_id+1);


if (from.saldo >= mydata->valor){ // 2
from.saldo -= mydata->valor;
to.saldo += mydata->valor;

printf("Transferência %d concluída com sucesso!\n Saldo c1: %d - Saldo c2: %d \n", mydata->thread_id, from.saldo, to.saldo);

}
else{
   
   printf("Transferência %d nao realizada. C1 sem saldo.\n Saldo c1: %d - Saldo c2: %d \n", mydata->thread_id, from.saldo, to.saldo);
 
}
pthread_exit(0);
//return 0;
}


// deposito

void *deposito( void *arg)
{
struct thread_data *mydata2;
mydata2 = (struct thread_data *)arg;

printf("Iniciando... deposito %d !\n", mydata2->thread_id);


if (to.saldo >= mydata2->valor){ // 2
to.saldo -= mydata2->valor;
from.saldo += mydata2->valor;

printf("Deposito %d concluída com sucesso!\n Saldo c1: %d - Saldo c2: %d \n", mydata2->thread_id, from.saldo, to.saldo);

}
else{
   
     printf("deposito %d nao realizada!. Saldo de C2 insuficiente\n", mydata2->thread_id);
}
pthread_exit(0);
//return 0;
}

int main()
{

int i;
int cont=0, cont2 =0;
from.saldo = 200;
to.saldo = 200;
printf( "Transferindo valores entre contas c1 e c2 \n" );
printf( "Saldo inicial c1: %d \n", from.saldo );
printf( "Saldo inicial c2: %d \n", to.saldo );
printf("***************\n");


pthread_t threads[MAXTHREAD];
pthread_t threads2[10];
for (i = 0; i < MAXTHREAD; i++) {
  thread_data_array[i].thread_id = i;
  thread_data_array[i].valor = 10;
 
  pthread_create(&threads[i],NULL,transferencia,(void *)&thread_data_array[i]);
 
  cont += 1;
  if (cont == 10) {
   pthread_create(&threads2[cont2],NULL,deposito,(void *)&thread_data_array[i]);
   cont = 0;
   cont2 += 1;
  }
}

for (i=0; i < MAXTHREAD; i++) {
  pthread_join(threads[i],NULL);
 
}

for (i=0; i<cont2; i++) {
  pthread_join(threads2[i],NULL);

}
return 0;
}
