#include<stdio.h>
int ceilSearch(int arr[], int low, int high, int x)
{
int mid;

if(x <= arr[low])
	return low;

if(x > arr[high])
	return -1;

mid = (low + high)/2; 

if(arr[mid] == x)
	return mid;
	
else if(arr[mid] < x)
{
	if(mid + 1 <= high && x <= arr[mid+1])
	return mid + 1;
	else
	return ceilSearch(arr, mid+1, high, x);
}
else
{
	if(mid - 1 >= low && x > arr[mid-1])
	return mid;
	else	
	return ceilSearch(arr, low, mid - 1, x);
}
}
int floorSearch(int arr[], int low, int high, int x)
{
int mid;

if(x >= arr[high])
	return high;

if(x < arr[low])
	return -1;

mid = (low + high)/2; 

if(arr[mid] == x)
	return mid;
	
else if(arr[mid] > x)
{
	if(mid - 1 >= low && x >= arr[mid-1])
	return mid - 1;
	else
	return floorSearch(arr, low, mid-1, x);
}
else
{
	if(mid + 1 <= high && x < arr[mid+1])
	return mid;
	else	
	return floorSearch(arr, mid+1, high, x);
}
}
int main()
{
int arr[] = {1, 4, 9, 16, 25, 36, 49};
int n = sizeof(arr)/sizeof(arr[0]);
int x = 32;
int index = ceilSearch(arr, 0, n-1, x);
if(index == -1)
	printf("Ceiling of %d doesn't exist in array ", x);
else
	printf("ceiling of %d is %d", x, arr[index]);
index = floorSearch(arr, 0, n-1, x);
printf("\n");
if(index == -1)
	printf("Floor of %d doesn't exist in array ", x);
else
	printf("Floor of %d is %d", x, arr[index]);
// getchar();
return 0;
}
