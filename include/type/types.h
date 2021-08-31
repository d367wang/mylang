#ifndef _TYPES_H
#define _TYPES_H

#include <string>
#include <stdexcept>
#include <utility>
#include "base.h"

    class IValue;
    class IVistor;

    class IntValue : public IValue {
    private:
        int val;
    public:
        explicit IntValue(int val) : val(val) {}
        ~IntValue() {}

        int getValue() { return val; }
        void setValue(int v) { val = v; }
        ValueType getType() { return ValueType::INT32; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitInt(this);}

        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };


    class DoubleValue : public IValue {
    private:
        double val;
    public:
        explicit DoubleValue(double val) : val(val) {}
        ~DoubleValue() = default;

        double getValue() { return val; }
        void setValue(double v) { val = v; }
        ValueType getType() { return ValueType::DOUBLE; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitDouble(this);}

        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };


    class IVisitor;

    class StringValue : public IValue {
    private:
        string val;
    public:
        explicit StringValue(const char *str) : val(str) {}
        explicit StringValue(string  str) : val(move(str)) {}
        explicit StringValue(string &&str) : val(move(str)) {}
        ~StringValue() {}

        const string &getValue() { return val; }
        void setValue(string&& str) { val = move(str); }
        ValueType getType() { return ValueType::STR; }
        shared_ptr<IValue> accept(IVisitor* visitor) {return visitor->visitString(this);}

        shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type);
        shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type);
    };


#endif
