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
};

void insert (string str, int pos, trieNode *rootNode)
{
    if(rootNode->children[str[pos]-'a']==NULL)
    {
        trieNode *newNode = new trieNode();
        for(int i=0;i<26;i++)
        {
            newNode->children[i] = NULL;
        }
        rootNode->children[str[pos]-'a'] = newNode;
        rootNode->children[str[pos]-'a']->isLeafNode = false;
    }
    if(str.length() == pos+1)
    {
        rootNode->children[str[pos]-'a']->isLeafNode = true;
    }
    else
    {
        insert(str, pos+1, rootNode->children[str[pos]-'a']);
    }
}

bool search (trieNode *root, string str, int pos)
{
    if(str.length() == pos && root->isLeafNode)
    {
        return true;
    }
    else if(root->children[str[pos]-'a'] ==NULL)
    {
        return false;
    }
    else
    {
        return search(root->children[str[pos]-'a'], str, pos+1);
    }
}

int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    trieNode root;
    for(int i=0;i<26;i++)
    {
        root.children[i] = NULL;
    }
    root.isLeafNode = false;
    for(int i=0;i<2;i++)
    {
        string str;
        cin>>str;
        insert(str,0,&root);
    }
    for(int i=0;i<10;i++)
    {
        string str;
        cin>>str;
        cout<<search(&root,str,0)<<endl;
    }
    return 0;
}

