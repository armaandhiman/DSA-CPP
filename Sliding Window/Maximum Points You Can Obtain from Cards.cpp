class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int l = k-1;
        int r = n;

        int sum = 0;
        int maxsum = 0;
        for(int i = 0 ; i <= k-1 ; i++)
        {
            sum += cardPoints[i];
        }
        maxsum = sum;
        while(r > n-k)
        {
            sum -= cardPoints[l];
            l--;
            r--;
            sum += cardPoints[r];
            maxsum = max(sum , maxsum);
        }
        return maxsum;
    }
};
