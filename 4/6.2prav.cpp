#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int GetRandomInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {

	srand(time(NULL));

	cout << "Enter amount of dates: ";
	int n;
	cin >> n;

	union Date
	{
		unsigned short simb;
		struct
		{
			unsigned int day : 5;
			unsigned int month : 4;
			unsigned int year : 7;
		};
	}; 

	Date *Array = new Date[10];

	for (int i = 0; i < n; i++) {
	
		Array[i].day = GetRandomInt(1, 31);
		Array[i].month = GetRandomInt(1, 12);
		Array[i].year = GetRandomInt(0, 99);
		cout << setw(2) << Array[i].day << "." << setw(2) << Array[i].month << "." << setw(2) << Array[i].year << " -> " << Array[i].simb << endl;

	}

	delete[] Array;
	return 0;

}
