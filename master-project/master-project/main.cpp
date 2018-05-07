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

long minimum(long first, long second)
{
    long min = first>second?second:first;
    return min;
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>evenNums,oddNums;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if((i%2) == 0)
            {
                evenNums.push_back(num);
            }
            else
            {
                oddNums.push_back(num);
            }
        }
        sort(evenNums.begin(), evenNums.end());
        sort(oddNums.begin(), oddNums.end());
        vector<int> cumulativeEvens(evenNums.size()+1, 0);
        vector<int> cumulativeOdds(oddNums.size()+1, 0);
        for(int i=0;i<evenNums.size();i++)
        {
            cumulativeEvens[i+1] = cumulativeEvens[i] + evenNums[i];
        }
        for(int i=0;i<oddNums.size();i++)
        {
            cumulativeOdds[i+1] = cumulativeOdds[i] + oddNums[i];
        }
        if(n == 1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(cumulativeOdds[cumulativeOdds.size()-1] > cumulativeEvens[cumulativeEvens.size()-1])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                int kNew =(int) minimum(evenNums.size(), oddNums.size());
                k = k>kNew ?kNew: k;
                int oddSum = cumulativeOdds[cumulativeOdds.size()-1];
                int evenSum = cumulativeEvens[cumulativeEvens.size()-1];
                int rightExtarctedSum = cumulativeOdds[k];
                int leftExtarctedSum = cumulativeEvens[cumulativeEvens.size()-1] - cumulativeEvens[cumulativeEvens.size()-1-k];

                if (oddSum - rightExtarctedSum + leftExtarctedSum > evenSum -leftExtarctedSum + rightExtarctedSum)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    
    return 0;
}

