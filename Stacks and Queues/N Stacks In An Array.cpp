//https://www.youtube.com/watch?v=9x7TYLP3714&t=1589s
class NStack
{
public:
    // Initialize your data structure.
    vector<int> arr, top, next;
    int free = 0;
    
    NStack(int N, int S)
    {
        arr.clear();
     	arr.resize(S);
        top.clear();
        top.resize(N, -1);
        next.clear();
        next.resize(S);
        
        for(int i = 0; i < S; i++){
            if(i == S - 1){
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
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(isFull()){
            return false;
        }
        int i = free;
        free = next[i];
        next[i] = top[m - 1];
        top[m-1] = i;
        arr[i] = x;
        return true;
    }
	bool isEmpty(int m){
        if(top[m-1] == -1){
            return true;
        }
        return false;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(isEmpty(m)){
            return -1;
        }
        int i = top[m-1];
        top[m-1] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};
