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


# :heavy_check_mark: tree/SegmentTree/lazysegtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f1973713ea4397a8e0580271720556c9">tree/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/SegmentTree/lazysegtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 15:39:34+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/verify/euler_tour.test.cpp.html">verify/euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/verify/lazysegtree.test.cpp.html">verify/lazysegtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
#pragma once
#include <vector>
#include <algorithm>
#include <functional>

template <typename T,typename E>
struct LazySegmentTree{
private:
    typedef std::function<T(T,T)> F;
    typedef std::function<T(T,E)> G;
    typedef std::function<E(E,E)> H;
    typedef std::function<E(E,int)> P;
    int n;
    F cal;//function for merge
    G upd;//function for update
    H ecal;//function for evaluate
    P rcal;//function for range calculate
    std::vector<T> init;
    T initv;
    E opinit;
    std::vector<T> node;
    std::vector<E> lazy;
public:
    explicit LazySegmentTree(//配列で初期化する場合
            int sz,
            F cal,
            G upd,
            H ecal,
            P rcal=[](T a,int b){return a;},
            std::vector<T> init=std::vector<T>(1,0),
            E opinit=0
    ):
    cal(cal),
    upd(upd),
    ecal(ecal),
    rcal(rcal),
    init(init),
    opinit(opinit)
    {
        n=1;
        initv=init[0];
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), init[0]);//はみ出る分は0番地に指定
        for (int i = 0; i <sz ; ++i) node[i+n-1]=init[i+1];
        for (int i = n-2; i >= 0 ; --i) node[i]=cal(node[2*i+1],node[2*i+2]);

        lazy.resize(static_cast<unsigned int>(2 * n - 1), opinit);
        for (int i = 0; i <sz ; ++i) lazy[i+n-1]=opinit;
        for (int i = n-2; i >= 0 ; --i) lazy[i]=ecal(lazy[2*i+1],lazy[2*i+2]);
    }

    explicit LazySegmentTree(//特定の要素で初期化する場合
            int sz,
            F cal,
            G upd,
            H ecal,
            P rcal=[](T a,int b){return a;},
            T initv=0,
            E opinit=0
    ):
    cal(cal),
    upd(upd),
    ecal(ecal),
    rcal(rcal),
    initv(initv),
    opinit(opinit)
    {
        n=1;
        while(n<sz)n=n*2;
        node.resize(static_cast<unsigned int>(2 * n - 1), initv);
        for (int i = 0; i <sz ; ++i) node[i+n-1]=initv;
        for (int i = n-2; i >= 0 ; --i) node[i]=cal(node[2*i+1],node[2*i+2]);

        lazy.resize(static_cast<unsigned int>(2 * n - 1), opinit);
        for (int i = 0; i <sz ; ++i) lazy[i+n-1]=opinit;
        for (int i = n-2; i >= 0 ; --i) lazy[i]=ecal(lazy[2*i+1],lazy[2*i+2]);
    }

    void update(int p,int q,E val,int k=0,int l=0,int r=-1){//[p,q):0-indexed
        if(r<0)r=n;
        eval(k,r-l);
        if(r<=p||l>=q)return;
        if(p<=l&&r<=q){
            lazy[k]=ecal(lazy[k],val);
            eval(k,r-l);
        }
        else{
            update(p,q,val,2*k+1,l,(l+r)/2);
            update(p,q,val,2*k+2,(l+r)/2,r);
            node[k]=cal(node[2*k+1],node[2*k+2]);
        }
    }

    T query(int p,int q,int k=0,int l=0,int r=-1){//[p,q):0-indexed
        if(r<0)r=n;
        if(r<=p||l>=q)return initv;

        eval(k,r-l);
        if(p<=l&&r<=q)return node[k];
        T vl=query(p,q,2*k+1,l,(l+r)/2);
        T vr=query(p,q,2*k+2,(l+r)/2,r);
        return cal(vl,vr);
    }

    void eval(int k,int len){//k:0-indexed
        if(lazy[k]==opinit)return;
        node[k]=upd(node[k],rcal(lazy[k],len));
        if(k<n-1){
            lazy[2*k+1]=ecal(lazy[2*k+1],lazy[k]);
            lazy[2*k+2]=ecal(lazy[2*k+2],lazy[k]);
        }
        lazy[k]=opinit;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 172, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tree/SegmentTree/lazysegtree.cpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

