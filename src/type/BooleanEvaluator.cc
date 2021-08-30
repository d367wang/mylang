#include "visitor.h"

namespace MYLANG {

    shared_ptr<BoolValue> visitInt(IntValue* ival) {
        return ival->val;
    }

    shared_ptr<BoolValue> visitBool(BoolValue* bval) {
        return ival->val;
    }

    shared_ptr<BoolValue> visitDouble(DoubleValue* dval) {
        return (int) ival->val;
    }

    shared_ptr<BoolValue> visitString(StringValue* sval) {
        throw std::runtime_error("string cannot be used as condition");
    }

}