#pragma once
#ifndef SOMELIB_H
#define SOMELIB_H


/**
 * @brief Compute the GCD of two numbers using Euclid's algorithm.
 * 
 * This implementation works with arbitrary integers, except 0.
 * 
 * @param a     The first number for which the GCD must be computed.
 * @param b     The second number for which the GCD must be computed.
 * @return int  The GCD of a and b. If either number is 0, returns 0.
 */
int gcd(int a, int b);

#endif // SOMELIB_H