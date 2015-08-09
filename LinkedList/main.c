#include <stdio.h>
//#include"SinglyLinkedListTest.h"
//#include"DoublyLinkedListTest.h"
//#include"CircularLinkedListTest.h"
//#include"FindNthNodeFromEndTest.h"
#include"HashMapTest.h"
#include"FindCycleInLinkedListTest.h"

int main(int argc, char **argv)
{
	
   // testSinglyLinkedList();
    //testCircularLinkedList();
    //testDoublyLinkedList();
    
   // testFindNthNodeBruteForce();
    //testFinNthNodeHashMapStrategy();
    //testFindNthNodeCountingNodeStrategy();
    //testFindNthNodePointerDifferenceStrategy();
    //testHashMap();
    
    testFindWetherListHasCycleHashMapStrategy();
    testFindWetherListHasCycleFloydCycleFindingAlgorithm();
    testFindStartNodeOfLoopFloydCycleFindingAlgorithm();
    testFindLoopSizeFloydCycleFindingAlgorithm();
	return 0;
}
