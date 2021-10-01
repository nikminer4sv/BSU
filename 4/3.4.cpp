#include <iostream>
#include <vector>

#define base 1000000000

using namespace std;

void writelong(vector<int> vec){
    printf ("%d", vec.empty() ? 0 : vec.back());

    for (int i = (int)vec.size() - 2; i >= 0; --i)
        printf ("%09d", vec[i]);

}

vector<int> smult(vector<int> a, int b){
    int carry = 0;

    for (size_t i = 0; i < a.size() || carry; ++i) {

        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);

    }

    while (a.size() > 1 && a.back() == 0)
        a.pop_back();

    return a;
}

int main(){

    int b;
    cin >> b;
    vector<int> a(1,1);

    for (int i = 1; i <= b; i++)
        a = smult(a,i);

    writelong(a);
    cout << endl;

    return 0;
}
