/*
* @Author: Zakaria 
* @Date:   2022-04-04 09:57:12
* @Last Modified time: 2022-04-04 10:41:03
*/

#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         200002
typedef long long ll;
using namespace std;

vector<int>node[MAX],Transpose_node[MAX];
int vis[MAX];
int intime[MAX], outime[MAX];
vector<int>order;
vector<int>SCC;
int timer;

void dfs(int parent)
{
	   intime[parent]=++timer;
	   vis[parent]=1;

	   for(auto Child : node[parent])
	   {
	   	   if(!vis[Child])
	   	   	 dfs(Child);
	   }
	   outime[parent]=++timer;
	   order.push_back(parent);

}

void DfsForSCC(int parent)
{
	    vis[parent]=1;
        SCC.push_back(parent);
	    for(auto Child : Transpose_node[parent])
	    {
             if(!vis[Child])
             	DfsForSCC(Child);
	    }
}

int main()
{

	    ios::sync_with_stdio(false);
        cin.tie(0);
        int n,m;
        cin>>n>>m;

        for(int i=0 ; i<m ; i++)
        {
        	 int a,b;
        	 cin>>a>>b;
        	 node[a].push_back(b);
        	 Transpose_node[b].push_back(a);
        }


        for(int i=0 ; i<n ; i++)
        {
        	 if(!vis[i])
        	 	dfs(i);
        }


        for(auto i:order)
        	cout<<i<<endl;

        for(int i=0 ; i<n ; i++)
        	vis[i]=0;
       
       while(order.size())
       {
       	     if(!vis[order.back()])
       	     {
       	     	  SCC.clear();
       	     	  cout<<"SCC is :\n";
       	     	  DfsForSCC(order.back());
                  for(auto i:SCC)
                  	cout<<i<<" ";
                  cout<<endl;

       	     }
       	     order.pop_back();
       }


}




/*
8 12
0 1
7 1
1 6
6 7
6 0
0 4
6 4
6 5
5 3
3 4
4 2
2 3
*/