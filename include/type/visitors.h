#ifndef _VISITOR_H
#define _VISITOR_H

#include <memory>
#include "IVisitor.h"
#include "base.h"


class ToIntVisitor : public IVisitor {
    public:
        shared_ptr<IValue> visitInt(IntValue* ival);

        shared_ptr<IValue> visitDouble(DoubleValue* dval);

        shared_ptr<IValue> visitString(StringValue* sval);
    };


    class ToDoubleVisitor : public IVisitor {
    public:
        shared_ptr<IValue> visitInt(IntValue* ival);

        shared_ptr<IValue> visitDouble(DoubleValue* dval);

        shared_ptr<IValue> visitString(StringValue* sval);
    };


    class ToStringVisitor : public IVisitor {
    public:
        shared_ptr<IValue> visitInt(IntValue* ival);

        shared_ptr<IValue> visitDouble(DoubleValue* dval);

        shared_ptr<IValue> visitString(StringValue* sval);
    };


#endif
