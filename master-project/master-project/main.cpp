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


int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
        int arr[4];
        map<int,int>hashMap;
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        for(int i=0;i<4;i++)
        {
            hashMap[arr[i]]=0;
        }
        for(int i=0;i<4;i++)
        {
            hashMap[arr[i]]++;
        }
        int count =0;
        for(int i=0;i<4;i++)
        {
            count +=hashMap[arr[i]];
        }
        if(count ==8 || count ==16)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    
    return 0;
}

