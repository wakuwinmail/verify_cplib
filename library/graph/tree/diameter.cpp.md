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


# :x: graph/tree/diameter.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#28790b6202284cbbffc9d712b59f4b80">graph/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/tree/diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 18:20:02+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">graph/graph_template.cpp</a>


## Verified with

* :x: <a href="../../../verify/verify/diameter.test.cpp.html">verify/diameter.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

#include "../graph_template.cpp"

//G:グラフを管理してる型（vector<vector>やvector<set>を指定する）
//T:辺のコスト
template <typename T>
struct TreeDiam {
private:
    using G = graph<T>;
    int u,v;//直径の両端
    T maxdist;//直径
    void dfs(G &g,int x,int p,int dist) {
    //std::cerr<<"x:"<<x<<std::endl;
        if(dist>maxdist){
            v=x;
            maxdist=dist;
        }
        for(auto y:g[x]) {
            if(y.to==p)continue;
            dfs(g,y.to,x,dist+y.cost);
        }
    }

public:
    TreeDiam(G g) {
        u=0;//仮に置いた端点
        maxdist=0;
        dfs(g,u,-1,0);
    //std::cerr<<"md:"<<maxdist<<std::endl;
        u=v;
        maxdist=0;
        dfs(g,u,-1,0);
    }

    std::pair<int,int> end_nodes(){
        return std::make_pair(u,v);
    }

    T diameter(){
        return maxdist;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/tree/diameter.cpp"
#include <vector>
#include <utility>

#line 3 "graph/graph_template.cpp"
template<typename T=long long>
struct edge {
public:
    int from;
    int to;
    T cost;
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}
};

template<typename T>
using graph = std::vector<std::vector<edge<T>>>;//重み付きグラフ

using Graph = std::vector<std::vector<int>>;//重み無しグラフ
#line 6 "graph/tree/diameter.cpp"

//G:グラフを管理してる型（vector<vector>やvector<set>を指定する）
//T:辺のコスト
template <typename T>
struct TreeDiam {
private:
    using G = graph<T>;
    int u,v;//直径の両端
    T maxdist;//直径
    void dfs(G &g,int x,int p,int dist) {
    //std::cerr<<"x:"<<x<<std::endl;
        if(dist>maxdist){
            v=x;
            maxdist=dist;
        }
        for(auto y:g[x]) {
            if(y.to==p)continue;
            dfs(g,y.to,x,dist+y.cost);
        }
    }

public:
    TreeDiam(G g) {
        u=0;//仮に置いた端点
        maxdist=0;
        dfs(g,u,-1,0);
    //std::cerr<<"md:"<<maxdist<<std::endl;
        u=v;
        maxdist=0;
        dfs(g,u,-1,0);
    }

    std::pair<int,int> end_nodes(){
        return std::make_pair(u,v);
    }

    T diameter(){
        return maxdist;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

