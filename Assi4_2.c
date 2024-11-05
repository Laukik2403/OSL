#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t wr, mutex;
int a = 10, readcount = 0;

void *reader(void *arg) {
    long int num = (long int)arg;

    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
        pthread_mutex_lock(&wr);
    pthread_mutex_unlock(&mutex);

    printf("Reader %ld is in critical section\n", num);
    printf("Reader %ld reads the data: %d\n", num, a);
    sleep(1);

    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0)
        pthread_mutex_unlock(&wr);
    pthread_mutex_unlock(&mutex);

    printf("Reader %ld left critical section\n", num);
    return NULL;
}

void *writer(void *arg) {
    long int num = (long int)arg;

    pthread_mutex_lock(&wr);

    printf("Writer %ld is in critical section\n", num);
    a++;
    printf("Writer %ld writes data: %d\n", num, a);
    sleep(1);

    pthread_mutex_unlock(&wr);

    printf("Writer %ld left the critical section\n", num);
    return NULL;
}

int main() {
    pthread_t r[10], w[10];
    int nor, now;

    // Initialize mutex variables
    pthread_mutex_init(&wr, NULL);
    pthread_mutex_init(&mutex, NULL);

    // Read the number of readers and writers
    printf("Enter the number of readers and writers: ");
    scanf("%d %d", &nor, &now);

    // Create reader threads
    for (int i = 0; i < nor; i++)
        pthread_create(&r[i], NULL, reader, (void *)(long)i);

    // Create writer threads
    for (int j = 0; j < now; j++)
        pthread_create(&w[j], NULL, writer, (void *)(long)j);

    // Join reader threads
    for (int i = 0; i < nor; i++)
        pthread_join(r[i], NULL);

    // Join writer threads
    for (int j = 0; j < now; j++)
        pthread_join(w[j], NULL);

    // Destroy mutex variables
    pthread_mutex_destroy(&wr);
    pthread_mutex_destroy(&mutex);

    return 0;
}
