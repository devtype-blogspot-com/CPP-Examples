//
//  main.cpp
//  MaximumSubset
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, x;
    cin >> n >> x;

    std::multiset<int> a;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        a.insert(input);
    }
    
    std::multiset<int>::reverse_iterator it = a.rbegin();
    int prev = *it, cnt = 1;
    ++it;
    int num;
    for (; it != a.rend(); ++it) {
        num = *it;
        if (prev + num <= x) {
            break;
        }
        cnt++;
        prev = num;
    }
    
    cout << cnt;
    
    return 0;
}

/*
 
 Задача на программирование.
 
 Дано натуральное число n≤10^5 , не отрицательное x и массив не отрицательных чисел a[1],…,a[n] . 
 x и a[i] не превосходят 10^9. 
 Вам требуется вывести размер максимального подмножества I⊆{1,…,n} 
 т.ч. для любых двух неравных i,j∈I выполняется, что a[i]+a[j]>x.
 
 Sample Input:
 10 48
 57 26 9 94 72 70 45 4 86 83
 
 Sample Output:
 8
 
*/