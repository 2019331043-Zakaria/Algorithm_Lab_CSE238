/*
* @Author: Zakaria
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-03-14 10:56:54
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002
typedef long long ll;
using namespace std;
using namespace std ::chrono;


void Merge(int a[], int left, int mid , int right)
{
       int n1=mid-left+1;
       int n2=right-mid;
       int tempLeft[n1], tempRight[n2];

       for(int i=0 ; i<n1 ; i++)
       {
           tempLeft[i]=a[left+i];
       }

       for(int j=0 ; j<n2; j++)
       {
           tempRight[j]=a[mid+1+j];
       }

       int i=0,j=0,index=left;

       while(i<n1 && j<n2)
       {
          if(tempLeft[i]<=tempRight[j])
          {
             a[index]=tempLeft[i];
             i++;
          }
          else
          {
             a[index]=tempRight[j];
             j++;
          }
          index++;
       }

       while(i<n1)
       {
          a[index]=tempLeft[i];
          index++;
          i++;
       }
       while(j<n2)
       {
          a[index]=tempRight[j];
          index++;
          j++;
       }
      // cout<<i<<" "<<j<<endl;
}

void Merge_Sort(int a[], int left, int right)
{
      if(left<right)
      {
            int mid=left + (right-left)/2;
            Merge_Sort(a, left , mid);
            Merge_Sort(a, mid+1, right);
            Merge(a, left, mid , right);
      }
}
int partition(int a[], int low, int high)
{

     
      int temp=rand();
      //temp%=low;
      if(low)
      temp=temp%low+low;
      else
        temp=high;
     // swap(a[temp],a[high]);
      int pivot=a[temp];

      int j,i=low;

      for(int j=low;j<high;j++)
      {
         if(a[j]<=pivot)
         {
            swap(a[i],a[j]);
            i++;
         }
      }
      swap(a[i],a[high]);

      return i;

}

void quick_sort(int a[], int low, int high)
{
   
     if(low<high)
     {
        // cout<<low<<" "<<high<<endl;
         int p=partition(a, low, high);
         
         quick_sort(a,low,p-1);
         quick_sort(a,p+1,high);


     }
}


int main()
{
      
      int n;
      n=1000;      
      int a[n],b[n];
      ll time_for_mergesort=0,time_for_quicksort=0;
      
      for(int period=0 ; period<1000; period++)
      { 

      
              for(int i=0 ; i<n ; i++)
              {
                 int x;
                 x=rand()%100;
                 a[i]=x;
                 b[i]=x;
              }

             

              auto start=high_resolution_clock::now();
              Merge_Sort(a, 0, n);
              auto stop=high_resolution_clock::now();

              auto duration=duration_cast<microseconds>(stop-start);
              int t=duration.count();
              time_for_mergesort+=t;
               
              
              auto start1=high_resolution_clock::now();
              quick_sort(b, 0, n);
              auto stop1=high_resolution_clock::now();
              
              auto duration1=duration_cast<microseconds>(stop1-start1);
              int t1=duration1.count();
              time_for_quicksort+=t1;
             
      }

      cout<<"time for mergesort: \n";
      cout<<time_for_mergesort<<endl;
      cout<<"time_for_quicksort: \n";
      cout<<time_for_quicksort<<endl;

      return 0;

}