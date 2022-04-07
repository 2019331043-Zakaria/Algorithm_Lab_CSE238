/*
* @Author: Zakaria 
* @Date:   2022-03-07 09:23:15
* @Last Modified time: 2022-03-07 09:45:45
*/
#include <bits/stdc++.h>
#define  endl        '\n'
#define  sz      100005
typedef long long ll;
using namespace std;

vector<int>node[sz];
vector<int>ans;
int indegree[sz];

void topsort()
{

       queue<int>q;

       for(int i=1 ; i<=n ; i++)
       {
           if(!indegree[i])
            q.push(i);
       }

       while(q.size())
       {
           int x=q.front();
           ans.push_back(x);
           q.pop();

           for(auto i:node[x])
           {
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
           }
       }
}

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);

      int n,m;
      cin>>n>>m;

      for(int i=1 ; i<=m ; i++)
      {
             int x,y;
             cin>>x>>y;
             node[x].push_back(y);
             indegree[y]++;
      }

      topsort();

      if(ans.size()==n)
      {
          for(auto i:ans)
            cout<<i<<" ";
          cout<<endl;
      }
      else
        cout<<"topsort not possible\n";
      

      return 0;

}
