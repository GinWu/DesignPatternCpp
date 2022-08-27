#include<iostream>
#include<string>
#include<list>

using namespace std;

class Employee {
public:
    Employee(string name, string dept, int salary): _name(name), _dept(dept), _salary(salary) {
    
    }

    void add(Employee* employee) {
        _subordinates.emplace_back(employee);
    }

    void remove(Employee* employee) {
        _subordinates.remove(employee);
    }

    list<Employee*> getSubordinates() {
        return _subordinates;
    }

    string toString() {
        return "Employee: [ Name: " + _name + \
        ", dept: " + _dept + ", salary: " + to_string(_salary) + " ]";
    }
    
    ~Employee() {
        for(auto iter = _subordinates.begin(); iter != _subordinates.end(); ++iter) {
            delete (*iter);
            *iter = nullptr;
        }
        _subordinates.clear();
    }
private:
    string _name;
    string _dept;
    int _salary;
    list<Employee*> _subordinates;
};


int main() {
    Employee* ceo = new Employee("Thomas", "ceo", 100000);
    Employee* cto = new Employee("Jenny", "cto", 50000);
    Employee* coo = new Employee("Marine", "coo", 50000);
    
    Employee* e1 = new Employee("Mary", "develop", 20000);
    Employee* e2 = new Employee("Gin", "develop", 25000);
    Employee* e3 = new Employee("Mike", "develop", 22000);
    Employee* e4 = new Employee("Tom", "DB", 30000);
    Employee* e5 = new Employee("Michael", "pm", 18000);
    Employee* e6 = new Employee("Lee", "operation", 28000);
    Employee* e7 = new Employee("Philip", "sales", 28000);

    ceo->add(cto);
    ceo->add(coo);

    cto->add(e1);
    cto->add(e2);
    cto->add(e3);
    cto->add(e5);

    coo->add(e4);
    coo->add(e6);
    coo->add(e7);

    cout << ceo->toString() << endl;
    for (auto headEmployee: ceo->getSubordinates()) {
        cout << headEmployee->toString() << endl;
        for (auto employee: headEmployee->getSubordinates()) {
            cout << employee->toString() << endl;
        }
    }
    system("pause");

    return 0;
}