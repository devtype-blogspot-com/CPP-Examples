//
//  По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.
//

#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
    
    if (a == 0) return b;
    if (b == 0) return a;
    if (a >= b) return gcd(a % b, b);
    if (b >= a) return gcd(a, b % a);
    
    
    assert(a > 0 && b > 0);
    // optimize this function
    
    Int current_gcd = 1;
    for (Int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

void test() {
    assert(gcd(18, 35) == 1);
    std::cout << gcd(18, 35) << std::endl;

    assert(gcd(14159572, 63967072) == 4);
    std::cout << gcd(14159572, 63967072) << std::endl;
}

int main(void) {
    test();
    
//    std::int32_t a, b;
//    std::cin >> a >> b;
//    std::cout << gcd(a, b) << std::endl;
    return 0;
}