#include "base.h"
#include <cassert>
#include <string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;
using std::map;


/* return the reference to mapped value for "key" */
/* technique: return reference (actually address) to some heap memory */
int& VarTable::find(string key) {
    if (mmap.count(key)) return mmap[key];
    if (next == nullptr) {
        cout << "undefined variable: " << key << endl;
        exit(-1);
    }
    return next->find(key);
}

i