#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100000

void menu(int []);
void selection(int []);
void insertion(int []);
void bubble(int []);
void shell(int []);
void print(int []);
void tukar(int *, int *);
void mergesort();
void merge();
void quicksort();
void quick();
void generate(int []);

int n;
time_t t, t1, t2;



int main()
{
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);

    int data[n];

    generate(data);
    menu(data);
    return 0;
}

void generate(int a[]){
    srand((unsigned)time(&t));

    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }
}

void menu(int a[]){
    int pilih;
    printf("Metode Sort\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Shell Sort\n5. Merge Sort\n6. Quick Sort");
    printf("\nMasukkan Pilihan anda : ");
    scanf("%d",&pilih);
    switch (pilih)
    {
    case 1:
        //print(a);
        selection(a);
        //print(a);
        break;
    case 2:
        //print(a);
        insertion(a);
        //print(a);
        break;
    case 3:
        //print(a);
        bubble(a);
        //print(a);
        break;
    case 4:
        //print(a);
        shell(a);
        //print(a);
        break;
    case 5:
        //print(a);
        mergesort(0, n-1, a);
        //print(a);
        break;
    case 6:
        //print(a);
        quicksort(a, 0, n-1);
        //print(a);
        break;
    default:
        break;
    }
}

void mergesort(int l, int r, int x[]){
    int m;
    if(l<r){
        m = (l+r) / 2;
        mergesort(l, m, x);
        mergesort(m+1, r, x);
        merge(l, m, r, x);
    }

}

void merge(int l, int m, int r, int x[]){
    int ki1, ki2, ka1, ka2, temp[n], i, j;
    ki1 = l;
    ka1 = m;
    ki2 = m+1;
    ka2 = r;
    i = l;

    while(ki1 <= ka1 && ki2 <= ka2){
        if(x[ki1] < x[ki2]){
            temp[i] = x[ki1];
            ki1++;
        }
        else{
            temp[i] = x[ki2];
            ki2++;
        }
        i++;
    }

    while(ki1 <= ka1){
        temp[i] = x[ki1];
        i++;
        ki1++;
    }

    while(ki2 <= ka2){
        temp[i] = x[ki2];
        i++;
        ki2++;
    }

    j = l;
    while(j <= r){
        x[j] = temp[j];
        j++;
    }
}

void quicksort(int x[], int p, int r){
    int q;

    if(p < r){
        q = partisi(x, p, r);
        quicksort(x, p, q);
        quicksort(x, q+1, r);
    }
}

int partisi(int x[], int p, int r){
    int pivot, i, j;

    pivot = x[p];
    i = p;
    j = r;

    while(i < j){
        while(x[j] > pivot)
            j--;
        while(x[i] < pivot)
            i++;

        if(i<j){
            tukar(&x[i], &x[j]);
            i++;
            j--;
        }
        else{
            if (j > p) {
                return j;
            } else {
                return i;
            }
        }
    }
}

void bubble(int x[])
{
    int i, pos_akhir, did_swap = 1;
    pos_akhir = n - 2;
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
        pos_akhir--;
    }
}


void shell(int x[])
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
                if(x[i] > x[i+jarak])
                {
                    tukar(&x[i], &x[i+jarak]);
                    did_swap = 1;
                }
            }
        }
    }
}

void selection(int x[]){
    int i, j, min;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(x[j] < x[min]){
                min = j;
            }
        }
        tukar(&x[min], &x[i]);
    }
}

void insertion(int x[]){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = x[i];
        j = i - 1;
        while(x[j] > key && j >= 0){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
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
