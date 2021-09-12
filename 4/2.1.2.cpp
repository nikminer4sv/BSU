#include <tchar.h>
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <cmath>
#include <vector>
 
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    double number, number1; 
    int k, n, sum = 0;   
    vector<int> numbers;
    cin >> number >> k >> n;
    number1 = number - floor(number);
    stringstream ss;
    ss << setprecision(15) <<  number;
    string strNum = ss.str();
    size_t pos = strNum.find('.');       
    int NoD = strNum.size() - 1 - pos;
    for (int i = 0; i < NoD; i++)
    {
        number1 *= 10;
        numbers.push_back(trunc(number1));
        number1 -= trunc(number1);
    }
    for (int i = 0; i < n; i++)
    {
        sum += numbers[k + i];
    }
    if (numbers[k - 1] == sum)
    {
        cout << "Ravno";
    } else 
    {
        cout << "Ne ravno";
    } 
    return 0;   
}
