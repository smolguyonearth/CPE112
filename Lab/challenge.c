//Nitis Jadipang 66070501020

// List Slicing

#include <stdio.h>

#define MAX_SIZE 100

void assignArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    int size, left, right, step;
    scanf("%d", &size);

    int arr[MAX_SIZE];
    assignArr(arr, size);

    scanf("%d %d %d", &left, &right, &step);

    left = (left < -size) ? -size : ((left > size - 1) ? size - 1 : left);
    right = (right < -size - 1) ? -size - 1 : ((right > size) ? size : right);

    left = (left < 0) ? size + left : left;
    right = (right < 0) ? size + right : right;

    int valid = 0;
    if (left < right) {
        if (step > 0) {
            for (int i = left; i < right; i += step) {
                valid = 1;
                printf("%d ", arr[i]);
            }
        }
    } else {
        if (step < 0) {
            for (int i = left; i > right; i += step) {
                valid = 1;
                printf("%d ", arr[i]);
            }
        }
    }

    if (!valid) {
        printf("empty");
    }

    return 0;
}


// explain here

//Nitis Jadipang 66070501020
// List Slicing

#include <stdio.h>

// Define a constant for the maximum size of the array
#define MAX_SIZE 100

// Function to assign values to an array
void assignArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read input values and assign them to array elements
    }
}

// Main function
int main() {
    int size, left, right, step;
    
    // Read the size of the array
    scanf("%d", &size);

    int arr[MAX_SIZE]; // Declare an array with maximum size
    assignArr(arr, size); // Call function to assign values to array elements

    // Read parameters for list slicing: left index, right index, and step size
    scanf("%d %d %d", &left, &right, &step);

    // Adjust left and right indices to ensure they are within the valid range
    left = (left < -size) ? -size : ((left > size - 1) ? size - 1 : left);
    right = (right < -size - 1) ? -size - 1 : ((right > size) ? size : right);
    left = (left < 0) ? size + left : left;
    right = (right < 0) ? size + right : right;

    int valid = 0; // Flag to check if slicing occurred

    // Perform list slicing and output the sliced elements
    if (left < right) {
        if (step > 0) {
            for (int i = left; i < right; i += step) {
                valid = 1; // Slicing occurred, set flag to 1
                printf("%d ", arr[i]); // Print sliced element
            }
        }
    } else {
        if (step < 0) {
            for (int i = left; i > right; i += step) {
                valid = 1; // Slicing occurred, set flag to 1
                printf("%d ", arr[i]); // Print sliced element
            }
        }
    }

    // If no slicing occurred, print "empty"
    if (!valid) {
        printf("empty");
    }

    return 0;
}
