/*
* @Author: Zakaria 
* @Date:   2022-03-10 22:12:49
* @Last Modified time: 2022-03-10 22:16:48
*/
#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;  

vector<int> adj[10001], path;
vector< vector<int> > ham;
bool vis[10001];

int n,m;
void dfs(int u)
{
    vis[u]=1;
    if(path.size()==n)
    {
        ham.push_back(path);
        vis[u]=0;
        return;
    }

    for(int v:adj[u])
    {
        if(!vis[v])
        {
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }
    vis[u] = false;
}

void Hamilton()
{

    for(int i=1; i<=n; i++)
    {
        path.push_back(i);
        dfs(i);
        path.pop_back();
    }

}

int main()
{
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Hamilton();

    if(ham.empty())
        cout<<"Hamilton Path Doesn't exist\n";
    else
    {
        cout<<"Hamilton Path is:\n";
        for(auto x:ham.front())
            cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}