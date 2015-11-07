#include"BinaryHeap.h"

int main(int argc, char **argv)
{
	heap * heap=createHeap(10,MAX_HEAP);

    insert(heap,3);
    insert(heap,2);
    insert(heap,1);
    insert(heap,5);
    insert(heap,7);
    insert(heap,6);
    insert(heap,8);
    displayHeap(heap);
    
    int max_data=deleteMax(heap);
    printf("Max Data : %d\n",max_data);
    displayHeap(heap);
    max_data=deleteMax(heap);
    printf("Max Data : %d\n",max_data);
    displayHeap(heap);
    max_data=deleteMax(heap);
    printf("Max Data : %d\n",max_data);
    displayHeap(heap);
    max_data=deleteMax(heap);
    printf("Max Data : %d\n",max_data);
    displayHeap(heap);
    max_data=deleteMax(heap);
    printf("Max Data : %d\n",max_data);
    displayHeap(heap);
    
    printf("Going to destroy heap\n");
    destroyHeap(heap);
	printf("Heap destroyed\n");
    
    int arra[]={3,2,4,6,7,1,9,8};
    
     heap=createHeap(10,MAX_HEAP);
     printf("Calling heapify\n");
    heapifyArray(heap,arra,8);
    printf("Heapified\n");
    displayHeap(heap);
    
    heap=heapSort(arra,8);
    displayHeap(heap);
    return 0;
}
