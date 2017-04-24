#include<iostream>
using namespace std;

//PROTOTYPES/////
int* doubleCapacity(const int* listPtr, int oldArraySize);
//////////

int main() // TEST FUNCTION --- "This is only a test"
{
	const int arraySize = 10;
	int* listPtr = new int[arraySize]; // a pointer to a new array of size 10 (arraySize)

	// loop that walks through the array, assigning it some values
	for (int i = 0; i < arraySize; i++)
	{
		*(listPtr + i) = i;
	}

	// temporarily hold the current pointer to the array in a temporary variable (temp)
	// so that the original values in the array aren't lost/erased
	int* temp = listPtr;

	// assign "listPtr" a new array of double length by means of the doubleCapacity function
	listPtr = doubleCapacity(listPtr, arraySize);

	delete[] temp; // delete "temp," since we're done with it
	temp = NULL;

	// loop that walks through the new, longer array, assigning it some values in the new
	// second half of the array
	for (int i = 10; i < arraySize * 2; i++)
	{
		*(listPtr + i) = i;
	}

	// loop that prints all the values in the new [20] length array
	for (int i = 0; i < arraySize * 2; i++)
	{
		cout << *(listPtr + i) << endl;
	}

	delete[] listPtr; // delete "listPtr," since we're all done
	listPtr = NULL;

	return 0;
}

//INPUT: the pointer to the array (listPtr), and the original size of the array (oldArraySize)
/*PROCESS: creates new array of double the original length, and assigns its first half
of elements the values of the original elements in the old array*/
//OUTPUT: the pointer to the new, extended array
int* doubleCapacity(const int* listPtr, int oldArraySize)
{
	int* newListPtr = new int[oldArraySize * 2]; // create new array of double the original length

	// loop that walks through the new array, assigning its first half of elements
	// the values of the original elements in the old array (from listPtr to newListPtr)
	for (int i = 0; i < oldArraySize; i++)
	{
		*(newListPtr + i) = *(listPtr + i);
	}

	return newListPtr;
}