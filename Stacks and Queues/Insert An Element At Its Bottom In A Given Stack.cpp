void insert_at_bottom(stack<int> &myStack, int x){
    
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    int ele = myStack.top();
    myStack.pop();
    insert_at_bottom(myStack, x);
    myStack.push(ele);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    insert_at_bottom(myStack, x);
    return myStack;
}
