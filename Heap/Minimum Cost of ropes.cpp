class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    #define ll long long
    long long minCost(long long arr[], long long n) {
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        ll sum = 0;
        
        while(pq.size() != 1){
            
            ll c1 = pq.top();
            pq.pop();
            ll c2 = pq.top();
            pq.pop();
            
            sum += c1 + c2;
            pq.push(c1 + c2);
        }
        return sum;
    }
};
