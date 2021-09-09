#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() // 1 5 3 10 -> 5 1 3 10 -> 10 1 3 5 -> 10 3 1 5 -> 10 5 1 3 -> 10 5 3 1
{
    float x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    if (x1 < x2)
    {
        swap(x1,x2);
    }
    if (x1 < x3)
    {
        swap(x1,x3);
    }
    if (x1 < x4)
    {
        swap(x1,x4);
    }
    if (x2 < x3)
    {
        swap(x2, x3);
    }
    if (x2 < x4)
    {
        swap(x2, x4);
    }
    if (x3 < x4)
    {
        swap(x3,x4);
    }
    if ((x1 > x2) && (x2 > x3) && (x3 > x4))
    {
        cout << "ok";
    } else 
    {
        cout << "no";
    }
}
