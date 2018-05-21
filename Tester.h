//
// Created by lhjlbjyjd on 21.05.2018.
//

#ifndef COMEVOAYGE_TESTER_H
#define COMEVOAYGE_TESTER_H

#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
#include <tuple>
#include <set>
#include "Generator.h"
#include "Boruvka.h"
#include "Bruteforce.h"

typedef std::tuple<int, int, double, int> Edge;
typedef std::pair<double,double> Point;

class Tester {
public:
    Point experiment(int pointsNumber, int radius, int repeats);

private:
    double length(Point p1, Point p2);

    std::vector<std::vector<int>> makeListGraph(int n, std::vector<Edge>& edges);

    void DFS(const std::vector<std::vector<int>>& graph, std::set<int>& visited, int current);

    double getMin(const std::vector<std::vector<int>>& graph, const std::vector<Point>& points, std::vector<Edge>& edges);

    double relax(int n, double rad);
};


#endif //COMEVOAYGE_TESTER_H
