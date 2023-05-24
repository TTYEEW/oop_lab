#pragma once
#include <string>

namespace Job {

	enum TypeEmployee { Staff, Part };

	class Employee
	{
	private:
		TypeEmployee _type;
		std::string _full_name;
		int _hire_day;
		int _hire_month;
		int _hire_year;
		// only for staff
		int _base_rate_for_1_month;
		// only for part
		int _base_rate_for_1_hour;
		int _percentage_individual_allowance;
		int _number_of_hours_worked_last_month;
		Employee(TypeEmployee type, std::string full_name, int hire_day, int hire_month, int hire_year, int base_rate_for_1_month);
		Employee(TypeEmployee type, std::string full_name, int hire_day, int hire_month, int hire_year, int base_rate_for_1_hour, int percentage_individual_allowance, int number_of_hours_worked_last_month);
	public:
		Employee();
		static Employee* staff(std::string full_name, int hire_day, int hire_month, int hire_year, int base_rate_for_1_month);
		static Employee* part(std::string full_name, int hire_day, int hire_month, int hire_year, int base_rate_for_1_hour, int percentage_individual_allowance, int number_of_hours_worked_last_month);

		const std::string& get_full_name() const;
		int get_hire_day() const;
		int get_hire_month() const;
		int get_hire_year() const;
		int get_base_rate_for_1_month() const;
		int get_base_rate_for_1_hour() const;
		int get_percentage_individual_allowance() const;
		int get_number_of_hours_worked_last_month() const;
		TypeEmployee get_type() const;
		double salary() const;

	};

	bool operator==(const Employee& rhs, const Employee& lhs);
	bool operator!=(const Employee& rhs, const Employee& lhs);

	class EmployeeList
	{
		Employee** _employee;
		int _size;

	public:
		EmployeeList();
		EmployeeList(const EmployeeList& other);
		~EmployeeList();
		int get_size() const;
		double index_of_max_salary() const;
		void swap(EmployeeList& other);
		int insert(Employee* employee,const int index);
		void remove(const int index);
		EmployeeList& operator=(EmployeeList other);
		Employee* operator[](const int index) const;
	};
}
