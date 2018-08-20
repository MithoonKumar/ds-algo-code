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
    int t;
    cin>>t;
    string str;
    while(t--){
        char c;
        cin>>c;
        str.push_back(c);
    }
    if (str.length() == 1) {
        cout<<"Yes"<<endl;
    } else {
        unordered_map<char, int> unorderedMap;
        for (int i=0; i<str.length(); i++) {
            unorderedMap[str[i]]++;
        }
        if (unorderedMap.size() == str.length()) {
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }
    
    return 0;
}

