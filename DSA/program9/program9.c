#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 5

struct stack {
    int type;
    int i;
    float f;
    char c;
} s[MAX];

int top = -1;

void show(int idx) {
    if (s[idx].type == 1) printf("%d\n", s[idx].i);
    else if (s[idx].type == 2) printf("%.2f\n", s[idx].f);
    else if (s[idx].type == 3) printf("%c\n", s[idx].c);
}

void push() {
    int ch;
    float temp; // <-- Add a normal float variable
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("1.Int  2.Float  3.Char : ");
    scanf("%d", &ch);
    if (ch < 1 || ch > 3) {
        printf("Invalid type!\n");
        return;
    }
    s[++top].type = ch;
    printf("Enter value: ");
    if (ch == 1) scanf("%d", &s[top].i);
    else if (ch == 2) {
        scanf("%f", &temp); // <-- Scan into normal float first
        s[top].f = temp;    // <-- Then assign to struct
    }
    else scanf(" %c", &s[top].c);
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Deleted: ");
    show(top--);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (i = top; i >= 0; i--)
        show(i);
}

void main() {
    int ch;
    clrscr();
    while (1) {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
