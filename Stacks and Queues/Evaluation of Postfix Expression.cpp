class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i = 0; i < S.size(); i++){
            
            if(S[i] == '*' || S[i] == '+' ||S[i] == '-' || S[i] == '/'){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                if(S[i] == '*') st.push(val2*val1);
                if(S[i] == '-') st.push(val2 - val1);
                if(S[i] == '+') st.push(val2 + val1);
                if(S[i] == '/') st.push(val2/val1);
            }
            else if(isdigit(S[i])){
                st.push(S[i] - '0');
            }
        }
        return st.top();
    }
};
