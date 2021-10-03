#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main() {

	int i = 0, j = 0;
	long long degree = 0, number;
	cin >> number;

	while (degree < abs(number)) {

		degree = pow(2, i);
		i++;

	}

	char *digits = new char[255];

	if (number >= 0) {

		while (i >= 0) {

			degree = pow(2, i);

			if (number & degree) {

				digits[j] = '1';

			} else

				digits[j] = '0';

			i--;
			j++;

		}
		digits[j] = '\0';

	} else if (number < 0) {

		while (i >= 0) {

			degree = pow(2, i);

			if ((abs(number) - 1) & degree) {

				digits[j] = '1';

			} else

				digits[j] = '0';

			i--;
			j++;

		}
		digits[j] = '\0';

		for (int k = 0; k < j; k++) {

			if (digits[k] == '0')

				digits[k] = '1';

			else

				digits[k] = '0';

		}	

	}
	
	cout << digits;

}
