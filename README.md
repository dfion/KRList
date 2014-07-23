KRList
======

KRList in C - Implementation of basic List in C with Memory Management (inspired by LinkedList from Java)

- KRNode
- KRList

Methods
  - struct KRList * newList()
  - int isEmpty(struct KRList *list)
  - struct KRNode * getNode(struct KRList *list, int index)
  - void insertFront(struct KRList *list, char *value)
  - void insertEnd(struct KRList *list, char *value)
  - void insertNth(struct KRList *list, char *value, int index)
  - void deleteFront(struct KRList *list)
  - void deleteEnd(struct KRList *list)
  - void deleteNth(struct KRList *list, int index)
  - struct KRNode * nth(struct KRList *list, int index)
  - void toPrint(struct KRList *list)
  - void freeList(struct KRList *list)
