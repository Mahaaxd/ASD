#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 30

struct siswa
{
    int no;
    char nama[MAX];
    char nilai;
};

int n;
time_t t, t1, t2;

//FUNGSI SORT
void inisial(struct siswa []);
void insSort(struct siswa [], int, int);
void selSort(struct siswa [], int, int);
void bubSort(struct siswa [], int, int);
void sheSort(struct siswa [], int, int);
void tukar(struct siswa *, struct siswa *);
//FUNGSI MENU
void menu();
void tampil(struct siswa []);
int urut();
int modeUrut();

int main()
{
    menu();
    return 0;
}

void inisial(struct siswa data[])
{
    puts("\nMEMASUKKAN DATA");
    for(int i = 0; i < n; i++)
    {
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

int modeUrut()
{
    int pilih;
    puts("\nPengurutan berdasarkan\n1. No\n2. Nama\n3. Nilai");
    printf("Masukkan pilihan : ");
    scanf("%d",&pilih);
    return pilih;
}

int urut()
{
    int pilih;
    puts("\nJENIS SORT\n1. ASCENDING\n2. DESCENDING");
    printf("Masukkan pilihan : ");
    scanf("%d",&pilih);
    return pilih;
}


void menu()
{
    int pilih, sort, mode;
    struct siswa data[MAX];
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);
    inisial(data);
    fflush(stdin);
    do
    {
        puts("\n\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble Sort\n4. Shell Sort\n5. Keluar");
        printf("\nMasukkan pilihan anda : ");
        scanf("%d",&pilih);
        if(pilih < 5){
            sort = urut();
            mode = modeUrut();
        }
        switch(pilih)
        {
        case 1:
            time(&t1);
            insSort(data, sort, mode);
            time(&t2);
            tampil(data);
            break;
        case 2:
            time(&t1);
            selSort(data, sort, mode);
            time(&t2);
            tampil(data);
            break;
        case 3:
            time(&t1);
            bubSort(data, sort, mode);
            time(&t2);
            tampil(data);
            break;
        case 4:
            time(&t1);
            sheSort(data, sort, mode);
            time(&t2);
            tampil(data);
            break;
        case 5:
            exit(0);
        default:
            puts("Pilihan salah");
            break;
        }
    }
    while(pilih != 5);

}

void insSort(struct siswa data[], int kondisi, int mode)
{
    int i, j;
    struct siswa key;

    puts("");
    for(i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;

        switch(mode)
        {
        case 1:
            while(j >= 0 && (kondisi == 1 && data[j].no > key.no) || (kondisi == 2 && data[j].no < key.no))
            {
                data[j+1] = data[j];
                j--;
            }
            break;
        case 2:
            while(j >= 0 && (kondisi == 1 && (strcmp(data[j].nama, data[j+1].nama) > 0)) || (kondisi == 2 && (strcmp(data[j].nama, data[j+1].nama) < 0)))
            {
                data[j+1] = data[j];
                j--;
            }
            break;
        case 3:
            while(j >= 0 && (kondisi == 1 && data[j].nilai > key.nilai) || (kondisi == 2 && data[j].nilai < key.nilai))
            {
                data[j+1] = data[j];
                j--;
            }
            break;
        }
        data[j+1] = key;
    }
    puts("");
}

void selSort(struct siswa data[], int kondisi, int mode)
{
    int i, j, min;

    puts("");
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            switch(mode)
            {
            case 1:
                if((kondisi == 1 && data[j].no < data[min].no) || (kondisi == 2 && data[j].no > data[min].no))
                {
                    min = j;
                }
                break;
            case 2:
                if((kondisi == 1 && (strcmp(data[j].nama, data[min].nama) < 0)) || (kondisi == 2 && (strcmp(data[j].nama, data[min].nama) > 0)))
                {
                    min = j;
                }
                break;
            case 3:
                if((kondisi == 1 && data[j].nilai < data[min].nilai) || (kondisi == 2 && data[j].nilai > data[min].nilai))
                {
                    min = j;
                }
                break;
            }

        }
        tukar(&data[i], &data[min]);
    }
    puts("");
}

void bubSort(struct siswa data[], int kondisi, int mode)
{
    int pos_akhir, did_swap = 1;
    pos_akhir = n - 2;
    while (pos_akhir >= 0 && did_swap)
    {
        did_swap = 0;
        for(int i = 0; i <= pos_akhir ; i++)
        {
            switch(mode)
            {
            case 1:
                if((kondisi == 1 && (data[i].no > data[i+1].no)) || (kondisi == 2 && (data[i].no < data[i+1].no)))
                {
                    tukar(&data[i], &data[i+1]);
                    did_swap = 1;
                }
                break;
            case 2:
                if((kondisi == 1 && (strcmp(data[i].nama, data[i+1].nama) > 0)) || (kondisi == 2 && (strcmp(data[i].nama, data[i+1].nama) < 0)))
                {
                    tukar(&data[i], &data[i+1]);
                    did_swap = 1;
                }
                break;
            case 3:
                if((kondisi == 1 && (data[i].nilai > data[i+1].nilai)) || (kondisi == 2 && (data[i].nilai < data[i+1].nilai)))
                {
                    tukar(&data[i], &data[i+1]);
                    did_swap = 1;
                }
            }
        }
        pos_akhir--;
    }
}

void sheSort(struct siswa data[], int kondisi, int mode)
{
    int jarak, did_swap = 1;
    jarak = n;
    while(jarak > 1)
    {
        jarak = jarak / 2;
        did_swap = 1;
        while(did_swap)
        {
            did_swap = 0;
            for(int i = 0; i < (n - jarak); i++)
            {
                switch(mode)
                {
                case 1:
                    if((kondisi == 1 && (data[i].no > data[i+jarak].no)) || (kondisi == 2 && (data[i].no < data[i+jarak].no)))
                    {
                        tukar(&data[i], &data[i+jarak]);
                        did_swap = 1;
                    }
                    break;
                case 2:
                    if((kondisi == 1 && (strcmp(data[i].nama, data[i+1].nama) > 0)) || (kondisi == 2 && (strcmp(data[i].nama, data[i+1].nama) < 0)))
                    {
                        tukar(&data[i], &data[i+1]);
                        did_swap = 1;
                    }
                    break;
                case 3:
                    if((kondisi == 1 && (data[i].nilai > data[i+jarak].nilai)) || (kondisi == 2 && (data[i].nilai < data[i+jarak].nilai)))
                    {
                        tukar(&data[i], &data[i+jarak]);
                        did_swap = 1;

                    }
                }
            }
        }
    }
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
    printf("Waktu : %ld detik", t2-t1);
}
