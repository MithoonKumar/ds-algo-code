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

long long findHCF (long long first, long long second) {
    long long dividend = first;
    long long divisor = second;
    long long quotient, remainder;
    while (1) {
        quotient = dividend / divisor;
        remainder = (dividend % divisor);
        if (remainder == 0)
            return divisor;
        dividend = divisor;
        divisor = remainder;
    }
}

long long findGcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return findGcd(b % a, a);
}

long long findFirstPrimeFactor(long long num) {
    if ((num%2) == 0) {
        return 2;
    } else {
        for (long long i = 3; i <= sqrt((double) num); i = i+2 ) {
            if ((num%i) == 0 ){
                return i;
            }
        }
    }
    
    return num;
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    long long n;
    cin>>n;
    //n = 1000;
    vector<long long> vec;
    for (long long i = 0; i < n; i++) {
        long long num1, num2;
        cin>>num1>>num2;
        vec.push_back(num1*num2);
    }
    sort(vec.begin(), vec.end());
    long long gcd = vec[0];
    for (long long i = 0; i < n-1; i++) {
        gcd = findHCF(gcd, vec[i+1]);
    }
    if (gcd == 1) {
        cout<<-1<<endl;
    } else {
        cout<<findFirstPrimeFactor(gcd)<<endl;
    }
    return 0;
}

