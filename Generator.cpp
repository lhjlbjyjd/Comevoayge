#include <random>
#include "Generator.h"

std::vector<Point> Generator::generate(int n, double rad){
    std::vector<Point> result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    for(int i = 0; i < n; i++) {
        double phi = dis(gen) + 0.00000000000000000000001;
        double r = dis(gen) + 0.00000000000000000000001;

        result.emplace_back(cos(2 * 3.14159265359 * phi) * sqrt(-2 * log(r)) * rad,
                            sin(2 * 3.14159265359 * phi) * sqrt(-2 * log(r)) * rad);
    }
    return result;
}