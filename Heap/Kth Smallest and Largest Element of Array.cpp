//https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?leftPanelTab=0

//Approach 1
//Using heap
#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	  priority_queue<int,vector<int>,greater<int>> pq1;
    
    for(int i = 0; i < n; i++){
        pq1.push(arr[i]);
        if(pq1.size() > k) pq1.pop();
    }
    
    priority_queue<int> pq2;
    
    for(int i = 0; i < n; i++){
        pq2.push(arr[i]);
        if(pq2.size() > k) pq2.pop();
    }
    
    vector<int> res = {pq2.top(),pq1.top()};
    return res;
}

//Approach 2
//Using quick select
//Ref1: https://www.youtube.com/watch?v=fnbImb8lo88
//Ref2: https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_1115488?leftPanelTab=2
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int pivot, int lo, int hi){
    
    int i = lo, j = lo;
    
    while(i <= hi){
        if(arr[i] <= pivot){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return j - 1;
}
int quickSelect(vector<int> &arr, int lo, int hi, int k){
    
    int pivot = arr[hi];
    int pi = partition(arr, pivot, lo, hi);
    
    if(k > pi){
        return quickSelect(arr, pi + 1, hi, k);
    }
    else if(k < pi){
        return quickSelect(arr, lo, pi - 1, k);
    }
    else{
        return arr[pi];
    }
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	int ksmallest = quickSelect(arr, 0, n - 1, k - 1);
    int klargest = quickSelect(arr, 0, n - 1, n - k);
    vector<int> res = {ksmallest, klargest};
    return res;
}
