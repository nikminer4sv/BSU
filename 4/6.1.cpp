#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string FirstName;
    string LastName;
    string Patronymic;
    int Age;
    int Course;
    string Gender;
    int Progress;

public:

    void ManualInitialization() {

        cout << "Введите имя: ";
        cin >> this->FirstName;

        cout << "Введите фамилию: ";
        cin >> this->LastName;

        cout << "Введите отчество: ";
        cin >> this->Patronymic;

        cout << "Введите возраст: ";
        cin >> this->Age;

        cout << "Введите курс: ";
        cin >> this->Course;

        cout << "Выберите пол:\n1. Мужской\n2. Женский\n";
        int temp;
        cin >> temp;

        if (temp == 1)
            this->Gender = "Мужской";
        else if (temp == 2)
            this->Gender = "Женский";


        cout << "Введите успеваемость: ";
        cin >> this->Progress;        

    }

    Student() {

       ManualInitialization();

    }

    Student(string FirstName, string LastName, string Patronymic, 
            int Age, int Course, string Gender, int Progress) {

        this->FirstName = FirstName;
        this->LastName = LastName;
        this->Patronymic = Patronymic;
        this->Age = Age;
        this->Course = Course;
        this->Gender = Gender;
        this->Progress = Progress;

    }

    string *GetInfo() {

        string *Array = new string[7];

        Array[0] = FirstName;
        Array[1] = LastName; 
        Array[2] = Patronymic;
        Array[3] = to_string(Age);
        Array[4] = to_string(Course);
        Array[5] = Gender;  
        Array[6] = to_string(Progress);

        return Array;

    }

};

class Students {
private:
    vector<Student> StudentsData;

public: 
    
    Students(int NumberOfStudents) {

        for (int i = 0; i < NumberOfStudents; i++) {

            Student TempStudent;
            StudentsData.push_back(TempStudent);

        }

    }

    Student GetStudent(int Index) {

        return StudentsData.at(Index);

    }

    //Определить количество студентов мужского пола на n курсе.
    int Condition(int n) {

        int Counter = 0;

        for (int i = 0; i < StudentsData.size(); i++) {
            if (stoi(StudentsData[i].GetInfo()[4]) == n && StudentsData[i].GetInfo()[5] == "Мужской")
                Counter += 1;
        }

        return Counter;

    }

};

int main() {

    int NumberOfStudents;

    cout << " Введите количество студентов: ";
    cin >> NumberOfStudents;

    int Course;
    cin >> Course;
    
    Students StudentsArray(NumberOfStudents);

    cout << StudentsArray.Condition(Course);

}
