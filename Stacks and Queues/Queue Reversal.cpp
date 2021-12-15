//function Template for C++

//Function to reverse the queue.

void solve(queue<int> &q){
    
    if(q.size() == 0){
        return;
    }
    
    int ele = q.front();
    q.pop();
    solve(q);
    q.push(ele);
}
queue<int> rev(queue<int> q)
{
   solve(q);
   return q;
}
