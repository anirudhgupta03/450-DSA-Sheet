void max_heapify(long *arr, int n, int i){
    
    int l = 2*i + 1, r = 2*i + 2;
    int largest = i;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
void minHeapToMaxHeap(long *arr, int n)
{
    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
}
