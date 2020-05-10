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


# :heavy_check_mark: verify/euler_tour.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8418d1d706cd73548f9f16f1d55ad6e">verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/euler_tour.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 16:07:24+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/2871">https://onlinejudge.u-aizu.ac.jp/problems/2871</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/euler_tour.cpp.html">graph/euler_tour.cpp</a>
* :heavy_check_mark: <a href="../../library/graph/graph_template.cpp.html">graph/graph_template.cpp</a>
* :heavy_check_mark: <a href="../../library/tree/SegmentTree/lazysegtree.cpp.html">tree/SegmentTree/lazysegtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 214, in update
    raise BundleError(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/euler_tour.cpp: line 2: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

