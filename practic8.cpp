// practic8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>

using namespace std;

enum class Type{type1, type2};

struct Person
{
    char fullName[100];
    Type type;
    union
    {
        struct 
        {
        char JobTitle[100];
        char Addres[100];
        int Num;

        } info;


    } Working;
};

int main()
{
    setlocale(LC_ALL, "ru");
    list<Person> List;
    list<Person> Working;

    Person person1;
    strcpy(person1.fullName, "Иванов Иван Иванович");
    person1.type = Type::type1;
    strcpy(person1.Working.info.JobTitle, "Инженер");
    person1.Working.info.Num = 123456;
    List.push_back(person1);

    Person person2;
    strcpy(person2.fullName, "Петров Петр Петрович");
    person2.type = Type::type1;
    strcpy(person2.Working.info.JobTitle, "Инженер");
    person2.Working.info.Num = 123456;
    List.push_back(person2);

    Person person3;
    strcpy(person3.fullName, "Петров Петр Петрович");
    strcpy(person2.Working.info.Addres, "Первомайская");
    person3.type = Type::type2;
    List.push_back(person3);
    
    for (const auto& person : List)
    {
        if (person.type == Type::type1)
        {
            cout << person.fullName << endl;
            cout << person.Working.info.JobTitle << endl;
            cout << person.Working.info.Num << endl;
            cout << endl;
        }
    }

    return 0;
}
