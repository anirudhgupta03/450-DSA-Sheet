//Ref: https://www.youtube.com/watch?v=1LkOrc-Le-Y
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    void insertHeap(int &num)
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        
        if(lsize == 0){
            maxheap.push(num);
        }
        else if(lsize == rsize){
             if(num < minheap.top()){
                 maxheap.push(num);
             } 
             else{
                 int temp = minheap.top();
                 minheap.pop();
                 minheap.push(num);
                 maxheap.push(temp);
             }
        }
        else{
            if(minheap.size() == 0){
                if(num > maxheap.top()){
                    minheap.push(num);
                }
                else{
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if(num >= minheap.top()){
                minheap.push(num);
            }
            else{
                if(num < maxheap.top()){
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
                else{
                    minheap.push(num);
                }
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        
        if(lsize > rsize){
            return double(maxheap.top());
        }
        else{
            return ((double)(maxheap.top()) + (double)(minheap.top()))/2.0;
        }
    }
};
