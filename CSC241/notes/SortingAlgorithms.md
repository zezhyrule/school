NOTES - 2016/11/01

Chapter 10 - Algorithm Efficiency and Sorting

##Analysis of Algorithms

Order of Magnitude: a measure of the complexity of an algorithm. Either a
measure of the amount of work or the space requirements for a particular
algorithm. A function of the number of data items, usually referred to as n.
Represented as O(n) or big O notation. 

Why algorithms and not programs? Algorithms may be coded differently. With
programs, you wind up comparing implementations rather than algorithms. The
computer you use may cause variation is speed. Data used also effects the
algorithm.

An algorithm's time requirements can be measured as a function of the problem
size. An algorithm's growth rate enables the comparison of one algorithm with
another. Algorithm efficiency is typically a concern for large problems only.

_pg. 510_ Definition of the order of an algorithm.

Algorithm A is order f(n) - denoted O(f(n)) if constants k and n sub O exist
such that A requires no more than k * f(n) time units to solve a problem of size
n >= n sub O.

## Time and Space Complexity

An algorithm can be analyzed in terms of the amount of time it takes to execute
and/or the amount of storage it will take. Growth Rate Functions are defined on
_pg. 513_. Constant complexity is an algorithm that runs at a constant amount of
time, regardless of the number of data items. Logarithmic time, linear time,
polynomial time, and  exponential time are other types. Visual representations
of the comparison between these types of algorithms are also in the textbook. On
_pg. 511_ gives the order of growth. 

Properties of growth-rate functions: you can ignore low-order terms and you can
ignore a multiplicative constant in the high-order term. O(f(n)) + O(g(n)) =
O(f(n) + g(n)).

## Order-of-Magnitude Analysis and Big O Notation

An algorithm can require different times to solve different problems of the same
size. Worst-case analysis is a determination of the maximum amount of time that
an algorithm requires to solve problems of size n. Average-case is the average
amount of time.

Throughout the course of analysis, keep in mind that you are interested only in
significant differences in efficiency. When choosing an ADT's implementation,
consider how frequently particular ADT operations occur in a given application.
Some seldom-used but critical operations must be efficient.

If the problem size is always small, you can probably ignore an algorithm's
efficiency.  Weigh the trade-offs between an algorithm's time requirements and
its memory requirements. Compare algorithms for both style and efficiency.

Sequential search
Binary search

## Sorting Algorithms and Their Efficiency

Sorting is a process that organizes a collection of data into either ascending
or descending order. Categories of sorting algorithms include an internal sort,
which requires that the collection of data fit entirely in the computer's main
memory, and an external sort, in which the collection of data will not fit in
the computer's main memory all at once but must reside in secondary storage.

*Selection Sort* - Strategy: select the largest item and put it in its correct
place by swapping it with the item where it should be. Then select the next
largest item and put it in its correct place.

Finding the largest executes a total of (n-1) + (n-2) + ... + 1 which is equal
to n * (n-1)/2 times. There are (n-1) swaps, each requiring 3 moves. So we have
n * (n-1)/2 + 3*(n-1) = (n^2)/2 + 5 * n/2 - 3

O(n^2) algorithm. O(n) data moves. In place sort.

*Bubble Sort* - Strategy: compare adjacent elements and exchange them if they
are out of order. Comparing the first two elements, the second and third
elements, and so on, will move the largest (or smallest) elements to the end of
the array. Repeating this process will eventually sort the array into ascending
(or descending) order.

Pass i requires n-i comparisions and at most n-i exchanges. Worst case, # of
comparios and # of exchanges: n*(n-1)/2. Each exchange requires 3 moves. Worst
case in O(n^2). Best case is O(n). In place sort.

*Insertion Sort* - Strategy: partition the array into two regions: sorted
section and unsorted section. Take the item from the unsorted region and insert
it into its correct order in the sorted region.

Same as other two, O(n^2), in place sort.

*Radix Sort* - Also called a bin sort or pocket sort. Two phases for each digit
or character: distribution phase and collection phase. Distribute based on
rightmost digit and then collect out into new queue in queue order. Repeat with
the next rightmost digit and so on. n moves to distribute, n moves to collect.
Phases occur d number of times (number of digits). 2 * n * d. O(n) algorithm.
Not an in-place sort. "Pockets" required.

*Mergesort* - Important divide-and-conquer sorting algorithm. It's recursive,
and gives the same performance, regardless of the initial order of the array
items. Strategy: divide array into halves, sort each half, merge into one array.

Worst case: O(n * log2n). Advantage is it's extremely efficient algorithm with
respect to time. Drawback: requires second array of same size as original.

*Quick Sort* - Most efficient when the sublists are as nearly balanced in size
as possible. Strategy: partition an array into items that are less than the
pivot and those that are greater than or equal to the pivot. Sort the left
section, sort the right section. Choose an element a from a specific position
in the list called the pivot point. Place it in position j. Worst case is O(n^2)
and average case is O(n*log2n). 

## Summary

Order-of-Magnitude analysis and Big O notation measure an algorithm's time
requirement as a function of the problem size by using a growth-rate function.
To compare the inherit efficiency of algorithms, examine their growth-rate
functions when the problems are large. Consider only significant differences in
growth-rate functions. Worst-case analysis considers the maximum amount of work
an algorithm requires on a problem of a given size. Average-case analysis
considers the expected amount of work an algorithm requires on a problem of
given size. Order-of-magnitude analysis can be used to choose an implementation
for an ADT. Selection sort, bubble sort, and insertion sort are all O(n^2)
algorithms. Quicksort and mergesort are two very efficient sorting algorithms.
