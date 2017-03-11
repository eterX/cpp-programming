#include <iostream>


int main(int argc, const char *argv[])
{
    struct Person
	{
	    int age;
		double weight;
	};

	Person p;
	Person &refer = p;
	refer.age = 25;
	std::cout << "Age: " <<  refer.age << "\n";

	// Pointers
	// Person *person // segmentation fault
	// person->age = 25;
	// std::cout << "Age: " <<  person->age << "\n";
	
	Person person;
	Person *person_pointer = &person;
    person_pointer->age = 25;
	std::cout << "Age: " <<  person_pointer->age << "\n";

	return 0;
}
