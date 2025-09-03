class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int cur=target-nums[i];
            bool check=false;
            for(int j=i+1; j<n; j++){
                if(cur==nums[j]){
                    ans.push_back(j);
                    check=true;
                }
            }
            if(check){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};