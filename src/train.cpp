#include "train.h"

Train::Car::Car(bool l) : light(l), next(nullptr), prev(nullptr) {}

Train::Train() : first(nullptr), countOp(0) {}

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
    Car* current = first;
    do {
        current->light = false;
        current = current->next;
        ++countOp;
    } while (current != first);
    first->light = true;
    current = first;
    int steps = 0;
    while (true) {
        current = current->next;
        ++countOp;
        ++steps;
        if (current->light) {
            break;
        } else {
            current->light = false;
        }
    }
    return steps;
}
int Train::getOpCount() {
    return countOp;
}
