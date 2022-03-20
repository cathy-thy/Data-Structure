#include "bst.h"
#include "treenode.h"
//#include "AVL-tree.h"

int main(){
    bstADT tree;
    for (int i=10; i<0; i--){
        char *key = "a0"+i;
        void *value = &i;
        treeNodeADT node = NewNode(key, value);
        InsertNode(tree, node);
    }

}