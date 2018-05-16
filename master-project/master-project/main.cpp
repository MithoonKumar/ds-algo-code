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
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int n,m;
    cin>>n>>m;
    char arr[102][102];
    char dupArr[102][102];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            dupArr[i][j] = arr[i][j];
            if(dupArr[i][j] != '*')
            {
                dupArr[i][j] = '0';
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dupArr[i][j] == '*')
            {
                for(int k=i-1;k<=i+1;k++)
                {
                    for(int l=j-1;l<=j+1;l++)
                    {
                        if((k==i && l==j) || dupArr[k][l] == '*')
                        {
                            continue;
                        }
                        else
                        {
                            dupArr[k][l]++;
                        }
                    }
                }
            }
        }
    }
    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dupArr[i][j] == '0')
            {
                dupArr[i][j] = '.';
            }
            if(dupArr[i][j]!=arr[i][j])
            {
                flag = false;
            }
        }
    }

    
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}

