//Ref: https://www.youtube.com/watch?v=7AhF1h1fGnk
class Solution
{
    public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size(), n = grid[0].size();
	    
	    vector<vector<int>> ans(m,vector<int>(n, INT_MAX));
	    queue<pair<int,int>> q;
	    
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            if(grid[i][j] == 1){
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int x = q.front().first, y = q.front().second;
	        q.pop();
	        
	        for(int i = 0; i < 4; i++){
	            int xo = x + dx[i], yo = y + dy[i];
	            
	            if(xo >= 0 && xo < m && yo >= 0 && yo < n){
	                if(ans[xo][yo] > ans[x][y] + 1){
	                    ans[xo][yo] = ans[x][y] + 1;
	                    q.push({xo,yo});
	                }
	            }
	        }
	    }
	    return ans;
	}
};
