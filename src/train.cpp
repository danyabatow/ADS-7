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
  if (first == nullptr) {
    countOp = 0;
    return 0;
  }
  int length = 1;
  const Car* current = first -> next;
  bool disabledLight = !first->light;
  while (current != first) {
    if (!current->light) {
      disabledLight = true;
    }
    length +=1;
    current = current->next;
  }
  if (disabledLight) {
    countOp = length * 2;
  } else {
    countOp = length * (length + 1);
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
