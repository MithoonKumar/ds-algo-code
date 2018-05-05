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
    long t;
    cin>>t;
    for(long tc=0; tc<t; tc++)
    {
        long n;
        cin>>n;
        long arr[10000], totalUniqueNums = 0;
        unordered_map<long,long>hashMap;
        for(long i=0;i<n;i++)
        {
            long num;
            cin>>num;
            if(hashMap.find(num) == hashMap.end())
            {
                arr[totalUniqueNums] = num;
                totalUniqueNums++;
                hashMap[num] = 1;
            }
            else
            {
                hashMap[num] = hashMap[num]+1;
            }
        }
        long count = 0;
        for(long i=0;i<totalUniqueNums;i++)
        {
            for(long j=i+1;j<totalUniqueNums;j++)
            {
                long sum = arr[i] + arr[j];
                long half = sum/2;
                if(half*2==sum)
                {
                    if(hashMap.find(half) != hashMap.end())
                        count+= (hashMap[arr[i]]*hashMap[arr[j]]);
                }
                
            }
            count+=((hashMap[arr[i]]*(hashMap[arr[i]]-1))/2);
        }
        cout<<count<<endl;
    }
    
    return 0;
}

