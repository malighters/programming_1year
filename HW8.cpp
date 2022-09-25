#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student{
    string name;
    string surname;
    int age;

    Student(string name, string surname, int age){
        this->name = name;
        this->surname = surname;
        this->age = age;
    }
    Student(){
        name = "None";
        surname = "";
        age = 17;
    }
};

struct Group{
public:
    Group(){
        name = "Unknown";
        year = 1;
    };
    Group(string name, int year){
        this->name = name;
        this->year = year;
    };

    void AddStudent(Student student){
        group.push_back(student);
        cout << "Student " << student.name << " successfully added"<<endl;

    };

    void DeleteStudent(){
        if(group.size() == 0)
            cout << "The group doesn't have students"<<endl;
        else
            group.pop_back();
    };

    void FindStudent(){
        Student max = {"Unknown", "", 17};
        if(group.size() != 0){
            for(int i = 0; i < group.size(); i++){
                if(max.surname.size() < group[i].surname.size())
                    max = group[i];
                }
            cout << max.surname << endl;
        }
        else{
            cout << "The group doesn't have students" << endl;
        }

    };


private:
    string name;
    int year;
    vector<Student> group;
};

int main() {
    Group a1;
    a1.FindStudent();
    a1.DeleteStudent();

    Student k = {"MC", "Bird", 25}, f = {"AKA", "Tiger", 21};
    a1.AddStudent(k);
    a1.AddStudent(f);

    a1.FindStudent();
    a1.DeleteStudent();
    a1.FindStudent();


    return 0;
}
