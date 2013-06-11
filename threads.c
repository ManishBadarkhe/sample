#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>


void print_message_function ( void *ptr );
void write_message_function ( void *ptr );
void read_message_function ( void *ptr );

/* struct to hold data to be passed to a thread
   this shows how multiple data items can be passed to a thread */
typedef struct str_thdata
{
	int thread_no;
	char message[100];
} thdata;


thdata data;
sem_t my_semaphore;	     /* Semaphore operations */			

int main()
{
	pthread_t thread1, thread2;  /* thread variables */
	thdata data1, data2;         /* structs to be passed to threads */


	/* initialize data to pass to thread 1 */
	data1.thread_no = 1;
	strcpy(data1.message, "Hello!");

	/* initialize data to pass to thread 2 */
	data2.thread_no = 2;
	strcpy(data2.message, "Hi!");

	sem_init(&my_semaphore,0,1); /* Binary semaphore and its local */	

	/* create threads 1 and 2 */    
	pthread_create (&thread1, NULL, (void *) &write_message_function, (void *) &data);
	pthread_create (&thread2, NULL, (void *) &read_message_function, (void *) &data);

	/* Main block now waits for both threads to terminate, before it exits
	   If main block exits, both threads exit, even if the threads have not
	   finished their work */ 
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	/* exit */  
	exit(0);
}

void write_message_function ( void *ptr )
{
	thdata *temp;            
	temp = (thdata *) ptr;  /* type cast to a pointer to thdata */
	
	strcpy(temp->message, "Hello Manish!");
	temp->thread_no = 12;	

	/* do the work */
	printf("Thread %d says %s \n", temp->thread_no, temp->message);

	pthread_exit(0); /* exit */	
}

void read_message_function ( void *ptr )
{
	thdata *temp;            
	temp = (thdata *) ptr;  /* type cast to a pointer to thdata */

	sem_wait(&my_semaphore);
	/* do the work */
	printf("Thread %d says %s \n", temp->thread_no, temp->message);
	sem_post(&my_semaphore);

	pthread_exit(0); /* exit */	
}
