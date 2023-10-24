/**
 * File: preorder_traversal_i_compact.c
 * Created Time: 2023-05-10
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

struct Result {
    TreeNode **data;
    int dataSize;
};

typedef struct Result Result;

Result *newResult() {
    Result *p = malloc(sizeof(Result));
    p->data = NULL;
    p->dataSize = 0;
    return p;
}

void delResult(Result *res) {
    for (int i = 0; i < res->dataSize; i++) {
        free(res->data[i]);
    }
    free(res);
}

void printResult(Result *res) {
    for (int i = 0; i < res->dataSize; i++) {
        printf("%d ", res->data[i]->val);
    }
    printf("\n");
}

Result *res;

/* 前序遍历：例题一 */
void preOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    if (root->val == 7) {
        // 记录解
        res->data = realloc(res->data, (res->dataSize + 1) * sizeof(TreeNode *));
        res->data[res->dataSize++] = root;
    }
    preOrder(root->left);
    preOrder(root->right);
}

/* Driver Code */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    res = newResult();
    TreeNode *root = arrToTree(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\n初始化二叉树\r\n");
    printTree(root);

    // 前序遍历
    preOrder(root);

    printf("\n输出所有值为 7 的节点\r\n");
    printResult(res);
    delResult(res);
}