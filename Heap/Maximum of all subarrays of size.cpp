class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        
        for(int i = 0; i < k; i++){
            
            if(i == 0) dq.push_back(arr[i]);
            else if(arr[i] > dq.back()){
                while(!dq.empty() && arr[i] > dq.back()){
                    dq.pop_back();
                }
                dq.push_back(arr[i]);
            }
            else{
                dq.push_back(arr[i]);
            }
        }
        
        vector<int> res;
        for(int i = 0; i <= n - k; i++){
            
            res.push_back(dq.front());
            if(dq.front() == arr[i]) dq.pop_front();
            
            if(arr[i + k] > dq.back()){
                while(!dq.empty() && arr[i + k] > dq.back()){
                    dq.pop_back();
                }
                dq.push_back(arr[i + k]);
            }
            else{
                dq.push_back(arr[i + k]);
            }
        }
        return res;
    }
};
