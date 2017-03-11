int main(int argc, const char *argv[])
{
	int value = 5;
	int *ptr = new int;  // allocate memory
	ptr = &value;        // old address lost, memory leak results
}
