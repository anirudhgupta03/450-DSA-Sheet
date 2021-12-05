//https://www.codingninjas.com/codestudio/problems/find-if-there-is-a-path-of-more-than-k-length-from-a-source_1229512
#include<bits/stdc++.h>
using namespace std;

bool solve(int node, int sum, vector<pair<int,int>> al[], vector<int> &vis, int k){
    
    if(sum > k){
        return true;
    }
    
    for(int i = 0; i < al[node].size(); i++){
        if(vis[al[node][i].first] == 0){
            vis[al[node][i].first] = 1;
            bool flag = solve(al[node][i].first, sum + al[node][i].second, al, vis, k);
            if(flag){
                return true;
            }
            vis[al[node][i].first] = 0;
        }
    }
    return false;
}
string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges)
{
    vector<int> vis(n, 0);
    vis[0] = 1;
    
    vector<pair<int,int>> al[n];
    
    int a,b,w;
    for(int i = 0; i < edges.size(); i++){
        a = edges[i][0], b = edges[i][1], w = edges[i][2];
        al[a].push_back({b,w});
        al[b].push_back({a,w});
    }
    
    bool flag = solve(0,0,al,vis,k);
    
    if(flag){
        return "YES";
    }
    return "NO";
}
