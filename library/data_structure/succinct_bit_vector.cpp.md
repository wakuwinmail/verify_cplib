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


# :warning: data_structure/succinct_bit_vector.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/succinct_bit_vector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:55:57+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
//cut begin
using unsigned char=i8;
using unsigned short=i16;

struct BitVector{
private:
    i16 length,cnum,bnum
    i16 cw=256,bw=8;
    std::vector<i8> bit;
    std::vector<i16> chunk;
    std::vector<std::vector<i8>> block;
    static std::vector<i8> table;

    i8 popcount(u8 n){
        return table[n];
    }
public:
    explicit BitVector(int n):length(n){
        cnum=(length+cw-1/cw);
        bnum=cw/bw;
        bit.assign(cnum*bnum,0);
        chunk.assign(cnum+1,0);
        block.assign(cnum,std::vector<i8>(bnum,0));
    }

    void set(int pos,int b){//0-indexed
        int bpos=pos/bw;
        int offset=pos%bw;
        if(b==0){
            bit[bpos] &= ~(1<<offset);
        }
        else{
            bit[bpos] |= (1<<offset);
        }
    }

    void build(){
        chunk[0]=0;
        for (int i = 0; i < cnum; ++i){
            block[i][0]=0;
            for (int j = 1; j < bnum; ++j){
                block[i][j]=block[i][j-1]+popcount(bit[(i+1)*bnum+j]);
            }
            chunk[i+1]=chunk[i]+block[i][bnum-1]+popcount(bit[(i+1)*bnum-1]);
        }
    }
};

vector<u8> bitVector::table = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 
};
//cut end
void solve(){

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
#line 1 "data_structure/succinct_bit_vector.cpp"
#include <vector>
//cut begin
using unsigned char=i8;
using unsigned short=i16;

struct BitVector{
private:
    i16 length,cnum,bnum
    i16 cw=256,bw=8;
    std::vector<i8> bit;
    std::vector<i16> chunk;
    std::vector<std::vector<i8>> block;
    static std::vector<i8> table;

    i8 popcount(u8 n){
        return table[n];
    }
public:
    explicit BitVector(int n):length(n){
        cnum=(length+cw-1/cw);
        bnum=cw/bw;
        bit.assign(cnum*bnum,0);
        chunk.assign(cnum+1,0);
        block.assign(cnum,std::vector<i8>(bnum,0));
    }

    void set(int pos,int b){//0-indexed
        int bpos=pos/bw;
        int offset=pos%bw;
        if(b==0){
            bit[bpos] &= ~(1<<offset);
        }
        else{
            bit[bpos] |= (1<<offset);
        }
    }

    void build(){
        chunk[0]=0;
        for (int i = 0; i < cnum; ++i){
            block[i][0]=0;
            for (int j = 1; j < bnum; ++j){
                block[i][j]=block[i][j-1]+popcount(bit[(i+1)*bnum+j]);
            }
            chunk[i+1]=chunk[i]+block[i][bnum-1]+popcount(bit[(i+1)*bnum-1]);
        }
    }
};

vector<u8> bitVector::table = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 
};
//cut end
void solve(){

}

int main(){
    solve();
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

