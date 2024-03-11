# analysis-and-design-of-algorithm

##  1.Practical 1 :- Selection sort analysis
ALGORITHM :  This practical  implements the selection sort algorithm. It iterates through the array, finds the minimum element in the unsorted part, and swaps it with the first element of the unsorted part. This process is repeated until the entire array is sorted.

GRAPH:import matplotlib.pyplot as plt

values = [
    (1000, 0),
    (3000, 4),
    (5000, 10),
    (7000,17),
    (9000, 29),
    (11000, 43),
    (13000,63),
    (15000,80),
    (17000,103),
    (19000,133)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')

plt.ylabel('Seconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![1_graph](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/078ae408-14ea-4fa0-8d0e-afd25de553ca)

TIME COMPLEXITY : The time complexity of the selection sort algorithm is O(n^2) in the worst case. This is because, for each element in the array, it performs a linear search through the remaining unsorted elements to find the minimum value and then swaps it. The nested loops contribute to the quadratic time complexity


## 2.PRACTICAL 2 :- SUM OF n NUMBERS

ALGORITHM : The algorithm used here is a straightforward summing of the elements in an array. The sum_numbers function iterates through each element of the array and accumulates the sum.

GRAPH:
import matplotlib.pyplot as plt

values = [
    (1000000,1621300),
    (1500000, 3539600),
    (2000000, 3340500),
    (2500000,4778800),
    (3000000, 5626300),
    (3500000,6389800),
    (4000000,6254900),
    (4500000,7175600),
    (5000000,9147300)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/86d69680-a869-4d6e-a40f-b7daf49ed5d6)

TIME COMPLEXITY: The time complexity of the summing operation is O(n), where 'n' is the number of elements in the array. The loop in the sum_numbers function iterates through each element once, resulting in linear time complexity

## 3.PRACTICAL 3 : TOWER OF HANOI

ALGORITHM: The Tower of Hanoi algorithm is a classical recursive problem. It follows the principles of divide and conquer. The idea is to move 'n' disks from the source peg to the target peg using an auxiliary peg. 

GRAPH: 
import matplotlib.pyplot as plt

values = [
    (18,6221318),
(19,2812452),
(20,10571623),
(21,27133626),
(22,49885788),
(23,110367291),
(24,232394370)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/d4c72d88-419a-4b59-aae5-be6fea176673)

TIME COMPLEXITY : The time complexity of the Tower of Hanoi algorithm is O(2^n), where 'n' is the number of disks. This is an exponential time complexity because, at each step, the problem is divided into two recursive subproblems.

## 4.PRACTICAL 4 : COIN PERMUTATION 

ALGORITHM : 
This function recursively generates all combinations of heads (1) and tails (0) for a given number of coin tosses. It starts with an array arr initialized to all zeros, and at each recursion level, it sets the current toss to heads (1) and recursively calls itself for the next toss. Then, it sets the current toss to tails (0) and recursively calls itself again. 
GRAPH: 
import matplotlib.pyplot as plt

values = [
    (10,0),
    (13, 0),
    (16, 1076300),
    (19,4862400),
    (22, 40249500)

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/b629443f-9640-4d4d-8019-8579d950ffb4)


TIME COMPLEXITY:
The time complexity of this code is exponential, specifically O(2^n), where 'n' is the number of coin tosses. This is because, at each toss, there are two possibilities (heads or tails), and the recursive function explores all possible combinations


## 5.PRACTICAL 5 : STRING PERMUTATION 
ALGORITHM :
This PRACRTICAL generates all permutations of a string using recursive backtracking. It swaps characters at different positions in the string to generate all possible arrangements. The base case is when the current position (k) reaches the end of the string (n).

GRAPH:
from math import radians
import numpy as np
import matplotlib.pyplot as plt

values = [
    (3,772),
    (5,7323),
    (7, 321847),
    (9,24059966),
    (11, 3517819827 )

]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/13e9befa-65dc-445a-95b1-da5df54926d3)


TIME COMPLEXITY :
The time complexity of generating all permutations of a string is O(n!), where 'n' is the length of the string. The recursive backtracking approach explores all possible arrangements, resulting in a factorial growth in the number of function calls.

## 6.PRACTICAL : P0WER FUNCTION

**1.brute approach**

ALGORITHM :
This practical implements a simple recursive algorithm to calculate the power of 'm' raised to the 'n'-th exponent. It uses the recursive property of exponentiation: m^n = m * m^(n-1).


TIME COMPLEXITY : 
The time complexity of this code is exponential, specifically O(2^n), where 'n' is the exponent. This is because, at each step of the recursion, the problem is divided into two subproblems. 

**2.optimal approach**


ALGORITHM : 
The algorithm uses a recursive approach to calculate the power of 'm' raised to the 'n'-th exponent. It takes advantage of the fact that if 'n' is even, the exponentiation can be expressed as the square of the power of 'm' raised to half of 'n'.

TIME COMPLEXITY:
The time complexity of this code is logarithmic, specifically O(log n), where 'n' is the exponent. The optimization for even exponents significantly reduces the number of recursive calls, making the algorithm more efficient compared to the naive recursive approach. 


GRAPH :
import matplotlib.pyplot as plt

values = [
(1000, 3812),

(3000, 16874),
(4000, 21663),
(5000, 30111),
(6000, 35862),
 (7000, 34181),
(8000, 38398),
(9000, 38409),
(10000, 42505)
]



comparison_values = [
(1000, 1200),
(2000, 6800),
(3000, 73000),
(4000, 73000),
(5000, 78000),
(6000, 78000),
(7000, 85000),
(8000, 77000),
(9000, 77000),
(10000, 78000)

]

x_values, y_values = zip(*values)

x_comparison, y_comparison = zip(*comparison_values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.plot(x_comparison, y_comparison, marker='s', linestyle='--', color='r', label='Comparison Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/15613a0b-cebd-41e3-9ba5-d8bfd94c92ab)


## 7.PRACTICAL 7 : QUICK SORT ANALYSIS
ALGORITHM:

This function implements the partition operation of the QuickSort algorithm. It selects a pivot element (here, the first element), rearranges the array elements such that elements smaller than the pivot come before it, and elements greater than the pivot come after it. The function returns the index of the pivot after partitioning.


GRAPH:

import matplotlib.pyplot as plt
values = [
(1000000,1696900),
(1050000,1686100),
(1100000,1684900),
(1150000,3296500),
(1200000,4991100),
(1250000,2151000),
(1300000,3353100),
(1350000,1521300),
(1400000,1686600),
(1450000,4773100),
(1500000,4853600),
(1550000,1779800),
(1600000,3417300),
(1650000,3400300),
(1700000,5020600),
(1750000,4903600),
(1800000,1844600),
(1850000,4775000),
(1900000,5095700),
(1950000,5274300),
(2000000,5364900),
(2050000,3545400),
(2100000,4806200),
(2150000,3327900),
(2200000,6712900),
(2250000,6795300),
(2300000,5184600),
(2350000,6869900),
(2400000,6330500),
(2450000,8046900),
(2500000,2835300),
(2550000,3538400),
(2600000,4965900),
(2650000,7992400),
(2700000,4161200),
(2750000,5046700),
(2800000,6562700),
(2850000,7407200),
(2900000,5851600),
(2950000,3715100),
(3000000,8400100),
(3050000,7181300),
(3100000,7896700),
(3150000,6677400),
(3200000,3344800),
(3250000,4868500),
(3300000,9109300),
(3350000,10471300),
(3400000,8252300),
(3450000,5106400),
(3500000,10910300),
(3550000,9309400),
(3600000,6824600),
(3650000,9708900),
(3700000,11761300),
(3750000,12322100),
(3800000,11688500),
(3850000,9776600),
(3900000,6657600),
(3950000,5005600),
(4000000,8805100),
(4050000,11371200),
(4100000,5006400),
(4150000,7384600),
(4200000,11356600),
(4250000,11255200),
(4300000,9176000),
(4350000,12974500),
(4400000,5132600),
(4450000,13116900),
(4500000,9576000),
(4550000,11330600),
(4600000,8623600),
(4650000,7965700),
(4700000,13249700),
(4750000,12945700),
(4800000,5385600),
(4850000,12718000),
(4900000,9598000),
(4950000,11166400),
(5000000,11564900),
(5050000,12917000),
(5100000,14487800),
(5150000,14178800),
(5200000,11157900),
(5250000,14533400),
(5300000,7546300),
(5350000,9108900),
(5400000,9802700),
(5450000,14265600),
(5500000,16550600),
(5550000,14201200),
(5600000,8042000),
(5650000,8005500),
(5700000,11188900),
(5750000,17218500),
(5800000,11221500),
(5850000,12525800),
(5900000,15737700),
(5950000,15811000),
(6000000,17404700),
(6050000,9617200),
(6100000,20719400),
(6150000,16508000),
(6200000,9596400),
(6250000,17433900),
(6300000,19645400),
(6350000,11054900),
(6400000,14489500),
(6450000,8042800),
(6500000,15990800),
(6550000,19967900),
(6600000,17399800),
(6650000,15992400),
(6700000,17424300),
(6750000,11031500),
(6800000,11133600),
(6850000,21053000),
(6900000,12482400),
(6950000,17874300),
(7000000,15645700),
(7050000,9538800),
(7100000,12735700),
(7150000,11131800)
]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/5f4fd052-e735-4832-84b0-8813af3bf381)


TIME COMPLEXITY:
The time complexity of the partition operation in the QuickSort algorithm is O(n), where 'n' is the size of the array being partitioned



## 8.PRACTICAL : MERGE SORT ANALYSIS

ALGORITHM:

This practical implements the merge sort algorithm recursively. It divides the array into two halves, sorts each half independently, and then merges the sorted halves.
GRAPH:
import matplotlib.pyplot as plt

values = [
    (100000, 400100),
 (120000, 799900),
  (140000, 700400),
  (160000, 699500),
  (180000, 900300),
  (200000, 1103200),
  (220000, 1201400),
  (240000, 1100600),
   (260000, 1401600),
  (280000, 1699600),
  (300000, 1500200),
  (320000, 1899700),
  (340000, 1798900),
  (360000, 1899700),
  (380000, 1899500),
  (400000, 2099700),
  (420000, 2302200),
  (440000, 2300400),
  (460000, 2800400),
   (480000, 3199800),
  (500000, 3397200)
  ]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/3eb0e5d6-cc31-4a5a-bdaf-f89ed27a28e6)


TIME COMPLEXITY:

The time complexity of the merge sort algorithm is O(n log n), where 'n' is the size of the array.


## 9. GENERATE MAGIC SQAURE 

ALGORITHM :

The Siamese method is a constructive algorithm for creating odd-order magic squares.
The main idea is to start from the central cell of the first row and fill the square by moving diagonally up and to the right.
If a move takes the position out of the matrix bounds, it wraps around to the opposite side.
If the cell is already occupied, move vertically down one position instead.


GRAPH:

import matplotlib.pyplot as plt

values = [
(3,00 ),
(5,00 ),
(7,00 ),
(9,10 ),
(11,20 ),
(13,20 ),
(15,30 ),
      
]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/e8986be6-e2dc-4e25-90be-3ec91fea579b)


