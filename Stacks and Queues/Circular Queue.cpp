//https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0
class CircularQueue{
    public:
    // Initialize your data structure.
    int rear, front, size;
    vector<int> arr;
    
    CircularQueue(int n){
        size = n;
        front = rear = -1;
        arr.clear();
        arr.resize(n);
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        
        if((front == 0 && rear == size - 1) || (front == rear + 1)){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size - 1 && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        
        if(front == -1){
            return -1;
        }
        int data = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
        return data;
    }
};
