//youtube.com/watch?v=IWOcH6cjTpw
//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> st;
    
    for(int i = 0; i < len; i++){
        st.push(S[i]);
    }
    
    char *s = new char[len];
    int ind = 0;
    
    while(!st.empty()){
        s[ind] = st.top();
        st.pop();
        ind++;
    }
    s[ind] = '\0';
    return s;
}
