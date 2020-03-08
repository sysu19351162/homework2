
#include<iostream>
#include<iomanip>
#include<string>
#include <set>

using namespace std;

const char n[10]{ "xxxxx" };


//�����
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

    Identify(Identify& i)//���ƹ��캯�� 
    {
        number_ = i.number_;

        int j;
        for (j = 0; j < 10 && *(i.name_) != '\0'; j++)
        {
            *(name_ + j) = *(i.name_ + j);
        }

        cout << "call out the copy constructer" << endl;
    }

    ~Identify()  //��������
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



//���֤�Ŵ��뺯��
void Identify::set_number(long long number)
{
    number_ = number;
    cout << "set_number constructer" << endl;
}


//���֤�Ŵ�ӡ����
void Identify::show_number()
{
    cout << "number:" << number_ << endl;
}


//�������뺯��
void Identify::set_name(const char* n)
{
    int i;

    for (i = 0; i < 10 && n[i] != '\0'; n++)
    {
        name_[i] = n[i];
    }
}


//������ӡ����
void Identify::show_name()
{
    cout << "name:" << name_ << endl;
}



//ѧ����
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


//ѧ����ݴ��뺯��
void Student::set_id(const char* name = "unknown", long long number = 11111111111111)
{
    cout << "calling the student_id-setting constructer" << endl;

    id_.set_number(number);

    id_.set_name(name);
}


//ѧ����ݴ�ӡ����
void Student::show_id()
{
    cout << "calling the student_id-showing constructer" << endl;

    id_.show_number();
    id_.show_name();
}

//ѧ��ѧУ���뺯��
void Student::set_school(std::string school = "unknown")
{
    cout << "calling the student_school setting constructer" << endl;

    school_ = school;
}

//ѧ��ѧУ��ӡ����
void Student::show_school()
{
    cout << "calling the student_school showing constructer" << endl;
    cout << "school:" << school_;
}



int main()
{
    //Identify�ຯ������
    Identify id1("unknown", 11222222222222);

    id1.set_name("С��");
    id1.set_number(440922222222222222);

    id1.show_name();
    id1.show_number();

    //Student�ຯ������
    Student s1(id1, "unknown");

    s1.set_id();
    s1.set_school("��ɽ��ѧ");

    s1.show_id();
    s1.show_school();

    //MakeStudent��������
    Student s2(s1);
    
    s2 = MakeStudent("С��", 9999999999999, "����Сѧ");

    return 0;
}
