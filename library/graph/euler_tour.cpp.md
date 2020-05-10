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


# :x: graph/euler_tour.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/euler_tour.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 14:59:00+09:00




## Verified with

* :x: <a href="../../verify/test/euler_tour.test.cpp.html">test/euler_tour.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/problems/2871
#include <vector>
#include <utility>

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/euler_tour.cpp"
//https://onlinejudge.u-aizu.ac.jp/problems/2871
#include <vector>
#include <utility>

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
