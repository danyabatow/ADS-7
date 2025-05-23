// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!first) {
    newCar->next = newCar;
    newCar->prev = newCar;
    first = newCar;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getOpCount() const { return countOp; }

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  int length = 1;
  Car* current = first;
  while (current->next != first) {
    current = current->next;
    ++length;
    ++countOp;
  }
  return length;
}
