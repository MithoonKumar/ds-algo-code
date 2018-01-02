#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<list>
#include<set>
#include<unordered_map>
#include<sstream>
#include<limits.h>
#include<stdio.h>
using namespace std;
#define faster  ios_base::sync_with_stdio(false); cin.tie(NULL)

void createSegementTree(int * segmentArray,int * arr,int s,int e,int index)
{
    if(s == e)
    {
        segmentArray[index] = s;
        return ;
    }
    int mid = s+(e-s)/2;
    createSegementTree(segmentArray,arr, s, mid, 2*index);
    createSegementTree(segmentArray, arr, mid+1, e, 2*index+1);
    segmentArray[index] = arr[segmentArray[2*index]]<arr[segmentArray[2*index+1]]?segmentArray[2*index]:segmentArray[2*index+1];
}
int findMinIndex(int s,int e,int s1,int e1,int * segmentArray,int *arr,int index)
{
   if(s1>e ||e1<s)
   {
       return -1;
   }
   else if(s1<=s && e<=e1)
   {
       return segmentArray[index];
   }
   else
   {
       int mid = s+(e-s)/2;
       int leftIndex = findMinIndex(s,mid, s1, e1, segmentArray,arr ,2*index);
       int rightIndex = findMinIndex(mid+1,e, s1, e1, segmentArray,arr ,2*index+1);
       if(leftIndex == -1)
       {
           return rightIndex;
       }
       else if(rightIndex == -1)
       {
           return leftIndex;
       }
       else
       {
           return arr[leftIndex]<arr[rightIndex]?leftIndex:rightIndex;
       }
   }
}

int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int arr[] = {89,1,3,4,23,5,67,5,78,9,-1,4,32,7};
    int segmentArray [4*sizeof(arr)/sizeof(int)+1];
    createSegementTree(segmentArray,arr,0,sizeof(arr)/sizeof(int) - 1,1);
    int s1,e1;
    cin>>s1>>e1;
    cout<<findMinIndex(0,sizeof(arr)/sizeof(int) - 1,s1,e1,segmentArray,arr,1);
    return 0;
}

