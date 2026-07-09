typedef enum TreeType {
    RB_TREE, AVL_TREE, TREAP, SPLAY
} TreeType;

typedef struct Tree {
    TreeType type;
    void* data;
    void (*create)(struct Tree* self, int capacity);
    void (*destroy)(struct Tree* self);
    void (*insert)(struct Tree* self, int val);
    void (*erase)(struct Tree* self, int val);
    void* (*find)(struct Tree* self, int val);
    int (*find_val)(struct Tree* self, int val);
    int (*rank)(struct Tree* self, int val);
    void* (*kth)(struct Tree* self, int k);
    int (*kth_val)(struct Tree* self, int k);
    void* (*prev)(struct Tree* self, int val);
    int (*prev_val)(struct Tree* self, int val);
    void* (*lower_bound)(struct Tree* self, int val);
    void* (*upper_bound)(struct Tree* self, int val);
    void* (*next)(struct Tree* self, int val);
    int (*next_val)(struct Tree* self, int val);
} Tree;

Tree tree_init(TreeType type);

