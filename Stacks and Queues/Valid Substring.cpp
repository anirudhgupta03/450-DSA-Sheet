  class Solution{
  public:
    int findMaxLen(string s) {
        
        stack<int> st1;
        stack<char> st2;
        
        st1.push(-1);
        
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                st2.push(s[i]);
                st1.push(i);
            }
            else{
                if(st2.empty()){
                    st2.push(s[i]);
                    st1.push(i);
                }
                else{
                    if(st2.top() == '('){
                        st1.pop();
                        maxLen = max(maxLen, i - st1.top());
                        st2.pop();
                    }
                    else{
                        st2.push(s[i]);
                        st1.push(i);
                    }
                }
            }
        }
        return maxLen;
    }
};
