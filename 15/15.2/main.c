#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define MAX 10
#define M 99999

typedef int itemType;

typedef struct
{
    itemType items[MAX];
    int count;
    int rear;
    int front;
} Queue;

typedef struct
{
    int size;
    int matriks[MAX][MAX];
} Graph;

typedef struct
{
    itemType data[MAX];
    int count;
} Stack;

//FUNGSI QUEUE
void initQueue(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void enqueue(itemType, Queue *);
itemType dequeue(Queue *);
int isNotInQueue(itemType, Queue *);
//FUNGSI GRAPH
void buatGraph(Graph *);
void dijkstra(Graph *, int, int);
void initTq(int *, int);
void initR(int *, int);
void cetak(int [], int [], int, int);
// FUNGSI STACK
void initStack(Stack *);
int fullStack(Stack *);
int emptyStack(Stack *);
void push(itemType, Stack *);
itemType pop(Stack *);

int n;

int main()
{
    int awal, akhir;
    Graph g;

    buatGraph(&g);

    printf("Masukkan node asal: ");
    scanf("%d", &awal);
    printf("Masukkan node tujuan: ");
    scanf("%d", &akhir);

    dijkstra(&g, awal - 1, akhir - 1);

    return 0;
}

void buatGraph(Graph *g)
{
    printf("Masukkan ukuran matriks : ");
    scanf("%d", &n);

    g->size = n;

    printf("Masukkan matriks : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char value[2];
            scanf("%s", value);
            if (value[0] == 'M') {
                g->matriks[i][j] = M;
            } else {
                g->matriks[i][j] = atoi(value);
            }
        }
    }
}

void dijkstra(Graph *g, int awal, int akhir)
{
    int tq[n], r[n];
    Queue q;

    initTq(tq, n);
    initR(r, n);
    initQueue(&q);
    enqueue(awal, &q);

    while(!isEmpty(&q))
    {
        itemType currentNode = dequeue(&q);
        for(int i = 0; i < n; i ++)
        {
            if(g->matriks[currentNode][i] != 0)
            {
                if(g->matriks[currentNode][i] + tq[currentNode] < tq[i])
                {
                    tq[i] = g->matriks[currentNode][i] + tq[currentNode];
                    r[i] = currentNode;
                    if(i != awal && i != akhir && isNotInQueue(i, &q) == 1)
                    {
                        enqueue(i, &q);
                    }
                }
            }
        }
    }

    cetak(tq, r, awal, akhir);
}

void cetak(int tq[], int r[], int awal, int akhir)
{
    Stack s;

    initStack(&s);

    printf("Total Beban : %d\n", tq[akhir]);

    printf("Rute tercepat dari %d ke %d : ", awal + 1, akhir + 1);
    int i = akhir;
    while(i != -1)
    {
        push(i, &s);
        i = r[i];
    }
    while(!emptyStack(&s))
    {
        printf("%d ", pop(&s) + 1);
    }

    printf("\nMatriks TQ : ");
    for(int i = 0; i < n; i++)
        printf("%d ",tq[i]);
    printf("\n");

    printf("Matriks R : ");
    for(int i = 0; i < n; i++)
        printf("%d ",r[i]);
    printf("\n");
}

int isNotInQueue(itemType i, Queue *q)
{
    if (isEmpty(q))
    {
        return 1;
    }

    for (int j = q->front; j != q->rear; j = (j + 1) % MAX)
    {
        if (q->items[j] == i)
        {
            return 0; // i ditemukan
        }
    }

    return 1;
}

void initTq(int *tq, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            tq[i] = 0;
        else
        {
            tq[i] = M;
        }
    }
}

void initR(int *r, int n)
{
    for(int i = 0; i < n; i++)
    {
        r[i] = -1;
    }
}

void initQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int isFull(Queue *q)
{
    return q->count == MAX ? 1 : 0;
}

int isEmpty(Queue *q)
{
    return q->count == 0 ? 1 : 0;
}

void enqueue(itemType x, Queue *q)
{
    if (isFull(q))
    {
        puts("Queue Overflow");
        return;
    }

    q->items[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
}

itemType dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        puts("Queue Underflow");
        return '\0';
    }

    itemType temp = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return temp;
}

void initStack(Stack *s)
{
    s->count = 0;
}

int fullStack(Stack *s)
{
    return (s->count == MAX) ? 1 : 0;
}

int emptyStack(Stack *s)
{
    return (s->count == 0) ? 1 : 0;
}

void push(itemType x, Stack *s)
{
    if (fullStack(s))
    {
        puts("Stack penuh.");
    }
    else
    {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(Stack *s)
{
    itemType temp;
    if (emptyStack(s))
    {
        puts("Stack kosong.");
        temp = -1;
    }
    else
    {
        --s->count;
        temp = s->data[s->count];
    }
    return temp;
}
