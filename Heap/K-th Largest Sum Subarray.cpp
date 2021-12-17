//https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=1
//Approach - 1
//TLE
#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    
	vector<int> prefix(n + 1,0);
    
    for(int i = 0; i < n; i++){
        prefix[i + 1] = arr[i] + prefix[i];
    }
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int sum = prefix[j] - prefix[i];
            pq.push(sum);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    return pq.top();
}
//Approach - 2
//Accepted
#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    
	vector<int> prefix(n + 1,0);
    
    for(int i = 0; i < n; i++){
        prefix[i + 1] = arr[i] + prefix[i];
    }
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int x = prefix[j] - prefix[i];
            if (pq.size() < k)
                pq.push(x);
 
            else
            {
                // it the min heap has equal to
                // k elements then just check
                // if the largest kth element is
                // smaller than x then insert
                // else its of no use
                if (pq.top() < x)             //Slight Modification
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }
    return pq.top();
}
