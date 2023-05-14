// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    countOp++;
    if (first == nullptr) {
        first = newCage;
        first->next = first;
        first->prev = first;
    }
    else {
        Cage* last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
}
int Train::getLength() {
    int result = 0;
    if (first != nullptr) {
        Cage* p = first;
        do {
            result++;
            p = p->next;
        } while (p != first);
    }
    return result;
}
int Train::getOpCount() {
    if (countOp == 0)
        getLength();
    return countOp;
}
