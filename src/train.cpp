// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->prev = nullptr;
        first->next = nullptr;
        first->light = true;
    }
    else if (first != nullptr) {
        Cage* cage = new Cage;
        cage->next = nullptr;
        cage->prev = nullptr;
        cage->light = light;
        Cage* tmp;
        if (first->next == nullptr) {
            cage->next = first;
            cage->prev = first;
            first->next = cage;
            first->prev = cage;
        }
        else {
            tmp = first;
            while (tmp->next != first) {
                tmp = tmp->next;
            }
            tmp->next = cage;
            cage->next = first;
            cage->prev = tmp;
            first->prev = cage;
        }
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
    return countOp;
}
