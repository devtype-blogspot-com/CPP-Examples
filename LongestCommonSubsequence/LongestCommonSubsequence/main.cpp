//
//  main.cpp
//  LongestCommonSubsequence
//  http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lcs(vector<int>& X, vector<int>& Y, int m, int n) {
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}

int main()
{
    int m;
    cin >> m;
    vector<int> X(m);
    for (int i = 0; i < m; i++) cin >> X[i];
    
    int n;
    cin >> n;
    vector<int> Y(n);
    for (int i = 0; i < n; i++) cin >> Y[i];

    cout << lcs(X, Y, m, n);
    
    return 0;
}

/*
 Наибольшая общая подпоследовательность
 
 Дано натуральное число 1≤n≤10^3 и последовательность целых чисел −10^4≤a[1],…,a[n]≤10^4,
 а также натуральное число 1≤m≤10^3 и последовательность целых чисел −10^4≤b[1],…,b[m]≤10^4.
 Выведите длину их наибольшей общей подпоследовательности (то есть такое максимальное число k, 
 что существуют последовательности 1≤i[1]<i[2]…<i[k]≤n и 1≤j[1]<j[2]<…<j[k]≤m,
 что a[i[1]]=b[j[1]],a[i[2]]=b[j[2]],…,a[i[k]]=b[j[k]]).
 
 Sample Input:
 3
 1 2 3
 4
 2 1 3 5
 
 Sample Output:
 2
 
*/