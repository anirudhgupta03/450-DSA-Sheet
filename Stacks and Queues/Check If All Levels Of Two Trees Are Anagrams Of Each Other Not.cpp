//https://www.codingninjas.com/codestudio/problems/check-if-all-levels-of-two-trees-are-anagrams-of-each-other-not_1214546?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class TreeNode {
    public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool anagram(TreeNode<int>*root1, int n, TreeNode<int>*root2, int m)
{
	if(n != m){
        return false;
    }
    
    queue<TreeNode<int>*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    
    while(!q1.empty() || !q2.empty()){
        
        int sz1 = q1.size(), sz2 = q2.size();
        if(sz1 != sz2){
            return false;
        }
        vector<int> v1, v2;
        while(sz1--){
            
            TreeNode<int>* temp1 = q1.front();
            q1.pop();
            v1.push_back(temp1 -> val);
            
            TreeNode<int>* temp2 = q2.front();
            q2.pop();
            v2.push_back(temp2 -> val);
            
            if(temp1 -> right){
                q1.push(temp1 -> right);
            }
            if(temp1 -> left){
                q1.push(temp1 -> left);
            }
            if(temp2 -> right) q2.push(temp2 -> right);
            if(temp2 -> left) q2.push(temp2 -> left);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
    }
    return true;
}
