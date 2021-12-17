//Ref: https://www.youtube.com/watch?v=bWowdBPkidw
// function should print the required range
class Solution{
    public:
    #define pipii pair<int,pair<int,int>>
    struct cmp{
        bool operator()(pipii p1, pipii p2){
            return p1.first > p2.first;
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          priority_queue<pipii,vector<pipii>,cmp> pq;
          
          int mine = INT_MAX, maxe = INT_MIN;
          int range = INT_MAX;
          
          for(int i = 0; i < k; i++){
              pq.push({KSortedArray[i][0],{i,0}});
              mine = min(mine, KSortedArray[i][0]);
              maxe = max(maxe, KSortedArray[i][0]);
          }
          
          int lo, hi;
          while(!pq.empty()){
              
              mine = pq.top().first;
              
              int row = pq.top().second.first, col = pq.top().second.second;
              pq.pop();
              
              if(maxe - mine < range){
                range = maxe - mine;
                lo = mine;
                hi = maxe;
              }
              
              if(col + 1 < n){
                  maxe = max(maxe, KSortedArray[row][col + 1]);
                  pq.push({KSortedArray[row][col + 1],{row, col + 1}});
              }
              else{
                  break;
              }
          }
          return {lo,hi};
    }
};
