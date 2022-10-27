# Sorting Algorithms Test
## This is for a school project.   
This project includes implementations for the selection, bubble, merge, heap and merge sort algorithms. I have tested the performance of every algorithm, and later in the README I will explain the time complexity for each of the algorithms individually.

| Algorithm | Elements Sorted | Time (s) |
| --------- | :--------------:| --------:|
| Selection |    400000       |    359   |
|   Bubble  |    400000       |    1018  |
|   Merge   |    400000       |    0.13  |
|   Quick   |    400000       |    0.18  |
|    Heap   |    400000       |    0.23  |

We can see from the data above that all sorting algorithms are not created equally. One can take a fraction of a second to finish sorting hundreds of thousands of numbers, while others can take many minutes. Why is this? If we look at the Big O notation for these algorithms it may clear this up.

| Algorithm | Big O Average  | Big O Worst Case | Big O Best Case |
| --------- |:--------------:|:----------------:|----------------:|
| Selection |    O(n^2)      |        O(n^2)    |       O(n^2)    |
|   Bubble  |    O(n^2)      |        O(n^2)    |       O(n^2)    |
|   Merge   |    O(n log(n)) |    O(n log(n))   |    O(n log(n))  |
|   Quick   |    O(n log(n)) |        O(n^2)    |    O(n log(n))  |
|    Heap   |    O(n log(n)) |    O(n log(n))   |    O(n log(n))  |

## Bubble Sort
The bubble sort algorithm goes through each element in the array and compares it with the next element in the array. If the first element is larger than the second, then you swap the two elements. This continues through the whole array until the largest element is at the end. Then you do the same with with every element excluding the last element since it must be the largest.   
Bubble sort has a constant time complexity of O(n^2). This is because for every element in an array, the algorithm loops through every element (up to the end or to the sorted part) comparing the current element with the next element in the array. Since n^2 is the dominant term, bubble sort has a time complexity of O(n^2).


## Selection Sort
The selection sort algorithm starts by storing the first element in the array as the largest element object. Then you compare the largest element object with every element in the array. If the current element is larger than the largest element object than the current element becomes the largest element object. This continues until you get to the end of the array. Once at the end of the array you swap the places of the last element and the largest element. The algorithm then continues the same process excluding the last element.   
This algorithm has advantages over the bubble sort because it does not swap as many elements, so it is less memory intensive.   
Selection sort has a constant time complexity of O(n^2). This is because for every element in the array you must loop through every element (up to the end or sorted part). Since n^2 is the dominant term, selection sort has a time complexity of O(n^2).

## Merge
The merge sort algorithm splits the array to sort in half as evenly as possible, then keeps splitting the sub-arrays in half until there is only 1 element in each sub-array. The algorithm then compares each adjacent sub-array, from the bottom up, and rebuilds the parent array by merging the sub-arrays in order. These merges continue until you are left with a sorted array.   
Merge sort has a constant time complexity of O(n log(n)). We can visualize this by looking at how the initial array will get broken down. The first sub-layer will contain two sub-arrays since the initial array was only split in half once. The second sub-layer will have four sub-arrays. This continues until you have n sub-arrays. Since the merge of every sub-layer takes O(n) time, merge sort will take O(nh) time where h is equal to the number of sub-layers. However, it would be more useful for us to express h in terms of n. We know that the number of sub-arrays doubles for every layer deeper you do, which means we can derive this equation: n = 2^h. When solving for h we get: h = log<sub>2</sub>(n). Finally, h can be subbed for log(n) in the initial equation giving us O(n log(n)).
