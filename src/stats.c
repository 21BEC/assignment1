/*
 ============================================================================
 Name        : stats.c
 Author      : Mradul
 Version     :
 Copyright   : Your copyright notice
 Description : It includes functions to calculate and print statistics such as the minimum, maximum, mean, and median of the data array.

1. `print_statistics(int array[], int length)`: This function takes an array of integers and its length as input and print the calculated value, including the minimum, maximum, mean, and median .

2. `print_array(int array[], int length)`:      This function takes an array of integers and its length as input and prints the elements of the array to the screen.

3. `find_median(int array[], int length)`:      This function calculates and returns the median value of the input array. I used a simple bubble to sort the array to calculate median.

4. `find_mean(int array[], int length)`:        This function calculates and returns the mean (average) value of the input array.

5. `find_maximum(int array[], int length)`:     This function finds and returns the maximum value from the input array.

6. `find_minimum(int array[], int length)`:     This function finds and returns the minimum value from the input array.

7. `sort_array(int array[], int length)`:       This function sorts the input array in descending order, from the largest to the smallest value,
                                                using a basic bubble sort algorithm.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_statistics(int array[], int length);
void print_array(int array[], int length);
int find_median(int array[], int length);
float find_mean(int array[], int length);
int find_maximum(int array[], int length);
int find_minimum(int array[], int length);

int main() {

    int data[] = {12, 45, 6, 23, 78, 91, 53};
    int length = sizeof(data) / sizeof(data[0]);

    print_array(data, length);
    print_statistics(data, length);

    return 0;
}

void print_statistics(int array[], int length) {
    printf("Minimum: %d\n", find_minimum(array, length));
    printf("Maximum: %d\n", find_maximum(array, length));
    printf("Mean: %.2f\n", find_mean(array, length));
    printf("Median: %d\n", find_median(array, length));
}

void print_array(int array[], int length) {
    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int find_median(int array[], int length) {
    int temp;
    temp = length;
    for (int i = 0; i < length; i++) {
        temp[i] = array[i];
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap the elements
                int tempVal = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempVal;
            }
        }
    }

    if (length % 2 == 0) {
        // If array length is even
        return (temp[length / 2 - 1] + temp[length / 2]) / 2;
    } else {
        // If array length is odd
        return temp[length / 2];  // returns middle element
    }
}

float find_mean(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (float) sum / length;
}

int find_maximum(int array[], int length) {
    int max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int find_minimum(int array[], int length) {
    int min = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}
