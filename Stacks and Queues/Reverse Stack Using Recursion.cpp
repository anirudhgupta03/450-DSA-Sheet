//https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0
void insert_at_bottom(stack<int> &stack, int ele){
    
    if(stack.size() == 0){
        stack.push(ele);
        return;
    }
    
    int t = stack.top();
    stack.pop();
    insert_at_bottom(stack, ele);
    stack.push(t);
}
void reverseStack(stack<int> &stack) {
    
    if(stack.size() == 0){
        return;
    }
    
    int ele = stack.top();
    stack.pop();
    reverseStack(stack);
    insert_at_bottom(stack, ele);
}
