#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void main() {
    char postfix[100];
    int i, a, b;
    clrscr();

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            b = pop();
            a = pop();
            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '%': push(a % b); break;
            }
        }
    }

    printf("Result = %d", pop());
    getch();
}
