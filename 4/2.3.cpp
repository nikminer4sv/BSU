#include <iostream>
#include <cmath>

using namespace std;

bool simple(int n)
{
    bool pr;
    double m = int(sqrt(n));
    if (n == 1) pr =  false;
    else if (n == 2) pr = true;
    else if (!(n % 2)) pr = false;
    else
    { 
        pr = true;
        for (int k =3; k <= m && pr; k = k + 2)
        if ( !(n % k)) pr = false; 
    }
    return pr;
}

int main()
{
    int n, x = 0, y = 0;
    cin >> n;
    for (int i = n; i <= 2 * n; i++)
    {
        if (simple(i) == 1)
        {
            x = i;
        }
        if (x - y == 2)
        {
            cout << "[" << y << "] [" << x << "]\n";
        }
        y = x;
    }  
}
