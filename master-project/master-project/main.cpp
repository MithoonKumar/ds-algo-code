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
    int  n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    vector<int>mapA(200,0),mapB(200,0),mapC(200,0);
    int maxA,maxB,maxC;
    maxA = 0;
    maxB = 0;
    maxC = 0;
    for(int i=0;i<a.length();i++)
    {
        mapA[a[i]]++;
        maxA = mapA[a[i]]>maxA?mapA[a[i]]:maxA;
        mapB[b[i]]++;
        maxB = mapB[b[i]]>maxB?mapB[b[i]]:maxB;
        mapC[c[i]]++;
        maxC = mapC[c[i]]>maxC?mapC[c[i]]:maxC;
    }
    
    maxA = maxA + n;
    maxB = maxB + n;
    maxC = maxC + n;
    if(maxA > a.length())
    {
            if(n==1)
            {
                if(a.length() == 1)
                {
                    maxA = 1;
                }
                else
                {
                    maxA = a.length()-1;
                }
            }
            else
            {
                maxA = a.length();
            }
    }
    if(maxB>b.length())
    {
        if(n==1)
        {
            if(b.length() == 1)
            {
                maxB = 1;
            }
            else
            {
                maxB = b.length()-1;
            }
        }
        else
        {
            maxB = b.length();
        }
    }
    if(maxC>c.length())
    {
        if(n==1)
        {
            if(c.length() == 1)
            {
                maxC = 1;
            }
            else
            {
                maxC = c.length()-1;
            }
        }
        else
        {
            maxC = c.length();
        }
    }
    
    
    
    int max = (maxA>maxB?maxA:maxB)>maxC?(maxA>maxB?maxA:maxB):maxC;
    if(max == maxA && maxA>maxB && maxA>maxC)
    {
        cout<<"Kuro"<<endl;
    }
    else if(max == maxB && maxB>maxA && maxB>maxC)
    {
        cout<<"Shiro"<<endl;
    }
    else if(max == maxC && maxC>maxA && maxC>maxB)
    {
        cout<<"Katie"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
    return 0;
}
