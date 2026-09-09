class Solution {
public:
    // int solve(int idx, vector<int> &nums, vector<int> &dp){
    //     if(idx<0) return 0;
    //     if(dp[idx] != -1) return dp[idx];
    //     int take = nums[idx]+solve(idx-2, nums, dp);
    //     int notTake = solve(idx-1, nums,dp);
    //     return dp[idx] = max(take,notTake);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1,-1);

        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);
        for(int i = 3; i<=n; i++){
            int take = nums[i-1] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[n];
    }
};
