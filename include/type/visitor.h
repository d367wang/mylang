#ifndef _TOSTRINGVISITOR_H
#define _TOSTRINGVISITOR_H

#include <memory>
#include "types.h"

using std::shared_ptr;

namespace MYLANG {

    class BooleanEvaluator : public IVisitor {
    public:
        shared_ptr<BoolValue> visitInt(IntValue* ival);

        shared_ptr<BoolValue> visitBool(BoolValue* bval);

        shared_ptr<BoolValue> visitDouble(DoubleValue* dval);

        shared_ptr<BoolValue> visitString(StringValue* sval);
    };

    class ToIntVisitor : public IVisitor {
    public:
        shared_ptr<IntValue> visitInt(IntValue* ival);

        shared_ptr<IntValue> visitBool(BoolValue* bval);

        shared_ptr<IntValue> visitDouble(DoubleValue* dval);

        shared_ptr<IntValue> visitString(StringValue* sval);
    };


    class ToDoubleVisitor : public IVisitor {
    public:
        shared_ptr<DoubleValue> visitInt(IntValue* ival);

        shared_ptr<DoubleValue> visitBool(BoolValue* bval);

        shared_ptr<DoubleValue> visitDouble(DoubleValue* dval);

        shared_ptr<DoubleValue> visitString(StringValue* sval);
    };


    class ToStringVisitor : public IVisitor {
    public:
        shared_ptr<StringValue> visitInt(IntValue* ival);

        shared_ptr<StringValue> visitBool(BoolValue* bval);

        shared_ptr<StringValue> visitDouble(DoubleValue* dval);

        shared_ptr<StringValue> visitString(StringValue* sval);
    };

}
#endif
