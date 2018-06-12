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

    string str;
    cin>>str;
    if(str.length()<=2)
    {
        cout<<"No"<<endl;
    }
    else
    {
        bool flag = false;
        for(int i=1;i<=str.length()-2;i++)
        {
            unordered_map<char, bool>map;
            map[str[i-1]] = true;
            map[str[i]] = true;
            map[str[i+1]] = true;
            if(map.size() == 3)
            {
                int sum = 0;
                for (std::unordered_map<char,bool>::iterator it=map.begin(); it!=map.end(); ++it)
                {
                    sum+=(it->first);
                }
                if(sum == 3*'B')
                {
                    flag = true;
                    cout<<"Yes"<<endl;
                    break;
                }
            }
        }
        if (!flag)
        cout<<"No"<<endl;
    }
    

}

