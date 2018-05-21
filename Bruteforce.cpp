#include "Bruteforce.h"

double Bruteforce::length(Point p1, Point p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double Bruteforce::getAnswer(std::vector<Point > &points) {
    double min = INT_MAX;
    std::vector<int> vertex(points.size() - 1);
    for (int i = 0; i < vertex.size(); i++) {
        vertex[i] = i + 1;
    }
    do {
        double current = 0;
        for (int i = 1; i < vertex.size(); i++) {
            current += length(points[vertex[i - 1]], points[vertex[i]]);
        }
        current += length(points[0], points[vertex[0]]);
        current += length(points[0], points[vertex[vertex.size() - 1]]);
        if(current < min){
            min = current;
        }
    } while(next_permutation(vertex.begin(), vertex.end()));

    return min;
}