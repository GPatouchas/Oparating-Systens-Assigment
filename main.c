#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "header.h" 

pthread_mutex_t lock;
pthread_cond_t cond;

int money = 0;
int row = 1;
int num = 1;
int random;

int resources = phones;
int pin[front_rows+back_rows][seats_per_row]; // defining array of seats

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
    
    //initialize seat availability
    for(int rows = 0; rows<front_rows+back_rows;rows++){
        for(int seat_num = 0; seat_num <seats_per_row;seat_num++){
            pin[rows][seat_num] = 0;
        }
    }
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
        rand_r(&argv[2]+id)
        printf("The customer %d is on the line\n",id);
        rc = pthread_mutex_lock(&lock); // lock
        while (resources == 0) {
            printf("The customer %d is waiting on the line...\n", id);
            rc = pthread_cond_wait(&cond, &lock);
        }

        printf("The customer %d is being serviced.\n%d", id);
        resources--; // using the resource

        srand(time(NULL));
        int tickets = rand() % seatHigh + seatLow;
        int row_selection = row_generator();

        for(int i=1; i<=10;i++){
            if(pin[row_selection][i]= 1 ){
                    continue;
            for(int j= i+1; j<=tickets; j++){
                if(pin[row_selection][j] = 1){
                    break;
                }
            }
        }


        rc = pthread_mutex_unlock(&lock); // unlock
        rc = pthread_mutex_lock(&lock); // lock



        printf("The customer %d was serviced succesfully \n", id);
        resources++; // add resource back
        
        random = (rand() % (tHigh - tSlow + 1)) + tSlow;//genarate random number
        rc = pthread_cond_signal(&cond); // signal condition
        rc = pthread_mutex_unlock(&lock); // pthread_mutex_unlock
        sleep(random)//sleep for that random random
        pthread_exit(NULL); // quit thread

    } // main function for threads

    int row_generator(){
        srand(time(NULL));
        float prob = (float) rand() / RAND_MAX;

        if(prob <= 0.3){
            srand(time(NULL));
            int row_choice = rand() % front_rows;
        }else{
            int row_choice = rand() % 20+10;
        }

        return row_choice;
    }


