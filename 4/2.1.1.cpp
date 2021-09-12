#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    int x;
    set<int> cifry;
    cin >> x;
    int kolvo = log10(x);
    int array[kolvo + 1];
    for (int i = 0; i < kolvo; i++)
    {
        array[i] = x % 10;
        cifry.insert(x % 10);
        x /= 10;
    }
    array[kolvo] = x;
    cifry.insert(x);
    if (cifry.size() == (kolvo + 1))
    {
        cout << "Povtora net";
    } else
    {
        cout << "Povtor est'";
    }
}
