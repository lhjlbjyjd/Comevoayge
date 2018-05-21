#include <vector>
#include "Tester.h"

double Tester::length(Point p1, Point p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

std::vector<std::vector<int>> Tester::makeListGraph(int n, std::vector<Edge>& edges){
    std::vector<std::vector<int>> graph(n);
    for(Edge &e : edges){
        graph[std::get<0>(e)].emplace_back(std::get<1>(e));
        graph[std::get<1>(e)].emplace_back(std::get<0>(e));
    }
    return graph;
}

void Tester::DFS(const std::vector<std::vector<int>>& graph, std::set<int>& visited, int current){
    if(visited.count(current) > 0){
        return;
    }
    visited.insert(current);
    for(int vertex : graph[current]){
        DFS(graph, visited, vertex);
    }
}

double Tester::getMin(const std::vector<std::vector<int>>& graph, const std::vector<Point>& points, std::vector<Edge>& edges){
    std::set<int> visited;
    double result = 0;
    DFS(graph, visited, 0);
    for(int i = 1; i < visited.size(); i++){
        result+= length(points[i - 1], points[i]);
    }
    result+= length(points[visited.size() - 1], points[0]);
    return result;
}

double Tester::relax(int n, double rad) {
    Generator gen;
    Boruvka boruvka;
    Bruteforce brut;
    std::vector<Point> points = gen.generate(n, rad);
    std::vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.emplace_back(i, j, length(points[i], points[j]), i * n + j);
        }
    }
    edges = boruvka.getMinOstov(points.size(), edges);
    double ideal = brut.getAnswer(points);
    return getMin(makeListGraph(points.size(), edges), points, edges) / ideal;
}

Point Tester::experiment(int pointsNumber, int radius, int repeats) {
    std::vector<double> declines(repeats);
    double sum = 0;
    for (int i = 0; i < repeats; i++) {
        declines[i] = relax(pointsNumber, radius);
        sum += declines[i];
    }
    double mean = sum / repeats;
    sum = 0;
    for (int i = 0; i < repeats; i++) {
        sum += (declines[i] - mean) * (declines[i] - mean);
    }
    return {mean, sqrt(sum / repeats)};
};