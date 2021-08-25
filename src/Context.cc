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
IValue& Context::getVal(string key) {
    if (mmap.count(key)) return mmap[key];
    Context* p = next;
    // traverse the linked list to find the nearest scope that contains the varname
    while (p != nullptr) {
        if (p->mmap.count(key)) return p->mmap[key];
    }

    assert(p != nullptr);
    // igore warning, unreachable
}

void Context::setVal(string key, IValue val) {
    IValue& target = getVal(key);
    target = val;
}

void Context::addVar(string key) {
    mmap[key] = NULLVAL;
}

void Context::addVar(string key, IValue val) {
    mmap[key] = val;
}