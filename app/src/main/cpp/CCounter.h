//
// Created by hiking on 2017/3/7.
//
#include "test.h"
#ifndef JNIDEMO012_CCOUNTER_H
#define JNIDEMO012_CCOUNTER_H


class CCounter {
    int n;
    test * t;
public:
    CCounter(int v) {
        n = v;
        t = new test;
    }

    int execute() {
        t->age=100;
        int i, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += i;
        }
        return t->age;
    }
};


#endif //JNIDEMO012_CCOUNTER_H
