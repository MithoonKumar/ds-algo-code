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

void findAllPerm(string str,vector<string>&allPerm,int pos,int len,string tempPerm,bool *visited)
{
    if(pos == len)
    {
        allPerm.push_back(tempPerm);
        return;
    }
    
    for(int i=0;i<str.length();i++)
    {
      if(!visited[i])
      {
          tempPerm[pos] = str[i];
          visited[i] = true;
          findAllPerm(str, allPerm, pos+1, len, tempPerm,visited);
          visited[i] = false;
      }
    }
    
}

int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    string str;
    cin>>str;
    vector<string>allPerm;
    bool visited[str.length()];
    for(int i=0;i<str.length();i++)
    {
        visited[i] = false;
    }
    findAllPerm(str,allPerm,0,str.length(),str,visited);
    for(int i=0;i<allPerm.size();i++)
    {
        cout<<allPerm[i]<<endl;
    }
    return 0;
}

