//Ref: https://www.youtube.com/watch?v=Xc4sICC8m4M
class LRUCache
{
    private:

    public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int capacity;
    unordered_map<int,node*> m;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addnode(node* newnode){
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    void deletenode(node* delnode){
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode -> val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head -> next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(m.find(key) != m.end()){
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == capacity){
            m.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        addnode(new node(key, value));
        m[key] = head -> next;
    }
};
