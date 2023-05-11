#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void selSort(int []);
void tampil(int []);
void tukar(int *, int *);

int swap, comparison, movement;

int main() {
    int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    //int a[MAX] = {1,2,3,4,5,9,7,6,8,10};
    //int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    //int a[MAX] = {10,9,8,7,6,5,4,3,2,1};
    printf("Selection Sort\nSebelum :");
    tampil(a);
    selSort(a);
    printf("\nSetelah :");
    tampil(a);
    return 0;
}

void selSort(int x[]){
    int i, j, min;
    for(i = 0; i < MAX - 1; i++){
        min = i;
        swap++;
        for(j = i+1; j < MAX; j++){
            if(x[j] < x[min]){
                min = j;
            }
        }
        tukar(&x[min], &x[i]);
        comparison+=3;
    }
}

void tukar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int x[]){
    for(int i = 0; i < MAX; i++){
        printf(" %d", x[i]);
    }
    printf("\nHasil Swap \t: %d\nHasil Comparison \t: %d\n",swap,comparison);
}
