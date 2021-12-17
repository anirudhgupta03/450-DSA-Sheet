class Solution{
    public:
    void max_heapify(vector<int> &res, int n, int i){
        
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        int largest = i;
        
        if(l < n && res[l] > res[largest]) largest = l;
        if(r < n && res[r] > res[largest]) largest = r;
        
        if(largest != i){
            swap(res[largest],res[i]);
            max_heapify(res, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> res;
        
        int i = 0, j = 0;
        
        while(i < n && j < m){
            if(a[i] > b[j]){
                res.push_back(a[i]);
                i++;
            }
            else{
                res.push_back(b[j]);
                j++;
            }
        }
        while(i < n){
            res.push_back(a[i]);
            i++;
        }
        while(j < m){
            res.push_back(b[j]);
            j++;
        }
        
        for(int i = (n + m)/2 - 1; i >= 0; i--){
            max_heapify(res, n + m, i);
        }
        return res;
    }
};
