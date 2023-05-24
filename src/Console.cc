#include <Employee/Employee.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace Job;

void menu()
{
	system("cls");
	std::cout << "" << endl;
	cout << " | 1 - Вставить элемент в список по указанному индексу                    |" << endl;
	cout << " | 2 - Удалить элемент из списка по указанному индексу                    |" << endl;
	cout << " | 3 - Вывести список на экран                                            |" << endl;
	cout << " | 4 - Поиск в списке первого сотрудника с максимальной заработной платой |" << endl;
	cout << " | 5 - Расчёт заработной платы                                            |" << endl;
	cout << " | 6 - Завершить программу                                                |\n" << endl;
}

void _insert(EmployeeList& e)
{
	int index;
	int type;
	std::string full_name;
	int day;
	int month;
	int year;
	int base_rated_for_1_month;
	int base_rated_for_1_hour;
	int percentage_individual_allowance;
	int number_of_hours_worked_last_month;

	std::cout << "Введите индекс: " << std::endl;

	do
	{
		std::cin >> index;
	} while (index - e.get_size() >= 1 || index < 0);
	cout << "Введите тип: (0 - Staff, 1 - Part) ";

	do
	{
		std::cin >> type;
	} while (type != 1 && type != 0);

	switch (type)
	{
	case 0: 
		std::cout << "Введите имя работника: " << std::endl;
		std::cin >> full_name;
		std::cout << "Введите день, месяц, год наёма на работу: " << std::endl;
		std::cin >> day;
		std::cin >> month;
		std::cin >> year;
		std::cout << "Введите базовую ставку за 1 месяц: " << std::endl;
		std::cin >> base_rated_for_1_month;
		e.insert(Employee::staff(full_name, day, month, year, base_rated_for_1_month), index);
		break;
	case 1: 
		std::cout << "Введите имя работника: " << std::endl;
		std::cin >> full_name;
		std::cout << "Введите день, месяц, год наёма на работу: " << std::endl;
		std::cin >> day;
		std::cin >> month;
		std::cin >> year;
		std::cout << "Введите базовую ставку за 1 час" << std::endl;
		std::cin >> base_rated_for_1_hour;
		std::cout << "Введите процент индивидуальной надбавки: " << std::endl;
		std::cin >> percentage_individual_allowance;
		std::cout << "Введите кол-во отработанных часов за последний месяц: " << std::endl;
		std::cin >> number_of_hours_worked_last_month;
		e.insert(Employee::part(full_name, day, month, year, base_rated_for_1_hour, percentage_individual_allowance, number_of_hours_worked_last_month), index);
		break;
	}
}

void _remove(EmployeeList& e)
{
	if (e.get_size() == 0)
	{
		std::cout << "Список пуст" << std::endl;
		return;
	}
	int index;
	std::cout << "Введите индекс, откуда хотите удалить элемент" << std::endl;
	do
	{
		std::cin >> index;
	} while (index - e.get_size() >= 1 || index < 0);
	e.remove(index);
}

void _print(const EmployeeList& emp)
{
	for (int i = 0; i < emp.get_size(); i++)
	{
		if (emp[i]->get_type() == 0)
		{
			std::cout << "Staff" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_month() << std::endl;
		}
		else
		{
			std::cout << "Part" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_hour() << " " << emp[i]->get_percentage_individual_allowance() << " " << emp[i]->get_number_of_hours_worked_last_month() << std::endl;
		}
	}
}

void _search(const EmployeeList& emp)
{
	if (emp.get_size() == 0)
		return;
	int i = emp.index_of_max_salary();
	if (emp[i]->get_type() == 0)
	{
		std::cout << "Staff" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_month() << std::endl;
	}
	else
	{
		std::cout << "Part" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_hour() << " " << emp[i]->get_percentage_individual_allowance() << " " << emp[i]->get_number_of_hours_worked_last_month() << std::endl;
	}
}

void _calculation(EmployeeList& emp)
{
	if (emp.get_size() == 0)
		return;
	int i;
	std::cout << "Введите индекс сотрудника: " << std::endl;
	do
	{
		std::cin >> i;
	} while (i - emp.get_size() >= 1 || i < 0);

	if (emp[i]->get_type() == 0)
	{
		std::cout << "Staff" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_month() << std::endl;
	}
	else
	{
		std::cout << "Part" << " " << emp[i]->get_full_name() << " " << emp[i]->get_hire_day() << " " << emp[i]->get_hire_month() << " " << emp[i]->get_hire_year() << " " << emp[i]->get_base_rate_for_1_hour() << " " << emp[i]->get_percentage_individual_allowance() << " " << emp[i]->get_number_of_hours_worked_last_month() << std::endl;
	}
	std::cout << "Зарплата: " << emp[i]->salary() << std::endl;
}