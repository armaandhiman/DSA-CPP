class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
      vector<int> ans;
      
      queue<int> q;
      q.push(0);
      
      unordered_set<int> st;
      st.insert(0);
      while(!q.empty())
      {
          int node = q.front();
          q.pop();
          
          for(auto &it : adj[node])
          {
              if(st.find(it) == st.end())
              {
                  st.insert(it);
                  q.push(it);
              }
          }
          
          ans.push_back(node);
      }
      return ans;
    }
};