TIME COMPLEXITY:
The time complexity of generating a magic square using the Siamese method is O(n^2), where 'n' is the order of the square.


## 10.MERGE SORT ALGORITHM 

ALGORITHM:

Merge sort is a divide-and-conquer algorithm that recursively divides the array into two halves, sorts each half, and then merges the sorted halves.
The merging step involves comparing and combining elements from two sorted arrays into a single sorted array.


GRAPH:
import matplotlib.pyplot as plt

values = [
(1000,472 ),
(2000,928 ),
(3000,1385 ),
(4000,1895 ),
(5000,2510 )
      
]

x_values, y_values = zip(*values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b')

plt.xlabel('Input Values')
plt.ylabel('NanoSeconds')
plt.title('Inputs Vs Time Graph')

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/b441c561-cc8a-471a-9b4d-1bb812ce00bc)


TIME COMPLEXITY:
The time complexity of the merge sort algorithm is O(n log n), where 'n' is the size of the array.


## 11.PRACTICAL 11 : QUICK SORT ANALYSIS

**AVERAGE CASE** 


ALGORITHM :

Quick Sort is a divide-and-conquer sorting algorithm.
It selects a pivot element from the array and partitions the other elements into two subarrays, according to whether they are less than or greater than the pivot.
The process is repeated recursively on the subarrays.

