//https://www.codingninjas.com/codestudio/problems/print-all-possible-paths-from-top-left-corner-to-bottom-right-corner-of-a-2-d-matrix_1171152?leftPanelTab=1
int dx[4] = {1,0};
int dy[4] = {0,1};

bool isValid(int x, int y, int m, int n){
    if(x >= 0 && y >= 0 && x < m && y < n){
        return true;
    }
    return false;
}
void solve(int x, int y, vector<int> &temp, vector<vector<int>> &res, vector<vector<int>> &mat, int m, int n, vector<vector<int>> &vis){
    
    if(x == m - 1 && y == n - 1){
        res.push_back(temp);
        return;
    }
    
    //temp.push_back(mat[x][y]);
    
    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(isValid(xo,yo,m,n)){
            if(vis[xo][yo] == 0){
                vis[xo][yo] = 1;
                temp.push_back(mat[xo][yo]);
                solve(xo, yo, temp, res, mat, m, n, vis);
                temp.pop_back();
                vis[xo][yo] = 0;
            }
        }
    }
}
vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    
    temp.push_back(mat[0][0]);
    
    vector<vector<int>> vis(m, vector<int>(n,0));
    vis[0][0] = 1;
    solve(0,0,temp,res, mat, m, n, vis);
    
    return res;
}
