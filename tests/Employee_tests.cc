#include <gtest/gtest.h>
#include <Employee/Employee.h>

using namespace Job;

TEST(EmployeeTests, TestFunctions)
{
	const auto worker1 = Employee::staff("Sergey Sergeevich", 23, 5, 2020, 34000);
	const auto worker2 = Employee::part("Aleksandr Aleksandrowich", 4, 3, 2021, 500, 2, 56);
	const auto worker3 = Employee::part("Konstantin Konstantinovich", 15, 12, 2018, 750, 3, 47);
	const auto worker4 = Employee::staff("Rishat Rishatovich", 7, 7, 2022, 34000);

	EXPECT_EQ(worker1->salary(), 34510);
	EXPECT_EQ(worker2->get_full_name(), "Aleksandr Aleksandrowich");
	EXPECT_EQ(worker3->get_type(), TypeEmployee::Part);
	EXPECT_EQ(worker4->get_hire_year(), 2022);
	EXPECT_ANY_THROW(worker1->get_percentage_individual_allowance());
	EXPECT_ANY_THROW(worker2->get_base_rate_for_1_month());
	EXPECT_ANY_THROW(worker4->get_number_of_hours_worked_last_month());
}
