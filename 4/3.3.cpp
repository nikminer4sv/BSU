#include <math.h>
#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    int Size = 2 * N;
    bool a[Size]={0};
    
    for (int i = 2; i < Size; i++)
        a[i] = true;

    unsigned int n = sqrt(double(Size));

    for (int i = 2; i <= n; i++)
        if (a[i]) 
            for (int j = i * 2; j < Size; j += i)
                a[j] = false;

    for (int i = 0; i < Size; i++)
        if (a[i] && i >= N)
            cout << i << " "; 

    cout << endl;
}
