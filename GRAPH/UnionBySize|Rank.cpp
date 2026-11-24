#include<iostream>
using namespace std;

class DisjointSet
{
    
    vector<int> rank,par,size;
    int n ;
    public:

    DisjointSet(int N)
    {   
        n = N;
        rank.resize(N+1 , 0);
        par.resize(N+1);
        size.resize(N+1);
        
        for(int i = 0 ; i <= N ; i++)
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

    void UnionByRank(int u , int v)
    {
        int UlPu = findPar(u);
        int UlPv = findPar(v);

        int Ru = rank[u];
        int Rv = rank[v];

        if(UlPu == UlPv)
        return ;

        if(Ru < Rv)
        {
            par[UlPu] = UlPv;
        }
        else if(Rv > Ru)
        {
            par[UlPv] = UlPu;
        }
        else
        {
            par[UlPv] = UlPu;
            rank[UlPu]++;
        }
    }
    void UnionBySize(int u , int v)
    {
        int UlPu = findPar(u);
        int UlPv = findPar(v);

        int Ru = rank[u];
        int Rv = rank[v];

        if(UlPu == UlPv)
        return ;

        if(Ru < Rv)
        {
            par[UlPu] = UlPv;
            size[UlPv] += size[UlPu];
        }
        else if(Rv > Ru)
        {
            par[UlPv] = UlPu;
            size[UlPu] += size[UlPv];
        }
        else
        {
            par[UlPv] = UlPu;
            rank[UlPu]++;
            size[UlPu] += size[UlPv];
        }
    }
};

int main()
{
    DisjointSet ds(7);

    /*ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);*/
     ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);


    if(ds.findPar(3) == ds.findPar(7))
    {
        cout << "same" << endl;;
    }
    else
    cout << "not same" << endl;

    ds.UnionBySize(3,7);
     if(ds.findPar(3) == ds.findPar(7))
    {
        cout << "same" << endl;
    }
    else
    cout << "not same" << endl;
    
    return 0;
}
