/**
 * File: preorder_traversal_iii_compact.c
 * Created Time: 2023-06-04
 * Author: Gonglja (glj0@outlook.com)
 */
#include "../utils/common.h"

#define MAX_PATH_SIZE 1000
#define MAX_PATH_LEN  100

TreeNode *path[MAX_PATH_LEN];
int pathSize = 0;

TreeNode *res[MAX_PATH_SIZE][MAX_PATH_LEN];
int resSize[MAX_PATH_SIZE];
int resIdx = 0;

/* 前序遍历：例题三 */
void preOrder(TreeNode *root) {
    // 剪枝
    if (root == NULL || root->val == 3) {
        return;
    }
    // 尝试
    path[pathSize++] = root;

    if (root->val == 7) {
        // 记录解
        for (int i = 0; i < pathSize; i++) {
            res[resIdx][i] = path[i];
        }
        resSize[resIdx] = pathSize;
        resIdx++;
    }

    preOrder(root->left);
    preOrder(root->right);

    // 回退
    pathSize--;
}

// 打印向量中的元素
void printResult() {
    for (int i = 0; i < resIdx; i++) {
        printf("[");
        for (int j = 0; j < resSize[i]; j++) {
            if (j == resSize[i] - 1) {
                printf("%d", res[i][j]->val);
            } else {
                printf("%d, ", res[i][j]->val);
            }
        }
        printf("]\n");
    }
}

/* Driver Code */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = arrToTree(arr, n);
    printf("\r\n初始化二叉树\r\n");
    printTree(root);

    // 前序遍历
    preOrder(root);
    // 输出结果
    printf("输出所有根节点到节点 7 的路径，要求路径中不包含值为 3 的节点\n");
    printResult();

    freeMemoryTree(root);
    return 0;
}
