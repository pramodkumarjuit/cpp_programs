#include<iostream>
#include<queue> // for priority_queue    
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm> // std::max_element()

using namespace std;
#if 1 // linked list
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for the min-heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap: smallest value at the top
    }
};

ListNode* mergeKSortedLists(std::vector<ListNode*>& lists) {
    // Min-heap to store the current heads of the k linked lists
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

    // Push the head of each non-empty list into the min-heap
    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    // Dummy node to simplify list merging
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Merge the lists
    while (!minHeap.empty()) {
        // Get the smallest node from the heap
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        // Add the smallest node to the merged list
        current->next = smallest;
        current = current->next;

        // If there are more nodes in the same list, push the next node into the heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    // Return the head of the merged list
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    // Example input: k sorted lists
    std::vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    // Merge k sorted lists
    ListNode* mergedList = mergeKSortedLists(lists);

    // Output the merged list
    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

# else // vector
int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> nums2 = {21,22,23,24,25,26,27,28,29,210};
    vector<int> nums3 = {31,32,33,34,35,36,37,38,39,310};
    cout << "Input1:" << endl;
    for(auto &e : nums1) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Input2:" << endl;
    for(auto &e : nums2) {
        cout << e << " ";
    }
    cout << endl;
    cout << "Input3:" << endl;
    for(auto &e : nums3) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> merged;
    priority_queue<int, vector<int>, greater<int>> minHeap; // min at top
    for (auto &e: nums1) {
        minHeap.push(e);
    }
    for (auto &e: nums2) {
        minHeap.push(e);
    }
    for (auto &e: nums3) {
        minHeap.push(e);
    }

    while(!minHeap.empty()) {
        merged.push_back(minHeap.top());
        minHeap.pop();
    }

    cout << "output:" << endl;
    for(auto &e : merged) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
#endif
