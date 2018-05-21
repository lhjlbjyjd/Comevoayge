#include <iostream>
#include "Tester.h"

using namespace std;

typedef pair<double,double> Point;

int main() {
    Tester tester;
    for (int i = 2; i < 10; i++) {
        Point ans = tester.experiment(i, 1, 200);
        cout << i << " points:" << endl << ans.first << " " << ans.second << endl;
    }
    return 0;
}