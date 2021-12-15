//Ref: https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/
//https://www.codingninjas.com/codestudio/problems/n-queue-using-array_1170053?leftPanelTab=0

class NQueue{
public:
    // Initialize your data structure.
    vector<int> arr, front, rear, next;
    int free;
    
    NQueue(int n, int s){
        
        free = 0;
        
        arr.clear();
        arr.resize(s);
        
        front.clear();
        front.resize(n,-1);
        
        rear.clear();
        rear.resize(n);
        
        next.clear();
        next.resize(s);
        
        for(int i = 0; i < s; i++){
            if(i == s - 1){
                next[i] = -1;
            }
            else{
                next[i] = i + 1;
            }
        }
    }
	bool isFull(){
        if(free == -1){
            return true;
        }
        return false;
    }
    bool isEmpty(int m){
        if(front[m-1] == -1){
            return true;
        }
        return false;
    }
    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(isFull()){
            return false;
        }
        int i = free;
        free = next[i];
        
        if(isEmpty(m)){
            front[m-1] = i;
        }
        else{
            next[rear[m-1]] = i;
        }
        next[i] = -1;
        rear[m-1] = i;
        arr[i] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(isEmpty(m)){
            return -1;
        }
        int i = front[m-1];
        front[m-1] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};
