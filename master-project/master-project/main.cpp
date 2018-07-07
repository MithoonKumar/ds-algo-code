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

void printPermutations(string str, string temp, int tempLength, int length, bool visited[3])
{
    if(tempLength == length)
    {
        cout<<temp<<endl;
    }
    for(int i=0;i<length;i++)
    {
        if(!visited[i])
        {
            temp[tempLength] = str[i];
            visited[i] = true;
            printPermutations(str, temp, tempLength+1, length, visited);
            visited[i] = false;
        }
    }
}

int main(){
    //freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    string str;
    str = "abc";
    string temp="...";
    bool visited[3] ;
    for(int i=0;i<3;i++)
    {
        visited[i] = false;
    }
    printPermutations(str, temp, 0, 3, visited);
    return 0;
}

