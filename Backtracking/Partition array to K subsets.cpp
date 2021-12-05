//Ref: https://www.youtube.com/watch?v=3qN3bonkCG4
class Solution{
  public:
    bool solve(int a[], int n, int k, int sum, int count, vector<int> &vis, int reqsum){
        
        if(count == k - 1){
            return true;
        }
        
        if(sum == reqsum){
            bool flag = solve(a,n,k,0,count + 1, vis, reqsum);
            if(flag){
                return true;
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(sum + a[i] <= reqsum){
                    vis[i] = 1;
                    bool flag = solve(a,n,k,sum + a[i], count, vis, reqsum);
                    if(flag){
                        return true;
                    }
                    vis[i] = 0;
                }
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k > n) return false;
         
         if(n == 1) return true;
         
         int sum = 0;
         
         for(int i = 0; i < n; i++){
             sum += a[i];
         }
         
         if(sum % k != 0){
             return false;
         }
         
         vector<int> vis(n,0);
         
         return solve(a,n,k,0,0,vis,sum/k);
    }
};
