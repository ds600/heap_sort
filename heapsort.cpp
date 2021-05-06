#include <stdio.h>
#include "heapsort.h"
#include "config.h"

int arrayLength = 0;
int stepCount = 0;

//Fuehrt das Programm aus
void heapSort(int *anArray, int aLength)
{
    arrayLength = aLength;
    #ifdef INFOCOUNT
    copyCount = 0;
    compareCount = 0;
    #endif
    buildMaxHeap(anArray, aLength);
    while(aLength > 1)
    {
        swap(anArray, aLength - 1, 0);
        aLength--;
        swapMultiple(anArray, aLength, 0);
    }
}

//Baut einmal den MaxHeap, groesste Zahl ganz oben, kleinsten Zahlen unten
void buildMaxHeap(int *anArray, int aLength)
{
    int tLastParentIndex = getLastParentIndex(aLength);
    while(tLastParentIndex >= 0)
    {
        swapMultiple(anArray, aLength, tLastParentIndex);
        tLastParentIndex--;
    }
}

//Schaut einmal welches Child groesser ist und tauscht dann das groessere mit dem Parent, wenn der Parent auch kleiner ist
int swapSingle(int *anArray, int aLength, int aParentIndex)
{
    int tFirstChildIndex = getFirstChildIndexOfParent(aLength, aParentIndex);
    int tSecondChildIndex = getSecondChildIndexOfParent(aLength, aParentIndex);
    int tChangedIndex = aParentIndex;
    if(tSecondChildIndex >= 0 && anArray[tFirstChildIndex] < anArray[tSecondChildIndex])
    {
        if(anArray[tSecondChildIndex] > anArray[aParentIndex])
        {
            swap(anArray, aParentIndex, tSecondChildIndex);
            tChangedIndex = tSecondChildIndex;
        }
    }
    else
    {
        if(tFirstChildIndex >= 0 && anArray[tFirstChildIndex] > anArray[aParentIndex])
        {
            swap(anArray, aParentIndex, tFirstChildIndex);
            tChangedIndex = tFirstChildIndex;
        }
    }
    #ifdef INFOCOUNT
    compareCount += 2;
    #endif
    return tChangedIndex;
}

//Tauscht so lange Parents mit Childs, bis nach erneutem ausfuehren, immer noch die selbe Zahl oben steht, da das heisst der Parent ist bereits am groessten
void swapMultiple(int *anArray, int aLength, int aParentIndex)
{
    int tParentIndex = aParentIndex;
    int tFirstParentIndex;
    do
    {
        tFirstParentIndex = tParentIndex;
        tParentIndex = swapSingle(anArray, aLength, tParentIndex);
    } while(tFirstParentIndex != tParentIndex);
}

// Ermittelt den letzten Parent Index
int getLastParentIndex(int aLength)
{
    return aLength / 2 - 1;
}

//Ermittelt (falls moeglich) den 1. child index
int getFirstChildIndexOfParent(int aLength, int anIndex)
{
    int tChildIndex = (anIndex + 1) * 2 - 1;
    if(tChildIndex >= aLength)
        tChildIndex = -1;
    return tChildIndex;
}

//Ermittelt (falls moeglich) den 2. child index
int getSecondChildIndexOfParent(int aLength, int anIndex)
{
    int tChildIndex = (anIndex + 1) * 2;
    if(tChildIndex >= aLength)
        tChildIndex = -1;
    return tChildIndex;
}

//Gibt das Array aus
void printArray(int *anArray, int aLength)
{
    for(int i = 0; i < aLength; ++i)
      printf("%d ", anArray[i]);
    printf("\r\n");
}

//Tauscht 2 Indexe, ggf. erhoeht es auch den copycount / gibt den Zustand des Arrays durch "printArray" aus
void swap(int *anArray, int firstIndex, int secondIndex)
{
    int tLastIndexValue = anArray[firstIndex];
    anArray[firstIndex] = anArray[secondIndex];
    anArray[secondIndex] = tLastIndexValue;
    #ifdef INFOCOUNT
    copyCount += 3;
    #endif
    #ifdef INFOPRINT
    printf("%3d.: ", ++stepCount);
    printArray(anArray, arrayLength);
    #endif
}

