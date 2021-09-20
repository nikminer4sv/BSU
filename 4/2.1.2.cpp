#include <iostream>
#include <cmath>
 
using namespace std;

int main()
{
    double number, drob; 
    int k, n, sum = 0, x = 0;   
    cin >> number >> k >> n;
    drob = number - floor(number);
    for (int i = 0; i < k; i++)
    {
        drob *= 10;
        x = drob;
        drob -= floor(drob);
    }
    for (int i = 0; i < n; i++)
    {
        drob *= 10;
        sum += drob;
        drob -= floor(drob);                                                                                                                                                                                                                                                                 
    }                                                                                                                                                                                                                                                                               int z = log10(int(x)) + 1;  if ((z + k) <= 5) sum += 1;                        
    if (x == sum)
    {
        cout << "Ravno";
    } else 
    {
        cout << "Ne ravno";
    } 
    return 0;   
}
