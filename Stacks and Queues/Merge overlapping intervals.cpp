//https://www.codingninjas.com/codestudio/problems/merge-overlapping-intervals_1082151?leftPanelTab=0
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &i1, vector<int> &i2){
    return i1[0] < i2[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    sort(intervals.begin(),intervals.end(),cmp);
    
    vector<vector<int>> res;
    
    int e1 = intervals[0][0], e2 = intervals[0][1];
    
    for(int i = 1; i < intervals.size(); i++){
        
        if(intervals[i][0] <= e2){
            e2 = max(e2, intervals[i][1]);
        }
        else{
            vector<int> interval = {e1, e2};
            res.push_back(interval);
            e1 = intervals[i][0], e2 = intervals[i][1];
        }
    }
    vector<int> interval = {e1, e2};
    res.push_back(interval);
    return res;
}

//Using Stack
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &i1, vector<int> &i2){
    return i1[0] < i2[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    sort(intervals.begin(),intervals.end(),cmp);
    
    vector<vector<int>> res;
    
    stack<int> s;
    s.push(intervals[0][0]);
    s.push(intervals[0][1]);
    
//     int e1 = , e2 = intervals[0][1];
    
    for(int i = 1; i < intervals.size(); i++){
        
        if(intervals[i][0] <= s.top()){
            int ele = max(s.top(), intervals[i][1]);
            s.pop();
            s.push(ele);
        }
        else{
            int e1 = s.top();
            s.pop();
            int e2 = s.top();
            s.pop();
            vector<int> interval = {e2, e1};
            res.push_back(interval);
            e1 = intervals[i][0], e2 = intervals[i][1];
            s.push(e1);
            s.push(e2);
        }
    }
    int e1 = s.top();
    s.pop();
    int e2 = s.top();
    s.pop();
    vector<int> interval = {e2, e1};
    res.push_back(interval);
    return res;
}
