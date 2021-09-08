#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    int LadX, LadY, SlonX, SlonY;
    cin >> LadX >> LadY >> SlonX >> SlonY;
    if ((LadX == SlonX) || (LadY == SlonY))
    {
        cout << "Lad'a b'et slona na etom xody" << endl;
    } else 
    {
        cout << "Lad'a b'et slona na sled. xody" << endl;
    }
    if (abs(SlonX - LadX) != abs(SlonY - LadY))
    {
        cout << "Slon nikogda ne b'et lad'u";
    } else
    {
        if (abs(SlonX - LadX) == abs(SlonY - LadY))
        {
            cout << "Slon b'et lad'u na etom xody" << endl;
        } else 
        {
            cout << "Slon b'et lad'u na sled. xody" << endl;
        }
    }
}
