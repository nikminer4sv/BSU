#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int k, i = 0, y = 0;
    string ch;
    cin >> k;
    i = k - 1;
    do
    {
        int x = pow(3 , y);
        ch = to_string(x);
        i -= ch.size();
        cout << ch << " " << i << endl;
        y++;
    } while (i >= 0);
    cout << ch[ch.size() + i];
}