TIME COMPLEXITY:
The time complexity of the average case for Quick Sort is O(n log n), where 'n' is the size of the array.

**WORST CASE**    
 
 ALGORITHM:

Quick Sort is a divide-and-conquer sorting algorithm.
It selects a pivot element from the array and partitions the other elements into two subarrays, according to whether they are less than or greater than the pivot.
The process is repeated recursively on the subarrays.


TIME COMPLEXITY:
The worst-case time complexity of Quick Sort is O(n^2) when the input array is already sorted, and the pivot is consistently chosen as the smallest or largest element.

GRAPH:
import matplotlib.pyplot as plt

values = [
(500 , 0),
(1000 , 816100),
(1500 , 754800),
(2000 , 1180600),
(2500 , 1770300),
(3000 , 2074000),
(3500 , 3542700),
(4000 , 4711700),
(4500 , 5433500),
(5000 , 10442500)
]



comparison_values = [
(500 , 0),
(1000 , 342500),
(1500 , 505100),
(2000 , 1162300),
(2500 , 1955800),
(3000 , 3162800),
(3500 , 3745800),
(4000 , 4803900),
(4500 , 5266100),
(5000 , 6497600)

]

x_values, y_values = zip(*values)

x_comparison, y_comparison = zip(*comparison_values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.plot(x_comparison, y_comparison, marker='s', linestyle='--', color='r', label='Comparison Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/05ca6eb0-f889-4c0e-b790-e8abfa457ad7)


## 12. PRACTICAL 12 : FIND MAX-MIN 

ALGORITHM :

findMaxMinRecursive: Implements a recursive approach to find the maximum and minimum elements in the array within a specified range.The recursive approach follows a divide-and-conquer strategy. It divides the array into two halves, recursively finds the maximum and minimum in each half, and then combines the results.


findMaxMinIterative: Implements an iterative approach to find the maximum and minimum elements in the array.The iterative approach traverses the array once, keeping track of the maximum and minimum elements.


GRAPH:
import matplotlib.pyplot as plt

values = [
( 1000, 5811 ),
( 2000, 8220 ),
( 3000, 12349 ),
( 4000, 32460 ),
( 5000, 29640 ),
( 6000, 35400 ),
( 7000, 42500 ),
( 8000, 46580 ),
( 9000, 40790 ),
( 10000, 60110 )
]



comparison_values = [
( 1000, 5811 ),
( 2000, 8220 ),
( 3000, 12349 ),
( 4000, 32460 ),
( 5000, 29640 ),
( 6000, 35400 ),
( 7000, 42500 ),
( 8000, 46580 ),
( 9000, 40790 ),
( 10000, 60110 )

]

x_values, y_values = zip(*values)

x_comparison, y_comparison = zip(*comparison_values)

plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Original Line')

plt.plot(x_comparison, y_comparison, marker='s', linestyle='--', color='r', label='Comparison Line')

plt.xlabel('Input Values')
plt.ylabel('Seconds')

plt.title('Inputs Vs Time Graph')

plt.legend()

plt.show()
![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/5e9e537e-384f-4200-9892-9784a79b086b)



TIME COMPLEXITY:

Recursive Approach: The time complexity is O(n) due to the divide-and-conquer strategy, where 'n' is the size of the array.
Iterative Approach: The time complexity is also O(n) as it traverses the array once.


## 13. PRACTICAL 13 : KNAPSACK PROBLEM 

ALGORITHM:

The Knapsack problem is solved using dynamic programming. The knapsack function initializes a 2D array (dp) to store the maximum profit achievable for different weights and items. It then iteratively fills the array, considering each item and its weight in different scenarios.
The compareByWeight, compareByProfit, and compareByRatio functions are used to sort the items based on weight, profit, and profit-to-weight ratio, respectively.


GRAPH:
import matplotlib.pyplot as plt

input_sizes = [10, 50, 100, 200, 500]
time_weight = [10750, 68210, 276650, 880390, 5159290]  # Replace these values with your actual data
time_profit = [6940, 67530, 282020, 782469, 5568139]  # Replace these values with your actual data
time_ratio = [5760, 65230, 253610, 983030, 5468410]   # Replace these values with your actual data


plt.figure(figsize=(10, 6))
plt.plot(input_sizes, time_weight, marker='o', label='Time (Weight)')
plt.plot(input_sizes, time_profit, marker='o', label='Time (Profit)')
plt.plot(input_sizes, time_ratio, marker='o', label='Time (Ratio)')

plt.xlabel('Input Size')
plt.ylabel('Time (ns)')
plt.title('Knapsack Algorithm Comparison')
plt.legend()


plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/171aee04-4f39-47c7-b212-355fb907816f)


TIME COMPLEXITY:

The time complexity of the Knapsack problem solution is O(n * W), where 'n' is the number of items and 'W' is the capacity of the knapsack.
Sorting the items takes O(n * log(n)) time.
For each strategy, the overall time complexity is dominated by the sorting step.


## 14. PRACTICAL 14 : ACTIVITY SELECTION PROBLEM 

ALGORITHM :

The greedy algorithm selects activities based on their finish time.
It sorts the activities in ascending order of finish time.
It iterates through the sorted activities, selecting the first non-overlapping activity at each step.

GRAPH:

import matplotlib.pyplot as plt

(input size vs execution time in seconds)
input_sizes = [10, 20, 30, 40, 50]
execution_times = [2.1e-05, 1.7e-05, 2.4e-05, 2.6e-05, 4.6e-05] \

execution_times_ns = [time * 1e9 for time in execution_times]

plt.plot(input_sizes, execution_times_ns, marker='o', linestyle='-', color='b')
plt.title('Input Size vs Execution Time')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.grid(True)
plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/6b305ea2-fbe9-4520-b60c-439bc24e70f8)



