#include <stdio.h>
#define NA -1
void moveToEnd(int mPlusN[], int size)
{
	int i = 0, j = size - 1;
	for (i = size - 1; i >= 0; i--)
		if (mPlusN[i] != NA) {
			mPlusN[j] = mPlusN[i];
			j--;
		}
}
int merge(int mPlusN[], int N[], int m, int n)
{
	int i = n;
	int j = 0;
	int k = 0;
	while (k < (m + n))
	{
		if ((j == n)|| (i < (m + n)
			&& mPlusN[i] <= N[j]))
		{
			mPlusN[k] = mPlusN[i];
			k++;
			i++;
		}
		else 
		{
			mPlusN[k] = N[j];
			k++;
			j++;
		}
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
}
int main()
{
	int mPlusN[] = { 2, 8, NA, NA, NA, 13, NA, 15, 20 };
	int N[] = { 5, 7, 9, 25 };
	int n = sizeof(N) / sizeof(N[0]);
	int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;
	moveToEnd(mPlusN, m + n);
	merge(mPlusN, N, m, n);
	printArray(mPlusN, m + n);

	return 0;
}
