#include <stdio.h>
#include "heapsort.h"
#include "config.h"

#ifdef INFOCOUNT
int copyCount    = 0;
int compareCount = 0;
#endif

int main()
{
    int tArray[] = {3, 2, 13, 9, 14, 5, 7, 8, 9};
    int tArrayLength = sizeof(tArray) / sizeof(int);
    printf("Nicht sortiertes Array: ");
    printArray(tArray, tArrayLength);

    #ifdef INFOPRINT
    printf("==========================================================================\r\n");
    printf("Verarbeitungsschritte:\r\n");
    #endif
    heapSort(tArray, tArrayLength);
    #ifdef INFOPRINT
    printf("==========================================================================\r\n");
    #endif
    printf("Sortiertes Array:       ");
    printArray(tArray, tArrayLength);
    #ifdef INFOCOUNT
    printf("Kopiervorgänge: %d\r\n", copyCount);
    printf("Vergleichsvorgänge: %d\r\n", compareCount);
    #endif
    return 0;
}
