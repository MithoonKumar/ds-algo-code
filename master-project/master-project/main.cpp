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

void printnC2(string str, string temp, int index, int combinationLength)
{
    if(temp.length() == combinationLength)
    {
        cout<<temp<<endl;
        return;
    }
    if (index == str.length())
    {
        return;
    }
    
        temp.push_back(str[index]);
        printnC2(str, temp, index+1, combinationLength);
        temp.pop_back();
        printnC2(str, temp, index+1, combinationLength);
}

int main(){
    //freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    string str="abcd", temp;
    printnC2(str, temp, 0, 2);
    
}

