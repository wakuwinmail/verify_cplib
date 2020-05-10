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


# :question: graph/graph_template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 16:07:24+09:00




## Required by

* :heavy_check_mark: <a href="euler_tour.cpp.html">graph/euler_tour.cpp</a>
* :x: <a href="tree/diameter.cpp.html">graph/tree/diameter.cpp</a>


## Verified with

* :x: <a href="../../verify/verify/diameter.test.cpp.html">verify/diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/euler_tour.test.cpp.html">verify/euler_tour.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/graph_template.cpp"
#include <vector>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

