#include <iostream>
#include <Employee/Employee_functions.h>
#include <Employee/Employee.h>
#include <Windows.h>

using namespace std;
using namespace Job;

int main()
{
	setlocale(LC_ALL, "ru");
	EmployeeList emp;
	int input = 0;
	while (true)
	{
		menu();
		std::cin >> input;
		if (input == 6) break;
		switch (input)
		{
		case 1:
			_insert(emp);
			system("pause");
			break;
		case 2:
			_remove(emp);
			system("pause");
			break;
		case 3:
			_print(emp);
			system("pause");
			break;
		case 4:
			_search(emp);
			system("pause");
			break;
		case 5:
			_calculation(emp);
			system("pause");
			break;
		}
	}
	return 0;
}