# Sorting Algorithms Test
## This is for a school project.   
This project includes implementations for the selection, bubble, merge, heap and merge sort algorithms. I have tested the performance of every algorithm, and later in the README I will explain the time complexity for each of the algorithms individually.

| Algorithm | Time (s) [400,000] | Time (s) [100,000] | Time (s) [10,000] | Time (s) [1,000] |
| --------- | :-----------------:|:------------------:|:-----------------:|:-------------------:|
| Selection |    359   | 23.70   |   0.25    |   0.0028  |
|   Bubble  |    1018  |   58.67 |   0.39    |   0.0042  |   
|   Merge   |    0.13  |   0.034 |   0.0029  |   0.00030 |
|   Quick   |    0.18  | 0.029   |   0.0025  |   0.00019 | 
|    Heap   |   0.23   | 0.049   |   0.0045  |  0.00045  |

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

## Quick Sort
The quick sort algorithm starts by selecting a pivot point in the middle of the array, moving all the numbers greater than the pivot to the right of the pivot and all number less than it to the left. The same process occurs on the sub-array left of the pivot, and the sub-array right of the pivot.   
   
Quick sort has an average time complexity of O(n log(n)). This is because on average you will pick a pivot that will split the array right in half. This also happens to be the best case. When you split the array right in half it means that the sub-array are of equal size, and this means you only have to split the array h number of times. On the final level there would be 2^h sub-arrays which also happen to be n. So 2^h = n or log<sub>2</sub>(n) = h. Since the time total time to complete the algorithm would be O(nh) we can use the new formula for h and get O(n log(n)).   
   
However, quick sort is interesting because in the worst case it will have a time complexity of (O^2). This is because in the worst case the pivot will either be the largest value or smallest value in the array. If the largest or smallest value is the pivot in the first iteration then one sub-array will have n-1 elements and the other sub-array will only have 1 element. If this happens all the way through the algorithm then it will take n levels to sort the algorithm. In that case it would take the algorithm O((n)(n)) or O(n^2) time to complete.

## Heap Sort
To understand how heap sort works, you must first understand the heap data structure. A heap, or more specifically max heap in this case, is a data structure that can be represented as a tree of nodes. Each node has a maximum of two children that are smaller than the parent. A max heap could look like the following:      
&emsp;&nbsp;12   
&emsp;&nbsp;/  \   
&nbsp;&nbsp;&nbsp;8    10   
&nbsp;&nbsp;&nbsp;/ \  /  \   
&nbsp;2   4 5   6   
However, a heap can also be represented as an array. The heap above would look like the following as an array: `{[12],[8],[10],[2],[4],[5],[6]}`. The root node is at the start and it's children are below that. Then the children of those nodes follow. Since the largest number is always at the start of the array, heap sort moves the root node to the end, rebuilds the heap and repeats to sort the array.   
   
The heapify algorithm turns a unsorted array into a heap. This algorithm works from the bottom of the heap upwards and checks to make sure each parent child relationship is valid. Every time the size of the array doubles there is only one more layer added. This means that n = 2^h or h = log<sub>2</sub>(n). Since the heapify algorithm runs n times the time complexity is O(nh) or O(n log(n)).
