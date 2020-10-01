/*
Given a non-empty array containing only positive integers, 
find if the array can be partitioned into two subsets such
that the sum of elements in both subsets is equal.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool subsetsum(vector<int> nums,vector<vector<int>> &dp,int sum,int n){
        if(sum==0)
            return true;
        if(sum<0 || n==0)
            return false;
        if(dp[n-1][sum]!=-1){
            return dp[n-1][sum];
        }
        else{
            dp[n-1][sum]=subsetsum(nums,dp,sum,n-1)||subsetsum(nums,dp,sum-nums[n-1],n-1);
        }
        return dp[n-1][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums)
            sum+=i;
        if(sum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return subsetsum(nums,dp, sum/2,nums.size());
    }    
};

int main(){
    Solution obj;
    vector<int> nums = {1, 5, 11, 5};
    cout<<obj.canPartition(nums);
    return 0;
}