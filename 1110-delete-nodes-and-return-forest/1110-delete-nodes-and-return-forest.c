/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool toDelete(int value, int* to_delete, int to_deleteSize) {
    for (int i = 0; i < to_deleteSize; i++) {
        if (to_delete[i] == value) {
            return true;
        }
    }
    return false;
}

// Recursive function to process each node
struct TreeNode* processNode(struct TreeNode* node, int* to_delete, int to_deleteSize, struct TreeNode** result, int* returnSize, bool isRoot) {
    if (node == NULL) {
        return NULL;
    }

    // Check if this node needs to be deleted
    bool deleted = toDelete(node->val, to_delete, to_deleteSize);

    // If this is a root node (or a new root due to a deletion) and is not deleted, add to result
    if (isRoot && !deleted) {
        result[(*returnSize)++] = node;
    }

    // Recursively process the left and right children
    node->left = processNode(node->left, to_delete, to_deleteSize, result, returnSize, deleted);
    node->right = processNode(node->right, to_delete, to_deleteSize, result, returnSize, deleted);

    // If this node is deleted, return NULL to the parent
    return deleted ? NULL : node;
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    *returnSize = 0;

    // Allocate space for the result array (maximum possible size is the number of nodes in the tree)
    // In the worst case, each node can become a separate tree, so we need to allocate space for
    // each node in the tree.
    int maxNodes = 1000; // This should be the maximum number of nodes in the tree
    struct TreeNode** result = (struct TreeNode**) malloc(maxNodes * sizeof(struct TreeNode*));

    // Process the tree
    processNode(root, to_delete, to_deleteSize, result, returnSize, true);

    return result;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to free the memory of the tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Helper function to print the tree in-order
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}