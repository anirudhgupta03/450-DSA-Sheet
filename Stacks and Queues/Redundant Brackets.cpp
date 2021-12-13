#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                return true;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}
