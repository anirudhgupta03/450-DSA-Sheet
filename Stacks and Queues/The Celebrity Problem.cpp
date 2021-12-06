//Ref: https://www.youtube.com/watch?v=EbNw4LMWdL4
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
         stack<int> st;
         
         for(int i = 0; i < n; i++){
             st.push(i);
         }
         
         while(st.size() != 1){
             
             int e1 = st.top();
             st.pop();
             int e2 = st.top();
             st.pop();
             
             if(M[e1][e2] == 0){
                 st.push(e1);
             }
             else{
                 st.push(e2);
             }
         }
         
         int ans = st.top();
         
         for(int j = 0; j < n; j++){
             if(M[ans][j] == 1){
                 return -1;
             }
         }
         
         for(int i = 0; i < n; i++){
             if(i == ans) continue;
             else{
                 if(M[i][ans] == 0){
                     return -1;
                 }
             }
         }
         return ans;
    }
};
