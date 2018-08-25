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
    //freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    long long n, q;
    cin>>n>>q;
    long long midValue, squaredValue;
    squaredValue= n*n;
    if ((squaredValue%2) == 1) {
        midValue = squaredValue / 2 +1;
    } else {
        midValue = squaredValue / 2;
    }
    while (q--) {
        long long x, y;
        cin>>x>>y;
        long long prevRect = (x-1) * n;
        long long count1;
        if (((x+y)%2) == 0) {
            if ((prevRect%2) == 1) {
                count1 = prevRect / 2 +1;
            } else {
                count1 = prevRect / 2;
            }
        } else {
            count1 = midValue;
            count1 += prevRect/2;
        }
        long long count2;
        if ((y%2) == 1 ) {
            count2 = y / 2 +1;
        } else {
            count2 = y / 2;
        }
        cout<<count1 + count2<<endl;
    }
    
    return 0;
}
