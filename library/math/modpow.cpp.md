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


# :warning: math/modpow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modpow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://atcoder.jp/contests/atc002/tasks/atc002_b
#include <iostream>
//cut begin
long long mod=1000000007LL;

template<typename T>
constexpr T modpow(T a,int n){//(a^n)%MOD
    T ret=1;
    while(n>0){
        if((n&1)!=0){//n%2==1
            ret=ret*a%mod;
        }
        a=a*a%mod;
        n=n/2;
    }
    return ret;
}
//cut end
int main(){
    long long n,m,p;
    std::cin>>n>>m>>p;
    std::cout<<modpow(n,p,m)<<std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modpow.cpp"
//https://atcoder.jp/contests/atc002/tasks/atc002_b
#include <iostream>
//cut begin
long long mod=1000000007LL;

template<typename T>
constexpr T modpow(T a,int n){//(a^n)%MOD
    T ret=1;
    while(n>0){
        if((n&1)!=0){//n%2==1
            ret=ret*a%mod;
        }
        a=a*a%mod;
        n=n/2;
    }
    return ret;
}
//cut end
int main(){
    long long n,m,p;
    std::cin>>n>>m>>p;
    std::cout<<modpow(n,p,m)<<std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

