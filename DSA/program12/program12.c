#include <stdio.h>
#include <conio.h>

#define MAX 5

int q[MAX], f = -1, r = -1;

void insert() {
    int x;
    if ((r + 1) % MAX == f) printf("Full!\n");
    else {
        printf("Val: ");
        scanf("%d", &x);
        if (f == -1) f = 0;
        r = (r + 1) % MAX;
        q[r] = x;
    }
}

void del() {
    if (f == -1) printf("Empty!\n");
    else {
        printf("Del: %d\n", q[f]);
        f = (f == r) ? (r = -1) : (f + 1) % MAX;
    }
}

void display() {
    int i;
    if (f == -1) printf("Empty!\n");
    else {
        for (i = f; i != r; i = (i + 1) % MAX) printf("%d ", q[i]);
        printf("%d\n", q[r]);
    }
}

void main() {
    int ch;
    clrscr();
    while (1) {
        printf("\n1.Ins 2.Del 3.Show 4.Exit : ");
        scanf("%d", &ch);
        if (ch == 1) insert();
        else if (ch == 2) del();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
}
