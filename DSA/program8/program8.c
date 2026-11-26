#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int stack[100], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void main() {
    char exp[100];
    int i, op1, op2;
    clrscr();

    printf("Enter prefix expression: ");
    scanf("%s", exp);

    for (i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op1 = pop();
            op2 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push((int)pow(op1, op2)); break;
            }
        }
    }

    printf("Result = %d", pop());
    getch();
}
