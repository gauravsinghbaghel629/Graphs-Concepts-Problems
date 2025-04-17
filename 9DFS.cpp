#include<bits/stdc++.h>
using namespace std;



void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &ls){
    vis[node] = 1;
    
    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int> dfsTraversal(vector<int> adj[],int n){
    int V = n;
    vector<int> vis(V,0);

    vector<int> ls;

    dfs(0,adj,vis,ls);

    return ls;
}

int main(){
    vector<int> adj[5];

    addEdge(adj,0,2);
    addEdge(adj,2,4);
    addEdge(adj,0,1);
    addEdge(adj,0,3);

    vector<int> ans = dfsTraversal(adj,5);

    printAns(ans);

    return 0;
}