#ifndef COMEVOAYGE_BORUVKA_H
#define COMEVOAYGE_BORUVKA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

typedef std::tuple<int, int, double, int> Edge;
typedef std::pair<double,double> Point;

class Boruvka{

private:
    std::vector<int> findcomp(int n, std::vector<std::vector<int>> &g);

public:

    Boruvka() = default;

    std::vector<Edge> getMinOstov(int n, std::vector<Edge> &edges);

};

#endif //COMEVOAYGE_BORUVKA_H
