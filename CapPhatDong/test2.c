#include <stdio.h>

void setToNull(int *&ptr)	
{
	ptr = NULL; // (4)
}  // (5)

int main()
{
	int value = 5;
	int *pValue = &value; // (1)

    printf("\npValue point to: %d", pValue);
    setToNull(pValue);
    printf("\npValue point to: %d", pValue);
	return 0;
}