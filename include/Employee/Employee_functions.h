#pragma once
#include <Employee/Employee.h>

using namespace Job;

void menu();

void _insert(EmployeeList& e);

void _remove(EmployeeList& e);

void _print(const EmployeeList& emp);

void _search(const EmployeeList& emp);

void _calculation(EmployeeList& emp);
