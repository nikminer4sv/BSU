#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

	int i = 0;
	long long degree = 0, number;
	cin >> number;

	while (degree < abs(number)) {

		degree = pow(2, i);
		i++;

	}

	vector<int> digits;

	if (number >= 0) {

		while (i >= 0) {

			degree = pow(2, i);

			if (number & degree) {

				digits.push_back(1);

			} else

				digits.push_back(0);

			i--;

		}

	} else if (number < 0) {

		while (i >= 0) {

			degree = pow(2, i);

			if (abs(number) & degree) {

				digits.push_back(0);

			} else

				digits.push_back(1);

			i--;

		}

	}
	
	for (int i : digits)
		cout << i;

}
