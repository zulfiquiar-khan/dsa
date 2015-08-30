#include"StackUsingTwoQueues.h"

void testStackUsingTwoQueues()
{
    struct StackUsingQueue* stack=createStackUsingQueue();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    
    printf("%d  ",pop(stack));
    printf("%d  ",pop(stack));
    printf("%d  ",pop(stack));
    printf("%d  ",pop(stack));
    printf("%d  ",pop(stack));
}