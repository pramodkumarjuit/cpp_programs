- Maximum Depth of Binary Tree:  Easy
- Same Tree: Easy
- Invert Binary Tree: Easy
- Symmetric Tree: Easy
- Construct Binary Tree from Preorder and Inorder Traversal: Medium
- Construct Binary Tree from Inorder and Postorder Traversal: Medium
- Populating Next Right Pointers in Each Node II : Medium
- Flatten Binary Tree to Linked List: Medium
- Path Sum: Easy
- Sum Root to Leaf Numbers: Medium
- Binary Tree Maximum Path Sum: Hard
- Binary Search Tree Iterator: Medium
- Count Complete Tree Nodes: Easy
- Lowest Common Ancestor of a Binary Tree: Medium


| DFS Traversal | What it means (for a node `N`)     | Example Order | Underlying Search Method
| ------------- | ---------------------------------- | ------------- |------------------------
| **Preorder**  | Visit `N` → then left → then right | N → L → R     |     DFS
| **Inorder**   | Visit left → `N` → then right      | L → N → R     |     DFS
| **Postorder** | Visit left → right → then `N`      | L → R → N     |     DFS


 * Notes:
 *  - Search Techniques: DFS & BFS
 *  - Traversal types: preorder, inorder, postorder. Only defined for DFS, not BFS.
 *  - DFS: uses stack / recursion
 *  - BFS: uses Queue
 *  ===============================================================================
 *  DFS : suitable/preferred for finding max depth a binary tree due to simple
 *        implementation and less memory usage O(h)stack(h), height of tree
 *  ===============================================================================
 *  BFS can also be used for finding max depth a binary tree but code is simple (needs loop)
 *  and memory usage O(w)queue(w)
 *  Rule of Thumb:
 *  - Choose BFS when the problem involves levels, shortest paths, or minimal steps.
 *  - Choose DFS when the problem requires exploring all paths, backtracking, or subtree-level operations.
 *
 *  Common BFS Use Cases:
 *      Minimum depth of binary tree
 *      Shortest path in unweighted graph
 *      Level-order traversal
 *      Word ladder, knight’s shortest path
 *
 * Common DFS Use Cases:
 *      Maximum depth of tree
 *      Binary tree traversals (pre/in/post)
 *      Subset/combinations/backtracking
 *      Topological sort
 *      Maze solving (all paths) 
 *

# A perfect Binary Tree (root at level 0) - Space complexity for BFS
    - Every internal node has exactly 2 children.
    - All leaf nodes are at the same depth.
    - The tree is completely filled.

        1               <-- Level 0 (1 node)
      /   \
     2     3           <-- Level 1 (2 nodes)
    / \   / \
   4   5 6   7         <-- Level 2 (4 nodes)

For a perfect binary tree of height h (root at height 0), the number of nodes is:
    n = 2^(h+1) - 1
In the above example tree:
- Total nodes n = 1 + 2 + 4 = 7
- Nodes in last level = 4
- n/2 = 7/2 ≈ 3.5, so about half of the nodes are in the last level.

So, BFS typically has O(n) space complexity due to the queue, which at worst can
hold up to half the nodes in a perfect binary tree (especially when processing the last level).

# A perfect Binary Tree (root at level 0) - Space complexity for DFS
- DFS (recursive or iterative), and only using a stack (explicit or implicit via recursion), then:
  Space complexity = O(h), where h is the height (or depth) of the tree.
- In a balanced binary tree, height h ≈ log₂(n)
- So, space complexity = O(log n) !!! Ex: for above tree, height = 2 (root is level 0) & max stack depth = 3 → O(log 7) ≈ O(3)
