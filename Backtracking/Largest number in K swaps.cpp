//Ref: https://www.youtube.com/watch?v=ZnfqHvAt9bE
//Excellent Question
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(int ind, string &str, string &ans, int k){
        
        if(k >= 0){
            if(ans < str){
                ans = str;
            }
            if(k == 0){
                return;
            }
        }
        
        if(ind == str.size()){
            return;
        }
        
        char maxchar = str[ind];
        
        for(int i = ind + 1; i < str.size(); i++){
            if(str[i] > maxchar){
                maxchar = str[i];
            }
        }
        
        if(maxchar != str[ind]){
            for(int i = ind + 1; i < str.size(); i++){
                if(str[i] == maxchar){
                    swap(str[i],str[ind]);
                    solve(ind + 1, str, ans, k - 1);
                    swap(str[i],str[ind]);
                }
            }
        }
        else{
            solve(ind + 1, str, ans, k);    //Important Step
        }
    }
    string findMaximumNum(string str, int k)
    {
       string ans;
       solve(0,str,ans,k);
       return ans;
    }
};
