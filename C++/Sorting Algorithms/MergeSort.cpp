#include <iostream>
#include <vector>

/* ------------------------------------------- */
// Merge Sort Algorithm implemented recursively //
// for ASCENDING order                          //
/* ------------------------------------------- */
// Algorithm is split into 2 separate functions: //
// one recursively calls itself to divide        //
// the problem and determines the midpoint of    //
// the input array. The other takes this         //
// midpoint, separates the sorted input array    //
// into subarrays based on this point and merges //
// their values into a single sorted array.      //

void MergeArrays(int unsortedArray[],int begin,int mid,int end)
{
    // Subarray sizes are based on splitting the beginning and end indices with the midpoint
    int leftArraySize = (mid + 1) - begin;
    int rightArraySize = end - mid;
    int leftArrayIterator = 0;
    int rightArrayIterator = 0;
    int mergedArrayIndex = begin;
    // Allocate space for the 2 subarrays
    int* leftArray = new int[leftArraySize];
    int* rightArray = new int[rightArraySize];
    // Loops to initialize subarrays from input array
    for(int i = 0; i < leftArraySize; i++)
        leftArray[i] = unsortedArray[begin + i];

    for(int i = 0; i < rightArraySize; i++)
        rightArray[i] = unsortedArray[(mid + 1) + i];

    // While both subarrays are still being analyzed
    while(leftArrayIterator < leftArraySize && rightArrayIterator < rightArraySize)
    {
        // If left subarray value is greater than right, push right  subarray value into
        // sorted array and increment right subarray iterator
        if(leftArray[leftArrayIterator] > rightArray[rightArrayIterator])
        {
            unsortedArray[mergedArrayIndex] = rightArray[rightArrayIterator];
            rightArrayIterator++;
        }
        // Else if left subarray value is less than right, push left subarray value into
        // sorted array and increment left subarray iterator
        else
        {
            unsortedArray[mergedArrayIndex] = leftArray[leftArrayIterator];
            leftArrayIterator++;
        }
        mergedArrayIndex++;
    }

    // If only left subarray still has values, push all of those values to sorted array
    while(leftArrayIterator < leftArraySize)
    {
        unsortedArray[mergedArrayIndex] = leftArray[leftArrayIterator];
        leftArrayIterator++;
        mergedArrayIndex++;      
    }

    // If only right subarray still has values, push all of those values to sorted array
    while(rightArrayIterator < rightArraySize)
    {
        unsortedArray[mergedArrayIndex] = rightArray[rightArrayIterator];
        rightArrayIterator++;
        mergedArrayIndex++;    
    }
}

void MergeSort(int unsortedArray[],int begin,int end)
{
    // If previous recursion array only had one value,
    // current recursion will have begin >= end, so terminate
    if(begin >= end)
        return;
    
    // Simple midpoint calculation using beginning index as an offset
    int mid = begin + ((end - begin) / 2);
    
    MergeSort(unsortedArray,begin, mid);
    MergeSort(unsortedArray,mid + 1, end);
    // Merging only begins once array has been recursively split into
    // subarrays all containing 1 value
    MergeArrays(unsortedArray,begin,mid,end);

}

void Print(int array[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Driver Code
int main()
{
    int driverArray[] = { 3, 2, 55, 3, 11, 5, 3, 77, 56, 34, 65 };
    int arraySize = sizeof(driverArray)/sizeof(driverArray[0]);

    std::cout << "Unsorted Array: ";
    Print(driverArray,arraySize);

    MergeSort(driverArray,0,arraySize - 1);

    std::cout << "Sorted Array: ";
    Print(driverArray,arraySize);

    return 0;
}