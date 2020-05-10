#include <vector>
template<typename T=long long>
struct edge {
public:
    int from;
    int to;
    T cost;
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}
};

template<typename T>
using graph = std::vector<std::vector<edge<T>>>;//重み付きグラフ

using Graph = std::vector<std::vector<int>>;//重み無しグラフ