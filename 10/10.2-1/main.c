#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 30

struct siswa{
    int no;
    char nama[MAX];
    char nilai;
};

int n;

//FUNGSI SORT
void inisial(struct siswa []);
void insSort(struct siswa [], int);
void selSort(struct siswa [], int);
void tukar(struct siswa *, struct siswa *);
//FUNGSI MENU
void menu();
void menuMetodeIns(struct siswa []);
void menuMetodeSel(struct siswa []);
void tampil(struct siswa []);

int main()
{
    menu();
    return 0;
}

void inisial(struct siswa data[]){
    puts("\nMEMASUKKAN DATA");
    for(int i = 0; i < n; i++){
        printf("Siswa ke-%d\n",i+1);
        printf("No\t: ");
        scanf("%d",&data[i].no);
        fflush(stdin);
        printf("Nama\t: ");
        gets(data[i].nama);
        fflush(stdin);
        printf("Nilai\t: ");
        scanf(" %hhd",&data[i].nilai);
        fflush(stdin);
    }
}

void menu()
{
    int pilih;
    struct siswa data[MAX];
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);
    inisial(data);
    fflush(stdin);
    puts("\nMENU METODE SORTING");
    printf("1. Insertion Sort\n2. Selection Sort\n3. Keluar");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    fflush(stdin);
    switch(pilih)
    {
    case 1:
        menuMetodeIns(data);
        break;
    case 2:
        menuMetodeSel(data);
        break;
    case 3:
        exit(0);
    default:
        puts("Pilihan salah");
        break;
    }
}

void menuMetodeIns(struct siswa data[])
{
    int pilih;
    puts("\nJENIS INSERTION SORT");
    printf("1. ASCENDING\n2. DESCENDING");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    fflush(stdin);
    switch(pilih)
    {
    case 1:
    case 2:
        insSort(data, pilih);
        printf("Data setelah diurutkan :\n");
        tampil(data);
        puts("");
        break;
    default:
        puts("Pilihan salah");
        break;
    }
}

void menuMetodeSel(struct siswa data[])
{
    int pilih;
    puts("\nJENIS SELECTION SORT");
    printf("1. ASCENDING\n2. DESCENDING\n");
    printf("Masukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
    case 2:
        selSort(data, pilih);
        printf("Data setelah diurutkan :\n");
        tampil(data);
        puts("");
        break;
    default:
        puts("Pilihan salah");
        break;
    }
}

void insSort(struct siswa data[], int kondisi)
{
    int i, j;
    struct siswa key;

    puts("");
    for(i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;

        /*if(kondisi == 1)
        {
            while(data[j].no > key.no && j >= 0)
            {
                data[j+1] = data[j];
                j--;
            }
        }
        else
        {
            while(data[j].no < key.no && j >= 0)
            {
                data[j+1] = data[j];
                j--;
            }
        }*/

        while(j >= 0 && (kondisi == 1 && data[j].no > key.no) || (kondisi == 2 && data[j].no < key.no)){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
    puts("");
}

void selSort(struct siswa data[], int kondisi)
{
    int i, j, min;

    puts("");
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {

            /*if(kondisi == 1)
            {
                if(data[j].no < data[min].no)
                {
                    min = j;
                }
            }
            else{
                if(data[j].no > data[min].no)
                {
                    min = j;
                }
            }*/

            if((kondisi == 1 && data[j].no < data[min].no) || (kondisi == 2 && data[j].no > data[min].no)){
                min = j;
            }
        }
        tukar(&data[i], &data[min]);
    }
    puts("");
}

void tukar(struct siswa *a, struct siswa *b)
{
    struct siswa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(struct siswa data[])
{
    printf("No\tNama\tNilai\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\n", data[i].no, data[i].nama, data[i].nilai);
    }
    printf("\n");
}
