//Ref: https://www.youtube.com/watch?v=mUeaCLDdtnM
//https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
#define ll long long
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	
    deque<ll> dq1, dq2;
    
    for(int i = 0; i < k; i++){
        if(i == 0){
            dq1.push_back(nums[i]);
            dq2.push_back(nums[i]);
        }
        else{
            if(nums[i] >= dq1.back()){
                dq1.push_back(nums[i]);
            }
            else{
                while(!dq1.empty() && nums[i] < dq1.back()){
                    dq1.pop_back();
                }
                dq1.push_back(nums[i]);
            }
            
            if(nums[i] <= dq2.back()){
                dq2.push_back(nums[i]);
            }
            else{
                while(!dq2.empty() && nums[i] > dq2.back()){
                    dq2.pop_back();
                }
                dq2.push_back(nums[i]);
            }
        }
    }
    ll sum = 0;
    
    for(int i = 0; i <= n - k; i++){
        sum += dq1.front() + dq2.front();
        if(dq1.front() == nums[i]) dq1.pop_front();
        if(dq2.front() == nums[i]) dq2.pop_front();
        
    	if(nums[i + k] >= dq1.back()){
             dq1.push_back(nums[i + k]);
        }
        else{
            while(!dq1.empty() && nums[i + k] < dq1.back()){
                dq1.pop_back();
            }
            dq1.push_back(nums[i + k]);
        }
            
        if(nums[i + k] <= dq2.back()){
                dq2.push_back(nums[i + k]);
        }
        else{
            while(!dq2.empty() && nums[i + k] > dq2.back()){
                dq2.pop_back();
            }
            dq2.push_back(nums[i + k]);
        }    
    }
    return sum;
}
