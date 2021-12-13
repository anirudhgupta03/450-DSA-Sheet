//https://www.codingninjas.com/codestudio/problems/arithmetic-expression-evaluation_1170517?leftPanelTab=0
//Good Question
//Ref: https://www.youtube.com/watch?v=IY0nZLEg6MA&t=656s
#include<bits/stdc++.h>
using namespace std;

int precedence(char optor){
    if(optor == '+'){
        return 1;
    }
    else if(optor == '-'){
        return 1;
    }
    else if(optor == '*'){
        return 2;
    }
    else if(optor == '/'){
        return 2;
    }
}

int operation(int v1, int v2, char optor){
    if(optor == '+'){
        return v1 + v2;
    }
    else if(optor == '-'){
        return v1 - v2;
    }
    else if(optor == '*'){
        return v1*v2;
    }
    else if(optor == '/'){
        return v1/v2;
    }
}
int evaluateArithmeticExpression(string &expression) 
{
	stack<int> st1;
    stack<char> st2;
    
    for(int i = 0; i < expression.size(); i++){
        
        char ch = expression[i];
        
        if(ch == '('){
            st2.push(ch);
        }
        else if(isdigit(ch)){
            string s;
            while(isdigit(expression[i]) && i < expression.size()){
                s.push_back(expression[i]);
                i++;
            }
            i--;
            st1.push(stoi(s));  
        }
        else if(ch == ')'){
            while(st2.top() != '('){
                char optor = st2.top();
                st2.pop();
                int v2 = st1.top();
                st1.pop();
                int v1 = st1.top();
                st1.pop();
                
                int opv = operation(v1, v2, optor);
                st1.push(opv);
            }
            st2.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            
            while(st2.size() != 0 && st2.top() != '(' && precedence(ch) <= precedence(st2.top())){
                char optor = st2.top();
                st2.pop();
                int v2 = st1.top();
                st1.pop();
                int v1 = st1.top();
                st1.pop();
            
                int opv = operation(v1, v2, optor);
                st1.push(opv);
            }
            st2.push(ch);
        }
    }
    while(st2.size() != 0){
        char optor = st2.top();
        st2.pop();
        if(st1.size() >= 2){
            int v2 = st1.top();
             st1.pop();
             int v1 = st1.top();
             st1.pop();

             int opv = operation(v1, v2, optor);
             st1.push(opv);
        }
        else{
            break;
        }
     }   
     return st1.top();
}
