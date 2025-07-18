class Solution {
public:
    void gen_sum(int i,int n,int cnt,int sum,vector<int>&nums,unordered_map<int,vector<int>>& temp){
        if(i==n){
            temp[cnt].push_back(sum);
            return ;
        }
        gen_sum(i+1,n,cnt,sum,nums,temp);
        gen_sum(i+1,n,cnt+1,sum+nums[i],nums,temp);
    }

    int get_ans(unordered_map<int,vector<int>>& temp1,unordered_map<int,vector<int>>& temp2,int sum,int n){
        int ans=INT_MAX;
        int req_sum=sum/2;
        for(auto ele:temp1){
            for( auto it:ele.second){
                int req_sum2=req_sum-it;

                if(temp2.find(n-ele.first)!=temp2.end()){
                    vector<int> *vec_ptr=&temp2[n-ele.first];
                    int len=vec_ptr->size();
                    int ind=lower_bound(vec_ptr->begin(),vec_ptr->end(),req_sum2)-vec_ptr->begin()  ; 
                    // if(ind<len){
                    //     cout<<"cnt: "<<ele.first<<" element: "<<it<<endl;
                    //     cout<<"n-cnt: "<<n-ele.first<<" ind: "<<ind<<"val index: "<<vec_ptr[ind]<<endl;
                    // }
                        
                    if(ind<len && (*vec_ptr)[ind]==req_sum2){
                        return ((sum%2==0) ? 0 : 1);
                    }else if(ind<len && (*vec_ptr)[ind]>req_sum2){
                        ans=min(ans,abs(sum - 2*((*vec_ptr)[ind]+it)));
                        if(ind>0){
                            ans=min(ans,abs(sum - 2*((*vec_ptr)[ind-1]+it)));
                        }
                    }
                    else if(ind==len && len>0){
                        ans=min(ans,abs(sum - 2*((*vec_ptr)[ind-1]+it)));
                    }
                }
            }
        }
        return ans;
    }
    void print(unordered_map<int,vector<int>>& temp1){
        for(auto it:temp1){
            cout<<"cnt: "<<it.first<<"->";
            for(auto it2:it.second){
                cout<<it2<<" , ";
            }
        }
        cout<<endl;
    }
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(),sum=0;
        vector<int> nums1,nums2;
        unordered_map<int,vector<int>> temp1,temp2;
        for(int i=0;i<(n+1)/2 ; i++){
            nums1.push_back(nums[i]);
            sum+= nums[i];
        }
        for(int i=((n+1)/2);i<n;i++){
            nums2.push_back(nums[i]);
            sum+= nums[i];
        }
        gen_sum(0,nums1.size(),0,0,nums1,temp1);
        gen_sum(0,nums2.size(),0,0,nums2,temp2);
        // print(temp2);
        for(auto &it:temp2){
            sort(it.second.begin(),it.second.end());
        }
        // print(temp1);
        // print(temp2);
        int ans=get_ans(temp1,temp2,sum,n/2);
        return ans;
    }
};
    