#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include <iostream>
#include "../tree/SegmentTree/lazysegtree.cpp"

void solve(){
    int n,q;
    std::cin>>n>>q;
    LazySegmentTree<long,long> st(n,
        std::plus<long>(),
        std::plus<long>(),
        std::plus<long>(),
        [](long a,int b)->long{return a*b;},
        0L,
        0L
    );
    for(size_t i = 0; i < q; i++)
    {
        int com,x,p,q;
        std::cin>>com;
        if(com==0)//add
        {
            std::cin>>p>>q>>x;
            st.update(p-1,q,x);
        }
        else //get
        {
            std::cin>>x;
            std::cout<<st.query(x-1,x)<<std::endl;
        }
    }
}

int main(){
    solve();
    return 0;
}