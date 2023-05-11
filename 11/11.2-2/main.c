#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 30

struct siswa{
    int no;
    char nama[MAX];
    int nilai;
};

int n = 5;
time_t t, t1, t2;

//FUNGSI SORT
void bubSort(struct siswa [], int);
void sheSort(struct siswa [], int);
//FUNGSI MENU
void tampil(struct siswa []);
void tukar(struct siswa *, struct siswa *);
int urut();

int main()
{
    struct siswa data[MAX];
    int pilih;
    data[0].no = 3;
    strcpy(data[0].nama, "maha");
    data[0].nilai = 89;

    data[1].no = 5;
    strcpy(data[1].nama, "amir");
    data[1].nilai = 90;

    data[2].no = 1;
    strcpy(data[2].nama, "arief");
    data[2].nilai = 91;

    data[3].no = 2;
    strcpy(data[3].nama, "qois");
    data[3].nilai = 92;

    data[4].no = 4;
    strcpy(data[4].nama, "raihan");
    data[4].nilai = 93;


    pilih = urut();
    sheSort(data, pilih);
    tampil(data);

    return 0;
}

int urut(){
    int pilih;
    puts("JENIS SORT\n1. ASCENDING\n2. DESCENDING\n");
    printf("Masukkan pilihan : ");
    scanf("%d",&pilih);
    return pilih;
}

void bubSort(struct siswa data[], int kondisi){
    int pos_akhir, did_swap = 1;
    //struct siswa temp;
    pos_akhir = n - 2;

    while (pos_akhir >= 0 && did_swap)
    {
        did_swap = 0;
        for(int i = 0; i <= pos_akhir ; i++){
            if((kondisi == 1 && (data[i].no > data[i+1].no)) || (kondisi == 2 && (data[i].no < data[i+1].no))){
                tukar(&data[i], &data[i+1]);
                //temp = data[i];
                //data[i] = data[i+1];
                //data[i+1] = temp;
                did_swap = 1;
            }
        }
        pos_akhir--;
    }
}

void sheSort(struct siswa data[], int kondisi){
    int jarak, did_swap = 1;
    jarak = n;
    while(jarak > 1){
        jarak = jarak / 2;
        did_swap = 1;
        while(did_swap){
            did_swap = 0;
            for(int i = 0; i < (n - jarak); i++){
                if((kondisi == 1 && (data[i].no > data[i+jarak].no)) || (kondisi == 2 && (data[i].no < data[i+jarak].no))){
                    tukar(&data[i], &data[i+jarak]);
                    did_swap = 1;
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
}
