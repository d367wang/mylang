#include "visitor.h"

namespace MYLANG {

    shared_ptr<StringValue> ToStringVisitor::visitInt(IntValue* ival) {
        return std::make_shared<StringValue>(std::to_string(ival->getValue()));
    }

    shared_ptr<StringValue> ToStringVisitor::visitBool(BoolValue* bval) {
        return std::make_shared<StringValue>(bval->getValue() ? "true" : "false");
    }

    shared_ptr<StringValue> ToStringVisitor::visitDouble(DoubleValue* dval) {
        return std::make_shared<StringValue>(std::to_string(dval->getValue()));
    }

    shared_ptr<StringValue> ToStringVisitor::visitString(StringValue* sval) {
        return sval;
    }

}