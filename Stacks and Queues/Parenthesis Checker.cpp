class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i = 0; i < x.size(); i++){
            if(x[i] == '{' || x[i] == '(' || x[i] == '['){
                st.push(x[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(x[i] == '}' && st.top() != '{' || x[i] == ')' && st.top() != '(' || x[i] == ']' && st.top() != '['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        
        if(st.empty()){
            return true;
        }
        return false;
    }

};
