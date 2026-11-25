class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int cand = 1;
        long long sum = 1;
        int peak = 0;
        int n = ratings.size();
        int down = 0;
        for(int i = 1; i < ratings.size() ; i++)
        {
            if (ratings[i] == ratings[i - 1])
            {
                cand = 1;
                sum += 1;
                peak = 0;
            }
            //peak
            else if(i+1 < n && (ratings[i-1]<ratings[i] && ratings[i]>ratings[i+1]))
            {
                peak = cand+1;
                sum += peak;
                cand = 1;
            }
            //down
            else if (ratings[i - 1] > ratings[i] && (i + 1 == n || ratings[i] <= ratings[i + 1]))
            {
                down = cand+1;
                sum += cand;
                  int top = max(peak, 1); // Baseline height is 1 if no prior upward peak
                if (down > top)
                {
                    sum += (down - top);
                }  
                peak = 0;
                cand = 1;
            }

            else if(ratings[i] < ratings[i-1])
            {
                sum += cand;
                cand += 1;
            }
            else if(ratings[i]  > ratings[i-1])
            {   
                cand += 1;
                sum += cand;
            }
        }

        return sum;
    }
};
