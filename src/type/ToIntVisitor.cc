#include "visitor.h"

namespace MYLANG {

    shared_ptr<IntValue> ToIntVisitor:: visitInt(IntValue* ival) {
        return std::make_shared<IntValue>(ival->getValue());
    }

    shared_ptr<IntValue> ToIntVisitor:: visitBool(BoolValue* bval) {
        return std::shared_ptr<IntValue>(bval->getValue());
    }

    shared_ptr<IntValue> ToIntVisitor:: visitDouble(DoubleValue* dval) {
        return std::shared_ptr<IntValue>((int) dval->getValue());
    }

    shared_ptr<IntValue> ToIntVisitor:: visitString(StringValue* sval) {
        throw std::runtime_error("cannot convert string to int");
    }

}