#ifndef _TYPES_H
#define _TYPES_H

#include <string>
#include <stdexcept>
#include <utility>
#include "base.h"

using std::shared_ptr;
using std::string;

namespace MYLANG {

    enum ValueType {
        INT32, DOUBLE, STR
    };

    class IntValue;
    class DoubleValue;
    class StringValue;

    class IValue {
    public:
        IValue() {}
        virtual ~IValue() {}

        class IVisitor {
        public:
            virtual shared_ptr<IValue> visitInt(IntValue* ival) = 0;
            virtual shared_ptr<IValue> visitDouble(DoubleValue* dval) = 0;
            virtual shared_ptr<IValue> visitString(StringValue* sval) = 0;
        };

        virtual ValueType getType() = 0;
        virtual shared_ptr<IValue> accept(IVisitor* visitor) = 0;

        shared_ptr<IValue> binOp(shared_ptr<IValue> other, int type);
        virtual shared_ptr<IValue> cmpOp(shared_ptr<IValue>, int type) = 0;
        virtual shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type) = 0;

        static const shared_ptr<IValue> pTrueVal, pFalseVal, pNullVal;
    };

    class IntValue : public IValue {
    private:
        int val;
    public:
        explicit IntValue(int val) : val(val) {}
        ~IntValue() {}

        int getValue() const { return val; }
        void setValue(int v) { val = v; }
        ValueType getType() { return INT32; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitInt(this);};

        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };


    class DoubleValue : public IValue {
    private:
        double val;
    public:
        explicit DoubleValue(int val) : val(val) {}
        ~DoubleValue() = default;

        double getValue() const { return val; }
        ValueType getType() { return DOUBLE; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitDouble(this);};

        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };


    class StringValue : public IValue {
    private:
        string val;
    public:
        explicit StringValue(const char *str) : val(str) {}
        explicit StringValue(string  str) : val(std::move(str)) {}
        explicit StringValue(string &&str) : val(std::move(str)) {}
        ~StringValue() {}

        const string &getValue() const { return val; }
        void setValue(string&& str) { val = std::move(str); }
        ValueType getType() { return STR; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitString(this);};


        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };

}
#endif
