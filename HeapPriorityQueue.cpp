//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}
void HeapPriorityQueue::put_in(PuzzleState *elem){
  
   if (heap.size() == 0) {
     heap.resize(1,elem);
   return;
  }
   else {
     heap.push_back(elem);
     int n =(int)heap.size();
     swapUp(n-1);
     return;
   }
}

void HeapPriorityQueue::swapUp(int index) {
  if (index == 0){
    return;
  }
  else{
    int parent_index  = parent(index);    
    if ( heap[index]->getBadness() < heap[parent_index]->getBadness()){
      PuzzleState *temp = heap[index];
      heap[index] = heap[parent_index];
      heap[parent_index] = temp;
      swapUp ( parent_index);
    }
  }
  return;
  // TODO:  Put your code here!
}


PuzzleState * HeapPriorityQueue::take_out() {
  if (is_empty()) return NULL;
  PuzzleState *ret = heap[0];
  if ((int) heap.size()== 1){
    heap.resize(0);
    return ret;
  }
  else{
    int n = (int)heap.size();
    heap[0] = heap[n-1];
    heap.resize(n - 1);
    swapDown(0);
    return ret;
  }
  // TODO:  Put your code here!
}

void HeapPriorityQueue::swapDown(int index) {
  int s = index;
  int left = 2 * s + 1;
  int right = left + 1;
  int n = (int)heap.size();
  
  if (left > n) {
    return;
  }
   
  if (left <= n ){ 
    PuzzleState *left_s = heap[left];
    if (left_s->getBadness() < heap[s]->getBadness()){
      s = left;
     
    }
  }
  if (right <= n ){ 
    PuzzleState *right_s = heap[right];
    if (right_s->getBadness() < heap[s]->getBadness()){
      s = right;
     
    }
  }
  if (s!=index) {
    PuzzleState *temp = heap[index];
      heap[index] = heap[s];
      heap[s] = temp;
      swapDown(s);
  }
      return;
}



bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
