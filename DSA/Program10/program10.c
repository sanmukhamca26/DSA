#include <stdio.h>
#include <conio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int prec(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void main() {
    char exp[50], ch;
    int i;
    clrscr();

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");
    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (isalnum(ch)) {
            printf("%c", ch);
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop();
        } else {
            while (top != -1 && prec(stack[top]) >= prec(ch))
                printf("%c", pop());
            push(ch);
        }
    }

    while (top != -1)
        printf("%c", pop());

    getch();
}
