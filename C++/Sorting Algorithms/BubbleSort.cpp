#include<vector>
#include<iostream>

using namespace std;

void BubbleSort(vector<int> &unsortedArray)
{
    for(int i = 0; i < unsortedArray.size(); i++)
    {
        for(int j = 0; j < unsortedArray.size(); j++)
        {
            if(unsortedArray[i] > unsortedArray[j])
            {
                int temp = unsortedArray[j];
                unsortedArray[j] = unsortedArray[i];
                unsortedArray[i] = temp;
            }
        }
    }
}

int main()
{
    const int arr[] = { 3, 2, 55, 3, 11, 5, 3, 77, 56, 34, 65 };
    vector<int> driver(arr,arr + sizeof(arr)/sizeof(arr[0]));
    cout << "Unsorted List: ";
    for(int i = 0; i < driver.size(); i++)
    {
        cout << driver[i] << " ";
    }
    cout << endl;

    BubbleSort(driver);

    cout << "Sorted List: ";
    for(int i = 0; i < driver.size(); i++)
    {
        cout << driver[i] << " ";
    }
    cout << endl;

    return 0;
}