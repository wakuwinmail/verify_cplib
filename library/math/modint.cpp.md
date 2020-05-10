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


# :warning: math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<cstdint>
#include<iostream>

template<std::uint64_t Mod> struct ModInt{
    using u64=uint64_t;
private:
    u64 a;
public:
    constexpr ModInt(){}
    constexpr ModInt(u64 x=0):a(x%Mod){}

    constexpr u64 &value(){return a;}
    constexpr const u64 &value()const{return a;}


    constexpr ModInt &operator+=(const ModInt rhs){
        a+=rhs.value();
        if(a>=Mod){
            a-=Mod;
        }
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt rhs){
        if(a<rhs.value()){
            a+=Mod;
        }
        a-=rhs.value();
        return *this;
    }

    constexpr ModInt &operator*=(const ModInt rhs){
        a=a*rhs.value()%Mod;
        return *this;
    }

    constexpr ModInt &operator/=(ModInt rhs){
        u64 n=Mod-2;
        while(n>0){
        if((n&1)!=0){//n%2==1
            *this*=rhs;
        }
        rhs*=rhs;
        n=n/2;
        }
        return *this;
    }

    constexpr ModInt operator+(const ModInt rhs){
        return ModInt(*this)+=rhs;
    }

    constexpr ModInt operator-(const ModInt rhs){
        return ModInt(*this)-=rhs;
    }

    constexpr ModInt operator*(const ModInt rhs){
        return ModInt(*this)*=rhs;
    }

    constexpr ModInt operator/(const ModInt rhs){
        return ModInt(*this)/=rhs;
    }
    constexpr ModInt &operator++(){
        ++a;
        if(a>=Mod){
            a-=Mod;
        }
        return *this;
    }

    constexpr ModInt &operator--(){
        if(a==0){
            a+=Mod;
        }
        --a;
        return *this;
    }

    constexpr ModInt operator- (){
        if(a==0)return ModInt(0);
        else return ModInt(Mod-a);
    }


};

using Mi=ModInt<1000000007ull>;

Mi operator"" _mi(unsigned long long n){
    return Mi(n);
}

int main(){
    int n;
    std::cin>>n;
    Mi mi(n);
    mi+=-4_mi;
    std::cout<<mi.value()<<std::endl;
    mi-=5_mi;
    std::cout<<mi.value()<<std::endl;
    mi*=8_mi;
    std::cout<<mi.value()<<std::endl;
    mi/=2_mi;
    std::cout<<mi.value()<<std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.cpp"
#include<cstdint>
#include<iostream>

template<std::uint64_t Mod> struct ModInt{
    using u64=uint64_t;
private:
    u64 a;
public:
    constexpr ModInt(){}
    constexpr ModInt(u64 x=0):a(x%Mod){}

    constexpr u64 &value(){return a;}
    constexpr const u64 &value()const{return a;}


    constexpr ModInt &operator+=(const ModInt rhs){
        a+=rhs.value();
        if(a>=Mod){
            a-=Mod;
        }
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt rhs){
        if(a<rhs.value()){
            a+=Mod;
        }
        a-=rhs.value();
        return *this;
    }

    constexpr ModInt &operator*=(const ModInt rhs){
        a=a*rhs.value()%Mod;
        return *this;
    }

    constexpr ModInt &operator/=(ModInt rhs){
        u64 n=Mod-2;
        while(n>0){
        if((n&1)!=0){//n%2==1
            *this*=rhs;
        }
        rhs*=rhs;
        n=n/2;
        }
        return *this;
    }

    constexpr ModInt operator+(const ModInt rhs){
        return ModInt(*this)+=rhs;
    }

    constexpr ModInt operator-(const ModInt rhs){
        return ModInt(*this)-=rhs;
    }

    constexpr ModInt operator*(const ModInt rhs){
        return ModInt(*this)*=rhs;
    }

    constexpr ModInt operator/(const ModInt rhs){
        return ModInt(*this)/=rhs;
    }
    constexpr ModInt &operator++(){
        ++a;
        if(a>=Mod){
            a-=Mod;
        }
        return *this;
    }

    constexpr ModInt &operator--(){
        if(a==0){
            a+=Mod;
        }
        --a;
        return *this;
    }

    constexpr ModInt operator- (){
        if(a==0)return ModInt(0);
        else return ModInt(Mod-a);
    }


};

using Mi=ModInt<1000000007ull>;

Mi operator"" _mi(unsigned long long n){
    return Mi(n);
}

int main(){
    int n;
    std::cin>>n;
    Mi mi(n);
    mi+=-4_mi;
    std::cout<<mi.value()<<std::endl;
    mi-=5_mi;
    std::cout<<mi.value()<<std::endl;
    mi*=8_mi;
    std::cout<<mi.value()<<std::endl;
    mi/=2_mi;
    std::cout<<mi.value()<<std::endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

