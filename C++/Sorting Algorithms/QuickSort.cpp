#include<iostream>

using namespace std;

void Print(int array[],int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void QuickSort(int unsortedArray[],int begin,int end)
{
    // Pick pivot, compare with rest of array, then split recursively
    int i = begin;
    int j = end - 1;
    int temp;
    bool begend = begin == end;

    if(begin >= end)
    {
        /*
        if(unsortedArray[i] > unsortedArray[end])
        {
            temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[end];
            unsortedArray[end] = temp;
        }
        */
        return;
    };
    
    while(i <= j)
    {

        if(unsortedArray[i] > unsortedArray[end] && unsortedArray[j] < unsortedArray[end])
        {
            temp = unsortedArray[i];
            unsortedArray[i] = unsortedArray[j];
            unsortedArray[j] = temp;
            i++;
            j--;
        }

        if(unsortedArray[i] <= unsortedArray[end])
            i++;
        if(unsortedArray[j] >= unsortedArray[end])
            j--;
    }
    temp = unsortedArray[end];
    unsortedArray[end] = unsortedArray[i];
    unsortedArray[i] = temp;

    QuickSort(unsortedArray,begin,i-1);
    QuickSort(unsortedArray,i+1,end);
}

int main() {
    //int driverArray[] = { 5, 50, 44, 98, 103, 45, 34, 16, 199, 1, 67, 43, 43 };
    int driverArray[] = { 2, 7, 9, 3, 6, 8};
    int driverArraySize = sizeof(driverArray)/sizeof(driverArray[0]);

    cout << "Unsorted Array: ";
    Print(driverArray,driverArraySize);

    QuickSort(driverArray,0,driverArraySize - 1);

    cout << "Sorted Array: ";
    Print(driverArray,driverArraySize);

    return 0;
}