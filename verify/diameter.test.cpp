#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <iostream>
#include "../graph/tree/diameter.cpp"

void solve() {
    int n;
    std::cin>>n;
    graph<int> G(n);
    for(int i = 0;i < n-1;++i) {
        int s,t,w;
        std::cin>>s>>t>>w;
        G[s].emplace_back(s,t,w);
        G[t].emplace_back(t,s,w);
    }
    TreeDiam<int> td(G);
    std::cout<<td.diameter()<<std::endl;
}

int main() {
    solve();
    return 0;
}
