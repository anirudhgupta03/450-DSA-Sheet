//https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0
void min_heapify(vector<int> &arr, int n, int i){
    
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    
    if(l < n && arr[l] < arr[smallest]){
        smallest = l;
    }
    if(r < n && arr[r] < arr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        min_heapify(arr, n, i);
    }
    return arr;
}
