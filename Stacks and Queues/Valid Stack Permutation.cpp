//https://www.codingninjas.com/codestudio/problems/valid-stack-permutation_1170061?leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=KsIeZfmvuVQ
bool validStackPermutation(vector<int> &first, vector<int> &other){
	
    stack<int> st;
    
    int ind = 0;
    
    for(int i = 0; i < first.size(); i++){
        if(first[i] == other[ind]){
            ind++;
        }
        else{
            while(!st.empty() && st.top() == other[ind]){
                st.pop();
                ind++;
            }
            st.push(first[i]);
        }
    }
    while(!st.empty() && st.top() == other[ind]){
           st.pop();
           ind++;
    }
    if(st.size() == 0){
        return true;
    }
    return false;
}
