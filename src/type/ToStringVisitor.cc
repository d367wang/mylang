#include "visitor.h"
#include "types.h"

    shared_ptr<IValue> ToStringVisitor::visitInt(IntValue* ival) {
        return make_shared<StringValue>(to_string(ival->getValue()));
    }

    shared_ptr<IValue> ToStringVisitor::visitDouble(DoubleValue* dval) {
        return make_shared<StringValue>(to_string(dval->getValue()));
    }

    shared_ptr<IValue> ToStringVisitor::visitString(StringValue* sval) {
        return make_shared<StringValue>(sval->getValue());
    }

