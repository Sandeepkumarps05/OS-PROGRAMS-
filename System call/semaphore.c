#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

#define NUM_THREADS 5
#define MAX_RESOURCES 3

int resources = MAX_RESOURCES;
sem_t semaphore;

void *thread_func(void *thread_id) {
    int tid = *((int *)thread_id);

    sem_wait(&semaphore);

    if (resources > 0) {
        printf("Thread %d is using a resource. Remaining: %d\n", tid, resources - 1);

        resources--;

        sem_post(&semaphore);
        sleep(1);

        sem_wait(&semaphore);
        resources++;
        printf("Thread %d finished using a resource. Remaining: %d\n", tid, resources);
    } else {
        printf("Thread %d cannot use resources\n", tid);
        sem_post(&semaphore);
    }

    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    sem_init(&semaphore, 0, 1);

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&thread[i], NULL, thread_func, (void *)&thread_ids[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
