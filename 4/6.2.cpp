#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Data {
private:
    unsigned short RawData;

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

    void ConvertToNumber(unsigned short &RawData, int* RawDataArray) {

        for (int i = 0; i < 15; i++) {

            if (RawDataArray[i] == 1)
                RawData = (RawData | 1) << 1;
            else
                RawData = RawData << 1;

        }

        if (RawDataArray[15] == 1)
            RawData = (RawData | 1);

    }

    int ConvertToDecimal(int* ArrayOfBites, int Size) {

        int Result = 0;

        for (int i = Size - 1, Temp = 0; i > -1; i--, Temp++) {

            Result += ArrayOfBites[i] * pow(2, Temp);

        }

        return Result;

    }

    friend ostream& operator<< (ostream &out, Data &data) {
    
        if (data.GetDay() < 10)
            out << "0" << data.GetDay();
        else 
            out << data.GetDay();

        out << ".";

        if  (data.GetMonth() < 10)
            out << "0" << data.GetMonth();
        else 
            out << data.GetMonth();
 
        out << ".";

        if  (data.GetYear() < 10)
            out << "200" << data.GetYear();
        else 
            out << "20" << data.GetYear();

        return out;

    }

public:

    Data() {}

    Data(int Day, int Month, int Year) {

        
        if (Day < 1 || Day > 31 || 
            Month < 1 || Month > 12 || 
            Year < 0 || Year > 99) {

            cout << "Invalid data";
            exit(1);

        }

        int* RawDay;
        int* RawMonth;
        int* RawYear;

        RawDay = ConvertToRaw(Day,5);
        RawMonth = ConvertToRaw(Month,4);
        RawYear = ConvertToRaw(Year, 7);

        int *RawDataArray = MergeArrays(RawDay, 5, RawMonth, 4, RawYear, 7);

        ConvertToNumber(RawData, RawDataArray);

    }

    int GetDay() {

        int* RawDayArray = new int[5];

        for (int i = 0; i < 5; i++) {
            RawDayArray[i] = (RawData >> (i + 11)) & 1;
        }

        return ConvertToDecimal(RawDayArray, 5);

    }

    int GetMonth() {

        int* RawMonthArray = new int[4];

        for (int i = 0; i < 4; i++) {
            RawMonthArray[i] = (RawData >> (i + 7)) & 1;
        }
        
        return ConvertToDecimal(RawMonthArray, 4);

    }

    int GetYear() {

        int* RawYearArray = new int[7];

        for (int i = 0; i < 7; i++) {
            RawYearArray[i] = (RawData >> (i)) & 1;
        }

        return ConvertToDecimal(RawYearArray, 7);

    }

    short int GetRawData() { return RawData; }



};

bool DataComporator(Data &a, Data &b){

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

bool SortingComporator(Data& a, Data& b) {

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

void CustomSort(Data *Array, int Size) {

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
    Data *Array = new Data[n];

    // RANDOM INITIALIZATION START
    for (int i = 0; i < n; i++) {

        Array[i] = Data(GetRandomInt(1,31), GetRandomInt(1,12), GetRandomInt(0,99));
        cout << endl;
        cout << Array[i];
        cout << Array[i].GetRawData();

    }
    // RANDOM INITIALIZATON END

    // REPEATING ELEMENTS START
    cout << endl << endl << "Repeating Elements" << endl;

    for (int i = 0; i < n; i++) {

        int Temp = 0;

        for (int j = i + 1; j < n; j++) {

            if (Array[i].GetRawData() == Array[j].GetRawData())
                cout << Array[i] << endl;

        }

    }
    // REPEATING ELEMENTS END

    // SORTING START
    //sort(Array, Array + n, DataComporator);
    CustomSort(Array, n);

    cout << endl << "Sorted Elements" << endl;

    for (int i = 0; i < n; i++) { 
        cout << Array[i] << endl;
    }
    // SORTING END

}
