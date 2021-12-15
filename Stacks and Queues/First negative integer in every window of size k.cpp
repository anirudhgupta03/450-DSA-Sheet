#define ll long long
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    queue<ll> q;
    
    for(int i = 0; i < K; i++){
        if(A[i] < 0)
        q.push(A[i]);
    }
    
    vector<ll> res;
    
    for(int i = 0; i <= N - K; i++){
        
        if(!q.empty()){
            res.push_back(q.front());   
        }
        else{
            res.push_back(0);
        }
        
        if(A[i] == q.front()){
            q.pop();
        }
        if(A[i + K] < 0){
            q.push(A[i+K]);
        }
    }                        
    return res;
 }
