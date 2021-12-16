//https://www.codingninjas.com/codestudio/problems/build-heap_975375?leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=cuL8gXCSA58
void max_heapify(vector<int> &arr, int n, int i){
    
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
    return arr;
}
