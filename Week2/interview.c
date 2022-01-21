#include <stdio.h>  
int binarySearch(int arr[], int low, int high)    
{    
    if (high >= low)
	{
		int mid = (low + high)/2; 
		if ( (mid == 0 || 1 > arr[mid-1]) && (arr[mid] == 1) )
			return mid;
		else if (1 > arr[mid])
			return binarySearch(arr, (mid + 1), high);
		else
			return binarySearch(arr, low, (mid -1));
	}
	return -1;
}    
int main() {  
  int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};    
  int n = sizeof(a) / sizeof(a[0]);   
  int res = binarySearch(a, 0, n-1);   
  if (res == -1)  
  printf("\nThere is no transition");  
  else  
  printf("\nThe transition occurs at %dth position of the array", res);  
  return 0;  
}  