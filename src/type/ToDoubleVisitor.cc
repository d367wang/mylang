#include "visitors.h"
#include "types.h"

    shared_ptr<IValue> ToDoubleVisitor::visitInt(IntValue* ival) {
        return shared_ptr<IValue>(new DoubleValue(ival->getValue()));
    }

    shared_ptr<IValue> ToDoubleVisitor::visitDouble(DoubleValue* dval) {
        return shared_ptr<IValue>(new DoubleValue(dval->getValue()));
    }

    shared_ptr<IValue> ToDoubleVisitor::visitString(StringValue* sval) {
        throw runtime_error("cannot convert string to double");
    }

