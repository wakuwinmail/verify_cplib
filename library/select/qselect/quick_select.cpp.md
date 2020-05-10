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


# :warning: select/qselect/quick_select.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5b79bc804da25001450a7c95ae454d7">select/qselect</a>
* <a href="{{ site.github.repository_url }}/blob/master/select/qselect/quick_select.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://en.wikipedia.org/wiki/Median_of_medians
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

template<typename V>
int select(std::vector<V>&,int,int,int);

template<typename V>
int partition(std::vector<V>&,int,int,int,int);

template<typename V>
int pivot(std::vector<V>&,int,int);

template<typename V>
int median5(std::vector<V>&,int,int);

//dataの中からk番目(0-indexed)に大きい要素のindexを計算する
//探索範囲は[start,end]
template<typename V>
int select(std::vector<V>& data,int k,int start,int end){
    int pivotIndex=-1;
    while(start!=end){
        pivotIndex=pivot(data,start,end);
        pivotIndex=partition(data,start,end,pivotIndex,k);

        if(pivotIndex==k)return k;
        else if(pivotIndex<k){
            start=pivotIndex+1;
        }
        else if(pivotIndex>k){
            end=pivotIndex-1;
        }
    }
    return end;
}

template<typename V>
int partition(std::vector<V>& data,int start,int end,int pivotIndex,int k){
    V pivotValue=data[pivotIndex];
    std::swap(data[pivotIndex],data[end]);
    int storeIndex=start;

    for(int i=start;i<end;++i){
        if(data[i]<pivotValue){
            std::swap(data[storeIndex],data[i]);
            ++storeIndex;
        }
    }

    int storeIndexEq=storeIndex;
    for(int i=storeIndexEq;i<end;++i){
        if(data[i]==pivotValue){
            std::swap(data[storeIndexEq],data[i]);
            ++storeIndexEq;
        }
    }

    std::swap(data[end],data[storeIndexEq]);
    if(k<storeIndex)return storeIndex;
    else if(k<=storeIndexEq)return k;
    else return storeIndexEq;
}

//dataの[start,end]からpivot値を計算する
template<typename V>
int pivot(std::vector<V>& data,int start,int end){
    if(end-start<5){
        return median5(data,start,end);
    }

    for(int i=start;i<=end;i+=5){
        int substart=i;
        int subend=i+4<end?end:i+4;//max(i+4,end)

        int median=median5(data,substart,subend);

        int j=(i-start)/5;
        std::swap(data[median],data[start+j]);
    }

    int mid=(end-start)/10+start+1;
    return select(data,mid,start,start+(end-start)/5);
}

template<typename V>
int median5(std::vector<V>& data,int start,int end){
    for(int i=start+1;i<=end;++i){
        int j=i;
        while(j>start&&data[j-1]>data[j]){
            std::swap(data[j-1],data[j]);
            --j;
        }
    }
    return (start+end)/2;
}

int main(){
    int n,q;
    std::cin>>n>>q;
    std::vector<int> d(n);
    for(int i=0;i<n;++i)scanf("%d",&d[i]);
    for(int i=0;i<q;++i){
        int k;
        std::cin>>k;
        --k;
        std::cout<<d[select(d,k,0,n-1)]<<std::endl;
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "select/qselect/quick_select.cpp"
//https://en.wikipedia.org/wiki/Median_of_medians
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

template<typename V>
int select(std::vector<V>&,int,int,int);

template<typename V>
int partition(std::vector<V>&,int,int,int,int);

template<typename V>
int pivot(std::vector<V>&,int,int);

template<typename V>
int median5(std::vector<V>&,int,int);

//dataの中からk番目(0-indexed)に大きい要素のindexを計算する
//探索範囲は[start,end]
template<typename V>
int select(std::vector<V>& data,int k,int start,int end){
    int pivotIndex=-1;
    while(start!=end){
        pivotIndex=pivot(data,start,end);
        pivotIndex=partition(data,start,end,pivotIndex,k);

        if(pivotIndex==k)return k;
        else if(pivotIndex<k){
            start=pivotIndex+1;
        }
        else if(pivotIndex>k){
            end=pivotIndex-1;
        }
    }
    return end;
}

template<typename V>
int partition(std::vector<V>& data,int start,int end,int pivotIndex,int k){
    V pivotValue=data[pivotIndex];
    std::swap(data[pivotIndex],data[end]);
    int storeIndex=start;

    for(int i=start;i<end;++i){
        if(data[i]<pivotValue){
            std::swap(data[storeIndex],data[i]);
            ++storeIndex;
        }
    }

    int storeIndexEq=storeIndex;
    for(int i=storeIndexEq;i<end;++i){
        if(data[i]==pivotValue){
            std::swap(data[storeIndexEq],data[i]);
            ++storeIndexEq;
        }
    }

    std::swap(data[end],data[storeIndexEq]);
    if(k<storeIndex)return storeIndex;
    else if(k<=storeIndexEq)return k;
    else return storeIndexEq;
}

//dataの[start,end]からpivot値を計算する
template<typename V>
int pivot(std::vector<V>& data,int start,int end){
    if(end-start<5){
        return median5(data,start,end);
    }

    for(int i=start;i<=end;i+=5){
        int substart=i;
        int subend=i+4<end?end:i+4;//max(i+4,end)

        int median=median5(data,substart,subend);

        int j=(i-start)/5;
        std::swap(data[median],data[start+j]);
    }

    int mid=(end-start)/10+start+1;
    return select(data,mid,start,start+(end-start)/5);
}

template<typename V>
int median5(std::vector<V>& data,int start,int end){
    for(int i=start+1;i<=end;++i){
        int j=i;
        while(j>start&&data[j-1]>data[j]){
            std::swap(data[j-1],data[j]);
            --j;
        }
    }
    return (start+end)/2;
}

int main(){
    int n,q;
    std::cin>>n>>q;
    std::vector<int> d(n);
    for(int i=0;i<n;++i)scanf("%d",&d[i]);
    for(int i=0;i<q;++i){
        int k;
        std::cin>>k;
        --k;
        std::cout<<d[select(d,k,0,n-1)]<<std::endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

