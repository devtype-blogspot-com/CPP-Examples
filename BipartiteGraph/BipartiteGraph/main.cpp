#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

#define INF 1000

vector<int>vec[50];
map<int,int>color;
queue<int>q;

bool check(int n, int src)
{
    q.push(src);
    int i;
    
    color[src]=1;
    
    while(!q.empty())
    {
        src = q.front();
        q.pop();
        for(i=0;i<vec[src].size();i++)
        {
            //	cout<<vec[src][i]<<" ";
            if(color[vec[src][i]]==-1)
            {
                color[vec[src][i]]= 1- color[src];
                q.push(vec[src][i]);
            }
            
            else if(color[vec[src][i]]== color[src])
                return 0;
        }
        //	cout<<endl;
    }
    return 1;
}

int main() {
    // your code goes here
    int n,edges;
    cin>>n>>edges;
    int a,b,i;
    for(i=0;i<=n;i++)
        color[i]= -1;
    for(i=0;i<edges;i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    bool res=1;
    
    for(i=0;i<n;i++){
        if(color[i]==-1)
            res = (res&check(n,i));
    }
    
    if(res)
        cout<<"YES"; // Graph is bipartite
    else
        cout<<"NO"; // Graph is not bipartite
    
    return 0;
}

/*
 https://stepic.org/lesson/Двудольные-графы-Раскраски-графов-9588/step/8?unit=1816
 http://www.geeksforgeeks.org/bipartite-graph/
 http://ideone.com/r6Z58k
 http://www.sanfoundry.com/java-program-check-whether-graph-bipartite-using-2-color-algorithm/
 
 Проверить является ли граф двудольным.
 
 Формат входных данных:﻿
 В первой строке указаны два числа разделен﻿﻿ных﻿﻿ про﻿белом﻿﻿: v﻿﻿﻿ (число﻿ вершин﻿) и﻿ e﻿ (число﻿ ребер﻿). ﻿﻿В﻿ следующих e строках указаны пары вершин, соединенных ребром. Выполняются ограничения: ﻿﻿﻿0≤v≤1000,0≤e≤1000 .﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿
 
 Формат выходных данных:
 Одно слово: YES, если граф двудолен, или NO, в противном случае.
 
 ﻿
 Sample Input 1:
 4 2
 1 2
 3 2
 Sample Output 1:
 YES
 
 Sample Input 2:
 3 3
 1 2
 2 3
 3 1
 Sample Output 2:
 NO
*/