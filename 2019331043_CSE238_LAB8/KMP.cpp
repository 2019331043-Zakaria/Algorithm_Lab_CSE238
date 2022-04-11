/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-11 10:44:25
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



vector<int> ConstructLPS(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    
    for (int i = 1; i < pattern.length(); ) 
    {
        if (pattern[i] == pattern[index])
         lps[i] = index + 1, index++ , i++;
        else
         {
            if (index != 0) 
            	index = lps[index - 1];
            else 
            	lps[i] = index, i++;
         }
    }
    return lps;
}


int main()
{
       
       ios::sync_with_stdio(false);
       cin.tie(0);	     
	   
	   string pattern, text;

	   cin>>text>>pattern;

	   vector<int>LPS ;
	   LPS = ConstructLPS(pattern);
       

       cout<<"LPS array : "<<endl;
	   for(int i=0 ; i<pattern.size() ; i++)
	   	cout<<LPS[i]<<" ";
	   cout<<endl;


	   int i=0,j=0;
	   bool found=0;
	   while(i<text.size())
	   {
	   	   if(text[i]==pattern[j])
	   	   	i++,j++;
	   	   else
	   	   {
	   	   	  if(j)
	   	   	  	j=LPS[j-1];
	   	   	  else
	   	   	  	i++;
	   	   }

	   	   if(j==pattern.size())
	   	   {
	   	   	  found=1;
	   	   	  cout<<"Found at "<< i- pattern.size()<< endl;
	   	   	  j=LPS[j-1];
	   	   }
	   }

	   if(!found)
	   	cout<<"Not found"<<endl;



	   return 0;
}