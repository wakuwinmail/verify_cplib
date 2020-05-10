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


# :warning: graph/unionfind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
//cut begin
struct UnionFind{
private:
    std::vector<int> par;
    std::vector<int> rank;
public:
    UnionFind(int size){
        par=std::vector<int>(size);
        rank=std::vector<int>(size);
        for(int i=0;i<size;++i){
            par[i]=i;
            rank[i]=1;
        }
    }

    int root(int x){
        if(par[x]==x)return x;
        else {
            par[x]=root(par[x]);
            return par[x];
        }
    }

    bool same(int x,int y){//0-indexed
        return root(x)==root(y);
    }

    void unite(int x,int y){//0-indexed
        x=root(x);
        y=root(y);
        if(x==y)return;

        if(rank[x]<rank[y]){
            par[x]=y;
        }
        else{
            par[y]=x;
            if(rank[x]==rank[y])++rank[x];
        }
    }
};
//cut end
void solve(){
    int n,q;
    std::cin>>n>>q;
    UnionFind uf(n);
    int p,a,b;
    for(int i=0;i<q;++i){
        std::cin>>p>>a>>b;
        if(p==0)uf.unite(a,b);
        else{
            if(uf.same(a,b))std::cout<<"Yes\n";
            else std::cout<<"No\n";
        }
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
#line 1 "graph/unionfind.cpp"
#include <iostream>
#include <vector>
//cut begin
struct UnionFind{
private:
    std::vector<int> par;
    std::vector<int> rank;
public:
    UnionFind(int size){
        par=std::vector<int>(size);
        rank=std::vector<int>(size);
        for(int i=0;i<size;++i){
            par[i]=i;
            rank[i]=1;
        }
    }

    int root(int x){
        if(par[x]==x)return x;
        else {
            par[x]=root(par[x]);
            return par[x];
        }
    }

    bool same(int x,int y){//0-indexed
        return root(x)==root(y);
    }

    void unite(int x,int y){//0-indexed
        x=root(x);
        y=root(y);
        if(x==y)return;

        if(rank[x]<rank[y]){
            par[x]=y;
        }
        else{
            par[y]=x;
            if(rank[x]==rank[y])++rank[x];
        }
    }
};
//cut end
void solve(){
    int n,q;
    std::cin>>n>>q;
    UnionFind uf(n);
    int p,a,b;
    for(int i=0;i<q;++i){
        std::cin>>p>>a>>b;
        if(p==0)uf.unite(a,b);
        else{
            if(uf.same(a,b))std::cout<<"Yes\n";
            else std::cout<<"No\n";
        }
    }
}

int main(){
    solve();
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

