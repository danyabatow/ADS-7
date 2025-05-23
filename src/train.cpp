// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
    current = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* start = current;
  start->light = true;
  countOp++;
  int length = 1;
  while (true) {
    current = current->next;
    countOp++;
    if (current->light) {
      if (current == start) {
        current->light = false;
        return length;
      }
      current->light = false;
      countOp++;
      for (int i = 0; i < length; i++) {
        current = current->prev;
        countOp++;
      }
      if (!current->light) {
        return length;
      } else {
        length++;
        current = start->next;
      }
    }
  }
}

int Train::getOpCount() { return countOp; }
