// Good one 👍 Let’s keep it simple and clear.

// ---

// ## 🌲 **Binary Search Tree (BST)**

// A **Binary Search Tree** is a **special type of binary tree** with the following properties:

// 1. Each node has at most **two children** (left and right).
// 2. **Left subtree** contains only nodes with values **less than the parent node**.
// 3. **Right subtree** contains only nodes with values **greater than the parent node**.
// 4. This property holds **recursively** for every node in the tree.
// 5. Usually, **no duplicates** are allowed (depends on implementation).

// ---

// ### ✅ Example of a BST

// ```
//         10
//        /  \
//       5    20
//      / \   / \
//     3   7 15  30
// ```

// * Left of 10 → all smaller (5, 3, 7)
// * Right of 10 → all larger (20, 15, 30)
// * This pattern continues for every node.

// ---

// ### ⚡ Why is BST important?

// * **Searching**: Average O(log n) (like binary search).
// * **Insertion/Deletion**: Also O(log n) average.
// * **Traversal (Inorder)**: Gives elements in **sorted order**.

// ---

// ### ❌ Example of NOT a BST

// ```
//         10
//        /  \
//       20   5
// ```

// * Here, left child (20) is greater than root (10) → ❌ violates BST rule.

// ---

// 👉 In short:
// **A BST is a binary tree where each node’s left subtree has smaller values, and the right subtree has larger values, making searching efficient.**

// ---

// Do you want me to also show you the **basic operations (insert, search, delete)** in **C++ code** for a BST? That way you can directly practice.
