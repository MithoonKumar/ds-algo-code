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

struct node
{
    node * next;
    int nodeIndex;
    node (node *next, int index)
    {
        this->next = next;
        this->nodeIndex = index;
    }
};
node *nodeArr[300001];
vector<int>path;
void pathDfs(int x, int y,bool *visited, bool &pathFound)
{
    node *src = nodeArr[x];
    visited[src->nodeIndex] = true;
    path.push_back(x);
    if(x==y)
    {
        pathFound = true;
        return;
    }
    while(src!=NULL)
    {
        if(src->next && !visited[src->next->nodeIndex] && !pathFound)
        {
            pathDfs(src->next->nodeIndex, y, visited, pathFound);
        }
        if(pathFound)
        {
            return;
        }
        src = src->next;
    }
    path.pop_back();
}

void removeEdge(int a, int b)
{
    node * root = nodeArr[a];
    while(true)
    {
        if(root->next->nodeIndex == b)
        {
            root->next = root->next->next;
            return;
        }
        root = root->next;
    }
}

void individualDFS(int a, long long  &count, bool * visited)
{
    node *src = nodeArr[a];
    visited[src->nodeIndex] = true;
    count++;
    while(src!=NULL)
    {
        if(src->next && !visited[src->next->nodeIndex])
        {
            individualDFS(src->next->nodeIndex, count, visited);
        }
        src=src->next;
    }
}

void removeEdges()
{
    if(path.size() == 2)
    {
        removeEdge(path[0], path[1]);
        removeEdge(path[1], path[0]);
    }
    else
    {
        removeEdge(path[0], path[1]);
        removeEdge(path[1], path[0]);
        removeEdge(path[path.size()-2], path[path.size()-1]);
        removeEdge(path[path.size()-1], path[path.size()-2]);
    }
    
}

int main(){
    freopen("/Users/mithoonkumar/Documents/personal-github-repo/ds-algo-code/ds-algo-code/master-project/master-project/input.txt","r",stdin);
    faster;
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1; i<=n; i++)
    {
        nodeArr[i] = new node(NULL, i);
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        node *tempNode  = new node(NULL, b);
        node *root = nodeArr[a];
        while(true)
        {
            if(root->next == NULL)
            {
                root->next = tempNode;
                break;
            }
            root= root->next;
        }
        
        tempNode  = new node(NULL, a);
        root = nodeArr[b];
        while(true)
        {
            if(root->next == NULL)
            {
                root->next = tempNode;
                break;
            }
            root= root->next;
        }
    }
    bool visited[300001];
    bool pathFound = false;
    vector<int>path;
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    pathDfs(x, y, visited, pathFound);
    removeEdges();
    long long firstCount = 0;
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    individualDFS(x, firstCount, visited);
    long long secondCount = 0;
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    individualDFS(y, secondCount, visited);
    long long N = (long long )n;
    cout<<N*(N-1)-firstCount* secondCount<<endl;
    return 0;
}

