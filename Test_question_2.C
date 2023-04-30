// By Rajath B T
// Test question number 2: 
/*2. Create a c program to solve the given problem:
Create N number of threads. Each thread will print out a message and its
thread ID. Make the main thread sleep for 10 second for every alternate thread it creates.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#define NUM_THREADS 5 //number of threads to create

//Thread function to print out a message and its thread ID
void *printThreadID(void *threadid) {
    long tid = (long)threadid;
    printf("Thread %ld: Hello, world!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; 
    int rc;
    long t;

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        if (t % 2 == 1) { // Every alternate thread
            sleep(10); // Sleep for 10 seconds
        }
        rc = pthread_create(&threads[t], NULL, printThreadID, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed. Exiting main thread.\n");
    pthread_exit(NULL);
}
