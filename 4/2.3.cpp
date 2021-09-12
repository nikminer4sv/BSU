#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>

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
    int n;
    vector<int> simples;
    cin >> n;
    for (int i = n; i <= 2 * n; i++)
    {
        if (simple(i) == 1)
        {
            simples.push_back(i);
        }
    }
    for (int i = 0; i < simples.size(); i++)
    {
        if ((simples[i + 1] - simples[i]) == 2)
        {
            cout << "[" << simples[i] << "] [" << simples[i + 1] << "]\n";
        }
    }   
}
