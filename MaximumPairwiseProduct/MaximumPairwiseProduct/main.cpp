//
//  main.cpp
//  MaximumPairwiseProduct
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    std::sort (a.begin(), a.end());
    
    cout << a[a.size() - 1] * a[a.size() - 2];
    
    return 0;
}

/*
 Максимальное попарное произведение
 
 В первой строке входа дано целое число 2≤n≤2⋅10^5, 
 во второй — последовательность целых чисел 0≤a[1],a[2],…,a[n]≤10^5.
 
 Выведите максимальное попарное произведение двух элементов последовательности, 
 то есть max a[i]a[j], 1≤i≠j≤n.
 
 
 Sample Input:
 3
 1 2 3
 
 Sample Output:
 6
 
*/