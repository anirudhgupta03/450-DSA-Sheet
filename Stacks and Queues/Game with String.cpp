//Ref: https://www.youtube.com/watch?v=oqzAnZ1JvIw
class Solution{
public:
    int minValue(string s, int k){
        
        int alpha[26] = {0};
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        
        priority_queue<int> pq;
        
        for(int i = 0; i < 26; i++){
            if(alpha[i] != 0) pq.push(alpha[i]);
        }
        
        while(k-- && !pq.empty()){
            
            int ele = pq.top();
            pq.pop();
            
            ele--;
            if(ele != 0) pq.push(ele);
        }
        
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top()*pq.top();
            pq.pop();
        }
        return sum;
    }
};
