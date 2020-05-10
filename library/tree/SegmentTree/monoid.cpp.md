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


# :warning: tree/SegmentTree/monoid.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#f1973713ea4397a8e0580271720556c9">tree/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/SegmentTree/monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Required by

* :warning: <a href="abstsegtree.cpp.html">tree/SegmentTree/abstsegtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
