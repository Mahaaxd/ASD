#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 25000

void menu(int []);
void insertion(int [], int);
void selection(int [], int);
void bubble(int [], int);
void shell(int [], int);
void print(int []);
void tukar(int *, int *);
void generate(int []);

int n;
time_t t;

int main()
{
    int array[MAX];
    generate(array);
    menu(array);
    return 0;
}

void generate(int a[]){
    srand((unsigned)time(&t));

    printf("Berapa jumlah data yang diinginkan (n <= 20.000) : ");
    scanf("%d",&n);

    if(n >= 20000){
        puts("Jumlah data terlalu banyak!");
        exit(0);
    }else{
         for(int i = 0; i < n; i++){
            a[i] = rand() % 1000;
        }
    }

}

void menu(int a[]){
    int pilih1, pilih2;
    //int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    //int a[MAX] = {1,2,3,4,5,9,7,6,8,10};
    //int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    //int a[MAX] = {10,9,8,7,6,5,4,3,2,1};
    printf("Metode Sort\n1. Insertion Sort\n2. Selection Sort\n3. Bubble Sort\n4. Shell Sort");
    printf("\nMasukkan Pilihan anda : ");
    scanf("%d",&pilih1);
    printf("\n");
    printf("Jenis Sort\n1. ASCENDING\n2. DESCENDING");
    printf("\nMasukkan Pilihan anda : ");
    scanf("%d",&pilih2);
    switch (pilih1)
    {
    case 1:
        insertion(a, pilih2);
        print(a);
        break;
    case 2:
        selection(a, pilih2);
        print(a);
        break;
    case 3:
        bubble(a, pilih2);
        print(a);
        break;
    case 4:
        shell(a, pilih2);
        print(a);
        break;
    default:
        printf("\nInput tidak valid");
        break;
    }
}

void insertion(int x[], int kondisi)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = x[i];
        j = i - 1;
        while(j >= 0 && (kondisi == 1 && x[j] > key) || (kondisi == 2 && x[j] < key) ){
                x[j+1] = x[j];
                j--;
        }
        x[j+1] = key;
    }

}

void selection(int x[], int kondisi)
{
    int i, j, min;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if((kondisi == 1 && x[j] < x[min]) || (kondisi == 2 && x[j] > x[min])){
                min = j;
            }
        }
        tukar(&x[min], &x[i]);
        
    }
    puts("");
}

void bubble(int x[], int kondisi)
{
    int i, pos_akhir, did_swap = 1;
    pos_akhir = n - 2;
    while(pos_akhir >= 0 && did_swap)
    {
        did_swap = 0;
        for(i = 0; i <= pos_akhir; i ++)
        {
            if((kondisi == 1 && (x[i] > x[i+1])) || (kondisi == 2 && (x[i] <  x[i+1]))){
                tukar(&x[i], &x[i+1]);
                did_swap = 1;
            }
        }
        //if(did_swap)
        //    print(x);
        pos_akhir--;
    }
}


void shell(int x[], int kondisi)
{
    int i, jarak, did_swap = 1;

    jarak = n;
    while(jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = 1;
        while(did_swap)
        {
            did_swap = 0;
            for(i = 0; i < (n - jarak); i ++)
            {
                if((kondisi == 1 && (x[i] > x[i+jarak])) || (kondisi == 2 && (x[i] < x[i+jarak]))){
                    tukar(&x[i], &x[i+jarak]);
                    did_swap = 1;
                    //swap++;
                    //c++;
                    //mov+=3;
                }
                //if(did_swap)
                //    print(x);
            }
        }
    }
}

void print(int x[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

