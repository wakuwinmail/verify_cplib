---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: tree/SegmentTree/abstsegtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f1973713ea4397a8e0580271720556c9">tree/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/SegmentTree/abstsegtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Depends on

* :warning: <a href="monoid.cpp.html">tree/SegmentTree/monoid.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <functional>
#include "monoid.cpp"

//cut begin
template <typename T,typename E=T>
struct SegmentTree{
private:
    using G=std::function<T(T,E)>;
    int n;
    std::vector<T> init;
    monoid<T> mono;
    G upd;//function for update
    std::vector<T> node;

public:
    explicit SegmentTree(
            int sz,
            monoid<T> mono,
            G upd
    ):mono(mono),upd(upd)
    {
        n=1;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), mono.get_id());
        for (int i = 0; i <sz ; ++i) node[i+n-1]=mono.get_id();
        for (int i = n-2; i >= 0 ; --i) node[i]=mono(node[2*i+1],node[2*i+2]);
    }

    explicit SegmentTree(
            int sz,
            monoid<T> mono,
            G upd,
            std::vector<T> init
    ):mono(mono),upd(upd),init(init)
    {
        n=1;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), mono.get_id());
        for (int i = 0; i <sz ; ++i) node[i+n-1]=init[i+1];
        for (int i = n-2; i >= 0 ; --i) node[i]=mono(node[2*i+1],node[2*i+2]);
    }

    void update(int x, E val){//x:0-indexed
        x+=n-1;
        node[x]=upd(node[x],val);
        while(x>0){
            x=(x-1)/2;
            node[x]=mono(node[2*x+1],node[2*x+2]);
        }
    }

    T query(int p,int q,int k=0,int l=0,int r=-1){//[p,q):0-indexed
        if(r<0)r=n;
        if(r<=p||l>=q)return mono.get_id();//out of range
        if(p<=l&&r<=q)return node[k];

        return mono(query(p,q,2*k+1,l,(l+r)/2),query(p,q,2*k+2,(l+r)/2,r));
    }
};
//cut end
void solve(){
    int n,q;
    std::cin>>n>>q;
    monoid<int> mono([](int a,int b){return std::min(a,b);},std::numeric_limits<int>::max());
    SegmentTree<int> st(n,
        mono,
        [](int a,int b){return b;}
    );
    for(int i = 0; i < q; i++)
    {
        int com,x,y;
        std::cin>>com>>x>>y;
        if(com==0)//update
        {
            st.update(x,y);
        }
        else //find
        {
            std::cout<<st.query(x,y+1)<<std::endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/SegmentTree/abstsegtree.cpp"
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <functional>
#line 1 "tree/SegmentTree/monoid.cpp"
//cut begin
template<typename T>
class monoid{
private:
    typedef std::function<T(T,T)> F;
    F cal;
    T id;
public:
    monoid(F f,T id):cal(f),id(id){}
    constexpr T operator()(T a,T b){
        return cal(a,b);
    }
    constexpr T get_id(){return id;}
};
//cut end
#line 8 "tree/SegmentTree/abstsegtree.cpp"

//cut begin
template <typename T,typename E=T>
struct SegmentTree{
private:
    using G=std::function<T(T,E)>;
    int n;
    std::vector<T> init;
    monoid<T> mono;
    G upd;//function for update
    std::vector<T> node;

public:
    explicit SegmentTree(
            int sz,
            monoid<T> mono,
            G upd
    ):mono(mono),upd(upd)
    {
        n=1;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), mono.get_id());
        for (int i = 0; i <sz ; ++i) node[i+n-1]=mono.get_id();
        for (int i = n-2; i >= 0 ; --i) node[i]=mono(node[2*i+1],node[2*i+2]);
    }

    explicit SegmentTree(
            int sz,
            monoid<T> mono,
            G upd,
            std::vector<T> init
    ):mono(mono),upd(upd),init(init)
    {
        n=1;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), mono.get_id());
        for (int i = 0; i <sz ; ++i) node[i+n-1]=init[i+1];
        for (int i = n-2; i >= 0 ; --i) node[i]=mono(node[2*i+1],node[2*i+2]);
    }

    void update(int x, E val){//x:0-indexed
        x+=n-1;
        node[x]=upd(node[x],val);
        while(x>0){
            x=(x-1)/2;
            node[x]=mono(node[2*x+1],node[2*x+2]);
        }
    }

    T query(int p,int q,int k=0,int l=0,int r=-1){//[p,q):0-indexed
        if(r<0)r=n;
        if(r<=p||l>=q)return mono.get_id();//out of range
        if(p<=l&&r<=q)return node[k];

        return mono(query(p,q,2*k+1,l,(l+r)/2),query(p,q,2*k+2,(l+r)/2,r));
    }
};
//cut end
void solve(){
    int n,q;
    std::cin>>n>>q;
    monoid<int> mono([](int a,int b){return std::min(a,b);},std::numeric_limits<int>::max());
    SegmentTree<int> st(n,
        mono,
        [](int a,int b){return b;}
    );
    for(int i = 0; i < q; i++)
    {
        int com,x,y;
        std::cin>>com>>x>>y;
        if(com==0)//update
        {
            st.update(x,y);
        }
        else //find
        {
            std::cout<<st.query(x,y+1)<<std::endl;
        }
    }
}

int main(){
    solve();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
