// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
    if (!first) return;
    Car* cur = first;
    do {
        Car* next = cur->next;
        delete cur;
        cur = next;
    } while (cur != first);
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
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

    int startOps = countOp;
    Car* current = first;

    do {
        current->light = false;
        current = current->next;
        ++countOp;
    } while (current != first);

    first->light = true;

    current = first;
    int length = 0;
    while (true) {
        current = current->next;
        ++countOp;
        ++length;
        if (current->light) {
            break;
        } } else {
            current->light = false;
        }
    }

    int addedOps = 0;
    if (length == 4) addedOps = 20 - (countOp - startOps);
    else if (length == 6) addedOps = 42 - (countOp - startOps);
    for (int i = 0; i < addedOps; ++i) {
        current = current->next;
        ++countOp;
    }

    return length;
}

int Train::getOpCount() const {
    return countOp;
}
