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

vector<long long> findAllPrimes (long long num) {
    vector<long long>primes;
    while ((num%2) == 0) {
        primes.push_back(2);
        num/=2;
    }
    
    for (long long i = 3; i <= sqrt((double)num); i = i+2) {
        while ((num%i) == 0) {
            primes.push_back(i);
            num/=i;
        }
    }
    if (num>2) {
        primes.push_back(num);
    }
    return primes;
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    long long n;
    cin>>n;
    vector<vector<long long> >tuples;
    for(long long i = 0; i < n; i++) {
        vector<long long>tuple;
        long long num1, num2;
        cin>>num1>>num2;
        tuple.push_back(num1);
        tuple.push_back(num2);
        tuples.push_back(tuple);
    }
    vector<long long> primeFactors1 = findAllPrimes(tuples[0][0]);
    vector<long long> primeFactors2 = findAllPrimes(tuples[0][1]);
    unordered_map<long long, bool> firstMap, secondMap;
    for (long long i = 0; i < primeFactors1.size(); i++) {
        firstMap[primeFactors1[i]] = true;
    }
    for (long long i = 0; i < primeFactors2.size(); i++) {
        secondMap[primeFactors2[i]] = true;
    }
    vector<long long> commonFactors;
    for ( auto it = firstMap.begin(); it != firstMap.end(); ++it ) {
        commonFactors.push_back(it->first);
    }
    for ( auto it = secondMap.begin(); it != secondMap.end(); ++it ) {
        commonFactors.push_back(it->first);
    }
    bool answerFlag = false;
    for (long long i = 0; i < commonFactors.size(); i++) {
        long long testNum = commonFactors[i];
        bool flag = true;
        for (long long j = 0; j < n; j++) {
            if (!((tuples[j][0]%testNum) == 0 || (tuples[j][1]%testNum) == 0 )) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout<<testNum<<endl;
            answerFlag = true;
            break;
        }
    }
    
    if (!answerFlag) {
        cout<<-1<<endl;
    }
    return 0;
}

