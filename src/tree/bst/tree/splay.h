// This is the header of splay.
#ifndef SPLAY_H
#define SPLAY_H

typedef struct Node Node;

typedef struct {
    Node* root;
    Node* nil;
    Node* nodes;
    int idx;
    int capacity;
} Splay;

Splay* splay_create(int n);
void splay_insert(Splay* tree, int val);
void splay_erase(Splay* tree, int val);
Node* splay_find(Splay* tree, int val);
int splay_find_val(Splay* tree, int val);
void splay_destroy(Splay* tree);
Node* splay_upper_bound(Splay* tree, int val);
Node* splay_lower_bound(Splay* tree, int val);
Node* splay_next(Splay* tree, int val);
int splay_next_val(Splay* tree, int val);
Node* splay_prev(Splay* tree, int val);
int splay_prev_val(Splay* tree, int val);
Node* splay_kth(Splay* tree, int k);
int splay_kth_val(Splay* tree, int k);
int splay_rank(Splay* tree, int val);

#endif