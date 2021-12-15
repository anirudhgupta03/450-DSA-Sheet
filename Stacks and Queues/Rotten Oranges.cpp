//Using BFS
//Ref: https://www.youtube.com/watch?v=pUAPcVlHLKA
class Solution
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt= 0;
        
        queue<pair<int,int>> rotten;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;
            
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo < 0 || yo < 0 || xo >= m || yo >= n || grid[xo][yo] != 1) continue;
                    grid[xo][yo] = 2;
                    rotten.push({xo,yo});
                }
            }
            if(!rotten.empty()) days++;
        }
        return tot == cnt ? days : -1;
    }
};
