#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 30

typedef char data;
typedef struct Node tree;
struct Node
{
    data info;
    tree *kiri;
    tree *kanan;
};

void menu();
void masuk(data info [], tree **);
tree* sisip(tree *, data );
tree* bentuk(data);
tree* cari(tree *, data);
void preorder(tree *);
void postorder(tree *);
void inorder(tree *);

int main()
{
    menu();
    return 0;
}

void masuk(data info[], tree **root)
{
    printf("Ketikkan data, pisahkan dengan spasi : ");
    fgets(info, MAX, stdin);
    for(int i = 0; info[i] != '\0'; i++)
    {
        if(info[i] == ' ' || info[i] == '\0')
            continue;
        else
            *root = sisip(*root, info[i]);
    }
}

void menu()
{
    tree *root = NULL;
    int pilih;
    char lagi;
    data info[MAX], jwb, find;

    masuk(info, &root);

    do
    {
        printf("\n\nPilih Penelusuran Tree\n1. Preorder\n2. Postorder\n3. Inorder\n4. Keluar\nMasukkan pilihan : ");
        scanf("%d",&pilih);
        switch(pilih)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            postorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            break;
        }
    }
    while(pilih != 4);

    do{
        printf("Anda ingin mencari data : ");
        scanf(" %c", &lagi);
        fflush(stdin);
        if(lagi == 't' || lagi == 'T')
            exit(0);
        printf("Data yang ingin dicari : ");
        scanf(" %c", &find);
        if(cari(root, find) != NULL)
            printf("Data %c ditemukan dalam tree.\n",find);
        else
            printf("Data tidak ditemukan dalam tree.\n");

    }while(lagi == 'y' || lagi == 'Y');
    return 0;
}

tree* cari(tree *root, data info){
    if(root == NULL)
        return NULL;
    else if(info < root->info)
        return cari(root->kiri, info);
    else if(info > root->info)
        return cari(root->kanan, info);
    else if(info == root->info)
        return root;
    else
        return NULL;
}


tree* sisip(tree *root, data info)
{
    if (root == NULL)
    {
        return bentuk(info);
    }
    else
    {
        if (strcasecmp(&info, &root->info) < 0)
        {
            root->kiri = sisip(root->kiri, info);
        }
        else if (strcasecmp(&info, &root->info) > 0)
        {
            root->kanan = sisip(root->kanan, info);
        }
    }
    return root;
}

tree* bentuk(data info)
{
    tree *newTree = (tree*)malloc(sizeof(tree));
    newTree->info = info;
    newTree->kiri = NULL;
    newTree->kanan = NULL;
    return newTree;
}

void preorder(tree *root)
{
    if(root != NULL)
    {
        printf(" %c ",root->info);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void postorder(tree *root)
{
    if(root != NULL)
    {
        postorder(root->kiri);
        postorder(root->kanan);
        printf(" %c ",root->info);
    }
}

void inorder(tree *root)
{
    if(root != NULL)
    {
        inorder(root->kiri);
        printf(" %c ",root->info);
        inorder(root->kanan);
    }
}
