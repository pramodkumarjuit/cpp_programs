List of utility functions and algorithms in the C++ Standard Library that can be
used to work with std::vector and other container types.
-------------------------------------------------------------------------------



# 1. Sorting and Permutations
- std::sort: Sorts the elements in a range.
- std::stable_sort: Sorts the elements in a range while preserving the relative order of equivalent elements.
- std::partial_sort: Partially sorts the elements in a range.
- std::nth_element: Rearranges the elements in such a way that the element at the nth position is the element that would be in that position in a sorted sequence.
- std::is_sorted: Checks if a range is sorted.
- std::next_permutation: Generates the next lexicographical permutation of the range.
- std::prev_permutation: Generates the previous lexicographical permutation of the range.

# 2. Searching and Counting
- std::find: Finds the first element in a range that matches a value.
- std::find_if: Finds the first element in a range that satisfies a predicate.
- std::find_if_not: Finds the first element in a range that does not satisfy a predicate.
- std::count: Counts the occurrences of a value in a range.
- std::count_if: Counts the occurrences of elements that satisfy a predicate in a range.
- std::binary_search: Checks if a value exists in a sorted range.
- std::lower_bound: Finds the first position where a value could be inserted to maintain order.
- std::upper_bound: Finds the last position where a value could be inserted to maintain order.
- std::equal_range: Returns the range of elements equal to a given value in a sorted range.

# 3. Modifying Operations
- std::reverse: Reverses the order of elements in a range.
- std::rotate: Rotates the elements in a range to the left.
- std::replace: Replaces all occurrences of a value in a range with another value.
- std::replace_if: Replaces all elements satisfying a predicate in a range with another value.
- std::fill: Fills a range with a specified value.
- std::generate: Assigns the result of a generator function to each element in a range.
- std::transform: Applies a function to a range and stores the result in another range.
- std::remove: Removes elements equal to a value (logically).
- std::remove_if: Removes elements that satisfy a predicate (logically).
- std::unique: Removes consecutive duplicate elements in a range.

# 4. Mathematical Operations
- std::accumulate: Computes the sum of elements in a range.
- std::inner_product: Computes the inner product of two ranges.
- std::adjacent_difference: Computes the difference between adjacent elements in a range.
- std::partial_sum: Computes the partial sum of elements in a range.

# 5. Min/Max Operations
- std::min: Returns the smaller of two values.
- std::max: Returns the larger of two values.
- std::min_element: Returns an iterator to the smallest element in a range.
- std::max_element: Returns an iterator to the largest element in a range.
- std::minmax_element: Returns a pair of iterators to the smallest and largest elements in a range.

# 6. Set Operations
- std::set_union: Computes the union of two sorted ranges.
- std::set_intersection: Computes the intersection of two sorted ranges.
- std::set_difference: Computes the difference between two sorted ranges.
- std::set_symmetric_difference: Computes the symmetric difference between two sorted ranges.
- std::includes: Checks if one range is a subset of another.

# 7. Heap Operations
- std::make_heap: Converts a range into a heap.
- std::push_heap: Adds an element to the heap.
- std::pop_heap: Removes the largest element from the heap.
- std::sort_heap: Sorts a heap into a sorted range.
- std::is_heap: Checks if a range is a heap.
- std::is_heap_until: Finds the largest subrange that is a heap.

# 8. Partitioning
- std::partition: Reorders the elements in a range so that elements for which the predicate returns true precede those for which it returns false.
- std::stable_partition: Same as std::partition, but preserves the relative order of the elements.
- std::is_partitioned: Checks if a range is partitioned according to a predicate.
- std::partition_point: Finds the partition point in a partitioned range.

# 9. Utility Functions
- std::swap: Swaps two elements.
- std::swap_ranges: Swaps the elements in two ranges.
- std::copy: Copies a range to another range.
- std::copy_if: Copies elements that satisfy a predicate to another range.
- std::move: Moves a range to another range.
- std::fill_n: Fills the first n elements in a range with a specified value.
- std::equal: Compares two ranges for equality.
- std::lexicographical_compare: Compares two ranges lexicographically.
- std::for_each: Applies a function to each element in a range.

# 10. Randomization
- std::shuffle: Randomly shuffles the elements in a range.
- std::random_shuffle (deprecated in C++14 and removed in C++17): Randomly shuffles elements in a range.

# 11. Merge
- std::merge(): assumes that both inpuits (vectors/list/array ec.) are already sorted.
