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

bool bob(string tempStr) {
    int countB = 0;
    int countO = 0;
    for (int i=0; i<tempStr.length(); i++) {
        if (tempStr[i] == 'b') {
            countB++;
        }
        if (tempStr[i] == 'o') {
            countO++;
        }
    }
    if (countO == 1 && countB == 2){
        return true;
    }
    return false;
}


int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    while(t--) {
        string str1, str2;
        cin>>str1>>str2;
        string card[] = {"", "", ""};
        for (int i=0; i<str1.length(); i++ ) {
            if (str1[i] == 'b' || str1[i] == 'o') {
                card[i].push_back(str1[i]);
            }
            if (str2[i] == 'b' || str2[i] == 'o') {
                card[i].push_back(str2[i]);
            }
        }
        bool flag = false;
        for (int i=0; i<card[0].length(); i++) {
            if (flag) {
                break;
            }
            for (int j=0; j<card[1].length(); j++) {
                if (flag) {
                    break;
                }
                for (int k=0; k<card[2].length(); k++) {
                    if (flag) {
                        break;
                    }
                    string tempStr = "";
                    tempStr.push_back(card[0][i]);
                    tempStr.push_back(card[1][j]);
                    tempStr.push_back(card[2][k]);
                    if (bob(tempStr)) {
                        cout<<"yes"<<endl;
                        flag = true;
                    }
                }
            }
        }
        
        if (!flag) {
            cout<<"no"<<endl;
        }
        
    }
    
    return 0;
}

