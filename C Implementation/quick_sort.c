#include <stdio.h>


void swap(int *arr, int i, int j)
{
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

int partition(int *arr,int low,int high)
{
	int pivot = arr[high];
	int i = low;
	for(int j = low;j<high;j++)
	{
		if(pivot>arr[j])
		{
			swap(arr,i,j);
			i++;
		}
	}
	swap(arr,i,high);

	return i;
}	

	
int * quicksort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pos = partition(arr,low,high);
		arr = quicksort(arr,low,pos-1);
	    arr = quicksort(arr,pos+1,high);
	}
	return arr;
}



int main(int argv, char** argc)
{    
	int ant[22] = {3,0,1,2,4,5,6,7,11,203,3,32,24,55,32,4,2,3,1,0,5,6,0};
	int * j = quicksort(ant,0,22);
	for(int i = 0;i<22;i++)
	{
		printf("[%d]",j[i]);
	}
	printf("\n","");
}