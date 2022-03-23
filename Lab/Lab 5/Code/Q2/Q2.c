#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define size 500000

int getRandomNumber(){
    return rand() % 99;     
}

void printHistogram(int *hist){
    int i,j;
    for (i = 0 ; i < size ; i++){
        for (j = 0 ; j < hist[i] ; j++){
            printf("*");
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    clock_t begin = clock();
    srand(time(NULL));
    int hist[size] = {0};
    int counter = 0;
    int i,j;
    int fd[2];  
    pipe(fd);
    if (fork() != 0) {        
        close(fd[0]);
        for (i = 0 ; i < size ; i++){
            for (j = 0 ; j < size/2 ; j++){
                int temp = getRandomNumber();
                if (temp < 33){
                    counter --;
                }
                else if (temp > 32 && temp < 66){
                    counter = counter;
                }
                else if(temp > 65 && temp < 99){
                    counter ++;
                }
            }
            hist[(size/2) + counter] += 1;
            counter = 0;
    }

        write(fd[1], &hist, sizeof(hist));     
        close(fd[1]);
    }
    else {
        read(fd[0], &hist, sizeof(hist));
        for (i = 0 ; i < size ; i++){
            for (j = 0 ; j < size/2 ; j++){
                int temp = getRandomNumber();
                if (temp < 33){
                    counter --;
                }
                else if (temp > 32 && temp < 66){
                    counter = counter;
                }
                else if(temp > 65 && temp < 99){
                    counter ++;
                }
            }
            hist[(size/2) + counter] += 1;
            counter = 0;
    }

        write(fd[0], &hist, sizeof(hist));
        close(fd[0]);
    }
    clock_t end = clock();
    //printHistogram(hist);
    printf("Execution time: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}