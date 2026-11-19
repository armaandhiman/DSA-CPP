class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<pair<int, int>> vec;

        for(int i = 0 ; i < n ; i++)
        {
            vec.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(vec.begin() , vec.end() , [&](auto & it1 , auto & it2){
          return it1.second < it2.second;});
        int cnt = 0;
        int j = 0;
        for(int i = 1 ; i < vec.size() ; i++)
        { 
            if(vec[j].second <= vec[i].first)
            j = i;
            else 
            cnt++;
        }
        return cnt;
    }
};
