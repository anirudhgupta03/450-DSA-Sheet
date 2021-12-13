/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int t){
    
    if(s.size() == 0){
        s.push(t);
        return;
    }
    
    if(t >= s.top()){
        s.push(t);
        return;
    }
    int ele = s.top();
    s.pop();
    insert(s, t);
    s.push(ele);
}
void SortedStack :: sort()
{
   if(s.size() == 1){
       return;
   }
   
   int t = s.top();
   s.pop();
   sort();
   insert(s,t);
}
