class Solution
{
    public:
    //Function to merge k sorted arrays.
    #define pipii pair<int,pair<int,int>>
    struct cmp{
        bool operator()(pipii p1, pipii p2){
            return p1.first > p2.first;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pipii,vector<pipii>,cmp> pq;
        
        for(int i = 0; i < K; i++){
            pq.push({arr[i][0],{i,0}});
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            
            res.push_back(pq.top().first);
            int i = pq.top().second.first, j = pq.top().second.second;
            
            pq.pop();
            
            if(j < K - 1){
                j++;
                pq.push({arr[i][j],{i,j}});
            }
        }
        return res;
    }
};
