class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
       long long num = 0;
       for(int i = 0 ; i < nums.size() ; i++)
       {
        num ^= nums[i];
       }
       int right = 0;

       right = (num & (num-1))^num;

       int buck1 = 0;
       int buck2 = 0;
       for(int i = 0 ; i < nums.size() ; i++)
       {
        if((nums[i]&right) != 0)
        buck1 ^= nums[i];
        else
        buck2 ^= nums[i];
       }
       return {buck1,buck2};
    }
};
