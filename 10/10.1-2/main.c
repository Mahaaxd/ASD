#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insSort(int []);
void tampil(int []);
void tukar(int *, int *);

int swap, comparison, movement;

int main() {
    //int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    //int a[MAX] = {1,2,3,4,5,9,7,6,8,10};
    //int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int a[MAX] = {10,9,8,7,6,5,4,3,2,1};
    printf("Insertion Sort\nSebelum :");
    tampil(a);
    insSort(a);
    printf("\n\nSetelah :");
    tampil(a);
    return 0;
}

void insSort(int x[]){
    int i, j, key;
    swap++;
    for(i = 1; i < MAX; i++){
        key = x[i];
        j = i - 1;
        while(x[j] > key && j >= 0){
            x[j+1] = x[j];
            comparison++;
            movement++;
            j--;
        }
        x[j+1] = key;
        ;
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
    printf("\nHasil Swap \t: %d\nHasil Movement \t: %d\nHasil Comparison: %d",swap,movement,comparison);
}
