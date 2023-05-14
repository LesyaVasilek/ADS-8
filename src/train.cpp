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
Cage* cage = first;
while (cage) {
    cage = cage->next;
    countOp++;
    result++;
    if (cage->light == 1) {
        cage->light = 0;
        for (int i = 0; i < result; i++) {
            cage = cage->prev;
            countOp++;
        }
        if (cage->light == 0)
            if (cage->light == 0) {
                return result;
            }
        result = 0;
    }
}
return 0;
}
int Train::getOpCount() {
      if (countOp == 0)
          getLength();
    return countOp;
}
