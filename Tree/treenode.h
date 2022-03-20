typedef struct treeNodeCDT *treeNodeADT;

treeNodeADT NewNode(char *key, void *value);
char *GetNodeKey(treeNodeADT n);
void *GetNodeValue(treeNodeADT n);
void DelNode(treeNodeADT n);
treeNodeADT CopyNode(treeNodeADT n);
