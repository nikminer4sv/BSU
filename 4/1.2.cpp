#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x, y, R1, R2;
    bool p;
    cin >> x >> y >> R1 >> R2;
    p = (x*x + y*y >= R1) && (x*x + y*y <= R2) && ((x > 0 && y > 0) || (x < 0 && y < 0));
    cout << p;
}
