#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>


/// <summary>
/// ţ����������ı���
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
    /// ���ȼ����⣬��������Խ��
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


//ƽ�������
//������

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
// ע������������ݹ��ж�
// ���Եݹ�������������ҵݹ�
//    return abs(maxDepth(root->left) - maxDepth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
//}