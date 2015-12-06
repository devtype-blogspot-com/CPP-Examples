//
//  main.cpp
//  MinMaxEraser
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <set>

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    std::multiset<double> a;
    int input;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        a.insert(input);
    }
    
    //    std::cout << "smallest: " << *a.begin() << std::endl;
    //    std::cout << "largest: " << *a.rbegin() << std::endl;
    
    float s;
    for (int j = 0; j < n - 1; j++) {
        s = (*a.begin() + *a.rbegin()) / 2.;
        if (a.size() > 0) a.erase(a.begin());
        if (a.size() > 0) a.erase(--(a.end()));
        a.insert(s);
    }
    
    printf("%.7f", *a.begin());
    return 0;
}

/*
 
 На доске написано n чисел. С ними n−1 раз повторяется следующая простая операция: 
 стираются текущий минимум и текущий максимум, 
 выписывается их полусумма. 
 
 Ваша задача — определить, какое число останется в конце.
 
 Во входе дано целое число 1≤n≤10^5 и начальные целые числа  −10^5≤a[1],…,a[n]≤10^5. 
 Выведите итоговое число с точностью 10^−6.
 
 Sample Input:
 3 2 3 9
 
 Sample Output:
 4.2500000
 
*/

