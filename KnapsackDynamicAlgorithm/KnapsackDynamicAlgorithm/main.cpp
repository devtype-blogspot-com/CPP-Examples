//
//  main.cpp
//  KnapsackDynamicAlgorithm
//
//  https://stepic.org/lesson/Рюкзак-13259/step/5?unit=3444
//  http://www.sanfoundry.com/cpp-program-solve-knapsack-problem-using-dynamic-programming/
//  http://www.programminglogic.com/knapsack-problem-dynamic-programming-algorithm/
//  http://stackoverflow.com/questions/11036689/solving-the-integer-knapsack
//  https://sites.google.com/site/mikescoderama/Home/0-1-knapsack-problem-in-p
//

#include <iostream>
#include <vector>

using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int K[300 + 1][100000 + 1];

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val, int n)
{
    int i, w;
//    int K[n + 1][W + 1];
    
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    return K[n][W];
}

int main(){
    int W; // вместимость рюкзака
    cin >> W;
    
    int n; // число золотых слитков
    cin >> n;
    
    vector<int> w(n); // веса слитков
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        values[i] = w[i];
    }
    
    cout << knapSack(W, w, values, n);
    
    return 0;
}

/*
 
 Задача на программирование: рюкзак
 ﻿
 
 Первая строка входа содержит целые числа 1≤W≤10^4 и 1≤n≤300 — вместимость рюкзака и число золотых слитков. Следующая строка содержит n целых чисел 0≤w[1],…,w[n]≤10^5, задающих веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.
 
 
 Sample Input:
 10 3
 1 4 8
 
 Sample Output:
 9
 
*/