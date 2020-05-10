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


# :warning: math/modinv.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modinv.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <utility>

//long long mod=1000000007LL;

template<typename T>
T modinv(T a){
    T b=mod,u=1,v=0;
    while(b!=0){
        T t=a/b;
        a-=t*b;
        std::swap(a,b);
        u-=t*v;
        std::swap(u,v);
    }
    u%=mod;
    if(u<0)u+=mod;
    return u;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modinv.cpp"
#include <utility>

//long long mod=1000000007LL;

template<typename T>
T modinv(T a){
    T b=mod,u=1,v=0;
    while(b!=0){
        T t=a/b;
        a-=t*b;
        std::swap(a,b);
        u-=t*v;
        std::swap(u,v);
    }
    u%=mod;
    if(u<0)u+=mod;
    return u;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

