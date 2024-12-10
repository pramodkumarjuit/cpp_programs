Notes:
- Heap based question uses priority_queue data structure.

- A priority queue is a container in C++ (part of the <queue> library) that provides
  a way to access elements in sorted order based on priority. By default, it
  functions as a max-heap (the largest element is on top), but it can be customized for
  mean-heap as well.

  template <
    class T,                      // Type of the elements (e.g., int, float, custom class)
    class Container = vector<T>,  // The underlying container to store elements (default: std::vector<T>)
    class Compare = less<typename Container::value_type> // The comparator for ordering (defaultis std::less that max heap) # std::greate for min heap
> class priority_queue;

- The name refers to the type of element at the top of the heap. 
  Max-heap: [DEAFULT] The largest element at top.
  Min-heap: The smallest element at top.

- Automatic Sorting: Elements are ordered automatically.

- The top() function gives the highest priority element.

- insertion and removal of the top element happen in O(logn) time.

- understanding of when to use min-heaps vs. max-heaps is essential.

- Normal heap based questions sorting-like problems or maintaining top elements.

List of questions:
-----------------
1. Find the k Largest Elements in an Array.
   Problem: Given an integer array nums and an integer k, return the k largest elements in the array.
   Concept: Use a min-heap of size

2. Merge k Sorted Lists
   Problem: You are given k sorted linked lists, each with its head node.
            Merge all the linked lists into one sorted linked list and return its head.
   Concept: Use a min-heap (priority queue) to efficiently merge lists by always picking
            the smallest current node.
   Time Complexity: O(Nlogk) ; where N is the total number of nodes.

3. Top k Frequent Elements
   Problem: Given an array of integers nums and an integer k, return the k most frequent elements.
   Concept: Use a frequency map to count occurrences and a min-heap of size k to keep track of the
            top frequent elements.
   Time Complexity: O(nlogk), where n is the size of the array.

4. Median of a Data Stream
   Problem: Design a data structure that efficiently supports adding a number and finding the median of the numbers so far.
   Concept: Use two heaps:
            - A max-heap for the smaller half of the numbers.
            - A min-heap for the larger half of the numbers.

   Time Complexity: O(logn) per operation.

5. Meeting Rooms II
   Problem: Given an array of meeting time intervals, find the minimum number of meeting rooms required.
   Concept: Use a min-heap to track the end times of meetings. Allocate a new room if the current meeting's
            start time is earlier than the earliest ending meeting.

   Time Complexity: O(nlogn), where n is the number of meetings.
