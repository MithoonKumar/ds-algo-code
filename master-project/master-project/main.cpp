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

void swap(int firstIndex, int secondIndex, vector<int>&vec, vector<bool>&flag)
{
    int temp = vec[firstIndex];
    vec[firstIndex] = vec[secondIndex];
    vec[secondIndex] = temp;
    flag[firstIndex] = true;
    flag[secondIndex] = true;
}

int leftIndex(vector<int>vec, vector<bool>flag, int index, int num)
{
    int minIndex = -1;
    int minValue = num;
    for(int i = 0; i <index-1; i++)
    {
        if(flag[i] && vec[i]<minValue)
        {
            minValue = vec[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int rightIndex(vector<int>vec, vector<bool>flag, int index, int num)
{
    int maxIndex = -1;
    int maxValue = num;
    for(int i=(int)(vec.size()-1); i>index; i--)
    {
        if(!flag[i] && vec[i]>maxValue)
        {
            maxValue = vec[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findMinNumberOfSwaps(vector<int>vec, int num, int pos)
{
    vector<bool>flag(vec.size(), false);
    int low, high, mid;
    low = 0;
    int count = 0;
    high = (int)(vec.size()-1);
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (vec[mid] == num)
        {
            return count;
        }
        bool direction; //direction to be moved ,true for right and false for left
        if (pos > mid)
        {
            direction = true;
        }
        else
        {
            direction =false;
        }
        
        if (vec[mid] < num && direction)
        {
            low = mid+1;
            flag[mid] = true;
        }
        else if(vec[mid] > num && !direction)
        {
            high = mid-1;
            flag[mid] = true;
        }
        else if(direction)
        {
            int nextIndex = leftIndex(vec, flag, mid, num);
            if (nextIndex == -1)
            {
                return -1;
            }
            swap(mid, nextIndex, vec, flag);
            count++;
            low = mid+1;
        }
        else
        {
            int prevIndex = rightIndex(vec, flag, mid, num);
            if (prevIndex == -1)
            {
                return -1;
            }
            swap(mid, prevIndex, vec, flag);
            count++;
            high = mid -1;
        }
        
    }
    return count;
    
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
        int n,q;
        cin>>n>>q;
        vector<int>vec;
        unordered_map<int, int>hashMap;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            vec.push_back(num);
            hashMap[num] = i;
        }
        for(int i=0;i<q;i++)
        {
            int num;
            cin>>num;
            cout<<findMinNumberOfSwaps(vec, num, hashMap[num])<<endl;
        }
    }
    
    return 0;
}

