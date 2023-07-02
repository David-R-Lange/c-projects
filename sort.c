#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gen_random_numbers(int arr[], int size, int min, int max) {
	for(int i = 0; i < size; ++i) {
		arr[i] = rand() % (max - min +1) + min;
	}
}

void swap(int arr[],int index1, int index2) {
	int temp;
	if(index1 != index2) {
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];

	int i = (low-1);

	for(int j = low; j < high; ++j) {
		if(arr[j] <= pivot) {
			i = i+1;
			swap(arr,i,j);
		}
	}
	i = i+1;
	swap(arr,i,high);
	return i;
}


void bubble_sort(int arr[], int size) {
	int swap_flag;
	for(int step = 0; step < size-1; ++step) {
		swap_flag = 0;
		for(int i = 0; i < size-step-1; ++i) {
			if(arr[i] > arr[i+1]) {
				swap(arr,i,i+1);
				swap_flag = 1;
			}
		}
		if(swap_flag == 0) {
			break;
		}
	}
}

void selection_sort(int arr[], int size) {
	int smallest_element_index;
	for(int step = 0; step < size-1; ++step) {
		smallest_element_index = step;
		for(int i = step+1; i < size; ++i) {
			if(arr[smallest_element_index] > arr[i]) {
				smallest_element_index = i;
			}
		}
		swap(arr,step,smallest_element_index);
	}	
}

void insertion_sort(int arr[], int size) {
	for(int i = 1; i < size; ++i) {
		for(int j = i; j > 0 && arr[j-1] > arr[j]; --j) {
			swap(arr, j-1, j);
		}
	}
}

void quick_sort(int arr[], int low, int high) {
	if(low >= high || low < 0) {
		return;
	}

	int p = partition(arr,low,high);
	quick_sort(arr, low, p-1);
	quick_sort(arr, p+1, high);
}




void print_arr(int arr[], int size) {
	for(int i = 0; i < size; ++i) {
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

int main() {
	// Defining constant size of the arrays
	int const SIZE = 10;

	// Creating empty arrays of defined size
	int arr[SIZE] = {};
	int arr2[SIZE] = {};
	int arr3[SIZE] = {};
	int arr4[SIZE] = {};
	
	// Filling empty arrays with random numbers
	system("clear");
	srand(time(0));

	gen_random_numbers(arr,SIZE,0,1000);
	gen_random_numbers(arr2,SIZE,0,1000);
	gen_random_numbers(arr3,SIZE,0,1000);
	gen_random_numbers(arr4,SIZE,0,1000);

	// Sorting random arrays with different methods
	double start = clock();
	bubble_sort(arr,SIZE);
	double end = clock();
	double cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("Time used by bubble sort: %f\n",cpu_time_used);
	print_arr(arr,SIZE);

	
	start = clock();
	selection_sort(arr2,SIZE);
	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("\nTime used by selection sort: %f\n", cpu_time_used);
	print_arr(arr2,SIZE);


	start = clock();
	insertion_sort(arr3,SIZE);
	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("\nTime used by insertion sort: %f\n", cpu_time_used);
	print_arr(arr3,SIZE);


	
	start = clock();
	quick_sort(arr4,0,SIZE-1);
	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("\nTime used by quick sort: %f\n", cpu_time_used);
	print_arr(arr4,SIZE);

	return 0;
}
