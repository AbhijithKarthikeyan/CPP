#include<iostream>

void print(const int& Ref)
{
	std::cout << "The value ref is refering: " << Ref << std::endl;

	/*This doesnt get allowed since ref is constant*/
	//Ref = 3;

}