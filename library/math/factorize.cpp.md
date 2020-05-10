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


# :warning: math/factorize.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/factorize.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
#include <iostream>

void solve(){
    int n;
    std::cin>>n;
    std::cout<<n<<":";
    int t=n;
    for(int i=2;i*i<= n; ++i){
        while(t%i==0){
            std::cout<<" "<<i;
            t=t/i;
        }
    }
    if(t==n)std::cout<<" "<<n;
    else if(t!=1)std::cout<<" "<<t;

    std::cout<<std::endl;
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
#line 1 "math/factorize.cpp"
//https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
#include <iostream>

void solve(){
    int n;
    std::cin>>n;
    std::cout<<n<<":";
    int t=n;
    for(int i=2;i*i<= n; ++i){
        while(t%i==0){
            std::cout<<" "<<i;
            t=t/i;
        }
    }
    if(t==n)std::cout<<" "<<n;
    else if(t!=1)std::cout<<" "<<t;

    std::cout<<std::endl;
}

int main(){
    solve();
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

