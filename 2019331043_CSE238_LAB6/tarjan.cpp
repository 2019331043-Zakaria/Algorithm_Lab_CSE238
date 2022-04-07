/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:54:17
* @Last Modified time: 2022-04-04 10:22:32
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

vector<int>node[MAX];
bool PresentinStack[MAX];
int DiscoverTime[MAX], Lowtime[MAX];
stack<int>st;
int timer;

void dfs(int parent)
{

	   DiscoverTime[parent]=Lowtime[parent]=timer;
	   timer+=1;
	   st.push(parent);
	   PresentinStack[parent]=1;

	   for(auto Child : node[parent])
	   {
	   	   if(DiscoverTime[Child]==-1) //If Child is not visited
	   	   	{
	   	   		     dfs(Child);
	   	   		     Lowtime[parent]=min(Lowtime[parent], Lowtime[Child]);
	   	   	} 

	   	   else if(PresentinStack[Child]==1) //Differentiate back-edge and cross-edge
	   	   {
                Lowtime[parent]=min(Lowtime[parent], DiscoverTime[Child]);
	   	   }
	   }

	   if(Lowtime[parent] == DiscoverTime[parent]) //This is head of a SCC
	   {
	   	  cout<<"SCC is : \n";
	   	  while(st.top()!=parent)
	   	  {
	   	  	  cout<<st.top()<<" ";
	   	  	  PresentinStack[st.top()]=0;
	   	  	  st.pop();
	   	  }
	   	  cout<<st.top()<<endl;
	   	  PresentinStack[st.top()]=0;
	   	  st.pop();

	   }
}

void Tarjan(int n)
{

      memset(DiscoverTime, -1 ,sizeof(DiscoverTime));
      memset(Lowtime,-1 ,sizeof(Lowtime));\

	   for(int i=0 ; i<n ; i++)
	   {
	   	  if(DiscoverTime[i]==-1)
	   	  	dfs(i);
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
	      	  int x,y;
	      	  cin>>x>>y;
	      	  node[x].push_back(y);
	      }

           Tarjan(n);
       
         
      
   


}