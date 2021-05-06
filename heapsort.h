void heapSort(int *anArray, int aLength);
void buildMaxHeap(int *anArray, int aLength);
int swapSingle(int *anArray, int aLength, int aParentIndex);
void swapMultiple(int *anArray, int aLength, int aParentIndex);
int getLastParentIndex(int aLength);
int getFirstChildIndexOfParent(int aLength, int anIndex);
int getSecondChildIndexOfParent(int aLength, int anIndex);
void printArray(int *anArray, int aLength);
void swap(int *anArray, int firstIndex, int secondIndex);