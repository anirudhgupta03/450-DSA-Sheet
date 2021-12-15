// User function Template for C++

// Function to reverse first k elements of a queue.
void solve(queue<int> &q, int k){
    
    if(k == 0){
        return;
    }
    
    int ele = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k) {
    
    solve(q, k);
    
    int ind = 0;
    while(ind != q.size() - k){
        int ele = q.front();
        q.pop();
        q.push(ele);
        ind++;
    }
    return q;
}
