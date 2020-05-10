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


# :warning: math/matrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cmath>
#include <cstddef>
#include <vector>
#include <cassert>

struct has_idplus_impl {
    template <class T>
    static auto check(T&& x)->decltype(x.idplus(),std::true_type{});

    template <class T>
    static auto check(...)->std::false_type;
};

template <class T>
class has_idplus :
        public decltype(has_idplus_impl::check<T>(std::declval<T>())) {};


template<typename T>
struct Matrix{
    using scalarvalue=T;
private:
    std::vector<std::vector<scalarvalue>> data;
    int col,row;
public:
    constexpr Matrix(){}

    constexpr Matrix(std::vector<std::vector<scalarvalue>> data):data(data){
        col=data.size();
        row=data[0].size();
    }

    constexpr Matrix(int col,int row,scalarvalue init=0):row(row),col(col){
        data.assign(col,std::vector<scalarvalue>(row,init));
    }

    constexpr Matrix &operator+=(const Matrix rhs){
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]+=rhs[i][j];
            }
        }
    }

    constexpr Matrix &operator-=(const Matrix rhs){
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]-=rhs[i][j];
            }
        }
    }

    constexpr Matrix &operator*=(const scalarvalue rhs){//スカラー倍
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]*=rhs;
            }
        }
    }

    constexpr Matrix operator*(Matrix rhs){
        Matrix<scalarvalue> ret(col,rhs.get_row(),0);
        for(int i = 0; i < col; ++i){
            for(int k = 0; k < rhs.get_row(); ++k){
                for(int j = 0; j < row; ++j){
                    ret[i][j]+=data[i][k]*rhs[k][j];
                }
            }
        }
        return ret;
    }

    constexpr std::vector<scalarvalue>& operator[](const int i){
        return data[i];
    }

    constexpr Matrix pow(long long n){
        assert(is_square());//正方形じゃないと計算が定義できない
        Matrix<scalarvalue> ret(col,row,0);
        Matrix<scalarvalue> a(*this);
        for(int i = 0; i < col; ++i){
            ret[i][i]=1;//単位行列を作る
        }
        while(n>0){
            if((n&1)!=0){//n%2==1
                ret=ret*a;
            }
            a=a*a;
            n=n/2;
        }
        return ret;
    }




    bool is_square(){return col==row;}
    int get_col(){return col;}
    int get_row(){return row;}

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix.cpp"
#include <cmath>
#include <cstddef>
#include <vector>
#include <cassert>

struct has_idplus_impl {
    template <class T>
    static auto check(T&& x)->decltype(x.idplus(),std::true_type{});

    template <class T>
    static auto check(...)->std::false_type;
};

template <class T>
class has_idplus :
        public decltype(has_idplus_impl::check<T>(std::declval<T>())) {};


template<typename T>
struct Matrix{
    using scalarvalue=T;
private:
    std::vector<std::vector<scalarvalue>> data;
    int col,row;
public:
    constexpr Matrix(){}

    constexpr Matrix(std::vector<std::vector<scalarvalue>> data):data(data){
        col=data.size();
        row=data[0].size();
    }

    constexpr Matrix(int col,int row,scalarvalue init=0):row(row),col(col){
        data.assign(col,std::vector<scalarvalue>(row,init));
    }

    constexpr Matrix &operator+=(const Matrix rhs){
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]+=rhs[i][j];
            }
        }
    }

    constexpr Matrix &operator-=(const Matrix rhs){
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]-=rhs[i][j];
            }
        }
    }

    constexpr Matrix &operator*=(const scalarvalue rhs){//スカラー倍
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                data[i][j]*=rhs;
            }
        }
    }

    constexpr Matrix operator*(Matrix rhs){
        Matrix<scalarvalue> ret(col,rhs.get_row(),0);
        for(int i = 0; i < col; ++i){
            for(int k = 0; k < rhs.get_row(); ++k){
                for(int j = 0; j < row; ++j){
                    ret[i][j]+=data[i][k]*rhs[k][j];
                }
            }
        }
        return ret;
    }

    constexpr std::vector<scalarvalue>& operator[](const int i){
        return data[i];
    }

    constexpr Matrix pow(long long n){
        assert(is_square());//正方形じゃないと計算が定義できない
        Matrix<scalarvalue> ret(col,row,0);
        Matrix<scalarvalue> a(*this);
        for(int i = 0; i < col; ++i){
            ret[i][i]=1;//単位行列を作る
        }
        while(n>0){
            if((n&1)!=0){//n%2==1
                ret=ret*a;
            }
            a=a*a;
            n=n/2;
        }
        return ret;
    }




    bool is_square(){return col==row;}
    int get_col(){return col;}
    int get_row(){return row;}

};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

