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


# :warning: graph/strongly_conneted_components.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly_conneted_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

//cut begin
using Graph=std::vector<std::vector<int>>;//無向グラフ

struct StronglyConnectedComponents{
private:
    int n,m;//n:頂点数,m:辺数
    Graph G;//辺の情報を入れる
    Graph RG;//逆辺の情報を入れる
    Graph RES;//強連結成分に分けた後のグラフ
    std::vector<bool> visited;//dfsで使う
    std::vector<int> porder;//帰りがけ順
    std::vector<int> gp;//頂点が属する強連結成分の番号
    std::vector<std::vector<int>> scset;//連結成分に入っている頂点の集合
public:
    StronglyConnectedComponents(Graph &G):G(G){
        n=G.size();
        RG.resize(n);
        m=0;
        for(int t = 0; t < n; ++t){
            m+=G[t].size();
            for(auto f:G[t]){
                RG[f].emplace_back(t);
            }
        }

        visited.assign(n,false);
        for(int i = 0; i < n; ++i){
            if(visited[i])continue;
            dfs(i);
        }

        std::reverse(porder.begin(),porder.end());
        visited.assign(n,false);
        gp.assign(n,-1);
        int sc=0;
        for(auto i:porder){
            if(visited[i])continue;
            dfs2(i,sc);
            ++sc;
        }

        scset.resize(sc+1);
        for(int i = 0; i < n; ++i){
            scset[gp[i]].emplace_back(i);
        }
        
        RES.resize(n);
        for(int i = 0; i < n; ++i){
            for(auto v: G[i]){
                int x=gp[i],y=gp[v];
                if(x==y)continue;
                RES[x].push_back(y);
            }
        }
    }

    void dfs(int pos){//帰りがけ順の記録
        visited[pos]=true;
        for(auto i:G[pos]){
            if(!visited[i])dfs(i);
        }
        porder.emplace_back(pos);
    }

    void dfs2(int pos,int d){
        visited[pos]=true;
        gp[pos]=d;
        for(auto i:RG[pos]){
            if(!visited[i])dfs2(i,d);
        }
    }

    std::vector<int> scelememts(unsigned int s){//0-indexed,s番目の強連結成分の中身を返す
        if(s>=scset.size())return std::vector<int>();
        else return scset[s];
    }

    size_t size(){
        return scset.size();
    }

    bool same(int a,int b){//0-indexed,aとbが同じ強連結成分に属しているか
        return gp[a]==gp[b];
    }

    void dbg(int s){
        for(auto i:scset[s]){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};
//cut end

void solve(){
    int n,m;
    std::cin>>n>>m;
    Graph G(n);//辺の情報を入れる
    Graph RES;//強連結成分に分けた後のグラフ
    for(int i = 0; i < m; ++i){
        int f,t;
        std::cin>>f>>t;
        G[f].emplace_back(t);
    }
    StronglyConnectedComponents scc(G);
    int q;
    std::cin>>q;
    for(int i = 0; i < q; ++i){
        int a,b;
        std::cin>>a>>b;
        if(scc.same(a,b))std::cout<<1<<std::endl;
        else std::cout<<0<<std::endl;
    }
    /*
    for(int i = 0; i < n; ++i){
        auto it=scc.scelememts(i);
        std::cout<<i<<" ";
        scc.dbg(i);
        std::sort(it.begin(),it.end());
        for(int i = 0; i < (int)it.size(); ++i){
            std::cout<<it[i]+1;
            if(i==(int)it.size()-1)std::cout<<"\n";
            else std::cout<<" ";
        }
    }
    */
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
#line 1 "graph/strongly_conneted_components.cpp"
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

//cut begin
using Graph=std::vector<std::vector<int>>;//無向グラフ

struct StronglyConnectedComponents{
private:
    int n,m;//n:頂点数,m:辺数
    Graph G;//辺の情報を入れる
    Graph RG;//逆辺の情報を入れる
    Graph RES;//強連結成分に分けた後のグラフ
    std::vector<bool> visited;//dfsで使う
    std::vector<int> porder;//帰りがけ順
    std::vector<int> gp;//頂点が属する強連結成分の番号
    std::vector<std::vector<int>> scset;//連結成分に入っている頂点の集合
public:
    StronglyConnectedComponents(Graph &G):G(G){
        n=G.size();
        RG.resize(n);
        m=0;
        for(int t = 0; t < n; ++t){
            m+=G[t].size();
            for(auto f:G[t]){
                RG[f].emplace_back(t);
            }
        }

        visited.assign(n,false);
        for(int i = 0; i < n; ++i){
            if(visited[i])continue;
            dfs(i);
        }

        std::reverse(porder.begin(),porder.end());
        visited.assign(n,false);
        gp.assign(n,-1);
        int sc=0;
        for(auto i:porder){
            if(visited[i])continue;
            dfs2(i,sc);
            ++sc;
        }

        scset.resize(sc+1);
        for(int i = 0; i < n; ++i){
            scset[gp[i]].emplace_back(i);
        }
        
        RES.resize(n);
        for(int i = 0; i < n; ++i){
            for(auto v: G[i]){
                int x=gp[i],y=gp[v];
                if(x==y)continue;
                RES[x].push_back(y);
            }
        }
    }

    void dfs(int pos){//帰りがけ順の記録
        visited[pos]=true;
        for(auto i:G[pos]){
            if(!visited[i])dfs(i);
        }
        porder.emplace_back(pos);
    }

    void dfs2(int pos,int d){
        visited[pos]=true;
        gp[pos]=d;
        for(auto i:RG[pos]){
            if(!visited[i])dfs2(i,d);
        }
    }

    std::vector<int> scelememts(unsigned int s){//0-indexed,s番目の強連結成分の中身を返す
        if(s>=scset.size())return std::vector<int>();
        else return scset[s];
    }

    size_t size(){
        return scset.size();
    }

    bool same(int a,int b){//0-indexed,aとbが同じ強連結成分に属しているか
        return gp[a]==gp[b];
    }

    void dbg(int s){
        for(auto i:scset[s]){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};
//cut end

void solve(){
    int n,m;
    std::cin>>n>>m;
    Graph G(n);//辺の情報を入れる
    Graph RES;//強連結成分に分けた後のグラフ
    for(int i = 0; i < m; ++i){
        int f,t;
        std::cin>>f>>t;
        G[f].emplace_back(t);
    }
    StronglyConnectedComponents scc(G);
    int q;
    std::cin>>q;
    for(int i = 0; i < q; ++i){
        int a,b;
        std::cin>>a>>b;
        if(scc.same(a,b))std::cout<<1<<std::endl;
        else std::cout<<0<<std::endl;
    }
    /*
    for(int i = 0; i < n; ++i){
        auto it=scc.scelememts(i);
        std::cout<<i<<" ";
        scc.dbg(i);
        std::sort(it.begin(),it.end());
        for(int i = 0; i < (int)it.size(); ++i){
            std::cout<<it[i]+1;
            if(i==(int)it.size()-1)std::cout<<"\n";
            else std::cout<<" ";
        }
    }
    */
}

int main(){
    solve();
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

