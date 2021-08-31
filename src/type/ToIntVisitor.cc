#include "visitor.h"
#include "types.h"


    shared_ptr<IValue> ToIntVisitor:: visitInt(IntValue* ival) {
        return make_shared<IntValue>(ival->getValue());
    }

    shared_ptr<IValue> ToIntVisitor:: visitDouble(DoubleValue* dval) {
        return shared_ptr<IntValue>(new IntValue(dval->getValue()));
    }

    shared_ptr<IValue> ToIntVisitor:: visitString(StringValue* sval) {
        throw runtime_error("cannot convert string to int");
    }

