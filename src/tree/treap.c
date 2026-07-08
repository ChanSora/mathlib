#include <stdlib.h>
#include <stdio.h>
typedef struct Node {
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int val;
    int size;
    int weight;
} Node;

static void update_size(Node* node, Node* NIL) {
    if (node == NIL) return;
    node->size = 1 + node->left->size + node->right->size;
}

static void rotate_left(Node** root_ptr, Node* node, Node* NIL) {
    
    if (node == NIL) return;

    Node* parent = node->parent;

    Node* new_root = node->right;
    if (new_root == NIL) return;
    
    Node* b = new_root->left;
    if (b != NIL) b->parent = node;
    node->right = b;
    
    new_root->left = node;
    node->parent = new_root;
    
    new_root->parent = parent;

    if (parent == NIL) *root_ptr = new_root;
    else if (node == parent->left) parent->left = new_root, new_root->parent = parent;
    else parent->right = new_root, new_root->parent = parent;

    update_size(node, NIL);
    update_size(new_root, NIL);

}

static void rotate_right(Node** root_ptr, Node* node, Node* NIL) {
    if (node == NIL) return;

    Node* parent = node->parent;

    Node* new_root = node->left;
    if (new_root == NIL) return;

    Node* b = new_root->right;
    if (b != NIL) b->parent = node;
    node->left = b;

    node->parent = new_root;
    new_root->right = node;

    new_root->parent = parent;

    if (parent == NIL) *root_ptr = new_root;
    else if (node == parent->left) parent->left = new_root, new_root->parent = parent;
    else parent->right = new_root, new_root->parent = parent;
    
    update_size(node, NIL);
    update_size(new_root, NIL);
    
}

static void insert(Node** root_ptr, Node* node, Node* NIL) {
    if (node == NIL) return;
    if (*root_ptr == NIL) {
        *root_ptr = node;
        return;
    }

    Node* cur = *root_ptr;
    Node* parent = NIL;

    while (cur != NIL) {
        parent = cur;
        cur->size++;
        if (node->val < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    node->parent = parent;
    if (node->val < parent->val) parent->left = node;
    else parent->right = node;

    while (node->weight > parent->weight && node->parent != NIL) {
        if (node == parent->left) rotate_right(root_ptr, parent, NIL);
        else rotate_left(root_ptr, parent, NIL);
        parent = node->parent;
    }
}

static void delete(Node** root_ptr, int val, Node* NIL) {
    Node* cur = *root_ptr;
    Node* parent = NIL;
    while (cur != NIL) {
        parent = cur;
        if (val < cur->val) cur = cur->left;
        else if (val > cur->val) cur = cur->right;
        else {
            parent = cur->parent;
            if (cur->left == NIL || cur->right == NIL) {
                Node* child = (cur->left == NIL) ? cur->right : cur->left;
                if (cur == parent->left) parent->left = child;
                else parent->right = child;
                break;
            } else {
                Node* successor = cur->right;
                while (successor->left != NIL) successor = successor->left;
                cur->val = successor->val;
                val = successor->val;
                cur = successor;
                continue;
            }
        }
    }
}

static void inorder(Node* node, Node* NIL) {
    if (node == NIL) return;
    printf("In node %d\n", node->val);
    inorder(node->left, NIL);
    inorder(node->right, NIL);
}

Node node[10];

int main() {
    Node nil_node = node[0];
    Node* NIL = &nil_node;
    Node* root_ptr;
    
    NIL->parent = NIL;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->size = 0;
    NIL->val = 0;
    NIL->weight = 0;

    root_ptr = NIL;

    for (int i = 1; i < 9; i++) {
        node[i].parent = NIL;
        node[i].left = NIL;
        node[i].right = NIL;
        node[i].size = 1;
        node[i].val = i;
        node[i].weight = rand();
        insert(&root_ptr, &node[i], NIL);
    }
    inorder(root_ptr, NIL);
    return 0;
}