#ifndef SUMLIST_H
#define SUMLIST_H

#include <math.h>
#include "LinkedList.h"

LinkedList<int> sumList(LinkedList<int> * l1, LinkedList<int> * l2);
int toNum(LinkedList<int> * list);
int maxNum(int n1, int n2);
LinkedList<int> toList(int sum, int n);

#endif
