
#include<iostream>
#include<iomanip>
#include<string>
#include <set>

using namespace std;

const char n[10]{ "xxxxx" };


//身份类
class Identify
{
public:
    Identify(const char* n = "unknwon", long long number = 1111111111111) :number_(number)
    {
        int i;

        for (i = 0; i < 10 && n[i] != '\0'; i++)
        {
            name_[i] = *(n + i);
        }

        cout << "identify consturcter" << endl;
    }

    Identify(Identify& i)//复制构造函数 
    {
        number_ = i.number_;

        int j;
        for (j = 0; j < 10 && *(i.name_) != '\0'; j++)
        {
            *(name_ + j) = *(i.name_ + j);
        }

        cout << "call out the copy constructer" << endl;
    }

    ~Identify()  //析构函数
    {
        cout << "identify disturcter" << endl;
    }

    void set_number(long long number);
    void show_number();

    void set_name(const char* n);
    void show_name();

private:
    long long number_ = 1111111111111;
    char name_[10] = "xxxxx";

};



//身份证号存入函数
void Identify::set_number(long long number)
{
    number_ = number;
    cout << "set_number constructer" << endl;
}


//身份证号打印函数
void Identify::show_number()
{
    cout << "number:" << number_ << endl;
}


//姓名存入函数
void Identify::set_name(const char* n)
{
    int i;

    for (i = 0; i < 10 && n[i] != '\0'; n++)
    {
        name_[i] = n[i];
    }
}


//姓名打印函数
void Identify::show_name()
{
    cout << "name:" << name_ << endl;
}



//学生类
class Student
{
public:
    Student(Identify& id, string school = "unknown")
    {
        cout << "student constructer" << endl;
    }

    Student(Student& s)
    {
        id_ = s.id_;
        school_ = s.school_;
        cout << "call out the copy constructer" << endl;
    }

    ~Student()
    {
        cout << "student distructer" << endl;
    }


    void set_id(const char* name, long long number);
    void show_id();

    void set_school(std::string school);
    void show_school();

private:
    Identify id_;
    std::string school_{ "unknown" };
};


Student  MakeStudent(const char* name = "unknown", long long number = 11111111111111, std::string school = "unknown") 
{

    cout << "calling the MakeStudent constructer" << endl;
    

    Identify id(name, number);


    Student s(id, school);


    return (s);
}


//学生身份存入函数
void Student::set_id(const char* name = "unknown", long long number = 11111111111111)
{
    cout << "calling the student_id-setting constructer" << endl;

    id_.set_number(number);

    id_.set_name(name);
}


//学生身份打印函数
void Student::show_id()
{
    cout << "calling the student_id-showing constructer" << endl;

    id_.show_number();
    id_.show_name();
}

//学生学校存入函数
void Student::set_school(std::string school = "unknown")
{
    cout << "calling the student_school setting constructer" << endl;

    school_ = school;
}

//学生学校打印函数
void Student::show_school()
{
    cout << "calling the student_school showing constructer" << endl;
    cout << "school:" << school_;
}



int main()
{
    //Identify类函数测试
    Identify id1("unknown", 11222222222222);

    id1.set_name("小明");
    id1.set_number(440922222222222222);

    id1.show_name();
    id1.show_number();

    //Student类函数测试
    Student s1(id1, "unknown");

    s1.set_id();
    s1.set_school("中山大学");

    s1.show_id();
    s1.show_school();

    //MakeStudent函数测试
    Student s2(s1);
    
    s2 = MakeStudent("小红", 9999999999999, "阳光小学");

    return 0;
}
