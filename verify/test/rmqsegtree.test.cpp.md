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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/rmqsegtree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/rmqsegtree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 20:15:35+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/tree/SegmentTree/rmqsegtree.cpp.html">tree/SegmentTree/rmqsegtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#include "../tree/SegmentTree/rmqsegtree.cpp"


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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/rmqsegtree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#line 1 "tree/SegmentTree/rmqsegtree.cpp"
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
#include <vector>
#include <algorithm>
#include <cstdint>

template <typename T>
struct SegmentTree{
private:
    int n;
    T init;
    std::vector<T> node;
 
public:
    explicit SegmentTree(int sz,T initv=std::numeric_limits<T>::max()){
        n=1;
        init=initv;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), init);
        for (int i = 0; i <sz ; ++i) node[i+n-1]=init;
        for (int i = n-2; i >= 0 ; --i) node[i]=std::min(node[2*i+1],node[2*i+2]);
    }
 
    void update(int x, T val){//x:0-indexed
        x+=n-1;
        node[x]=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=std::min(node[2*x+1],node[2*x+2]);
        }
    }
 
    T getmin(int p,int q,int k=0,int l=0,int r=-1){//[p,q):0-indexed
        if(r<0)r=n;
        if(r<=p||l>=q)return init;//out of range
        if(p<=l&&r<=q)return node[k];
 
        return std::min(getmin(p,q,2*k+1,l,(l+r)/2),getmin(p,q,2*k+2,(l+r)/2,r));
    }
};
#line 5 "test/rmqsegtree.test.cpp"


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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

