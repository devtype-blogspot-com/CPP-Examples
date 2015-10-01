//
//  main.cpp
//

#include <iostream>

void print1DArray(int *a, unsigned sz)
{
    for (unsigned i = 0; i < sz; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main(int argc, const char * argv[]) {
    int a[] = { 1, 2, 3 };
    print1DArray(a, 3);
    return 0;
}
