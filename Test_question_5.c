//By Rajath B T
/*For a given integer array with no duplicates. A Binary tree can be built recursively using the following
algorithm:
• Pick any value x from the array.
• Create a root node whose value is x.
• Recursively build the left subtree on the subarray prefix to the left of x.
• Recursively build the right subtree on the subarray suffix to the right of x.
Print all Binary trees where the sum of the right subtree is greater that the sum of the left subtree.*/

#include <stdio.h>
#include <stdlib.h>

//binary tree node
struct node {
    int data;
    struct node *left, *right;
};

//new node in the binary tree
struct node* new_node(int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//finding the sum of the nodes in binary tree
int sum(struct node* root) {
    if(root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}

//print all binary trees where the sum of the right subtree is greater than the sum of the left subtree
void print_trees(int arr[], int start, int end) {
    if(start > end) {
        printf("NULL\n");
        return;
    }
    
    for(int i = start; i <= end; i++) {
        struct node* root = new_node(arr[i]);
        
        printf("(");
        print_trees(arr, start, i - 1);
        printf(") %d (", arr[i]);
        print_trees(arr, i + 1, end);
        printf(")");
        
        int left_sum = sum(root->left);
        int right_sum = sum(root->right);
        
        if(right_sum > left_sum) {
            printf("\nSum of right subtree is greater than left subtree.\n");
        } else {
            printf("\nSum of right subtree is NOT greater than left subtree.\n");
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Binary trees and their subtree sums:\n\n");
    print_trees(arr, 0, n - 1);
    
    return 0;
}
