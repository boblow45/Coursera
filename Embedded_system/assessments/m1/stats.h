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
 * @file stats.h
 * @brief 	This fill contains functions which allows the user to calculate basic 
 * 			statistics for a given array 
 *
 *	This fill contains functions which allows the user to calculate basic statistics 
 *	for a given array. The following are the functions contained in this file.
 *
 *  	- print_statistics() - 	A function that prints the statistics of an array 
 *								including minimum, maximum, mean, and median.
 * 		- print_array() - 	Given an array of data and a length, prints the array to 
 * 							the screen
 * 		- find_median() - 	Given an array of data and a length, returns the median value
 * 		- find_mean() - 	Given an array of data and a length, returns the mean
 * 		- find_maximum() - 	Given an array of data and a length, returns the maximum
 * 		- find_minimum() - 	Given an array of data and a length, returns the minimum
 * 		- sort_array() - 	Given an array of data and a length, sorts the array from 
 * 							largest to smallest. (The zeroth Element should be the largest 
 * 							value, and the last element (n-1) should be the smallest value. )
 *
 * @author Cillian O'Brien
 * @date 19-03-2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array 
 *								
 * @param unsigned char * array, Pointer to array which to print the statistics of
 * @param unsigned char size, Size of array pass to this function
 *
 * @return void
 */
void print_statistics(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, prints the array to 
 *        the screen
 *
 * @param unsigned char * array, Pointer to array which to print
 * @param unsigned char size, Size of array pass to this function
 *
 * @return void
 */
void print_array(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param unsigned char * array, Pointer to array which calculate statistics on
 * @param unsigned char size, Size of array pass to this function
 *
 * @return median value of the array
 */
float find_median(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param unsigned char * array, Pointer to array which calculate statistics on
 * @param unsigned char size, Size of array pass to this function
 *
 * @return mean value of the array
 */
float find_mean(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param unsigned char * array, Pointer to array which calculate statistics on
 * @param unsigned char size, Size of array pass to this function
 *
 * @return max vaule of the array
 */
unsigned char find_maximum(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param unsigned char * array, Pointer to array which calculate statistics on
 * @param unsigned char size, Size of array pass to this function
 *
 * @return minimum vaule of the array
 */
unsigned char find_minimum(unsigned char * array, unsigned int size);

/**
 * @brief Given an array of data and a length, sorts the array from 
 * 		  largest to smallest. (The zeroth Element should be the largest 
 * 		  value, and the last element (n-1) should be the smallest value. )
 *
 * @param unsigned char * array, Pointer to array which to sort
 * @param unsigned char size, Size of array pass to this function
 *
 * @return void
 */
void sort_array(unsigned char * array, unsigned int size);

#endif /* __STATS_H__ */
