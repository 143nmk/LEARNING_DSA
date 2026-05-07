#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int marks;

    Student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }
    bool operator<(const Student &s) const
    {
        return this->marks > s.marks;
    }
};

int main()
{
    priority_queue<Student> pq;
    pq.push(Student("Maha", 95));
    pq.push(Student("Aman", 90));
    pq.push(Student("Rohit", 80));
    while (!pq.empty())
    {
        Student s = pq.top();
        cout << s.name << " " << s.marks << endl;
        pq.pop();
    }
    return 0;
}