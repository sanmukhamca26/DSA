#include <stdio.h>
#include <conio.h>

void arithmetic(int *a, int *b) {
    printf("\nAddition = %d", *a + *b);
    printf("\nSubtraction = %d", *a - *b);
    printf("\nMultiplication = %d", (*a) * (*b));
    
    if (*b != 0)
        printf("\nDivision = %.2f", (float)*a / *b);
    else
        printf("\nDivision is not possible");
}

void main() {
    int a, b;
    clrscr();
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    arithmetic(&a, &b);
    getch();
}
