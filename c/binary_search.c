#include <stdio.h>
#include <math.h>

size_t binary_search(int *arr, int item, int arr_size)
{
	size_t current, index = 0, loops = sqrt(arr_size);

	for(int i = 0; i < loops; i++) 
	{
		current = arr[(arr_size / 2) - 1];
		
		if (current > item)
		{ 
			arr_size = arr_size / 2;
		}
		else if (current < item)
		{
			arr = arr + ((arr_size / 2));
			index += arr_size / 2;
			arr_size = arr_size / 2;
		}
		else
		{
			index += (arr_size / 2) - 1;
			break;
		}
	}

	return index;
}

int main(int argc, char *argv[])
{
	int arr[] = {30, 50, 78, 90, 120, 155, 171, 205, 223, 245, 256, 275, 305, 345, 567, 600};

	fprintf(stdout, "Index : %d \n", binary_search(arr, 567, sizeof(arr)/sizeof(arr[0])));

	return 0;
}
