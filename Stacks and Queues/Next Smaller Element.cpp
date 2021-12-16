#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nsr(n);
    nsr[n-1] = -1;
    
    stack<int> st;
    st.push(arr[n-1]);
    
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > st.top()){
            nsr[i] = st.top();
        }
        else{
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = -1;
            }
            else{
                nsr[i] = st.top();
            }
        }
        st.push(arr[i]);
    }
    return nsr;
}
