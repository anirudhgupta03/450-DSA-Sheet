//Ref: https://www.youtube.com/watch?v=Y9Pu7nHpeFc
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};
*************************************************************/
void inorder(BinaryTreeNode* root, vector<int> &temp){
    
    if(root == NULL){
        return;
    }
   	inorder(root -> left, temp);
    temp.push_back(root -> data);
    inorder(root -> right, temp);
}
void preorder(BinaryTreeNode* root, vector<int> &temp, int &i){
    
    if(root == NULL || i >= temp.size()){
        return;
    }
    root -> data = temp[i];
    i++;
   	preorder(root -> left, temp, i);
    preorder(root -> right, temp, i);
}


BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> temp;
    inorder(root, temp);
    
    int i = 0;
    preorder(root, temp, i);
    return root;
}
