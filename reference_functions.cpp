
void add(int a, int b, int& result)
{

	result = a + b;

}

void factorial(int number, int& result)
{
	result = 1;
	for (int i = 1; i <= number; i++)
	{
		result = result * i;
	}
}

void swap(int& a, int& b)
{
	int temp;

	temp = b;
	b = a;
	a = temp;
}