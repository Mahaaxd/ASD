#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 30

struct mahasiswa
{
    int no;
    char nama[MAX];
    int nilai;
};



int n, key;
char cari[MAX];
time_t t, t1, t2;

int main()
{
    menu();
    return 0;
}

void menu()
{
    int pilih, tipe;
    struct mahasiswa data[MAX];
    struct mahasiswa temp[MAX];
    printf("Masukkan jumlah data : ");
    scanf("%d",&n);
    inisial(data, temp);
    do
    {
        printf("\nMENU METODE SEARCHING\n1. Tampilkan Data\n2. Sequence Search\n3. Binary Search\n4. Keluar\nMasukkan pilihan : ");
        scanf("%d",&pilih);
        switch(pilih)
        {
        case 1:
            sorting(data, temp);
            break;
        case 2:
            tipe = mode();
            sequence(data, tipe);
            break;
        case 3:
            tipe = mode();
            binary(data, tipe, 0, n-1);
            break;
        case 4:
            exit(0);
        default:
            printf("Pilihan salah.\n");
        }
    }
    while(pilih != 4);
}

void tampil(struct mahasiswa data[]){
    printf("\nNo\tNama\tNilai\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%s\t%d\n",data[i].no,data[i].nama,data[i].nilai);
    }
}

void inisial(struct mahasiswa data[], struct mahasiswa temp[])
{
    puts("\nMEMASUKKAN DATA");
    for(int i = 0; i < n; i++)
    {
        printf("Siswa ke-%d\n",i+1);
        printf("No\t: ");
        scanf("%d",&data[i].no);
        fflush(stdin);
        printf("Nama\t: ");
        scanf(" %[^\n]%*c", data[i].nama);
        fflush(stdin);
        printf("Nilai\t: ");
        scanf(" %d",&data[i].nilai);
        fflush(stdin);
    }

    for(int i = 0; i < n; i++)
    {
        temp[i].no = data[i].no;
        strcpy(temp[i].nama, data[i].nama);
        temp[i].nilai = data[i].nilai;
    }
}

void sorting(struct mahasiswa data[], struct mahasiswa temp[])
{
    int pilih;
    printf("\nBENTUK DATA\n1. Tidak Terurut\n2, Terurut Berdasarkan No.\n3. Keluar\nMasukkan pilihan anda : ");
    scanf("%d",&pilih);
    switch(pilih)
    {
    case 1:
        printf("\nNo.\tNama\tNilai");
        for(int i = 0; i < n; i++)
        {
            printf("\n%d\t%s\t%d", data[i].no, data[i].nama, data[i].nilai);
        }
        printf("\n");
        break;
    case 2:
        //copy
        for (int i = 0; i < n; i++)
        {
            temp[i].no = data[i].no;
            strcpy(temp[i].nama, data[i].nama);
            temp[i].nilai = data[i].nilai;
        }

        //sort
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp[j].no > temp[j + 1].no)
                    tukar(&temp[j], &temp[j+1]);
            }
        }

        //tampil
        printf("\nNo.\tNama\tNilai\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t%s\t%d\n", temp[i].no, temp[i].nama, temp[i].nilai);
        }
        break;
    case 3:
        exit(0);
    }
}

void tukar(struct mahasiswa *a, struct mahasiswa *b)
{
    struct mahasiswa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int mode()
{
    int pilih;
    printf("\nPENCARIAN BERDASARKAN\n1. No\n2. Nama\nMasukkan Pilihan : ");
    scanf("%d",&pilih);
    return pilih;
}

void sequence(struct mahasiswa data[], int tipe)
{
    int i, found;
    i = found = 0;
    //puts("\nsebelum!!!!!!!!!!!!!!!!!!!!!\n");
    sort(data, tipe);
    //tampil(data);

    switch(tipe)
    {
    case 1:
        printf("\nMasukan no yang dicari : ");
        scanf("%d",&key);
        while(i < n && !found)
        {
            if(data[i].no == key)
                found = 1;
            i++;
        }
        break;
    case 2:
        printf("\nMasukkan nama yang dicari : ");
        scanf(" %[^\n]%*c", cari);
        while(i < n && !found)
        {
            if(strcmp(data[i].nama, cari) == 0)
                found = 1;
            i++;
        }
        break;
    }

    if(found){
        printf("\nData ditemukan pada indeks [%d].\n",i-1);
    }
    else{
        printf("\nData tidak ditemukan pada array.\n");
    }
    //puts("\nsesudah!!!!!!!!!!!!!!!!!!!!!\n");
    //tampil(data);
}

void sort(struct mahasiswa data[], int tipe)
{
    struct mahasiswa flag;
    for (int i = 1; i < n; i++)
    {
        flag = data[i];
        int j = i - 1;

        switch (tipe)
        {
        case 1: // no
            while (j >= 0 && data[j].no > flag.no)
            {
                data[j + 1] = data[j];
                j--;
            }
            break;
        case 2: // nama
            while (j >= 0 && strcmp(data[j].nama, flag.nama) > 0)
            {
                data[j + 1] = data[j];
                j--;
            }
            break;
        }

        data[j + 1] = flag;
    }
}

void binary(struct mahasiswa data[], int tipe, int l, int r){
    int m, found;

    m = (l+r) / 2;
    found = 0;

    sort(data, tipe);

    switch(tipe)
    {
    case 1:
        printf("\nMasukan no yang dicari : ");
        scanf("%d",&key);
        while(l <= r && !found)
        {
            m = (l+r) / 2;
            if(data[m].no == key)
                found = 1;
            if(data[m].no > key)
                r = m-1;
            if(data[m].no < key)
                l = m+1;
        }
        break;
    case 2:
        printf("\nMasukkan nama yang dicari : ");
        scanf(" %[^\n]%*c", cari);
        while(l <= r && !found)
        {
            m = (l+r) / 2;
            if(strcmp(data[m].nama, cari) == 0)
                found = 1;
            if(strcmp(data[m].nama, cari) > 0)
                r = m-1;
            if(strcmp(data[m].nama, cari) < 0)
                l = m+1;
        }
        break;
    }

    if(found){
        printf("\nData ditemukan pada indeks [%d].\n",m);
    }
    else{
        printf("\nData tidak ditemukan pada array.\n");
    }
}
