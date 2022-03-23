#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define size 5000

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

int main ()
{
    clock_t begin = clock();
    srand(time(NULL));
    int hist[size] = {0};
    int counter = 0;
    int i,j;
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
    clock_t end = clock();
    printHistogram(hist);
    printf("Execution time: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;

}