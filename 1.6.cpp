#include <iostream>
#include <bitset>
 
using namespace std;
 
int main() {
 
    short int n;
    cin >> n;
 
    auto ArrayOfBits = bitset<16>(n);
 
    for (int i = 0; i < 16; i++)
        cout << ArrayOfBits[i] << " ";
 
    cout << endl;
 
    cout << ArrayOfBits[0] << " " << ArrayOfBits[3] << " " << ArrayOfBits[13] << endl;  
 
    cout << ArrayOfBits[1].flip() << " " << ArrayOfBits[7].flip() << endl;
 
    for (int i = 0; i < 16; i++)
        cout << ArrayOfBits[i] << " ";
 
}
