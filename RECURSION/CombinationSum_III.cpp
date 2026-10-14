class Solution {
public:
  
    void find(int idx , vector<vector<int>> & ans , vector<int> & vec , int k , int target ,int cnt)
    {
        if(cnt == k)
        {
            if(target == 0)
            {
                ans.push_back(vec);
            }
            return ;
        }

        if(idx <= 9 && idx <= target)
        {
            vec.push_back(idx);
            find(idx+1 , ans , vec , k , target-idx , cnt+1);
            vec.pop_back(); 
            find(idx+1 , ans , vec , k , target , cnt);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;

        vector<int> ds;

        find(1 , ans , ds , k , n , 0);
        return ans;
    }
};
