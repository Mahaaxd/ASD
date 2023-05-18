#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 10

//fungsi searching
void bin(int [], int, int);
void seq(int []);
//fungsi sorting
void quicksort(int [], int, int);
int partisi(int [], int, int);
void tukar(int *, int *);
//fungsi menu
void generate(int []);
void menu(int []);
void tampil(int []);

int n, key;
time_t t, t1, t2;

int main()
{
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);

    int a[n];
    generate(a);
    //tampil(a);

    menu(a);
    return 0;
}

void menu(int a[])
{
    int pilih;
    do{
        printf("MENU SEARCHING\n1. Sequence Unsorted\n2. Sequence Sorted\n3. Biner Sorted\n4. Keluar\nMasukkan pilihan : ");
        scanf("%d",&pilih);
        switch(pilih)
        {
        case 1:
            time(&t1);
            seq(a);
            time(&t2);
            tampil(a);
            break;
        case 2:
            time(&t1);
            quicksort(a, 0, n-1);
            seq(a);
            time(&t2);
            tampil(a);
            break;
        case 3:
            time(&t1);
            quicksort(a, 0, n-1);
            bin(a, 0, n-1);
            time(&t2);
            tampil(a);
            break;
        case 4:
            exit(0);
        }
    }while(pilih != 4);
}

void seq(int a[]){
    int i, found, sum;
    sum = 0;
    i = 0;
    found = 0;
    printf("Angka yang dicari : ");
    scanf("%d",&key);
    while(i < n){
        //found = 0;
        if(a[i] == key){
            found = 1;
            sum++;
        }
        i++;
    }
    if(found)
        printf("Angka %d ditemukan pada array dan muncul sebanyak %d kali\n", key, sum);
    else
        printf("Angka %d tidak ditemukan pada array.\n", key);
}

void bin(int a[], int l, int r){
    int m, found, sum;
    sum = 0;
    m = (l+r) / 2;
    found = 0;

    printf("Bilangan yang dicari : ");
    scanf("%d",&key);

    while(l <= r && !found){
        m = (l+r) / 2;
        if(a[m] == key)
            found = 1;
        if(a[m] > key)
            r = m-1;
        if(a[m] < key)
            l = m+1;
    }

    if(found)
        printf("Angka %d berada pada indeks [%d]", key, m);
    else
        printf("Angka %d tidak ada dalam array",key);

}

void generate(int a[])
{
    srand((unsigned)time(&t));

    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }

}


void quicksort(int x[], int p, int r)
{
    int q;

    if(p < r)
    {
        q = partisi(x, p, r);
        quicksort(x, p, q);
        quicksort(x, q+1, r);
    }
}

int partisi(int x[], int p, int r)
{
    int pivot, i, j;

    pivot = x[p];
    i = p;
    j = r;

    while(i < j)
    {
        while(x[j] > pivot)
            j--;
        while(x[i] < pivot)
            i++;

        if(i<j)
        {
            tukar(&x[i], &x[j]);
            i++;
            j--;
        }
        else
            return j;
    }
    return j;
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
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\nWaktu : %ld\n\n",t2-t1);
}

