#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *printMessage(void *ptr);

int main()
{
	pthread_t thread1, thread2;
	char *message1 = "Marco ";
	char *message2 = "Polo\n";
	
	pthread_create(&thread1, NULL, printMessage, (void*) message1);
	pthread_create(&thread2, NULL, printMessage, (void*) message2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Smell ya later, dweebs\n");
	exit(0); 
}

void *printMessage(void *ptr){
	char *message;
	message = (char*) ptr;
	for(int i = 0 ; i<10; i++){
	printf("%s",message);
	sleep(1);
	}
}

