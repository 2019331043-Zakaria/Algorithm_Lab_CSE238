/*
* @Author: Zakaria
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-03-14 21:35:42
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

void max_heapify(int heap[], int heap_size, int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest_index=i;

    if(left<=heap_size && heap[left]>heap[i])
        largest_index=left;

    if(right<=heap_size && heap[right]>heap[largest_index])
        largest_index=right;

    if(largest_index==i)
        return;
    else
    {
        int temp=heap[i];

        heap[i]=heap[largest_index];   ///swapping largest child to parent;

        heap[largest_index]=temp;

        max_heapify(heap, heap_size, largest_index); ///recursive call to largest index;

    }

}

int main()
{
      
              int heap_size;
              heap_size=100000;

              int heap[heap_size];
              

              for(int i=1 ; i<=heap_size ; i++)
              {
                 
                 int x=rand()%100000;
                 heap[i]=x;
              }
             
              auto start=high_resolution_clock::now();
              

              for(int i=heap_size/2 ; i>=1 ;i--)
              max_heapify(heap, heap_size , i); /// heapify call start from 3
 
             int n=heap_size;

             for(int i=heap_size ; i>1 ;i--)
             {
                 int temp=heap[1];
                 heap[1]=heap[i];
                 heap[i]=temp;
                 heap_size-=1;
                 max_heapify(heap, heap_size , 1); ///calling heapify function and after each call the length of heap size decrease and heapify from up to down so that every time call 1;
              }

              heap_size=n;

              /*for(int i=1 ; i<=heap_size ; i++)
                cout<<heap[i]<<" ";
              cout<<endl;
*/


              auto stop=high_resolution_clock::now();

              auto duration=duration_cast<microseconds>(stop-start);
              int t=duration.count();
              
              cout<<"Time for Heap sort : \n";
              cout<<t<<endl;
               
              
     
      return 0;

}