class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
         sort(score.begin(), score.end() , [&](auto& i , auto& j){
            return i[k] > j[k];
        });
        return score;
    } 
};
