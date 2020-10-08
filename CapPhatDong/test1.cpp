#include <iostream>
using namespace std;

void setToNull(int *&ptr)	
{
	ptr = NULL; // (4)
}  // (5)

int main()
{
	int value = 5;
	int *pValue = &value; // (1)
	
	cout << "pValue point to " << pValue << endl; // (2)
	setToNull(pValue); // (3)
	cout << "pValue point to " << pValue << endl; // (6)
	
	system("pause");
	return 0;
}