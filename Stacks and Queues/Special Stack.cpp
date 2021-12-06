//Ref: https://www.youtube.com/watch?v=QTrNy-0Og7E
int minEle;

void push(stack<int>& s, int a){
    if(isEmpty(s)){
        minEle = a;
        s.push(a);
    }
    else{
        if(a < minEle){
            s.push(2*a - minEle);
            minEle = a;
        }
        else{
            s.push(a);
        }
    }
}

bool isFull(stack<int>& s,int n){
	if(s.size() == n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size() == 0){
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	if(!isEmpty(s)){
	    int ele = s.top();
	    s.pop();
	    if(ele < minEle){
	        minEle = 2*minEle - ele;
	        ele = minEle;
	    }
	    return ele;
	}
	else{
	    return -1;
	}
}

int getMin(stack<int>& s){
	return minEle;
}
