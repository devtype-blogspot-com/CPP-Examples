//
//  main.cpp
//  GreedyCoin
//
// http://ru.stackoverflow.com/a/472523/185642
// http://coding4.me/2013/07/22/money-change-algorithm/
// http://www.wasm.ru/forum/viewtopic.php?id=39642
// http://mathemlib.ru/books/item/f00/s00/z0000034/st003.shtml
// http://algolist.manual.ru/maths/combinat/payment1.php
// http://interactivepython.org/runestone/static/pythonds/Recursion/DynamicProgramming.html
// http://aliev.me/runestone/Recursion/DynamicProgramming.html
// http://everythingcomputerscience.com/algorithms/Greedy_Algorithm.html
// http://placementjump.blogspot.in/2013/08/coin-change-problem-in-java-dynamic.html
// http://n1b-algo.blogspot.com/2009/01/optimal-coin-change-problem.html
// http://condor.depaul.edu/rjohnson/algorithm/coins.pdf
// http://www.codeproject.com/Articles/31002/Coin-Change-Problem-Using-Dynamic-Programming
// http://www.algorithmist.com/index.php/Coin_Change
// http://javatalks.ru/topics/47007?page=1#239908
// http://rforfinance.ru/random-forest/
// https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/04GreedyAlgorithmsI-2x2.pdf
// 

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

void nonoptimal_solution(std::vector<int> coins, int target) {
    unsigned long long int w = target, v[30];
    int n = (int)coins.size(), k = 0;
    for (int i = 0; i < n; i++) v[i] = coins[i];
    
    int u[30];
    for (int i = 0; i < n; i++)
        u[i] = 0;
    
    while(w != 0){
        for (int i = n - 1; i >= 0; i--) {
            if (w >= v[i]) {
                w -= v[i];
                k++;
                u[i]++;
                break;
            }
        }
    }
    
    std::cout << k << " ";
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < u[i]; j++)
            std::cout << v[i] << " ";
    }
}

int min_coins(std::vector<int> coins, int target, std::vector<int> & result)
{
    int count = 0;
    result.clear();
    std::sort(coins.begin(), coins.end()); // отсортируем по возростанию
    
    for(  auto coin  = coins.rbegin() // перебираем от наибольших
        ;      coin != coins.rend()   // до наименьших
        &&  target > 0             // если поделили нацело выходим
        ;    ++coin              )
    {
        if(target >= (*coin))
        {
            count += target / (*coin);
            target = target % (*coin); // остаток от деления на coin
            result.push_back(*coin);
        }
    }
    
    return count;
}

int main() {
    int n;
    std::cin >> n;
    
    int w;
    std::cin >> w;
    
    std::vector<int> v;
    int input;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        v.push_back(input);
    }
    std::sort(v.begin(), v.end());
    std::vector<int> result;
    min_coins(v, w, result);
    std::sort(result.begin(), result.end());

    nonoptimal_solution(result, w);
    
    return 0;
}



/*
 По данным числам 1≤n≤30 и 1≤w≤10^9 и набору чисел 1≤v[1],…,v[n]≤10^9 найдите минимальное число k,
 для которого число w можно представить как сумму k чисел из набора {v[1],…,v[n]}.
 Каждое число из набора можно использовать сколько угодно раз. 
 Известно, что в наборе есть единица и что для любой пары чисел из набора одно из них делится на другое. 
 Гарантируется, что в оптимальном ответе число слагаемых не превосходит 10^4.
 
 Выведите число k и сами слагаемые.
 
 Sample Input:
 4 90 1 2 10 50
 
 Sample Output:
 5 50 10 10 10 10
 
 */
