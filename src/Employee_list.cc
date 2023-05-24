#include <Employee/Employee.h>
#include <cstdio>
#include <string>
#include <stdexcept>
#include <iostream>
#include <utility>

using namespace std;
using namespace Job;

int EmployeeList::get_size() const
{
	return _size;
}

EmployeeList::EmployeeList() : _employee(nullptr), _size(0) {}

EmployeeList::EmployeeList(const EmployeeList& other) : _employee(new Employee* [other._size]), _size(other._size)
{
	for (int i = 0; i < _size; ++i)
	{
		_employee[i] = new Employee(*other._employee[i]);
	}
}

EmployeeList::~EmployeeList()
{
	for (int i = 0; i < _size; i++)
	{
		delete _employee[i];
	}
	delete[] _employee;
	_employee = nullptr;
	_size = 0;
}

int EmployeeList::insert(Employee* employee, const int index)
{
	if (index < 0 || index - _size >= 1)
		throw runtime_error("Index out of range");

	auto _emp = new Employee * [_size + 1];
	for (int i = 0; i < _size; i++)
		_emp[i] = _employee[i];
	delete[] _employee;
	for (int i = _size; i > index; i--)
		_emp[i] = _emp[i - 1];
	_emp[index] = employee;
	_employee = _emp;
	_size++;
	return index;
}

void EmployeeList::remove(const int index)
{
	if (_size == 0 || index >= _size || index < 0)
		throw runtime_error("Index out of range");
	auto _emp = new Employee * [_size - 1];
	for (int i = 0; i < index; i++)
		_emp[i] = _employee[i];
	delete _employee[index];
	_size--;
	for (int i = index; i < _size; i++)
		_emp[i] = _employee[i + 1];
	delete[] _employee;
	_employee = _emp;
}

EmployeeList& EmployeeList::operator=(EmployeeList other)
{
	swap(other);
	return *this;
}

void EmployeeList::swap(EmployeeList& other)
{
	std::swap(_employee, other._employee);
	std::swap(_size, other._size);
}

Employee* EmployeeList::operator[](const int index) const
{
	if (index < 0 || _size < index)
		throw runtime_error("Invalid indyex");
	return _employee[index];
}

double EmployeeList::index_of_max_salary() const
{
	if (_size == 0)
		throw runtime_error("Size arr = 0");
	int rez = -1;
	double max_Salary = _employee[0]->salary();
	for (int i = 0; i < _size; i++)
	{
		const double Salary = _employee[i]->salary();
		if ((rez == -1) || (max_Salary < Salary))
		{
			rez = i;
			max_Salary = Salary;
		}
	}
	return rez;
}