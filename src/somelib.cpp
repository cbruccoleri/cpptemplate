
#include "somelib.h"

int gcd(int a, int b)
{
    // make sure that a >= b
    if (a < b) {
        int aux = a;
        a = b;
        b = aux;
    }
    // iterate to compute the GCD
    while (b != 0 && a != b) {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}
