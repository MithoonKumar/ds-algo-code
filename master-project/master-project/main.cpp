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

struct trieNode
{
    trieNode * children[26];
    bool isLeafNode;
    trieNode()
    {
        for(int i=0;i<26;i++)
        {
            this->children[i] = NULL;
        }
        this->isLeafNode = false;
    }
};

void insert (string str, trieNode *root)
{
    trieNode * pointer = root;
    for(int i=0;i<str.length();i++)
    {
        if(pointer->children[str[i]-'a'] == NULL)
            pointer->children[str[i]-'a'] = new trieNode();
        pointer = pointer->children[str[i]-'a'];
    }
    pointer->isLeafNode =true;
}

bool search (string str,trieNode *root)
{
    trieNode * pointer = root;
    for(int i=0;i<str.length();i++)
    {
        if(pointer->children[str[i]-'a'] == NULL)
        {
            return false;
        }
        pointer = pointer->children[str[i]-'a'];
    }
    return pointer->isLeafNode;
}

int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    trieNode node;
    for(int i=0;i<2;i++)
    {
        string str;
        cin>>str;
        insert(str, &node);
    }
    for(int i=0;i<10;i++)
    {
        string str;
        cin>>str;
        cout<<search(str, &node)<<endl;
    }
    
    return 0;
}

