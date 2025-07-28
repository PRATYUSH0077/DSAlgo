class NumArray {
    vector<int> nums;
    vector<int> segTree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        this->nums=nums;
        segTree.resize(4*n+1);
        segment(0,0,n-1);
    }
    void segment(int index,int lo,int high){
        if(lo==high){
            segTree[index]=nums[lo];
            return ;
        }

        int mid=(lo+high)/2;
        segment(2*index+1,lo,mid);
        segment(2*index+2,mid+1,high);
        segTree[index]=segTree[2*index+1]+segTree[2*index+2];
    }
    void updateSegment(int i,int low,int high,int index){
        if(low==high){
            segTree[i]=nums[index];
            return ;
        }
        int mid=(low+high)/2;
        if(index<=mid){
            updateSegment(2*i+1,low,mid,index);
        }else{
            updateSegment(2*i+2,mid+1,high,index);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    int query(int index,int low,int high,int left,int right){
        if(high<left || low>right) return 0;
        if(low>=left && high<=right){
            return segTree[index];
        }
        int mid=(low+high)/2;
        int query1=query(2*index+1,low,mid,left,right);
        int query2=query(2*index+2,mid+1,high,left,right);
        return query1+query2;
    }
    void update(int index, int val) {
        nums[index]=val;
        // updateSegment(int i,int low,int high,int index);
        updateSegment(0,0,n-1,index);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */