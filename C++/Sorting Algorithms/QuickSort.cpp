#include<iostream>

/* ------------------------------------------- */
// Quick Sort Algorithm implemented recursively //
// for ASCENDING order                          //
/* ------------------------------------------- */

void Print(int array[],int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void QuickSort(int unsortedArray[],int begin,int end)
{
    // i serves as the left iterator
    int i = begin;
    // j serves as the right iterator, not including the pivot
    // which is the final array entry, "end"
    int j = end - 1;
    int temp;

    // If iterators passed each other, terminate
    if(begin >= end)
    {
        return;
    };
    
    while(i <= j)
    {
        // While iterators have not yet passed each other, if left iterator's value is greater
        // than pivot and right iterator's value is less than pivot, swap values
        if(unsortedArray[i] > unsortedArray[end] && unsortedArray[j] < unsortedArray[end])
        {
            temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[j];
            unsortedArray[j] = temp;
            // Shift both iterators towards the center to compare new pair of values
            i++;
            j--;
        }

        // If the left iterator's value is less than pivot, it is in the correct place,
        // so increment i
        if(unsortedArray[i] <= unsortedArray[end])
            i++;
        // If the right iterator's value is greater than pivot, it is in the correct place,
        // so decrement j
        if(unsortedArray[j] >= unsortedArray[end])
            j--;
    }
    // Finally, swap the left iterator's value with the pivot, which is end, so that
    // all lesser values are left of pivot and greater values are right of pivot
    temp = unsortedArray[end];
    unsortedArray[end] = unsortedArray[i];
    unsortedArray[i] = temp;

    // Recursively call this function again for unsorted arrays to the left and right
    // of the pivot separately
    QuickSort(unsortedArray,begin,i-1);
    QuickSort(unsortedArray,i+1,end);
}


// Driver Code
int main() {
    int driverArray[] = { 5, 50, 44, 98, 103, 45, 34, 16, 199, 1, 67, 43, 43 };
    int driverArraySize = sizeof(driverArray)/sizeof(driverArray[0]);

    std::cout << "Unsorted Array: ";
    Print(driverArray,driverArraySize);

    QuickSort(driverArray,0,driverArraySize - 1);

    std::cout << "Sorted Array: ";
    Print(driverArray,driverArraySize);

    return 0;
}