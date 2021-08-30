#include "visitor.h"

namespace MYLANG {

    shared_ptr<DoubleValue> visitInt(IntValue* ival) {
        return std::shared_ptr<DoubleValue>((double) ival->getValue());
    }

    shared_ptr<DoubleValue> visitBool(BoolValue* bval) {
        return std::shared_ptr<DoubleValue>((double) bval->getValue());
    }

    shared_ptr<DoubleValue> visitDouble(DoubleValue* dval) {
        return std::shared_ptr<DoubleValue>(dval->getValue());
    }

    shared_ptr<DoubleValue> visitString(StringValue* sval) {
        throw std::runtime_error("cannot convert string to double");
    }

}