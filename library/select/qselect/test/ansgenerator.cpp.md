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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: select/qselect/test/ansgenerator.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7b9bdf5c6c8920be895da88488414838">select/qselect/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/select/qselect/test/ansgenerator.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);

    std::vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<q;++i){
        int k;
        scanf("%d",&k);
        --k;
        std::nth_element(a.begin(),a.begin()+k,a.end());
        printf("%d\n",a[k]);
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "select/qselect/test/ansgenerator.cpp"
#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);

    std::vector<int> a(n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<q;++i){
        int k;
        scanf("%d",&k);
        --k;
        std::nth_element(a.begin(),a.begin()+k,a.end());
        printf("%d\n",a[k]);
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
