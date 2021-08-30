#include "Context.h"
#include <cassert>

namespace MYLANG {

    bool Context::isDefined(string key) {
        if (mmap.count(key)) return 1;
        Context *p = next;
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
    shared_ptr<IValue> Context::getVal(string key) {
        if (mmap.count(key)) return mmap[key];
        Context *p = next;
        // traverse the linked list to find the nearest scope that contains the varname
        while (p != nullptr) {
            if (p->mmap.count(key)) return p->mmap[key];
        }
        return nullptr;
    }

    void Context::setVal(string key, shared_ptr<IValue> val) {
        mmap[key] = val;
    }

/**
 * Add uninitialized declared variable to the runtime context
 * the value for uninitialized variable in the map is null pointer
 * @param key
 */
    void Context::addVar(string key) {
        mmap[key] = nullptr;
    }

    void Context::addVar(string key, shared_ptr<IValue> val) {
        mmap[key] = val;
    }

}