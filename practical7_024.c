#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
    int q, proot, xa, xb, ya, yb, k1, k2;
    printf("\n\n\t\t\tDeffie-Hellman Key Exchange\n\n");
    printf("\nEnter value of q: ");
    scanf("%d", &q);
    printf("\nEnter Value of Primitve Root (primitive root < q): ");
    scanf("%d", &proot);
    printf("\nEnter Value of Xa (Private Key of User A): ");
    scanf("%d", &xa);
    printf("\nEnter Value of Xb (Private Key of User B): ");
    scanf("%d", &xb);
    ya = pow(proot, xa);
    ya = ya % q;
    yb = pow(proot, xb);
    yb = yb % q;
    printf("\n\nPublic Key of User A: %d", ya);
    printf("\nPublic Key of User B: %d", yb);
    k1 = pow(yb, xa);
    k1 = k1 % q;
    k2 = pow(ya, xb);
    k2 = k2 % q;
    printf("\nKey 1: %d", k1);
    printf("\nKey 2: %d", k2);
}