class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0 ; i <= (1<<n)-1 ; i++)
        {
           vector<int> vec;
           for(int j = 0 ; j <= 31 ; j++)
           {
             if((1<<j) & i)
             vec.push_back(nums[j]);
           }
           ans.push_back(vec);
        }
        return ans;
    }
};
