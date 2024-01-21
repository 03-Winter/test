#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>


/// <summary>
/// 牛客题二叉树的遍历
/// </summary>
typedef struct treenode
{
    char val;
    struct treenode* left;
    struct treenode* right;
} tnode;

tnode* creattree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        ++(*pi);
        return NULL;

    }

    /// <summary>
    /// 优先级问题，导致数组越界
    /// </summary>
    /// <param name="a"></param>
    /// <param name="pi"></param>
    /// <returns></returns>
    //if (a[(*pi)++] == '#')
    //    return;


    tnode* root = (tnode*)malloc(sizeof(tnode));
    if (!root) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    root->val = a[*pi];
    ++(*pi);
    root->left = creattree(a, pi);
    root->right = creattree(a, pi);

    return root;
}

void inorder(tnode* root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%c ", root->val);
    inorder(root->right);
}

int main() {
    char a[1000];
    scanf("%999s", a);
    int i = 0;
    tnode* tree = creattree(a, &i);

    if (tree) {
        inorder(tree);
    }
    else {
        fprintf(stderr, "Tree creation failed\n");
    }

    return 0;
}


//平衡二叉树
//力扣题

//int maxDepth(struct TreeNode* root) {
//    if (!root)
//        return 0;
//    int max = maxDepth(root->left);
//    int min = maxDepth(root->right);
//    return max > min ? max + 1 : min + 1;
//}
//bool isBalanced(struct TreeNode* root) {
//    if (!root)
//        return true;
//
// 
// 
// 
// 注意对左右子树递归判断
// 所以递归的条件包含左右递归
//    return abs(maxDepth(root->left) - maxDepth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
//}