class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {

        vector<pair<long long , long long>> vec;
        double vl= 0.0;
        double amt = 0.0;

        for(int i = 0 ; i < wt.size() ; i++)
        {
            vec.push_back({val[i] , wt[i]});
        }

        sort(vec.begin() , vec.end() , [&](auto & a , auto & b){
            return ((double)a.first/a.second)>((double)b.first/b.second);});

            for(auto &it : vec)
            {
                if(amt+it.second <= capacity)
                {
                    amt += it.second;
                    vl += it.first;
                }
                else
                {
                    double n = (double)(capacity-amt)/it.second;
                    vl += it.first*n;
                    break;
                }
            }
            return vl;

        
    }
};
