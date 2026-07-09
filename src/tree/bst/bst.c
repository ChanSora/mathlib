#include <utensils/tree.h>

#include <stdlib.h>

#include "tree/rb_tree.h"
#include "tree/avl_tree.h"
#include "tree/treap.h"
#include "tree/splay.h"


static void bst_create(Tree* tree, int capacity);
static void bst_destroy(Tree* tree);
static void bst_insert(Tree* tree, int val);
static void bst_erase(Tree* tree, int val);
static void* bst_find(Tree* tree, int val);
static int bst_find_val(Tree* tree, int val);
static int bst_rank(Tree* tree, int val);
static void* bst_kth(Tree* tree, int k);
static int bst_kth_val(Tree* tree, int k);
static void* bst_lower_bound(Tree* tree, int val);
static void* bst_upper_bound(Tree* tree, int val);
static void* bst_prev(Tree* tree, int val);
static int bst_prev_val(Tree* tree, int val);
static void* bst_next(Tree* tree, int val);
static int bst_next_val(Tree* tree, int val);

Tree tree_init(TreeType type) {
    Tree tree;
    tree.type = type;
    tree.data = NULL;
    tree.create = bst_create;
    tree.destroy = bst_destroy;
    tree.insert = bst_insert;
    tree.erase = bst_erase;
    tree.find = bst_find;
    tree.find_val = bst_find_val;
    tree.rank = bst_rank;
    tree.kth = bst_kth;
    tree.kth_val = bst_kth_val;
    tree.lower_bound = bst_lower_bound;
    tree.upper_bound = bst_upper_bound;
    tree.prev = bst_prev;
    tree.prev_val = bst_prev_val;
    tree.next = bst_next;
    tree.next_val = bst_next_val;
    return tree;
}

static void bst_create(Tree* tree, int capacity) {
    switch (tree->type) {
        case RB_TREE:   tree->data = rb_tree_create(capacity); break;
        case AVL_TREE:  tree->data = avl_tree_create(capacity); break;
        case TREAP:     tree->data = treap_create(capacity); break;
        case SPLAY:     tree->data = splay_create(capacity); break;
        default:        tree->data = NULL; break;
    }
}

static void bst_destroy(Tree* tree) {
    if (!tree->data) return;
    switch (tree->type) {
        case RB_TREE:   rb_tree_destroy((RB_Tree*)tree->data); break;
        case AVL_TREE:  avl_tree_destroy((AVL_Tree*)tree->data); break;
        case TREAP:     treap_destroy((Treap*)tree->data); break;
        case SPLAY:     splay_destroy((Splay*)tree->data); break;
        default: break;
    }
    tree->data = NULL;
}

static void bst_insert(Tree* tree, int val) {
    if (!tree->data) return;
    switch (tree->type) {
        case RB_TREE:   rb_tree_insert((RB_Tree*)tree->data, val); break;
        case AVL_TREE:  avl_tree_insert((AVL_Tree*)tree->data, val); break;
        case TREAP:     treap_insert((Treap*)tree->data, val); break;
        case SPLAY:     splay_insert((Splay*)tree->data, val); break;
        default: break;
    }
}

static void bst_erase(Tree* tree, int val) {
    if (!tree->data) return;
    switch (tree->type) {
        case RB_TREE:   rb_tree_erase((RB_Tree*)tree->data, val); break;
        case AVL_TREE:  avl_tree_erase((AVL_Tree*)tree->data, val); break;
        case TREAP:     treap_erase((Treap*)tree->data, val); break;
        case SPLAY:     splay_erase((Splay*)tree->data, val); break;
        default: break;
    }
}

static void* bst_find(Tree* tree, int val) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_find((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_find((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_find((Treap*)tree->data, val);
        case SPLAY:     return splay_find((Splay*)tree->data, val);
        default:        return NULL;
    }
}

static int bst_find_val(Tree* tree, int val) {
    if (!tree->data) return 0;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_find_val((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_find_val((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_find_val((Treap*)tree->data, val);
        case SPLAY:     return splay_find_val((Splay*)tree->data, val);
        default:        return 0;
    }
}

static int bst_rank(Tree* tree, int val) {
    if (!tree->data) return 0;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_rank((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_rank((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_rank((Treap*)tree->data, val);
        case SPLAY:     return splay_rank((Splay*)tree->data, val);
        default:        return 0;
    }
}

static void* bst_kth(Tree* tree, int k) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_kth((RB_Tree*)tree->data, k);
        case AVL_TREE:  return avl_tree_kth((AVL_Tree*)tree->data, k);
        case TREAP:     return treap_kth((Treap*)tree->data, k);
        case SPLAY:     return splay_kth((Splay*)tree->data, k);
        default:        return NULL;
    }
}

static int bst_kth_val(Tree* tree, int k) {
    if (!tree->data) return 0;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_kth_val((RB_Tree*)tree->data, k);
        case AVL_TREE:  return avl_tree_kth_val((AVL_Tree*)tree->data, k);
        case TREAP:     return treap_kth_val((Treap*)tree->data, k);
        case SPLAY:     return splay_kth_val((Splay*)tree->data, k);
        default:        return 0;
    }
}

static void* bst_lower_bound(Tree* tree, int val) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_lower_bound((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_lower_bound((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_lower_bound((Treap*)tree->data, val);
        case SPLAY:     return splay_lower_bound((Splay*)tree->data, val);
        default:        return NULL;
    }
}

static void* bst_upper_bound(Tree* tree, int val) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_upper_bound((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_upper_bound((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_upper_bound((Treap*)tree->data, val);
        case SPLAY:     return splay_upper_bound((Splay*)tree->data, val);
        default:        return NULL;
    }
}

static void* bst_prev(Tree* tree, int val) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_prev((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_prev((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_prev((Treap*)tree->data, val);
        case SPLAY:     return splay_prev((Splay*)tree->data, val);
        default:        return NULL;
    }
}

static int bst_prev_val(Tree* tree, int val) {
    if (!tree->data) return 0;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_prev_val((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_prev_val((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_prev_val((Treap*)tree->data, val);
        case SPLAY:     return splay_prev_val((Splay*)tree->data, val);
        default:        return 0;
    }
}

static void* bst_next(Tree* tree, int val) {
    if (!tree->data) return NULL;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_next((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_next((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_next((Treap*)tree->data, val);
        case SPLAY:     return splay_next((Splay*)tree->data, val);
        default:        return NULL;
    }
}

static int bst_next_val(Tree* tree, int val) {
    if (!tree->data) return 0;
    switch (tree->type) {
        case RB_TREE:   return rb_tree_next_val((RB_Tree*)tree->data, val);
        case AVL_TREE:  return avl_tree_next_val((AVL_Tree*)tree->data, val);
        case TREAP:     return treap_next_val((Treap*)tree->data, val);
        case SPLAY:     return splay_next_val((Splay*)tree->data, val);
        default:        return 0;
    }
}