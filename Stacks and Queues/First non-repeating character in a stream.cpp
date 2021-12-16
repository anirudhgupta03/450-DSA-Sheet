class Solution{
public:
		string FirstNonRepeating(string A){
		    
		    int alpha[26];
		    memset(alpha,-1,sizeof(alpha));
		    
		    string res;
		    
		    for(int i = 0; i < A.size(); i++){
		        if(alpha[A[i] - 'a'] == -1){
		            alpha[A[i] - 'a'] = i;
		        }
		        else if(alpha[A[i] - 'a'] != A.size()){
		            alpha[A[i] - 'a'] = A.size();
		        }
		        
		        int ind = INT_MAX;
		        
		        for(int j = 0; j < 26; j++){
		            if(alpha[j] != -1 && alpha[j] != A.size()){
		                ind = min(ind, alpha[j]);
		            }
		        }
		        if(ind != INT_MAX){
		            res.push_back(A[ind]);
		        }
		        else{
		            res.push_back('#');
		        }
		    }
		    return res;
		}

};
//Ref: https://www.youtube.com/watch?v=3PJD81KZdUo
//Using Queue
class Solution{
	public:
		string FirstNonRepeating(string A){
		    
		    queue<char> q;
		    int alpha[26] = {0};
		    
		    string ans;
		    
		    for(int i = 0; i < A.size(); i++){
		        q.push(A[i]);
		        alpha[A[i] - 'a']++;
		        
		        while(!q.empty() && alpha[q.front() - 'a'] != 1){
		            q.pop();
		        }
		        
		        if(q.size() != 0){
		            ans.push_back(q.front());
		        }
		        else{
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
