#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

//FUNGSI SORT
void insSort(int [], int);
void selSort(int [], int);
void tukar(int *, int *);
//FUNGSI MENU
void tampil(int []);
void menu();//
void menuMetodeIns(int []);
void menuMetodeSel(int []);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int pilih;
    //PILIHAN ARRAY :
    int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    //int a[MAX] = {1,2,3,4,5,9,7,6,8,10};
    //int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    //int a[MAX] = {10,9,8,7,6,5,4,3,2,1};
    puts("MENU METODE SORTING");
    printf("1. Insertion Sort\n2. Selection Sort\n3. Keluar");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        menuMetodeIns(a);
        break;
    case 2:
        menuMetodeSel(a);
        break;
    case 3:
        exit(0);
    default:
        puts("Pilihan salah");
        break;
    }
}

void menuMetodeIns(int a[])
{
    int pilih;
    puts("\nJENIS INSERTION SORT");
    printf("1. ASCENDING\n2. DESCENDING");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        printf("\nSebelum Insertion Sort: ");
        tampil(a);
        insSort(a, pilih);
        printf("Sesudah Insertion Sort: ");
        tampil(a);
        puts("");
        break;
    case 2:
        printf("\nSebelum Selection Sort: ");
        tampil(a);
        insSort(a, pilih);
        printf("Sesudah Selection Sort: ");
        tampil(a);
        puts("");
        break;
    default:
        puts("Pilihan salah");
        break;
    }
}

void menuMetodeSel(int a[])
{
    int pilih;
    puts("\nJENIS SELECTION SORT");
    printf("1. ASCENDING\n2. DESCENDING\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        printf("\nSebelum Selection Sort: ");
        tampil(a);
        selSort(a, pilih);
        printf("Sesudah Selection Sort: ");
        tampil(a);
        puts("");
        break;
    case 2:
        printf("\nSebelum Selection Sort: ");
        tampil(a);
        selSort(a, pilih);
        printf("Sesudah Selection Sort: ");
        tampil(a);
        puts("");
        break;
    default:
        puts("Pilihan salah");
        break;
    }
}


void insSort(int x[], int kondisi)
{
    int i, j, key;

    puts("");
    tampil(x);
    for(i = 1; i < MAX; i++)
    {
        key = x[i];
        j = i - 1;
        if(kondisi == 1)
        {
            while(x[j] > key && j >= 0)
            {
                x[j+1] = x[j];
                j--;
            }
        }
        else
        {
            while(x[j] < key && j >= 0)
            {
                x[j+1] = x[j];
                j--;
            }
        }
        x[j+1] = key;
        tampil(x);
    }
    puts("");
}

void selSort(int x[], int kondisi)
{
    int i, j, min;

    puts("");
    tampil(x);
    for(i = 0; i < MAX - 1; i++)
    {
        min = i;
        for(j = i+1; j < MAX; j++)
        {
            if(kondisi == 1)
            {
                if(x[j] < x[min])
                {
                    min = j;
                }
            }
            else{
                if(x[j] > x[min])
                {
                    min = j;
                }
            }
        }
        tukar(&x[min], &x[i]);
        tampil(x);
    }
    puts("");
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
