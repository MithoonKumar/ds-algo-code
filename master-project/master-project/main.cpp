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

void doFakeBinarySearch(int pos,vector<int>&unsortedVec, int start, int end, vector<int>&mismatchedSmall, vector<int>&mismatchedBig, vector<int>&matchedSmall, vector<int>&matchedBig)
{
    int mid = (start + end) /2;
    if (mid == pos)
    {
        return ;
    }
    else if (mid > pos)
    {
        if(unsortedVec[mid]>unsortedVec[pos])
        {
            matchedBig.push_back(unsortedVec[mid]);
        }
        else if (unsortedVec[mid]<unsortedVec[pos])
        {
            mismatchedSmall.push_back(unsortedVec[mid]);
        }
        doFakeBinarySearch(pos, unsortedVec, start, mid-1, mismatchedSmall, mismatchedBig, matchedSmall, matchedBig);
    }
    else
    {
        if(unsortedVec[mid]<unsortedVec[pos])
        {
            matchedSmall.push_back(unsortedVec[mid]);
        }
        else if (unsortedVec[mid]>unsortedVec[pos])
        {
            mismatchedBig.push_back(unsortedVec[mid]);
        }
        doFakeBinarySearch(pos, unsortedVec, mid+1, end, mismatchedSmall, mismatchedBig, matchedSmall, matchedBig);
    }

}

int main(){
    //freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int>unsortedVec;
        for(int i=0; i<n; i++)
        {
            int num;
            cin>>num;
            unsortedVec.push_back(num);
        }
        vector<int>sorted;
        for(int i=0; i<n; i++)
        {
            sorted.push_back(unsortedVec[i]);
        }
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int>sortedPositions, unsortedPositions;
        for(int i=0; i<n; i++)
        {
            sortedPositions[sorted[i]] = i;
            unsortedPositions[unsortedVec[i]] = i;
        }
        for(int i=0; i<q; i++)
        {
            int num;
            cin>>num;
            int count = 0;
            int pos = unsortedPositions[num];
            vector<int>mismatchedSmall, mismatchedBig, matchedSmall, matchedBig;
            doFakeBinarySearch(pos, unsortedVec, 0, unsortedVec.size()-1, mismatchedSmall, mismatchedBig, matchedSmall, matchedBig);
            int posOfQuerriedNum = sortedPositions[num];
            if (mismatchedSmall.size()>mismatchedBig.size())
            {
                int someCount = n - sortedPositions[num] - 1;
                if (someCount< (mismatchedBig.size() + matchedBig.size() + mismatchedSmall.size() -mismatchedBig.size()))
                {
                    cout<<-1<<endl;
                }
                else
                {
                    cout<<mismatchedSmall.size()<<endl;
                }
            }
            else if (mismatchedSmall.size()<mismatchedBig.size())
            {
                int someCount = sortedPositions[num];
                if (someCount< (mismatchedSmall.size() + matchedSmall.size() + mismatchedBig.size() -mismatchedSmall.size()))
                {
                    cout<<-1<<endl;
                }
                else
                {
                    cout<<mismatchedBig.size()<<endl;
                }
            }
            else
            {
                cout<<mismatchedBig.size()<<endl;
            }
        }
        
        
        
    }
    return 0;
}

