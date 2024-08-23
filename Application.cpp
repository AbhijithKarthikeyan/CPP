/* iostream contains librarry for input output*/
#include<iostream>
#include "reference_functions.h"

/*namesapace is a way to wrap types , std namespace contains cout
cout represents the computer console out */
using namespace std;

#define IO_PART 1
//#define UNIFORM_INITIALIZATION
//#define POINTER
//#define REFERENCE

//#define CONST_REFERENCE

//#define ASSIGNMENT




 /* In C++ main function always should return int , It cant return void*/
int main()
{
#ifdef IO_PART
	cout << "Hello World" << endl;
	/* endl is called the manipulator . It inserts new line and flushes the output buffer*/
	/*
		int i{ 0 };
		char c{ 'a' };
		int array[]{ 1 ,2, 3, 4 };
		cout << array[3] << endl;
	*/

	/* Usage of console IO*/

	char name[512];

	cout << "Enter Your Name : " << endl;
	//cin.getline(name, 20, '\n');
	cout << "Your name is :" << name << endl;



	char buff[512];

	cout << "Enter your Adddress(space after each word)";
	//cin.getline(buff, 100 , '\n');
	cout << " The entered Address is :" << buff << endl;
	/* return values goes to OS*/
#endif

#ifdef UNIFORM_INITIALIZATION

	//Before C++11

	int a1;					//Uninitialized variable
	int a[8];
	int a2 = 0;				// Initialization using assignment operator called copy initialization
	std::string  s1;		// This is Ok , because it initialized through the default constructor
	std::string s2("C++"); //Direct Initialization
	int a3(4);			  // Direct Initialization

	char c;
	char c1[8];						//Unitialized
	char c2[8] = { '\0' };			// Initialization using assignment operator called copy initialization
	char c3[8] = { 'a', 'b' , 'c' }; // Initialization using assignment operator called copy initialization, aggreagate init
	char c4[8] = { "abcd" };         // Initialization using assignment operator called copy initialization

	// Uniform Initialization in C++

	int b1{};  // initialized to default value , default for primitive type is 0 . Called Value Initialization . Initialize with value
	int b2{ 5 }; //Direct Initialization

	char e1[8]{};  // Array Init with uniform Initialization, Initializes to default value '\0'
	char e2[8]{ "Hello" };



	// Dynamic in heam
	int* p = new int; //unitialized
	int* p1 = new int{}; // Initialized with default value , 0
	int* p2 = new int{ 8 };


	char* p3 = new char[8] {};
	char* p4 = new char[8] {"Hello"}; /*Earlier it was not possible to initialize the dynamic memory created in heap. With Uniform Initialization it is possible*/


	/*Print all the values of initialized variables*/

	//cout << "a1" << a1 << endl;
	cout << "a" << " " << a << endl;
	cout << "a2" << " " << a2 << endl;
	cout << "a3" << " " << a3 << endl;

	//cout << "c" << " " << c << endl;
	cout << "c1" << " " << c1 << endl;
	cout << "c2" << " " << c2 << endl;
	cout << "c3" << " " << c3 << endl;
	cout << "c4" << " " << c4 << endl;

	cout << "b1" << " " << b1 << endl;
	cout << "b2" << " " << b2 << endl;
	cout << "e1" << " " << e1 << endl;
	cout << "e2" << " " << e2 << endl;

	cout << "*p" << " " << *p << endl;
	cout << "*p1" << " " << *p1 << endl;
	cout << "*p2" << " " << *p2 << endl;

	cout << "*p3" << " " << *p3 << endl;
	cout << "*p4" << " " << *p4 << endl;


	/* Unitialized primitive type array was allowed to be used and unitialized primitive type single variable was not allowed to be used , Why ?????*/

	/****Different Kinds*******************
	* 1. Value Intialization => T obj{}
	* 2. Direct Initialization => T obj {v}
	* 3. Copy Intiialization => T obj = v;
	* *************************************/


#endif


#ifdef POINTER
	/* From C++11 nullptr is used to initialize pointer instead of NULL*/
	int* ptr = nullptr;

	//Defefencing a null pointer is not allowed (both write and read) It should be assigned with address before dereference
	cout << *ptr << endl;
#endif

#ifdef REFERENCE
	/* Referent */
	int y;
	/*Reference */
	int& ref = y;

	int a = 2;
	int b = 3;
	int sum{};
	int factor{};

	add(a, b, sum);
	factorial(b, factor);
	swap(a, b);

	y = 20;

	cout << "y :" << " " << y << endl;
	cout << " Ref " << " " << ref << endl;

	cout << "The sum is " << sum << endl;
	cout << "The factorial is " << factor << endl;
	cout << "The swapped numbers are:  " << a << " " << b << endl;
#endif

#ifdef CONST_REFERENCE
	int y = 3;

	int& yRef = y;

	const int& lRef = 3;
	/* This is allowed since refernce is not of a constant*/
	yRef = 5;

	cout << "The new value of y =" << y << endl;


	/* This is not allowed as lRef is refering to a constant*/
	//lRef = 2;

#endif

#ifdef  ASSIGNMENT

//Try to modify x1 & x2 and see the compilation output
	int x = 5;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;

	ref_x1 = 2;
	// ref_x2 = 3;
	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int* ptr1 = &x;
	int* const ptr2 = &x;
	//const int * const ptr3 = &x ;

	/*
	int y = 3;
	*ptr1 = 1;
	ptr1 = &y;

	*ptr2 = 10;
	ptr2 = &y;

	*ptr3 = 11;
	ptr3 = &y;
	*/

	//Find which declarations are valid. If invalid, correct the declaration
	const int* ptr3 = &MAX;
	int* ptr4 = &MAX;   /* wrong as constant integer cant be converted to integer*/

	const int& r1 = ref_x1;
	int& r2 = ref_x2;   /* Wrong as constant int ref cant be converted to int ref*/

	int const*& p_ref1 = ptr1; /* wrong as ptr1 is a constant integer pointer, which can not be given to a reference which is not constatnt correct is int const *&p_ref1 = ptr1 ; */
	int* const& p_ref2 = ptr2; /* ptr2 is a constant pointer which is initialized to a reference which is a reference to constant correction is const int* const &p_ref2 = ptr2 ;*/

#endif

	return 0;
}


/* Notes */
/**************************************************************/

/* ****************Build Steps *********************************
1.	Preprocessor
2.	Compilation - output is .o object files
3.	Linking - Linking with libraries and make executable
3.	************************************************************/