//Ref: https://www.youtube.com/watch?v=kU4KBD4NFtw
//codingninjas.com/codestudio/problems/heap-sort_1262153?leftPanelTab=0
void max_heapify(vector<int> &arr, int n, int i){
    
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    int largest = i;
    
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
vector<int> heapSort(vector<int>& arr, int n) {
	
    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, n, i);
    }
    
	for(int i = n - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }    
    return arr;
}
