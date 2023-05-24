#include <gtest/gtest.h>
#include <Employee/Employee.h>

using namespace Job;

TEST(EmployeeListTests, Insert)
{
	EmployeeList emp;
	emp.insert(Employee::staff("Vladimir Vladimirovich", 23 , 4, 2021, 30000), 0);
	emp.insert(Employee::part("Ivan Ivanovich", 15, 7, 2018, 800, 3, 23), 1);
	emp.insert(Employee::staff("Aleksey Alekseevich", 6, 11, 2020, 40000), 2);
	emp.insert(Employee::staff("Dmitriy Dmitrievich", 3, 1, 2022, 3500), 3);
	EXPECT_EQ(emp.get_size(), 4);
	EXPECT_ANY_THROW(emp.insert(Employee::staff("Renat Renatovich", 1, 2, 2020, 37000), -12));
	EXPECT_ANY_THROW(emp.insert(Employee::staff("Renat Renatovich", 1, 2, 2020, 37000), -1));
}

TEST(EmployeeListTests, Remove)
{
	EmployeeList emp;
	emp.insert(Employee::staff("Vladimir Vladimirovich", 23, 4, 2021, 30000), 0);
	emp.insert(Employee::part("Ivan Ivanovich", 15, 7, 2018, 800, 3, 23), 1);
	emp.insert(Employee::staff("Aleksey Alekseevich", 6, 11, 2020, 40000), 2);
	emp.insert(Employee::staff("Dmitriy Dmitrievich", 3, 1, 2022, 35000), 3);
	emp.remove(2);
	EXPECT_EQ(emp.get_size(), 3);
	emp.remove(2);
	EXPECT_EQ(emp.get_size(), 2);
	EXPECT_ANY_THROW(emp.remove(17));
	EXPECT_ANY_THROW(emp.remove(-4));
}

TEST(EmployeeListTests, IndexOfMaxSalary)
{
	EmployeeList emp;
	emp.insert(Employee::staff("Vladimir Vladimirovich", 23, 4, 2021, 30000), 0);
	emp.insert(Employee::part("Ivan Ivanovich", 15, 7, 2018, 800, 3, 23), 1);
	emp.insert(Employee::staff("Aleksey Alekseevich", 6, 11, 2020, 40000), 2);
	emp.insert(Employee::staff("Dmitriy Dmitrievich", 3, 1, 2022, 35000), 3);
	EXPECT_EQ(emp.index_of_max_salary(), 2);
}
