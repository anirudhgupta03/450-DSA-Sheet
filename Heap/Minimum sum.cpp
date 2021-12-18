class Solution{   
public:
    string solve(int arr[], int n) {
        
        sort(arr, arr + n);
        
        string num1, num2;
        
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                num1.push_back(arr[i] + '0');   
            }
            else{
                num2.push_back(arr[i] + '0');
            }
        }
        
        if(num1.size() > num2.size()){
            num2.insert(num2.begin(),'0');
        }
        else if(num2.size() > num1.size()){
            num1.insert(num1.begin(),'0');
        }
        
        string res;
        
        int carry = 0;
        for(int i = num1.size() - 1; i >= 0; i--){
            int n1 = num1[i] - '0', n2 = num2[i] - '0';
            int temp = (n1 + n2 + carry)%10;
            carry = (n1 + n2 + carry)/10;
            res.push_back(temp + '0');
        }
        if(carry != 0){
            res.push_back(carry + '0');
        }
        int i = res.size() - 1;
        while(res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
