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
bool deleteInTrie (string str, trieNode * root, int pos, int len)
{
    if(pos == len)
    {
        root->isLeafNode = false;
        bool flag = true;
        for(int i=0;i<26;i++)
        {
            if(root->children[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool flag = deleteInTrie(str, root->children[str[pos]-'a'], pos+1, len);
    if(flag)
    {
        root->children[str[pos]-'a'] = NULL;
        bool tempFlag = true;
        for(int i=0;i<26;i++)
        {
            if(root->children[i])
            {
                tempFlag = false;
                break;
            }
        }
        return tempFlag;
    }
    else
    {
        return flag;
    }
}

int main(){
    freopen("/Users/mithoonkumar/Documents/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    trieNode node;
    for(int i=0;i<7;i++)
    {
        string str;
        cin>>str;
        insert(str, &node);
    }
    for(int i=0;i<2;i++)
    {
        string str;
        cin>>str;
        deleteInTrie(str, &node, 0, str.length());
    }
    for(int i=0;i<7;i++)
    {
        string str;
        cin>>str;
        cout<<search(str, &node)<<endl;
    }
    return 0;
}

