#include<stdio.h>
#include"HashMap.h"


void testHashMap()
{
    int data1=10;
    int data2=12;
    int data3=13;
    int data4=16;
    
    hashmap* map=hashmapCreate(10);
    hashmapInsert(map,&data1,data1);
    hashmapInsert(map,&data2,data2);
    hashmapInsert(map,&data3,data3);
    hashmapInsert(map,&data4,data4);
    
    int *data1_r=(int *)hashmapGet(map,data1);
    int *data2_r=(int *)hashmapGet(map,data2);
    int *data3_r=(int *)hashmapGet(map,data3);
    int *data4_r=(int *)hashmapGet(map,data4);

    printf("%lu\n",*data1_r);
    printf("%lu\n",*data2_r);
    printf("%lu\n",*data3_r);
    printf("%lu\n",*data4_r);
}