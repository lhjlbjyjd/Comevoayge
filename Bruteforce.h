#ifndef COMEVOAYGE_BRUTEFORCE_H
#define COMEVOAYGE_BRUTEFORCE_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

typedef std::tuple<int, int, double, int> Edge;
typedef std::pair<double,double> Point;

class Bruteforce{

private:
    double length(Point p1, Point p2);

public:

    Bruteforce() = default;

    double getAnswer(std::vector<Point>& points);
};

#endif //COMEVOAYGE_BRUTEFORCE_H
