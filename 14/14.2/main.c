#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

typedef char data;
typedef struct Node tree;
typedef struct Stack stack;

struct Node {
    data info;
    tree* kiri;
    tree* kanan;
};

struct Stack {
    int top;
    unsigned size;
    tree** array;
};

tree* build(data []);
stack* buatStack(unsigned);
void push(stack*, tree*);
tree* pop(stack*);
tree* peek(stack*);
int isEmpty(stack*);
int isFull(stack*);
int isOperator(char);
int isPrecedence(char);
tree* buatTree(data);
void preorder(tree*);
void postorder(tree*);
void inorder(tree*);

int main() {
    data infix[MAX];
    tree* root;

    printf("Masukkan ekspresi dalam notasi infix : ");
    fgets(infix, MAX, stdin);
    root = build(infix);

    printf("Hasil kunjungan secara PREORDER : ");
    preorder(root);
    printf("\nHasil kunjungan secara INORDER : ");
    inorder(root);
    printf("\nHasil kunjungan secara POSTORDER : ");
    postorder(root);

    return 0;
}

tree* build(data infix[]) {
    stack* stOperator = buatStack(strlen(infix));
    stack* stOperan = buatStack(strlen(infix));

    for (int i = 0; infix[i] != '\0'; i++) {
        char x = infix[i];
        if (x == '(') {
            push(stOperator, buatTree(x));
        } else if (isdigit(x)) {
            tree* operanTree = buatTree(x);
            push(stOperan, operanTree);
        } else if (isOperator(x)) {
            while (!isEmpty(stOperator) && isPrecedence(x) <= isPrecedence(peek(stOperator)->info)) {
                tree* operatorTree = pop(stOperator);
                operatorTree->kanan = pop(stOperan);
                operatorTree->kiri = pop(stOperan);
                push(stOperan, operatorTree);
            }
            push(stOperator, buatTree(x));
        } else if (x == ')') {
            while (!isEmpty(stOperator) && peek(stOperator)->info != '(') {
                tree* operatorTree = pop(stOperator);
                operatorTree->kanan = pop(stOperan);
                operatorTree->kiri = pop(stOperan);
                push(stOperan, operatorTree);
            }
            if (!isEmpty(stOperator) && peek(stOperator)->info == '(')
                pop(stOperator);
        }
    }

    while (!isEmpty(stOperator)) {
        tree* operatorTree = pop(stOperator);
        operatorTree->kanan = pop(stOperan);
        operatorTree->kiri = pop(stOperan);
        push(stOperan, operatorTree);
    }
    return pop(stOperan);
}

stack* buatStack(unsigned size) {
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack->top = -1;
    newStack->size = size;
    newStack->array = (tree**)malloc(newStack->size * sizeof(tree*));
    return newStack;
}

void push(stack* stack, tree* info) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = info;
}

tree* pop(stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

tree* peek(stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

int isEmpty(stack* stack) {
    return stack->top == -1;
}

int isFull(stack* stack) {
    return stack->top == stack->size - 1;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int isPrecedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

tree* buatTree(data info) {
    tree* newTree = (tree*)malloc(sizeof(tree));
    newTree->info = info;
    newTree->kiri = NULL;
    newTree->kanan = NULL;
    return newTree;
}

void preorder(tree* root) {
    if (root != NULL) {
        printf(" %c ", root->info);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void postorder(tree* root) {
    if (root != NULL) {
        postorder(root->kiri);
        postorder(root->kanan);
        printf(" %c ", root->info);
    }
}

void inorder(tree* root) {
    if (root != NULL) {
        inorder(root->kiri);
        printf(" %c ", root->info);
        inorder(root->kanan);
    }
}
