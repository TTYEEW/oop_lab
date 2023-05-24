#include <Employee/Employee.h>
#include <cstdio>
#include <string>
#include <stdexcept>

using namespace std;
using namespace Job;

Employee::Employee()
{
	_type = Staff;
	_full_name = "default";
	_hire_day = 1;
	_hire_month = 1;
	_hire_year = 1970;
	_base_rate_for_1_month = 0;
}

Employee::Employee(const TypeEmployee type, const std::string full_name, const int hire_day, const int hire_month, const int hire_year, const int base_rate_for_1_month) 
{
	_type = type;
	_full_name = full_name;
	_hire_day = hire_day;
	_hire_month = hire_month;
	_hire_year = hire_year;
	_base_rate_for_1_month = base_rate_for_1_month;
}

Employee::Employee(const TypeEmployee type, const std::string full_name, const int hire_day, const int hire_month, const int hire_year, const int base_rate_for_1_hour, const int percentage_individual_allowance, const int number_of_hours_worked_last_month)
{
	_type = type;
	_full_name = full_name;
	_hire_day = hire_day;
	_hire_month = hire_month;
	_hire_year = hire_year;
	_base_rate_for_1_hour = base_rate_for_1_hour;
	_percentage_individual_allowance = percentage_individual_allowance;
	_number_of_hours_worked_last_month = number_of_hours_worked_last_month;
}

Employee* Employee::staff(const std::string full_name, const int hire_day, const int hire_month, const int hire_year, const int base_rate_for_1_month)
{
	return new Employee(TypeEmployee::Staff, full_name, hire_day, hire_month, hire_year, base_rate_for_1_month);
}

Employee* Employee::part(const std::string full_name, const int hire_day, const int hire_month, const int hire_year, const int base_rate_for_1_hour, const int percentage_individual_allowance, const int number_of_hours_worked_last_month)
{
	return new Employee(TypeEmployee::Part, full_name, hire_day, hire_month, hire_year, base_rate_for_1_hour, percentage_individual_allowance, number_of_hours_worked_last_month);
}

int Employee::get_hire_day() const
{
	return _hire_day;
}

int Employee::get_hire_month() const
{
	return _hire_month;
}

int Employee::get_hire_year() const
{
	return _hire_year;
}

const string& Employee::get_full_name() const
{
	return _full_name;
}

int Employee::get_base_rate_for_1_month() const
{
	if (_type == Staff)
		return _base_rate_for_1_month;
	throw runtime_error("no base_rate_for_1_month");
}

int Employee::get_base_rate_for_1_hour() const
{
	if (_type == Part)
		return _base_rate_for_1_hour;
	throw runtime_error("no base_rate_for_1_hour");
}

int Employee::get_percentage_individual_allowance() const
{
	if (_type == Part)
		return _percentage_individual_allowance;
	throw runtime_error("no percentage_individual_allowance");
}

int Employee::get_number_of_hours_worked_last_month() const
{
	if (_type == Part)
		return _number_of_hours_worked_last_month;
	throw runtime_error("no number_of_hours_worked_last_month");
}

TypeEmployee Employee::get_type() const
{
	return _type;
}

double Employee::salary() const
{
	switch (_type)
	{
	case Staff:
		return _base_rate_for_1_month + ((2023 - _hire_year) * 0.005) * _base_rate_for_1_month;
	case Part:
		return ((1 + (_percentage_individual_allowance * 0.01)) * _base_rate_for_1_hour) * _number_of_hours_worked_last_month;
	default:
		throw runtime_error("Invalid type");
	}
}

bool Job::operator==(const Employee& rhs, const Employee& lhs)
{
	return rhs.get_type() == lhs.get_type() && rhs.get_full_name() == lhs.get_full_name() && rhs.get_hire_day() == lhs.get_hire_day() && rhs.get_hire_month() == lhs.get_hire_month() && rhs.get_hire_year() == lhs.get_hire_year() && rhs.get_base_rate_for_1_month() == lhs.get_base_rate_for_1_month();
}

bool Job::operator!=(const Employee& rhs, const Employee& lhs)
{
	return !(rhs == lhs);
}