TIME COMPLEXITY:

Sorting the activities: O(n log n), where 'n' is the number of activities.
Iterating through the sorted activities: O(n).
Overall time complexity: O(n log n).

## 15. PRACTICAL 15 : BINARY SEARCH ANALYSIS

ALGORITHM :

Binary search is an efficient algorithm for finding an element in a sorted array.
It repeatedly divides the search interval in half, comparing the target element to the middle element of the interval.
If the target element is equal to the middle element, the search is successful.
If the target is less than the middle element, the search continues in the lower half; otherwise, it continues in the upper half.
The process repeats until the target is found or the interval is empty.


GRAPH:
import matplotlib.pyplot as plt
 (input size vs execution time in seconds)
input_sizes = [1000, 5000, 10000, 50000, 100000]
best_case_times = [6e-06, 2e-06, 1e-06, 3e-06, 2e-06]  # Replace with your actual data
worst_case_times = [1e-06, 1e-06, 1e-06, 0, 1e-06]  # Replace with your actual data

best_case_times_ns = [time * 1e9 for time in best_case_times]
worst_case_times_ns = [time * 1e9 for time in worst_case_times]

plt.plot(input_sizes, best_case_times_ns, label='Best Case', marker='o', linestyle='-', color='b')

plt.plot(input_sizes, worst_case_times_ns, label='Worst Case', marker='s', linestyle='-', color='r')

