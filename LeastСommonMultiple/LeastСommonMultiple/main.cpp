//
//  main.cpp
//  LeastСommonMultiple
//
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

unsigned long long int lcm(unsigned long long int a, unsigned long long int b) {
    unsigned long long int t = gcd(a, b);
    if (t) {
        return (a / t * b);
    } else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    unsigned long long int a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b);
    return 0;
}

/*
 Задача на программирование
 
 По данным двум числам 1≤a,b≤2⋅10^9 найдите наименьшее натуральное число m, которое делится и на a, и на b.
 
 Sample Input:
 18 35
 
 Sample Output:
 630
*/
