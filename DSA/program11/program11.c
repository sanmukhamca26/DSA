#include <stdio.h>
#include <conio.h>

#define MAX 5

int q[MAX], f = -1, r = -1;

void enqueue() {
    int x;
    if (r == MAX - 1) printf("Full!\n");
    else {
        printf("Val: ");
        scanf("%d", &x);
        if (f == -1) f = 0;
        q[++r] = x;
    }
}

void dequeue() {
    if (f == -1 || f > r) printf("Empty!\n");
    else printf("Del: %d\n", q[f++]);
}

void display() {
    int i;
    if (f == -1 || f > r) printf("Empty!\n");
    else {
        for (i = f; i <= r; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

void main() {
    int ch;
    clrscr();
    while (1) {
        printf("\n1.Enq 2.Deq 3.Show 4.Exit : ");
        scanf("%d", &ch);
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
}
