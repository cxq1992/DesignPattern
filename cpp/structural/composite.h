#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <string>
#include <memory>
#include <vector>

namespace designpattern {
namespace structual {
class Employee
{
public:
    virtual std::string GetName() = 0;

    virtual void SetSalary(float salary) = 0;

    virtual float GetSalary() = 0;
};

class Developer : public Employee
{
public:
    Developer(const std::string& name, float salary)
        : _name(name), _salary(salary)
    {}

    std::string GetName() override
    {
        return _name;
    }

    void SetSalary(float salary) override
    {
        _salary = salary;
    }

    float GetSalary() override
    {
        return _salary;
    }
private:
    std::string _name;
    float _salary;
};

class Designer : public Employee
{
public:
    Designer(const std::string& name, float salary)
        : _name(name), _salary(salary)
    {}
    void SetSalary(float salary) override
    {
        _salary = salary;
    }

    float GetSalary() override
    {
        return _salary;
    }
private:
    std::string _name;
    float _salary;
};

class Organization
{
public:
    explicit Organization(size_t size)
        : _size(size)
    {}

    bool AddMemeber(std::shared_ptr<Employee> employee)
    {
        if (_employees.size() >= _size)
        {
            return false;
        }
        _employees.push_back(employee);
        return true;
    }

    size_t GetEmployeeSize()
    {
        return _size;
    }

    float GetTotalSalary()
    {
        float total = 0;
        for (auto employee : _employees)
        {
            total += employee->GetSalary();
        }
        return total;
    }
private:
    size_t _size;
    std::vector<std::shared_ptr<Employee>> _employees;
};
}
}
#endif // COMPOSITE_H

