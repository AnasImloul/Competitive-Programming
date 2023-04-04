class Solution {
public:
    vector<double> ans;
    priority_queue<int> mxh;
    priority_queue<int,vector<int>,greater<int>> mnh;
    void add(int& x){
        mxh.push(x);
        mnh.push(mxh.top());
        mxh.pop();
        if(mxh.size()<mnh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }
    }
    void erase(int &x){
        if(x<=mxh.top()){
            vector<int> tmp;
            while(x != mxh.top()){
                tmp.push_back(mxh.top());
                mxh.pop();
            }
            mxh.pop();
            for(auto &i: tmp){
                mxh.push(i);
            }
        }else{
            vector<int> tmp;
            while(x != mnh.top()){
                tmp.push_back(mnh.top());
                mnh.pop();
            }
            mnh.pop();
            for(auto &i: tmp){
                mnh.push(i);
            }
        }
    }
    void push(int &k){
        if(k&1){
            ans.push_back(mxh.top());
        }else{
            ans.push_back(((double)mxh.top()+(double)mnh.top())/2.0);
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            if(mxh.size()+mnh.size()+1<k){
                add(nums[i]);
            }else{
                add(nums[i]);
                push(k);
                erase(nums[i-k+1]);
            }
            
        }
        return ans;
    }
};