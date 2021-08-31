#include "visitors.h"
#include "types.h"

    shared_ptr<IValue> ToStringVisitor::visitInt(IntValue* ival) {
        return shared_ptr<IValue>(new StringValue(to_string(ival->getValue())));
    }

    shared_ptr<IValue> ToStringVisitor::visitDouble(DoubleValue* dval) {
        return shared_ptr<IValue>(new StringValue(to_string(dval->getValue())));
    }

    shared_ptr<IValue> ToStringVisitor::visitString(StringValue* sval) {
        return shared_ptr<IValue>(new StringValue(sval->getValue()));
    }

