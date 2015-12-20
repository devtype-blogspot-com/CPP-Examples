//
//  main.cpp
//  RepresentativeOfMajority
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    std::multiset<int> a;
    int input;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        a.insert(input);
    }
    
    std::multiset<int>::iterator it = a.begin();
    int prev = *it, c = 1;
    ++it;
    int num, l = n / 2;

    for (; it != a.end(); ++it) {
        num = *it;
        
        c = (num == prev) ? c + 1 : 1;
        if (c > l) {
            cout << 1;
            return 0;
        }
        
        prev = num;
    }
    
    cout << 0;
    
    return 0;
}

/*
 
 Представитель большинства
 ﻿
 Дано натуральное число 1≤n≤10^5 и последовательность целых чисел −10^9≤a[1],…,a[n]≤10^9.
 Выведите 1, если в последовательности есть число, встречающееся строго больше n/2 раз, и 0 в противном случае.
 
 Sample Input:
 5
 2 3 9 2 2
 
 Sample Output:
 1
 
*/