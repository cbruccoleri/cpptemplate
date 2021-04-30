#include "somelib.h"

#include <iostream>


int main(int argc, char* argv[])
{
    int seq1[] = {6, 4, 1, 0, -2, 18};
    int seq2[] = {4, 9, 1, 2, 6, -21};

    for (std::size_t k = 0L; k < std::size(seq1); ++k)
        std::cout << "gcd(" << seq1[k] << ", " << seq2[k] << ") = " << gcd(seq1[k], seq2[k]) << "\n";
    return 0;
}