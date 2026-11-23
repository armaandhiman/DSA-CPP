class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
     
       vector<pair<int, int>> vec;
       for(int i = 0 ; i < deadline.size() ; i++)
       {
           vec.push_back({deadline[i] , profit[i]});
       }
       
       sort(vec.begin() , vec.end() , [](auto& i , auto& j){
           return i.second > j.second;
       });
       
      int n = *max_element(deadline.begin() , deadline.end());
      int Pr = 0;
      int cnt = 0;
      
      vector<int> V(n+1 , -1);
      
      for(int i = 0 ; i < vec.size() ; i++)
      {
          int dead = vec[i].first;
          int pr = vec[i].second;
          while(dead > 0 && V[dead] != -1)
          {
              dead--;
          }
          if(dead > 0 && V[dead] == -1)
          {
              Pr += pr;
              cnt++;
              V[dead]=1;
          }
      }
      return {cnt , Pr};
    }
};
