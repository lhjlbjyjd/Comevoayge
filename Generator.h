#ifndef COMEVOAYGE_GENERATOR_H
#define COMEVOAYGE_GENERATOR_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

typedef std::tuple<int, int, double, int> Edge;
typedef std::pair<double,double> Point;

class Generator{

public:

    Generator() = default;
    std::vector<Point> generate(int n, double rad);
};

#endif //COMEVOAYGE_GENERATOR_H
