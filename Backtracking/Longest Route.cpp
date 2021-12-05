//https://www.codingninjas.com/codestudio/problems/longest-route_1170525?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
int px[4] = {-1,1,0,0};
int py[4] = {0,0,-1,1};

void solve(int x, int y, int dx, int dy, int &ans, int len, vector<vector<int>> &mat, vector<vector<int>> &vis){
    
    if(x == dx && y == dy){
         ans = max(ans,len);
         return;
    }
    
    for(int i = 0; i < 4; i++){
        int xo = x + px[i], yo = y + py[i];
        if(xo >= 0 && yo >= 0 && xo < mat.size() && yo < mat[0].size() && mat[xo][yo] == 1){
            if(vis[xo][yo] == 0){
                vis[xo][yo] = 1;
                solve(xo,yo,dx,dy,ans,len+1,mat,vis);
                vis[xo][yo] = 0;
            }
        }
    }
}
int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
	
    if(mat[sx][sy] == 0 || mat[dx][dy] == 0){
        return -1;
    }
    
    int ans = INT_MIN;
    vector<vector<int>> vis(n, vector<int>(m,0));
    
    vis[sx][sy] = 1;
    solve(sx,sy,dx,dy,ans,0,mat,vis);
    
    if(ans == INT_MIN) return -1;
    return ans;
}
