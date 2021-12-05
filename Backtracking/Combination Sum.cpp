//Ref: https://www.youtube.com/watch?v=SBN_fz18T1U
class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int ind, int sum, vector<int> &A, int B, vector<int> &temp, vector<vector<int>> &ans){
        
        if(sum == B){
            ans.push_back(temp);
            return;
        }
        
        if(ind == A.size()){
            return;
        }
        
        if(sum + A[ind] <= B){
            temp.push_back(A[ind]);
            solve(ind, sum + A[ind], A, B, temp, ans);
            temp.pop_back();
            solve(ind + 1, sum, A, B, temp, ans);
        }
        //
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        
        set<int> st;
        
        for(int i = 0; i < A.size(); i++){
            st.insert(A[i]);
        }
        
        A.clear();
        
        for(auto it: st){
            A.push_back(it);
        }
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0,0,A,B,temp,ans);
        
        return ans;
    }
};
