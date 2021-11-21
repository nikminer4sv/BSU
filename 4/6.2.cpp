#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

class Data {
private:
    unsigned short RawData;

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

    int* ConvertToRaw(int Number, int Size) {

        int *Result = new int[Size];
        int Index = 0;

        while (Number > 0) {

            if (Number % 2 == 0) {
                Result[Index] = 0;
            } else {
                Result[Index] = 1;
            }

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



};

int GetRandomInt(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

int main() {

    int n;
    cin >> n;

    Data *Array = new Data[n];

    for (int i = 0; i < n; i++) {

        Array[i] = Data(GetRandomInt(1,31), GetRandomInt(1,12), GetRandomInt(0,99));
        cout << endl;
        cout << Array[i];

    }

}
