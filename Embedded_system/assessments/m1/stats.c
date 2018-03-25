/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 *
 * @author Cillian O'Brien
 * @date 19-03-2018
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
				     114, 88,   45,  76, 123,  87,  25,  23,
            			     200, 122, 150, 90,   92,  87, 177, 244,
				     201,   6,  12,  60,   8,   2,   5,  67,
                		     7,  87, 250, 230,  99,   3, 100,  90};

	print_array(test, SIZE);
	print_statistics(test, SIZE);
}

/**
 * @brief A utility function to swap two elements
 *								
 * @param unsigned char* a, Pointer to first char which will be swapped
 * @param unsigned char* b, Pointer to first char which will be swapped
 *
 * @return void
 */
void swap(unsigned char* a, unsigned char* b)
{
    unsigned char t = *a;
    *a = *b;
    *b = t;
}
 
/**
 * @brief Function creates the pivotted partition for quick sort
 *
 * This function takes last element as pivot, places the pivot element at its 
 * correct position in sorted array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right of pivot
 * 
 * @param unsigned char* a, Pointer to first char which will be swapped
 * @param unsigned char* b, Pointer to first char which will be swapped
 *
 * @return void
 */
unsigned char partition (unsigned char * arr, int low, int high)
{
    unsigned char pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
 /**
 * @brief Function which emplemets quick sort
 *
 * This function takes last element as pivot, places the pivot element at its 
 * correct position in sorted array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right of pivot
 * 
 * @param unsigned char * arr, Array to be sorted
 * @param int low, Index to start quicksort at
 * @param int high, Index to end quicksort at
 *
 * @return void
 */
void quick_sort(unsigned char * arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}


void print_statistics(unsigned char * array, unsigned int size)
{	
	printf("\nFollowing values are the basic statistics for the pervided array\n");	
	printf("\tArray has a max value of %d\n", find_maximum(array, size));
	printf("\tArray has a min value of %d\n", find_minimum(array, size));
	printf("\tArray has a median value of %.4f\n", find_median(array, size));
	printf("\tArray has a mean value of %.4f\n", find_mean(array, size));
}

void print_array(unsigned char * array, unsigned int size)
{
	printf("\nFollowing values are the values stored at each index of the array\n");		
	for(int i =0; i < size; i++)
		printf("\tarray[%d] is %d \n", i, array[i]);
}

float find_median(unsigned char array[], unsigned int size){
	sort_array(array, size);
	
	if(size % 2)
        return (float)array[size / 2 -1];
    else
        return (float)array[size / 2] + array[size / 2 - 1] / 2;
}

float find_mean(unsigned char * array, unsigned int size){
	unsigned long int return_val = 0;

	for(int i=0; i < size; i++)
		return_val += array[i];
	
	return (float)return_val / size;
}
unsigned char find_maximum(unsigned char * array, unsigned int size){
	unsigned int max_val = 0;
	
	for(int i=0; i < size; i++){
		if(array[i] > max_val)
			max_val = array[i];
	}
	
	return max_val;
}

unsigned char find_minimum(unsigned char * array, unsigned int size){
	unsigned int min_val = 255;
	
	for(int i=0; i < size; i++){
		if(array[i] < min_val)
			min_val = array[i];
	}
	
	return min_val;
}

void sort_array(unsigned char * array, unsigned int size){
	quick_sort(array, 0, size - 1);
}
