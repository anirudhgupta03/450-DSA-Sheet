/*Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Only a stack can be used as an auxiliary space.*/

//Method - 1
void interLeaveQueue(queue < int > & q) {
    
    int n = q.size();
    
    vector<int> v1, v2;
    
    while(q.size() != n/2){
        int ele = q.front();
        q.pop();
        v1.push_back(ele);
    }
    
    while(q.size() != 0){
        int ele = q.front();
        q.pop();
        v2.push_back(ele);
    }
    
    int ind = 0;
    while(ind != n/2){
        q.push(v1[ind]);
        q.push(v2[ind]);
        ind++;
    }
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=d10MEFb4bYo
void interLeaveQueue(queue < int > & q) {
    stack<int> st;
    
    int n = q.size();
    
    //insert half of the elements in the stack
    while(q.size() != n/2){
        st.push(q.front());
        q.pop();
    }
    
    //enqueue
    while(st.size()){
        q.push(st.top());
        st.pop();
    }
    
    //dequeue and enqueue first half of the queue 
    int i = 0;
    while(i != n/2){
        q.push(q.front());
        q.pop();
        i++;
    }
    
    //push half of the elements to the stack
    while(q.size() != n/2){
        st.push(q.front());
        q.pop();
    }
    
    while(st.size()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}
