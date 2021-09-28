#include<vector>
#include<iostream>

/* ------------------------------------------- */
// Bubble Sort Algorithm implemented iteratively //
// in DESCENDING order
/* ------------------------------------------- */

void BubbleSort(std::vector<int> &unsortedArray)
{
    int temp;
    // Loop for single value to compare all other values
    for(int i = 0; i < unsortedArray.size(); i++)
    {
        // Loop for comparing all other values
        for(int j = 0; j < unsortedArray.size(); j++)
        {
            // If current comparison value is greater than
            // one of the other values in the array, swap
            // comparison value and other value
            if(unsortedArray[i] > unsortedArray[j])
            {
                temp = unsortedArray[j];
                unsortedArray[j] = unsortedArray[i];
                unsortedArray[i] = temp;
            }
        }
    }
}

// Driver Code - makes use of vectors instead of complex type array
int main()
{
    const int arr[] = { 3, 2, 55, 3, 11, 5, 3, 77, 56, 34, 65 };
    std::vector<int> driver(arr,arr + sizeof(arr)/sizeof(arr[0]));
    std::cout << "Unsorted List: ";
    for(int i = 0; i < driver.size(); i++)
    {
        std::cout << driver[i] << " ";
    }
    std::cout << std::endl;

    BubbleSort(driver);

    std::cout << "Sorted List: ";
    for(int i = 0; i < driver.size(); i++)
    {
        std::cout << driver[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}