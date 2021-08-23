#include "Context.h"
#include <cassert>

bool Context::isDefined(string key) {
    if (mmap.count(key)) return 1;
    Context* p = next;
    while (p != nullptr) {
        if (mmap.count(key)) return 1;
    }
    return 0;
}

bool Context::isInCurrent(string key) {
    return mmap.count(key);
}


/**
 * caller ensures the input key exists in the current scope or outer ones
 */
int& Context::getVal(string key) {
    if (mmap.count(key)) return mmap[key];
    Context* p = next;
    // traverse the linked list to find the nearest scope that contains the varname
    while (p != nullptr) {
        if (p->mmap.count(key)) return p->mmap[key];
    }

    assert(p != nullptr);
    // igore warning, unreachable
}

void Context::setVal(string key, int val) {
    int& target = getVal(key);
    target = val;
}

void Context::addVal(string key) {
    mmap[key] = 0;
}

void Context::addVal(string key, int val) {
    mmap[key] = val;
}