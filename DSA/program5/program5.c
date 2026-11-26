#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

struct stack {
    int top;
    int items[SIZE];
} s = {-1}; // Initializes top to -1 automatically

void push() {
    int item;
    if (s.top == SIZE - 1) {
        printf("\nStack Overflow!");
    } else {
        printf("\nEnter item: ");
        scanf("%d", &item);
        s.items[++s.top] = item; // Increments top and inserts in one step
    }
}

void pop() {
    if (s.top == -1) {
        printf("\nStack Underflow!");
    } else {
        printf("\nDeleted item: %d", s.items[s.top--]); // Prints and decrements top
    }
}

void display() {
    int i;
    if (s.top == -1) {
        printf("Empty");
    } else {
        for (i = 0; i <= s.top; i++)
            printf("%d(%d)  ", s.items[i], i);
    }
}

void main() {
    int ch;
    while (1) {
        clrscr(); // Keeps the Turbo C screen clean on every loop
        printf("--- STACK OPERATIONS ---\n");
        printf("Stack: ");
        display();
        printf("\n\n1. Push\n2. Pop\n3. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: exit(0);
            default: printf("\nInvalid choice!");
        }
        getch(); // Pauses to show messages before clearing screen
    }
}
