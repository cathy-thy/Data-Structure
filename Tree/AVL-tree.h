#include "treenode.h"

typedef struct bstCDT *bstADT;

bstADT EmptyBST();
int BSTIsEmpty(bstADT t);   //empty tree or not
bstADT MakeBST(treeNodeADT root, bstADT left, bstADT right);

bstADT RotateLeft(bstADT t);
bstADT RotateRight(bstADT t);
bstADT RotateLeftRight(bstADT t);
bstADT RotateRightLeft(bstADT t);
bstADT InsertNode(bstADT t, treeNodeADT n);

treeNodeADT Root(bstADT t);
bstADT LeftSubtree(bstADT t);
bstADT RightSubtree(bstADT t);
treeNodeADT FindNode(bstADT t, char *key);
