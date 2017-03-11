#include <iostream>

enum Type
{
    INT,
	FLOAT,
	CSTRING
};


void printValue(void *ptr, Type type)
{
    switch (type)
	{
		case INT:
			// cast to int pointer and dereference
			std::cout << *static_cast<int *>(ptr) << '\n'; 
			break;
		
		case FLOAT:
			// cast to float pointer and reference
		    std::cout << *static_cast<float *>(ptr) << '\n';
            break;

		case CSTRING:
			// cast to char pointer and reference
		    std::cout << static_cast<char *>(ptr) << '\n'; 	
            break;
	}
}


int main()
{
    int nValue = 5;
	float fValue = 7.5;
	char szValue[] = "Mobile";

	printValue(&nValue, INT);
	printValue(&fValue, FLOAT);
	printValue(szValue, CSTRING);

	return 0;
}

