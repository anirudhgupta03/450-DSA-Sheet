//https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence-of-first-n-natural-numbers_1164403?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &res, int n){
    
	int ind1 = -1;
    
    for(int i = n - 2; i >= 0; i--){
        if(res[i] < res[i+1]){
            ind1 = i;
            break;
        }
    }

	if(ind1 == -1){
        reverse(res.begin(),res.end());
        return;
    }

	int ele = INT_MAX, ind2 = -1;

	for(int i = ind1 + 1; i < n; i++){
        if(res[i] < ele && res[i] > res[ind1]){
            ind2 = i;
            ele = res[i];
        }
		else{
            break;
        }
    }

	swap(res[ind1],res[ind2]);
	int lo = ind1 + 1, hi = n - 1;
	while(lo < hi){
        swap(res[lo],res[hi]);
        lo++;
        hi--;
    }
}
vector<int>  kthPermutation(int n, int k)
{
    vector<int> res;
    
    for(int i = 1; i <= n; i++){
        res.push_back(i);
    }
    
    k--;
    while(k){
        solve(res,n);
        k--;
    }
    return res;
}
