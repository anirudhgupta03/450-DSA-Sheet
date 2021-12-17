/*
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    struct cmp{
      bool operator()(Node* node1, Node* node2){
          return node1 -> data > node2 -> data;
      }  
    };
    Node * mergeKLists(Node *arr[], int K)
    {
           priority_queue<Node*,vector<Node*>,cmp> pq;
           
           for(int i = 0; i < K; i++){
               pq.push(arr[i]);
           }
           
           Node* head = NULL, *prev = NULL;
           
           while(!pq.empty()){
               
               Node* curr = pq.top();
               pq.pop();
               
               if(head == NULL){
                   head = curr;
                   prev = curr;
               }
               else{
                   prev -> next = curr;
                   prev = curr;
               }
               Node* temp = curr -> next;
               curr -> next = NULL;
               
               if(temp){
                   pq.push(temp);
               }
           }
           return head;
    }
};
