// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car;
  newCar->light = light;
  newCar->next = nullptr;
  newCar->prev = nullptr;
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

int Train::getLength() {
  if (!first) return 0;
const Car* current = first;
current->light = true;  // Шаг 1
countOp++;
int length = 1;
while (true) {
  current = current->next;
  countOp++;
  if (current->light) {
    current->light = false;
    countOp++;
    int stepsBack = 0;
    while (stepsBack < length) {
      current = current->prev;
      countOp++;
      stepsBack++;
    }
    if (!current->light) {
      return length;
    } else {
      length++;
    }
  }
}
}

int Train::getOpCount() { return countOp; }
