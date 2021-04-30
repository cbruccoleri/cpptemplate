
#include "somelib.h"

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else {
        // make sure that a >= b
        if (a < b) {
            int aux = a;
            a = b;
            b = aux;
        }
        // iterate to compute the GCD
        while (a != b) {
            int aux = b;
            a = a % b;
            b = aux;
        }
        return a;
    }
}
