#include <iostream>
#include <vector>

using namespace std;

void MergeArrays(int unsortedArray[],int begin,int mid,int end)
{
    int leftArraySize = (mid + 1) - begin;
    int rightArraySize = end - mid;
    int leftArrayIterator = 0;
    int rightArrayIterator = 0;
    int mergedArrayIndex = begin;
    int* leftArray = new int[leftArraySize];
    int* rightArray = new int[rightArraySize];
    for(int i = 0; i < leftArraySize; i++)
        leftArray[i] = unsortedArray[begin + i];

    for(int i = 0; i < rightArraySize; i++)
        rightArray[i] = unsortedArray[(mid + 1) + i];

    while(leftArrayIterator < leftArraySize && rightArrayIterator < rightArraySize)
    {
        if(leftArray[leftArrayIterator] > rightArray[rightArrayIterator])
        {
            unsortedArray[mergedArrayIndex] = rightArray[rightArrayIterator];
            rightArrayIterator++;
        }
        else
        {
            unsortedArray[mergedArrayIndex] = leftArray[leftArrayIterator];
            leftArrayIterator++;
        }
        mergedArrayIndex++;
    }

    while(leftArrayIterator < leftArraySize)
    {
        unsortedArray[mergedArrayIndex] = leftArray[leftArrayIterator];
        leftArrayIterator++;
        mergedArrayIndex++;      
    }

    while(rightArrayIterator < rightArraySize)
    {
        unsortedArray[mergedArrayIndex] = rightArray[rightArrayIterator];
        rightArrayIterator++;
        mergedArrayIndex++;    
    }
}

void MergeSort(int unsortedArray[],int begin,int end)
{
    if(begin >= end)
        return;
    
    int mid = begin + ((end - begin) / 2);
    
    MergeSort(unsortedArray,begin, mid);
    MergeSort(unsortedArray,mid + 1, end);
    MergeArrays(unsortedArray,begin,mid,end);

}

void Print(int array[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main()
{
    int driverArray[] = { 3, 2, 55, 3, 11, 5, 3, 77, 56, 34, 65 };
    int arraySize = sizeof(driverArray)/sizeof(driverArray[0]);

    cout << "Unsorted Array: ";
    Print(driverArray,arraySize);

    MergeSort(driverArray,0,arraySize - 1);

    cout << "Sorted Array: ";
    Print(driverArray,arraySize);

    return 0;
}