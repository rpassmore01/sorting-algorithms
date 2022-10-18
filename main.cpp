#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swap(int *xp, int *yp)
{
    /// Swaps two pointer locations
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void siftUp(int arr[], int start, int end)
{
    int child = end;
    while (child > start)
    {
        int parent = (child - 1) / 2;
        if (arr[parent] < arr[child])
        {
            swap(&arr[parent], &arr[child]);
            child = parent;
        }
        else
        {
            return;
        }
    }
}

void heapify(int arr[], int count)
{
    int end = 1;

    while (end < count)
    {
        siftUp(arr, 0, end);
        end = end + 1;
    }
}

void heapSort(int arr[], int count)
{
    heapify(arr, count);

    int end = count - 1;

    while (end > 0)
    {
        swap(&arr[end], &arr[0]);
        heapify(arr, end);
        end = end - 1;
    }
}

int main()
{
    int length = 1000;
    string currText = "";
    ifstream inputFile("./sorting-data/data1000.txt");
    int sortingArray[length];
    int counter = 0;

    while (getline(inputFile, currText))
    {
        sortingArray[counter] = stoi(currText);
        counter++;
    }

    for (int i = 0; i < 1000; i++)
    {
        cout << sortingArray[i] << endl;
    }

    cout << endl;

    heapify(sortingArray, 1000);

    for (int i = 0; i < 1000; i++)
    {
        cout << sortingArray[i] << endl;
    }

    inputFile.close();
}