/*
* @Author: Zakaria 
* @Date:   2022-03-07 09:23:15
* @Last Modified time: 2022-03-07 10:55:59
*/
#include <bits/stdc++.h>
#define  endl        '\n'
#define  sz      100005
typedef long long ll;
using namespace std;

vector<int>node[sz];
vector<int>ans;
int indegree[sz];
int n,m;

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);

      
      cin>>n>>m;

      for(int i=1 ; i<=m ; i++)
      {
      	     int x,y;
      	     cin>>x>>y;
      	     node[x].push_back(y);
      	     indegree[y]++;
      }

      
      
      

      return 0;

}
