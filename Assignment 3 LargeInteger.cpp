/* @description LargeInteger class. Represent an arbitrarily large
* (signed) integer. This class keeps the digits of the integer in
* an array of integers internally. The array of integers is
* dynamically resized as necessary during LargeInteger operations.
* This abstract data type supports addition of large integers.
*/
#include "LargeInteger.hpp"

using namespace std;


// integer to create unique id for new LargeInteger instances
// please set and use this in the same way in the constructor you
// create for this assignment
static int nextLargeIntegerId = 1;

/** LargeInteger constructor
* Constructor for LargeInteger class that takes a simple built-in
* integer to be used as the initial value of the large integer.
*
* @param value A regular (32-bit) integer that we will use as the
* initial value of this LargeInteger data type.
*/
LargeInteger::LargeInteger(int value)
{
   // set this instance id
   id = nextLargeIntegerId++;

   // first determine number of digits, so we know what size of array
   // to construct dynamically
   // https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
   numDigits = (int)log10((double)value) + 1;

   // allocate an array of the right size
   digits = new int[numDigits];

   // iterate through the digits in value, putting them into our
   // array of digits.
   int digit;
   for (int digitIndex = 0; digitIndex < numDigits; digitIndex++)
   {
       // least significant digit
       digit = value % 10;
       digits[digitIndex] = digit;

       // integer division to chop of least significant digit
       value = value / 10;
   }
}

/** LargeInteger constructor
* Constructor for LargeInteger class that takes a two
* integers to be used to construct a large integer from an array
* of digits and an integer array as a second parameter
*
* @param sizeOfArrayOfDigits A regular (32-bit) integer that we will be the
* size of the array
*
* @param integerArray is the array that sizeOfArrayOfDigits is a size of
*
*/
LargeInteger::LargeInteger(int sizeOfArrayOfDigits, int* integerArray)
{
	// set this instance id
	id = nextLargeIntegerId++;

  // allocate an array of the right size
	digits = new int[sizeOfArrayOfDigits];
	
	//the size of digits is sizeOfArrayOfDigits
	numDigits = sizeOfArrayOfDigits;
  // iterate through the digits in value, putting them into our
  // array of digits.
	int digit;
	for (int digitIndex = 0; digitIndex < numDigits; digitIndex++)
   {
       // digit equals current element of integer array
       digit = integerArray[digitIndex];
       
       //digits array equals value of digit
       digits[digitIndex] = digit;
   }
}

/** LargeInteger destructor
* Destructor for the LargeInteger class. Make sure we are good
* managers of memory by freeing up our digits when this object
* goes out of scope.
*/
LargeInteger::~LargeInteger()
{
   // We display a log message to track destructor invocation. In
   // a real application we might send this to a log file, and parameterize
   // whether to log these type of events or not.
   cout << " destructor entered, freeing my digits" << endl
       << " id = " << id << endl
       //<< " value=" << tostring() // uncomment this after you implement tostring()
       << endl;
   delete[] this->digits;
}

/**
*  tostring function. Function that you can call that will
*  be a representation of the LargeInteger
* in order to assert different tostring calls I cannot change
* the class variables. So I create a copy and use them in 
* my function
*/
string LargeInteger::tostring()
{
	ostringstream output;

  int numberOfDigits;
  int* ptrArray;
  
  numberOfDigits = numDigits;
  ptrArray = digits;

	for(numberOfDigits; numberOfDigits --> 0;)
	{
    output << ptrArray[numberOfDigits];

	}
	return output.str();
}

/**
* function named maxDigits()
* This function will take a reference 
* to a LargeInteger as its only parameter
*
* @param LargeInteger secondNumber - variable that
* looks at another declared class member
* and checks which one is bigger
*/
int LargeInteger::maxDigits(LargeInteger secondNumber)
{
	if (numDigits<secondNumber.numDigits)
	{
		return secondNumber.numDigits;
	}
	else
	{
		return numDigits;
	}
}

/**
* function named digitAtPlace()
* This function returns the digit of this 
* large integer object at a particular digit index
*
* @param userEnteredElement - takes an integer index as its
* input parameter, and returns an integer as its result
*
*/
int LargeInteger::digitAtPlace(int value)
{

if(numDigits>=value && numDigits>=0)
	{
	  return digits[value];
	}
	else
	{
		/*I don't know what to do here. I tried a couple different things
		but nothing worked. I always get random value when index is under 0 */
    return 0; 
	}
}

void LargeInteger::appendDigit(int value)
{
	int* myNewArray;
	int size;
	size = numDigits +1;
	myNewArray = new int[size];
	for(int index = 0; index<size; index++)
	{
		myNewArray[index] = digits[index];
		digits[index] = myNewArray[index];
	}
	myNewArray[size] = value; //Test in order to see if my new array is correct
	for(int i = 0; i<size;i++)
	{
	cout<<myNewArray[i];
	}
	cout<<endl;
	
	delete [] digits;
	
	
	
	
	
}















