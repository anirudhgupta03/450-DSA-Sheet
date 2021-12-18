//Ref: https://www.youtube.com/watch?v=c8J-NkNgMeo&t=277s
//Complete BT: https://www.youtube.com/watch?v=I_JuQ5ayPmc
// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int solve(Node* tree){
        
        if(tree == NULL){
            return 0;
        }
        return 1 + solve(tree -> left) + solve(tree -> right);
    }
    bool checkheap(Node* root, int ind, int n){
        
        if(root == NULL){
            return 1;
        }
        
        if(ind >= n){
            return 0;
        }
        
        if((root -> left && root -> left -> data >= root -> data) || (root -> right && root -> right -> data >= root -> data)){
            return 0;
        }
        return checkheap(root -> left, 2*ind + 1, n) && checkheap(root -> right, 2*ind + 2, n);
    }
    bool isHeap(struct Node* tree) {
        
        if(tree == NULL){
            return true;
        }
        
        int n = solve(tree);
        
        return checkheap(tree, 0, n);
    }
};
