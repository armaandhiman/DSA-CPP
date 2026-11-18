class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        
        vector<pair<int,int>> vec;

        for(int i = 0 ; i < start.size() ; i++)
        {
            vec.push_back({start[i] , end[i]});
        }
        
        sort(vec.begin() , vec.end() , [&](auto &it1 , auto &it2){
            return it1.second < it2.second;});

        int cnt = 1;
        int j = 0;

        for(int i = 1 ; i < vec.size() ; i++)
        {
            if(vec[i].first > vec[j].second)
            {
                cnt ++;
                j = i;
            }
        }
        return cnt;
    } 
};
