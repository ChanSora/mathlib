#include <utensils/tree.h>
#include <stdio.h>

int main() {
    // 1. 初始化红黑树
    Tree t = tree_init(RB_TREE);
    t.create(&t, 1000);
    
    // 2. 插入数据
    t.insert(&t, 50);
    t.insert(&t, 30);
    t.insert(&t, 70);
    
    // 3. 查找
    void* node = t.find(&t, 30);
    printf("Found node: %p\n", node);
    
    // 4. 排名（如果支持 size）
    int rank = t.rank(&t, 50);
    printf("Rank of 50: %d\n", rank);
    
    // 5. 销毁
    t.destroy(&t);
    return 0;
}