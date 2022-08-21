#include <iostream>
#include <string>
#include <list>
using namespace std;

class Employee {
public:
    Employee(string& name, string& dept, int& salary) {
        _name = name;
        _dept = dept;
        _salary = salary;
    }
    void add(Employee* e) {
        subordinates.emplace_back(e);
    }

    void remove(Employee* e) {
        subordinates.remove(e);
        delete e;
        e = nullptr;
    }

    list<Employee*> getSubordinates() {
        return subordinates;
    }

    string toString() {
        string res = "Employee: [Name: " + _name + ", dept: " + _dept + \
            ", salary: " + to_string(_salary) + "]";

        return res;
    }


private:
    string _name;
    string _dept;
    int _salary;
    list<Employee*> subordinates;
};


int main() {
    string name1 = "Mary";
    string dept1 = "Dev";
    int salary1 = 20000;
    string name2 = "Jack";
    string dept2 = "Marketing";
    int salary2 = 30000;
    Employee eGroup(name1, dept1, salary1);
    Employee* e1 = new Employee(name1, dept1, salary1);
    Employee* e2 = new Employee(name2, dept2, salary2);
    eGroup.add(e1);
    eGroup.add(e2);

    list<Employee*> eList = eGroup.getSubordinates();
    for (auto& e: eList) {
        cout << e->toString() << endl;
    }
    cout << eGroup.toString() << endl;
    // cout << e2->toString() << endl;
    system("pause");
    return 0;
}