// https://www.codingninjas.com/codestudio/problems/tug-of-war_985253?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

void solve(int ind, int count, int n, vector<int> &arr, int sum, int &minDiff, int &tsum){
	
    if(n % 2 == 0){
    	if(count == n/2){
        	minDiff = min(minDiff,abs(sum-(tsum-sum)));
            return;
        }
    }
    else{
    	if(count == (n - 1)/2){
        	minDiff = min(minDiff,abs(sum-(tsum-sum)));
        }
        else if(count == (n + 1)/2){
        	minDiff = min(minDiff,abs(sum-(tsum-sum)));
            return;
        }
    }
    
    if(ind == arr.size()){
    	return;
    }
    
    solve(ind + 1, count + 1, n, arr, sum + arr[ind], minDiff, tsum);
    solve(ind + 1, count, n, arr, sum, minDiff, tsum);
}
int tugOfWar(vector<int> &arr, int n)
{	
	int tsum = 0;
    
	for(int i = 0; i < n; i++){
    	tsum += arr[i];
    }
    
	int sum = 0, minDiff = INT_MAX;
    solve(0,0,n,arr,sum,minDiff,tsum);
    
    return minDiff;
}
