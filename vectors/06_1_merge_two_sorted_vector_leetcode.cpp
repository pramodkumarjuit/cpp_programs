/* 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and
 * two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *
 * -------------------------------------------------------------------------
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * -------------------------------------------------------------------------
 * The final sorted array should not be returned by the function, but instead be stored inside
 * the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements
 * denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.
 * nums2 has a length of n.
 */

// num1 has already extra space

/**************************************************************
 * Time Complexity of : mergeSortedVector()
 *                      O(m+n)
 * Note: With vector num1,num2; std::copy() & std::sort()
 *       can be used but it will result into O((m+n)log(m+n))
 ***************************************************************/
#include<iostream>

using namespace std;

void mergeSortedVector(int num1[], int num2[], int m, int n)
{
    // indices
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    // in-place copy: compare last element of num1 with last element of num2....
    while(i>=0 && j>=0) {
        if (num1[i] > num2[j]) {
            num1[k--] = num1[i--];
        } else {
            num1[k--] = num2[j--];
        }
    }

    // num2 has still left something copy them
    while(j>=0) {
        num1[k--] = num2[j--];
    }
}


int main(int argc, char *argv[])
{
    //vector<int> vec1 = {1, 2, 3, 4, 5, 0, 0, 0, 0};
    //vector<int> vec2 = {6, 7, 8, 9};
    int vec1[] = {1, 2, 3, 4, 5, 0, 0, 0, 0};
    int vec2[] = {11, 12, 13, 14};
    int m = 5;
    int n = 4;

    cout << "First vector:\n";
    for(int i = 0; i <m; i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;


    cout << "Second vector:\n";
    for(int i = 0; i <n; i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    mergeSortedVector(vec1, vec2, m, n);

    cout << "After merge :\n";
    for(int i = 0; i <m+n; i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    return 0;
}
