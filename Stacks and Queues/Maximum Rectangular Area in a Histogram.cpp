class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    #define ll long long
    long long getMaxArea(long long arr[], int n)
    {
        stack<ll> st;
        
        vector<int> nsl(n);
        nsl[0] = -1;
        
        st.push(0);
        
        for(int i = 1; i < n; i++){
            
            if(arr[i] > arr[st.top()]){
                nsl[i] = st.top();
            }
            else{
                while(!st.empty() && arr[i] <= arr[st.top()]){
                    st.pop();
                }
                
                if(!st.empty()){
                    nsl[i] = st.top();
                }
                else{
                    nsl[i] = -1;
                }
            }
            st.push(i);
        }
        
        while(st.size()){
            st.pop();
        }
        
        vector<int> nsr(n);
        nsr[n-1] = n;
        st.push(n-1);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[st.top()]){
                nsr[i] = st.top();
            }
            else{
                while(!st.empty() && arr[i] <= arr[st.top()]){
                    st.pop();
                }
                
                if(!st.empty()){
                    nsr[i] = st.top();
                }
                else{
                    nsr[i] = n;
                }
            }
            st.push(i);
        }
        
        ll maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, (nsr[i] - nsl[i] - 1)*arr[i]);
        }
        return maxArea;
    }
};
