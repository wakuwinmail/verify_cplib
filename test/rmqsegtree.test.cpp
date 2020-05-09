#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#include "tree\SegmentTree\rmqsegtree.cpp"


void solve(){
    int n,q;
    std::cin>>n>>q;
    SegmentTree<int> st(n);
    for(size_t i = 0; i < q; i++)
    {
        int com,x,y;
        std::cin>>com>>x>>y;
        if(com==0)//update
        {
            st.update(x,y);
        }
        else //find
        {
            std::cout<<st.getmin(x,y+1)<<std::endl;
        }
    }
}

int main(){
    solve();
    return 0;
}