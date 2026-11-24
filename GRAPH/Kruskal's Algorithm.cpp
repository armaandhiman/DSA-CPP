class Solution {
        vector<int> rank,par,size;
        public:
           void init(int V){
            par.resize(V+1);
            size.resize(V+1);

            for(int i = 0 ; i <= V; i++)
            {
                par[i] = i;
                size[i] = 1;
            }
        }

        int findPar(int node)
        {
            if(node == par[node])
            return node;

            return par[node] = findPar(par[node]);
        } 

      
        void UnionBySize(int u , int v)
        {
            int UlPu = findPar(u);
            int UlPv = findPar(v);

            int Su = size[UlPu];
            int Sv = size[UlPv];

            if(UlPu == UlPv)
            return ;

            if(Su < Sv)
            {
                par[UlPu] = UlPv;
                size[UlPv] += size[UlPu];
            }
            else if(Su > Sv)
            {
                par[UlPv] = UlPu;
                size[UlPu] += size[UlPv];
            }
            else
            {
                par[UlPv] = UlPu;
                size[UlPu] += size[UlPv];
            }
        }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
      
      
      init(V);
      //sort acc to wt
      
     sort(edges.begin() , edges.end() , [](auto& i ,auto& j){
         return  i[2]<j[2];
     });
     
     unordered_set<int> st;
     
     int sum = 0;
     for(int i = 0 ; i < edges.size() ; i++)
     {
       if(findPar(edges[i][0]) != findPar(edges[i][1]))
       {
           sum += edges[i][2];
           UnionBySize(edges[i][0],edges[i][1]);
       }
     }
     return sum;
    }
};
