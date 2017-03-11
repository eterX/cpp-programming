#include <iostream>

struct Employee
{
    short id;
	int age;
};


void output_personal_info(Employee employee)
{
    std::cout << "id \t: " << employee.id << std::endl;
	std::cout << "age \t: " << employee.age << std::endl;
}


int main(int argc, const char * argv[])
{
    Employee ceo = {1, 35};
	output_personal_info(ceo);

	return 0;
}
