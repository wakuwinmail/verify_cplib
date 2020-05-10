//https://onlinejudge.u-aizu.ac.jp/problems/2871
#pragma once
#include <vector>
#include <utility>

#include "graph_template.cpp"

struct EulerTour{
private:
    int sz;
    std::vector<int> in;
    std::vector<int> out;
    int ord;
    Graph g;

    void dfs(int v,int p){//0-indexed
        in[v]=ord;
        ++ord;
        for(int c:g[v]){
            if(c==p)continue;
            dfs(c,v);
        }
        out[v]=ord;
        ++ord;
    }
public:
    EulerTour(Graph g,int root=0):g(g){//initialize
        in.resize(g.size());
        out.resize(g.size());
        ord=0;
        dfs(root,-1);
    }

    std::pair<int,int> interval(int n){
        return std::make_pair(in[n],out[n]);
    }
};