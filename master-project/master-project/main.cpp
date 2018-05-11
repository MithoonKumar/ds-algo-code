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


void calculateCommonFactors(vector<int>vec, unordered_map<int, int>& original)
{
    for(int i = 0; i <vec.size(); i++)
    {
        unordered_map<int, bool>map;
        while (vec[i]%2 == 0)
        {
            map[2] = true;
            vec[i] = vec[i]/2;
        }
        for (int j = 3; j <= sqrt(vec[i]); j = j+2)
        {
            while (vec[i]%j == 0)
            {
                map[j] = true;
                vec[i] = vec[i]/j;
            }
        }
        if (vec[i] > 2)
            map[vec[i]] = true;
        
        for ( auto it = map.begin(); it != map.end(); ++it )
        {
            original[it->first]++;
        }
        
    }
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    
    int t;
    cin>>t;
    for(int tc = 0; tc < t; tc++)
    {
        int n;
        cin>>n;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            vec.push_back(num);
        }
        unordered_map<int, int>map;
        calculateCommonFactors(vec, map);
        bool flag = false;
        for ( auto it = map.begin(); it != map.end(); ++it )
        {
            if(it->second == n)
            {
                cout<<-1<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout<<0<<endl;
        }
    }
    
    
    return 0;
}