plt.title('Input Size vs Execution Time (Binary Search)')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.legend()
plt.grid(True)

plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/9204131b-3066-447d-97da-57a4f11691c9)

TIME COMPLEXITY:


Best Case: O(1) - Occurs when the target is found in the middle in the first comparison.
Worst Case: O(log n) - Occurs when the target is not present, and the search space is halved at each step.
Average Case: O(log n) - Same as the worst case.

## 16. PRACTICAL 16 : ITERATIVE QUICK SORT

ALGORITHM:

The QuickSort algorithm sorts an array by selecting a pivot element, partitioning the other elements into two subarrays, and then recursively sorting the subarrays.
The iterative version uses a stack to manage the partitioning process without using recursion.


GRAPH:

import matplotlib.pyplot as plt
(input size vs execution time in seconds)
input_sizes = [1000, 5000, 10000, 50000, 100000]
execution_times = [0.000273, 0.001751, 0.004481, 0.042268, 0.141558]  # Replace with your actual data

execution_times_ns = [time * 1e9 for time in execution_times]

plt.plot(input_sizes, execution_times_ns, marker='o', linestyle='-', color='b')
plt.title('Input Size vs Execution Time (Iterative QuickSort)')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.grid(True)
plt.show()

![image](https://github.com/arin2107/analysis-and-design-of-algorithm/assets/121510816/a8007c08-3976-4ce1-98ab-2a58c54a4e33)


TIME COMPLEXITY:
Average Time Complexity: O(n log n)
Worst-Case Time Complexity: O(n^2) (uncommon with good pivot selection strategies)
The iterative version maintains the average time complexity of O(n log n) but avoids the function call overhead of recursion.


## 17.PRACTICAL 17 : PRIM'S ALGORITHM

ALGORITHM:

Prim's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph.
It starts with an arbitrary node and grows the MST one vertex at a time by adding the shortest edge that connects a vertex in the MST to a vertex outside the MST.
The process continues until all vertices are included in the MST


TIME COMPLEXITY:

In this implementation, a priority queue is used, and the overall time complexity is O((V + E) log V).


## 18.PRACTICAL 18 : DIJAKSTRA ALGORITHM 

ALGORITHM :

Dijkstra's algorithm is a greedy algorithm used for finding the single-source shortest paths in a weighted graph with non-negative weights.
It starts with an empty set of vertices and repeatedly selects the vertex with the minimum distance from the source, adding it to the set.
The algorithm then updates the distance values of the neighboring vertices based on the newly added vertex.
This process continues until all vertices are included in the set, and the algorithm finds the shortest paths from the source to all other vertices.



TIME COMPLEXITY :

In this implementation, an adjacency matrix is used, and the overall time complexity is O(V^2).


## 19.PRACTICAL 19 : CYCLE DETECTION

ALGORITHM:

The algorithm uses the Union-Find algorithm for detecting cycles in an undirected graph. It employs the concept of connected components and checks whether adding an edge forms a cycle by examining the roots of the vertices involved

TIME COMPLEXITY : 

The time complexity of the Union-Find operations (find and unionSets) is generally considered close to O(1) on average.
The isCyclic method iterates through all edges once, performing Union-Find operations. In the worst case, the time complexity is O(V + E * α(V)), where V is the number of vertices, E is the number of edges, and α is the inverse Ackermann function


## 20.PRACTICAL 20: KRUSKAL ALGORITHM

ALGORITHM: 

Kruskal's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected, undirected graph.
It works by sorting the edges in non-decreasing order of weight and adding each edge to the MST as long as it does not form a cycle.
The Disjoint-Set data structure is used to efficiently check whether adding an edge creates a cycle

TIME COMPLEXITY:

The time complexity of Kruskal's algorithm is dominated by the sorting step, which has a time complexity of O(E log E), where E is the number of edges.
The Union-Find operations (finding and merging) take nearly constant time on average.
Overall, the time complexity of the entire algorithm is O(E log E).

