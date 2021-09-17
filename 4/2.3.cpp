#include <iostream>

using namespace std;

int simple(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
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
