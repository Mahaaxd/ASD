#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void menu();
void bubble(int []);
void shell(int []);
void print(int []);
void tukar(int *, int *);

int main()
{
    menu();
    return 0;
}

void menu(){
    int pilih;
    //int a[MAX] = {3,10,4,6,8,9,7,2,1,5};
    //int a[MAX] = {1,2,3,4,5,9,7,6,8,10};
    //int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int a[MAX] = {10,9,8,7,6,5,4,3,2,1};
    printf("Metode Sort\n1. Bubble Sort\n2. Shell Sort");
    printf("\nMasukkan Pilihan anda : ");
    scanf("%d",&pilih);
    switch (pilih)
    {
    case 1:
        bubble(a);
        
        break;
    case 2:
        shell(a);
        
        break;
    default:
        break;
    }
}

void bubble(int x[])
{
    int i, pos_akhir, did_swap = 1;
    pos_akhir = MAX - 2;
    while(pos_akhir >= 0 && did_swap)
    {
        did_swap = 0;
        for(i = 0; i <= pos_akhir; i ++)
        {
            if(x[i] > x[i+1])
            {
                tukar(&x[i], &x[i+1]);
                did_swap = 1;
            }
        }
        if(did_swap)
            print(x);
        pos_akhir--;
    }
}


void shell(int x[])
{
    int i, jarak, did_swap = 1;

    jarak = MAX;
    while(jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = 1;
        while(did_swap)
        {
            did_swap = 0;
            for(i = 0; i < (MAX - jarak); i ++)
            {
                if(x[i] > x[i+jarak])
                {
                    tukar(&x[i], &x[i+jarak]);
                    did_swap = 1;
                    //swap++;
                    //c++;
                    //mov+=3;
                }
                if(did_swap)
                    print(x);
            }
        }
    }
}

void print(int x[])
{
    for(int i = 0; i < MAX; i++)
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
