#include <iostream>

struct Student
{
    int fn;
    char name[100];
    int course;
    int group;
};

Student getInfo();
Student getInfo()
{
    Student s;
    std::cout<<"Input name:";
    std::cin.get(s.name, 100);
    std::cout<<"Input fn:";
    std::cin>>s.fn;
    std::cout<<"Input course and group:";
    std::cin>>s.course>> s.group;
    return s;
}
int main()
{
    Student s1;
    Student s2;
    Student s3;
    Student s4;
    s1 = getInfo();
    s2 = getInfo();
    s3 = getInfo();
    s4 = getInfo();
    return 0;
}