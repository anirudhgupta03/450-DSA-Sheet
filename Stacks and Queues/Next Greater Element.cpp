class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<long long> res(n);
        res[n-1] = -1;
        
        stack<long long> ngr;
        ngr.push(arr[n-1]);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < ngr.top()){
                res[i] = ngr.top();
            }
            else{
                while(!ngr.empty() && arr[i] >= ngr.top()){
                    ngr.pop();
                }
                
                if(ngr.empty()){
                    res[i] = -1;
                }
                else{
                    res[i] = ngr.top();
                }
            }
            ngr.push(arr[i]);
        }
        
        return res;
    }
};
