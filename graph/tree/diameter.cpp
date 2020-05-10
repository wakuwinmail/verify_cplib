#pragma once
#include <vector>
#include <utility>

#include "../graph_template.cpp"

//G:グラフを管理してる型（vector<vector>やvector<set>を指定する）
//T:辺のコスト
template <typename T>
struct TreeDiam {
private:
    using G = graph<T>;
    int u,v;//直径の両端
    T maxdist;//直径
    void dfs(G &g,int x,int p,int dist) {
    //std::cerr<<"x:"<<x<<std::endl;
        if(dist>maxdist){
            v=x;
            maxdist=dist;
        }
        for(auto y:g[x]) {
            if(y.to==p)continue;
            dfs(g,y.to,x,dist+y.cost);
        }
    }

public:
    TreeDiam(G g) {
        u=0;//仮に置いた端点
        maxdist=0;
        dfs(g,u,-1,0);
    //std::cerr<<"md:"<<maxdist<<std::endl;
        u=v;
        maxdist=0;
        dfs(g,u,-1,0);
    }

    std::pair<int,int> end_nodes(){
        return std::make_pair(u,v);
    }

    T diameter(){
        return maxdist;
    }
};