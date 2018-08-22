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
    int n = (int) str.length();
    int maxValue = 1, counter = 0, count = 0;
    int tempLength = 1;
    while(1) {
        count++;
        if (str[counter] != str[(counter+1)%n]) {
            tempLength++;
        } else {
            maxValue = tempLength > maxValue ? tempLength: maxValue;
            tempLength = 1;
        }
        counter++;
        counter = counter%n;
        if (tempLength == n) {
            maxValue = n;
            break;
        }
        if (count == 2*n-1) {
            break;
        }
    }
    cout<<maxValue<<endl;
    return 0;
}

