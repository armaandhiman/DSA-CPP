class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int sum1 = accumulate(nums.begin() , nums.end(), 0);
        int sum2 = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            while(nums[i] != 0)
            {
                sum2 += nums[i]%10;
                nums[i]/=10;
            }
        }
        return abs(sum1-sum2);
    }
};
