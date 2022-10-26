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

void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    int largest = i;
 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build initial heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify array agian
        heapify(arr, i, 0);
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

    heapSort(sortingArray, 1000);

    for (int i = 0; i < 1000; i++)
    {
        cout << sortingArray[i] << endl;
    }

    inputFile.close();
}