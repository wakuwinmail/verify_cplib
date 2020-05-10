#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2871"

#include <iostream>
#include "../graph/euler_tour.cpp"
#include "../tree/SegmentTree/lazysegtree.cpp"


void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<int>> G(n);
    for(int i = 1; i < n; ++i){
        int p;
        std::cin>>p;
        --p;
        G[p].emplace_back(i);
    }
    EulerTour et(G);
    std::vector<long> val(n*2+1,0);
    for(int i = 0; i < n; ++i){
        char c;
        std::cin>>c;
        if(c=='G'){
            auto t=et.interval(i);
            val[t.first+1]=1;
            val[t.second+1]=1;
        }
    }

    LazySegmentTree<long,int> st(
        n*2,
        std::plus<long>(),
        [](long a,int b)->long{return b==0?a:b-a;},
        std::plus<int>(),
        [](int a,int b)->int{return a%2==0?0:b;},
        val
    );
    for(int i = 0; i < q; ++i){
        int v;
        std::cin>>v;
        --v;
        auto t=et.interval(v);
        st.update(t.first,t.second+1,1);
        if(st.query(0,2*n+1)>n)std::cout<<"broccoli"<<std::endl;
        else std::cout<<"cauliflower"<<std::endl;
    }
    

}

int main(){
    solve();
    return 0;
}