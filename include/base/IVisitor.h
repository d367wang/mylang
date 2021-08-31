#ifndef MYLANG_IVISITOR_H
#define MYLANG_IVISITOR_H

#include "base.h"

class IntValue;
class DoubleValue;
class StringValue;

class IVisitor {
public:
    virtual shared_ptr<IValue> visitInt(IntValue* ival) = 0;
    virtual shared_ptr<IValue> visitDouble(DoubleValue* dval) = 0;
    virtual shared_ptr<IValue> visitString(StringValue* sval) = 0;
};

#endif //MYLANG_IVISITOR_H
