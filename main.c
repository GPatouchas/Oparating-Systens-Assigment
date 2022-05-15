#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "header.h" 
pthread_mutex_t lock;
pthread_cond_t cond;

int row = 1;
int num = 1;

struct 
{
    int row_number;
    int seat_number;
    int available = 0;
    
};seat

void init() {
    if (seat_number == 10){
        row_number = row_number + 1;
        seat_number = 1;
    }else{
        seat_number++;
    }
}

int resources = phones;
seat pin[front_rows+back_rows][seats_per_row]; // defining array of seats

int main(int argc, char *argv[]) { // main
    // error handling
    if (argc < 2 || argc > 2) {return -1;}

    // type casting
    int number_of_threads = atoi(argv[1]);
    int seed = atoi(argv[2]);

    // initialization
    int id[number_of_threads];
    int rc;
    pthread_t threads[number_of_threads]; // thread array
    pthread_mutex_init(&lock, NULL); // mutex initialization
    pthread_cond_init(&cond, NULL);  //
    

    // thread creation
    for (int i = 0; i < number_of_threads; i++) {
        id[i] = i+1;
        printf("Creating Thread %d...\n", i+1);
        rc = pthread_create(&threads[i], NULL, booking, &id[i]);
    }

    // joining threads
    for (int i = 0; i < number_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock); // deleting mutex
    pthread_cond_destroy(&cond); // deleting condition
} // main end

    void *booking(void *x) { // main function for threads
        int id = *(int *)x;
        int rc;
        printf("The customer %d is on the line\n",id);
        rc = pthread_mutex_lock(&lock); // lock
        while (resources == 0) {
            printf("The customer %d is waiting on the line...\n", id);
            rc = pthread_cond_wait(&cond, &lock);
        }

        printf("The customer %d is being serviced.\n%d", id);
        resources--; // using the resource
        rc = pthread_mutex_unlock(&lock); // unlock
        sleep(5); //do something else

        rc = pthread_mutex_lock(&lock); // lock
        printf("The customer %d was serviced succesfully \n", id);
        resources++; // add resource back

        rc = pthread_cond_signal(&cond); // signal condition
        rc = pthread_mutex_unlock(&lock); // pthread_mutex_unlock
        pthread_exit(NULL); // quit thread

    } // main function for threads


