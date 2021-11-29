#include <iostream>
#include <vector>

using namespace std;

void ToArray(int Number, vector<int> *Array, int degree) {

	for (int i = 0; i < degree; i++) {

		Array->push_back((Number >> i) & 1);

   	}

}

int GetRandomInt(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

unsigned short int ToNumber(vector<int> Array) {

	unsigned short int Number = 0;

	for (int i = 0; i < Array.size(); i++)
		Number = Number ^ (Array[i] << i);

	return Number;

}

unsigned short int Realization(int day, int month, int year) {

	vector<int> Array;

	ToArray(day, &Array, 5);
	ToArray(month, &Array, 4);
	ToArray(year, &Array, 7);
	unsigned short int Number = ToNumber(Array);

	return Number; 

}

int main(){

	int n;
	cin >> n;

	struct Structura{

		unsigned int day;
		unsigned int month;
		unsigned int year;
		unsigned short int number;

	};
	Structura* date = new Structura[n];

	for (int i = 0; i < n; i++) {
	
		date[i].day = GetRandomInt(1, 31);
		date[i].month = GetRandomInt(1, 12);
		date[i].year = GetRandomInt(0, 99);
		date[i].number = Realization(date[i].day, date[i].month, date[i].year);
		cout << date[i].day << "." << date[i].month << "." << date[i].year << " -> " << date[i].number << endl;

	}
	delete[] date;

}
