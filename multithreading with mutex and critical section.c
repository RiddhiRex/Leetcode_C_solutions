//C program with multithreads and synchronization between the threads and mutex and critical section:
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int counter = 0;

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    
    // Critical section: increment counter
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread %d: Counter incremented to %d\n", thread_id, counter);
    pthread_mutex_unlock(&mutex);
    
    // Simulate some work
    sleep(1);
    
    // Critical section: decrement counter
    pthread_mutex_lock(&mutex);
    counter--;
    printf("Thread %d: Counter decremented to %d\n", thread_id, counter);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    
    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    return 0;
}
