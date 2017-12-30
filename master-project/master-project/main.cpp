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


int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    map<string,int> dayHash;
     dayHash["mon"]=0;
     dayHash["tues"]=1;
     dayHash["wed"]=2;
     dayHash["thurs"]=3;
     dayHash["fri"]=4;
     dayHash["sat"]=5;
     dayHash["sun"]=6;
    
    int t;
    cin>>t;
    for(int tc= 0 ;tc<t; tc++){
        int n;
        string str;
        cin>>n>>str;
        int ans[7];
        for(int i=0;i<7;i++)
        {
            ans[i]=4;
        }
        for(int i=dayHash[str];i<(n%28)+dayHash[str];i++)
        {
            ans[i]++;
        }
        for(int i=0;i<7;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}

