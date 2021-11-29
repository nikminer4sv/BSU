#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

class Date {
private:
    unsigned short RawDate;

public:

private:
    int* ConvertToRaw(int Number, int Size) {

        int *Result = new int[Size];
        int Index = 0;

        while (Number > 0) {

            if (Number % 2 == 0)
                Result[Index] = 0;
            else
                Result[Index] = 1;

            Index += 1;
            Number  = int(Number / 2);

        }

        return Result;

    }

    int* MergeArrays(int* RawDay, int RawDaySize, 
                     int* RawMonth, int RawMonthSize, 
                     int* RawYear, int RawYearSize) {

        int* ResultingArray = new int[RawDaySize + RawMonthSize + RawYearSize];
        int Index = 0;

        for (int i = 0, Temp = Index; Index < Temp + RawDaySize; i++, Index++)
            ResultingArray[Index] = RawDay[i];

        for (int i = 0, Temp = Index; Index < Temp + RawMonthSize; i++, Index++)
            ResultingArray[Index] = RawMonth[i];

        for (int i = 0, Temp = Index; Index < Temp + RawYearSize; i++, Index++)
            ResultingArray[Index] = RawYear[i];

        return ResultingArray;

    }

    void ConvertToNumber(unsigned short &RawDate, int* RawDateArray) {

        for (int i = 0; i < 15; i++) {

            if (RawDateArray[i] == 1)
                RawDate = (RawDate | 1) << 1;
            else
                RawDate = RawDate << 1;

        }

        if (RawDateArray[15] == 1)
            RawDate = (RawDate | 1);

    }

    int ConvertToDecimal(int* ArrayOfBites, int Size) {

        int Result = 0;

        for (int i = Size - 1, Temp = 0; i > -1; i--, Temp++) {

            Result += ArrayOfBites[i] * pow(2, Temp);

        }

        return Result;

    }

public:

    Date() {

        int Day, Month, Year;

        time_t Now = time(0);

        tm *ltm = localtime(&Now);

        Day = ltm->tm_mday;
        Month = 1 + ltm->tm_mon;
        Year = ltm->tm_year - 100;

        Initialization(Day, Month, Year);

    }

    Date(int Day, int Month, int Year) {

        Initialization(Day, Month, Year);

    }

    void Initialization(int Day, int Month, int Year) {

        if (Day < 1 || Day > 31 || 
            Month < 1 || Month > 12 || 
            Year < 0 || Year > 99) {

            cout << "Invalid Date";
            exit(1);

        }

        int* RawDay;
        int* RawMonth;
        int* RawYear;

        RawDay = ConvertToRaw(Day,5);
        RawMonth = ConvertToRaw(Month,4);
        RawYear = ConvertToRaw(Year, 7);

        int *RawDateArray = MergeArrays(RawDay, 5, RawMonth, 4, RawYear, 7);

        ConvertToNumber(RawDate, RawDateArray);

    }

    int GetDay() {

        int* RawDayArray = new int[5];

        for (int i = 0; i < 5; i++) {
            RawDayArray[i] = (RawDate >> (i + 11)) & 1;
        }

        return ConvertToDecimal(RawDayArray, 5);

    }

    int GetMonth() {

        int* RawMonthArray = new int[4];

        for (int i = 0; i < 4; i++) {
            RawMonthArray[i] = (RawDate >> (i + 7)) & 1;
        }
        
        return ConvertToDecimal(RawMonthArray, 4);

    }

    int GetYear() {

        int* RawYearArray = new int[7];

        for (int i = 0; i < 7; i++) {
            RawYearArray[i] = (RawDate >> (i)) & 1;
        }

        return ConvertToDecimal(RawYearArray, 7);

    }

    unsigned short GetRawDate() { return RawDate; }

    Date operator+ (Date other) {
        
        int Day, Month, Year;

        Day = this->GetDay();
        Month = this->GetMonth();
        Year = this->GetYear();

        Day += other.GetDay();

        if (Day > 31) {
            Month += 1;
            Day -= 31;
        }

        Month += other.GetMonth();

        if (Month > 12) {
            Year += 1;
            Month -= 12;
        }

        Year += other.GetYear();

        return Date(Day, Month, Year);

    }

    friend ostream& operator<< (ostream &out, Date Date) {
    
        if (Date.GetDay() < 10)
            out << "0" << Date.GetDay();
        else 
            out << Date.GetDay();

        out << ".";

        if  (Date.GetMonth() < 10)
            out << "0" << Date.GetMonth();
        else 
            out << Date.GetMonth();
 
        out << ".";

        if  (Date.GetYear() < 10)
            out << "200" << Date.GetYear();
        else 
            out << "20" << Date.GetYear();

        return out;

    }

};

bool DateComporator(Date &a, Date &b){

    if (a.GetYear() == b.GetYear()) {
        if (a.GetMonth() == b.GetMonth()) {
            if (a.GetDay() == b.GetDay()) {
                return true;
            } else {
                return (a.GetDay() < b.GetDay()); 
            }
        } else {
            return (a.GetMonth() < b.GetMonth()); 
        }
    } else {
        return (a.GetYear() < b.GetYear()); 
    }

}

int GetRandomInt(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

bool SortingComporator(Date& a, Date& b) {

    if (a.GetYear() == b.GetYear()) {

        if (a.GetMonth() == b.GetMonth()) {

            if (a.GetDay() == b.GetDay()) {

                return true;

            } else {

                return (a.GetDay() < b.GetDay()); 

            }

        } else {

            return (a.GetMonth() < b.GetMonth()); 

        }

    } else {

        return (a.GetYear() < b.GetYear()); 

    }

}

void CustomSort(Date *Array, int Size) {

    for (int i = 0; i < Size; i++) {

        for (int j = 0; j < Size; j++) {

            if (SortingComporator(Array[i], Array[j]))
                swap(Array[i], Array[j]);

        }

    }

}

int main() {

    int n;
    cin >> n;
    Date *Array = new Date[n];

    // RANDOM INITIALIZATION START
    for (int i = 0; i < n; i++) {

        Array[i] = Date(GetRandomInt(1,31), GetRandomInt(1,12), GetRandomInt(0,99));
        cout << endl;
        cout << "[" << Array[i] << "]" << " - ";
        cout << "[" << Array[i].GetRawDate() << "]";

    }
    // RANDOM INITIALIZATON END

    // REPEATING ELEMENTS START
    cout << endl << endl << "Repeating Elements" << endl;

    for (int i = 0; i < n; i++) {

        int Temp = 0;

        for (int j = i + 1; j < n; j++) {

            if (Array[i].GetRawDate() == Array[j].GetRawDate())
                cout << Array[i] << endl;

        }

    }
    // REPEATING ELEMENTS END

    // SORTING START
    sort(Array, Array + n, DateComporator);
    CustomSort(Array, n);

    cout << endl << "Sorted Elements" << endl;

    for (int i = 0; i < n; i++) { 
        cout << Array[i] << endl;
    }
    // SORTING */

}
