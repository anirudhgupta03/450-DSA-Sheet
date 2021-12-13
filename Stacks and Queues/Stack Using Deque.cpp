//https://www.codingninjas.com/codestudio/problems/stack-using-deque_1170512?leftPanelTab=0
class Stack
{
public:
    // Initialize your data structure.
    deque<int> dq;
    Stack()
    {
        dq.clear();
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        dq.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(!dq.empty()){
           	int ele =  dq.back();
            dq.pop_back();
            return ele;
        }
        else{
            return -1;
        }
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(!dq.empty()){
            int ele =  dq.back();
            return ele;
        }
        else{
            return -1;
        }
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if(dq.size() == 0){
            return true;
        }
        return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return dq.size();
    }
};
