class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        for(int i = 3; i<=n-1; i++){
            int take = nums[i-1]+dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take,notTake);
        }
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for(int i = 3; i<=n-1; i++){
            int take = nums[i]+dp2[i-2];
            int notTake = dp2[i-1];
            dp2[i] = max(take,notTake);
        }
        return max(dp[n-1],dp2[n-1]);
    }
};
