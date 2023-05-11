#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insSort(int []);
void selSort(int []);
void tampil(int []);
void tukar(int *, int *);
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int pilih;
    int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    puts("MENU METODE SORTING");
    printf("1. Insertion Sort\n2. Selection Sort\n3. Keluar");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        printf("Sebelum Insertion Sort: ");
        tampil(a);
        insSort(a);
        printf("Sesudah Insertion Sort: ");
        tampil(a);
        puts("");
        break;
    case 2:
        printf("Sebelum Selection Sort: ");
        tampil(a);
        selSort(a);
        printf("Sesudah Selection Sort: ");
        tampil(a);
        puts("");
        break;
    case 3:
        exit(0);
    default:
        puts("Pilihan salah");
        break;
    }
}

void insSort(int x[])
{
    int i, j, key;

    for(i = 1; i < MAX; i++)
    {
        key = x[i];
        j = i - 1;
        while(x[j] > key && j >= 0)
        {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }
}

void selSort(int x[])
{
    int i, j, min;
    for(i = 0; i < MAX - 1; i++)
    {
        min = i;
        for(j = i+1; j < MAX; j++)
        {
            if(x[j] < x[min])
            {
                min = j;
            }
        }
        tukar(&x[min], &x[i]);
    }
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int x[])
{
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}
