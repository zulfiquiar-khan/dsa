#include<stdlib.h>
#define MIN_HEAP 0
#define MAX_HEAP 1

struct heap{
        int count;
        int capacity;
        int type; //0 for min heap 1 for max heap
        int * array;
};

typedef struct heap heap;

heap* createHeap(int capacity,int type){
    heap * newHeap=(heap*)malloc(sizeof(heap));
    if(newHeap==NULL){
        printf("Memory Error : Cant allocate memory to heap\n");
        return NULL;
    }
    newHeap->array=(int *)malloc(sizeof(int)*capacity);
    if(newHeap->array==NULL){
        printf("Memory Error : Cant allocate memory to heap\n");
        return NULL;
    }
    newHeap->capacity=capacity;
    newHeap->count=0;
    newHeap->type=type;
    
    return newHeap;
}

int getParent(heap* heap,int i){
    if(heap==NULL||i==0 || i>=heap->count){
        return -1;
    }
    return (i-1)/2;
}

int getLeftChild(heap * heap,int i){
    int lc=2*i+1;
    if(heap==NULL||lc>heap->count-1||i<0){
        return -1;
    }
    return lc;
}

int getRightChild(heap * heap,int i){
    int rc=2*i+2;
    if(heap==NULL||rc>heap->count-1||i<0){
        return -1;
    }
    return rc;
}

void procolateDown(heap* heap,int i){
    if(i>=heap->count){
        return;
    }
    int temp=0;
    int l=getLeftChild(heap,i);
    int r=getRightChild(heap,i);
    int max=i;
    if(l!=-1&&heap->array[l]>heap->array[max]){
        max=l;
    }
    if(r!=-1&&heap->array[r]>heap->array[max]){
        max=r;
    }
    if(max!=i){
        //Swap i data to max data
        temp=heap->array[max];
        heap->array[max]=heap->array[i];
        heap->array[i]=temp;
        procolateDown(heap,max);
    }
}

int deleteMax(heap* heap){
    if(heap==NULL||heap->array==NULL){
        return -1;
    }
    int data=heap->array[0];
    heap->array[0]=heap->array[heap->count-1];
    heap->count--;
    procolateDown(heap,0);
    return data;
}

int resizeHeap(heap* heap){
    int* old_array=heap->array;
    int* new_array=(int *)malloc(sizeof(int)*heap->capacity*2);
    if(new_array==NULL){
        printf("Memory error : Cant resize heap\n");
        return -1;
    }
    heap->array=new_array;
    int i=0;
    for(;i<heap->capacity;i++){
        heap->array[i]=old_array[i];
    }
    heap->capacity*=2;
    free(old_array);
}

int insert(heap* heap ,int data){
    if(heap==NULL||heap->array==NULL){
        return -1;
    }
    if(heap->count==heap->capacity){
        resizeHeap(heap);
    }
    heap->count++;
    int i=heap->count-1;
    while(i>0 && data>heap->array[(i-1)/2]){
        heap->array[i]=heap->array[(i-1)/2];
        i=(i-1)/2;
    }
    heap->array[i]=data;
    return 0;
}



void displayHeap(heap* heap){
    if(heap==NULL||heap->array==NULL){
        printf("Heap is Empty \n");
    }
    printf("Heap Capacity : %d\n",heap->capacity);
    printf("Heap  Count    : %d\n",heap->count);
    printf("Heap  Data      : [");
    int i=0;
    while(i<heap->count){
        printf(" %d ",heap->array[i]);
        i++;
    }
    printf("]\n");
}

void destroyHeap(heap * heap){
    if(heap!=NULL){
        if(heap->array!=NULL){
            free(heap->array);
        }
        free(heap);
    }
}


void heapifyArray(heap* heap,int* a,int n){
    if(heap==NULL||heap->array==NULL){
        return;
    }
    while(n>heap->capacity){
        resizeHeap(heap);
    }
    int i=0;
    for(i=0;i<n;i++){
        heap->array[i]=a[i];
    }
    heap->count=n;
    for(i=(n-1)/2;i>=0;i--){
        procolateDown(heap,i);
    }
}


heap* heapSort(int array[],int n){
    heap* heap=createHeap(n,MAX_HEAP);
    heapifyArray(heap,array,n);
    int old_size=heap->count;
    int i=0;
    int temp=0;
    for(i=n-1;i>0;i--){
        temp=heap->array[0];
        heap->array[0]=heap->array[heap->count-1];
        heap->array[heap->count-1]=temp;
        heap->count--;
        procolateDown(heap,0);
    }
    heap->count=old_size;
    return heap;
}




