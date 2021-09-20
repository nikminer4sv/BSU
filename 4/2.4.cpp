#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    system("cls");
    int n, kolvo = 0, max = 0;
    cout << "Vvedite kolichestvo chisel : ";
    cin >> n;
    double t;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        t = sqrt(k);
        if (t == int(t))
        {
            ++kolvo;
        }
        else
        {
            if (kolvo >= max)
            {
                max = kolvo;
            }
            kolvo = 0;
        }
    }
    if (t == int(t) && kolvo >= max)
    max = kolvo;
    cout << max;
}
