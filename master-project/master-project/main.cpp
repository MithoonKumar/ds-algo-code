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

bool check1(char a, char b) {
    if (a==b || abs(a-b) == 2) {
        return true;
    }
    return false;
}

bool check(char a, char b) {
    vector<char>first;
    vector<char>second;
    if (a == b) {
        return true;
    }
    if (a == 'a') {
        first.push_back('b');
    }
    if (a == 'z') {
        first.push_back('y');
    }
    if (b == 'a') {
        second.push_back('b');
    }
    if (b == 'z') {
        second.push_back('y');
    }
    if (first.size() == 0) {
        first.push_back(a-1);
        first.push_back(a+1);
    }
    if (second.size() == 0) {
        second.push_back(b-1);
        second.push_back(b+1);
    }
    
    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < second.size(); j++) {
            if (first[i] == second[j]) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string str;
        cin>>str;
        bool flag = true;
        for (int i = 0; i < n/2; i++) {
            if (!check(str[i], str[n-i-1])) {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}

