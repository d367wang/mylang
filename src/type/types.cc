#include "base.h"
#include "types.h"
#include "base.h"
#include "visitor.h"
#include <iostream>

    static const shared_ptr<IValue> pTrueVal(new IntValue(1));
    static const shared_ptr<IValue> pFalseVal(new IntValue(0));
    static const shared_ptr<IValue> pNullVal(new StringValue(""));


/**************************  Base ******************************/
//    shared_ptr<IValue> IValue::binOp(shared_ptr<IValue> other, int type) {
//        if (type == PLUS || type == MINUS || type == TIMES || type == DIV)
//            return this->arithOp(other, type);
//        else
//            return this->cmpOp(other, type);
//    }


/**************************  Int ******************************/
    static int reverse(int type) {
        switch (type) {
            case EQ: return EQ;
            case NE: return NE;
            case GT: return LE;
            case GE: return LT;
            case LT: return GE;
            case LE: return GT;
            default: throw runtime_error("cperator not supported");
        }
    }

    shared_ptr<IValue> IntValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToIntVisitor visitor;

        // when the other operand has wider type (like double, string, etc), call the
        // other's member function
        if (other->getType() > ValueType::INT32) return other->arithOp(shared_ptr<IValue>(this), type);

        shared_ptr<IntValue> tmp;
        // when the other operand has equal or wider type (like double, string, etc), call the
        // other's member function
        tmp = other->accept(&visitor);
        switch (type) {
            case PLUS:
                tmp->setValue(getValue() + tmp->getValue()); break;
            case MINUS:
                tmp->setValue(getValue() - tmp->getValue()); break;
            case TIMES:
                tmp->setValue(getValue() * tmp->getValue()); break;
            case DIV:
                if (tmp->getValue() == 0) throw runtime_error("divde by 0");
                tmp->setValue(getValue() / tmp->getValue()); break;
        }
        return tmp;
    }

    shared_ptr<IValue> IntValue::cmpOp(shared_ptr<IValue> other, int type) {
        if (getType() < other->getType()) {
            return other->cmpOp(shared_ptr<IValue>(this), reverse(type));
        }

        static ToIntVisitor visitor;
        shared_ptr<IntValue> tmp = (static_pointer_cast<IntValue>) (other->accept(&visitor));
        switch (type) {
            case EQ:
                return tmp->getValue() == getValue() ? pTrueVal : pFalseVal;
            case GT:
                return tmp->getValue() > getValue() ? pTrueVal : pFalseVal;
            default: throw runtime_error("cperator not supported");
        }
    }


/*********************  Double ******************************/
    shared_ptr<IValue> DoubleValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToDoubleVisitor visitor;

        // when the other operand has wider type (like double, string, etc), call the
        // other's member function
        if (other->getType() > ValueType::DOUBLE) return other->arithOp(shared_ptr<IValue>(this), type);

        // when the other operand has equal or wider type (like double, string, etc), call the
        // other's member function
        shared_ptr<DoubleValue> tmp = static_pointer_cast<DoubleValue>(other->accept(&visitor));
        switch (type) {
            case PLUS:
                tmp->setValue(getValue() + tmp->getValue()); break;
            case MINUS:
                tmp->setValue(getValue() - tmp->getValue()); break;
            case TIMES:
                tmp->setValue(getValue() * tmp->getValue()); break;
            case DIV:
                if (tmp->getValue() == 0) throw runtime_error("divde by 0");
                tmp->setValue(getValue() / tmp->getValue()); break;
        }
        return tmp;
    }

    shared_ptr<IValue> DoubleValue::cmpOp(shared_ptr<IValue> other, int type) {
        if (getType() < other->getType()) {
            return other->cmpOp(shared_ptr<IValue>(this), reverse(type));
        }

        static ToDoubleVisitor visitor;
        shared_ptr<DoubleValue> tmp = (static_pointer_cast<DoubleValue>) (other->accept(&visitor));
        switch (type) {
            case EQ:
                return getValue() == tmp->getValue()? pTrueVal : pFalseVal;
            case GT:
                return getValue() > tmp->getValue() ? pTrueVal : pFalseVal;
            default: throw runtime_error("cperator not supported");
        }
    }


/**************************  String ******************************/

    shared_ptr<IValue> StringValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToStringVisitor visitor;

        shared_ptr<StringValue> tmp = (static_pointer_cast<StringValue>) (other->accept(&visitor));
        shared_ptr<IntValue> num;
        // when the other operand has equal or wider type (like double, string, etc), call the
        // other's member function
        switch (type) {
            case PLUS:
                tmp->setValue(getValue() + tmp->getValue()); break;
            case MINUS:
                throw runtime_error("string subtraction is not supported ");
            case DIV:
                throw runtime_error("string division is not supported ");

            case TIMES:     // special
                // if other is also string, concate it to this string
                num = dynamic_pointer_cast<IntValue>(other);
                if (!num) {
                    throw runtime_error("only support a string times an integer");
                }

                // if other is int value, duplicate this string n times
                for (int i = 1; i < num->getValue(); i++) {
                    tmp->setValue(tmp->getValue() + getValue()); // append this string to temporary, n - 1 times
                }
                break;
            default:
                throw runtime_error("unexpected operator");
        }
        return tmp;
    }

    shared_ptr<IValue> StringValue::cmpOp(shared_ptr<IValue> other, int type) {
        static ToStringVisitor visitor;
		shared_ptr<StringValue> tmp = (dynamic_pointer_cast<StringValue>) (other->accept(&visitor));
        switch (type) {
            case EQ:
                return tmp->getValue() == getValue() ? pTrueVal : pFalseVal;
            case GT:
                return tmp->getValue() > getValue() ? pTrueVal : pFalseVal;
            default: throw runtime_error("cperator not supported");
        }

    }

    shared_ptr<IValue> IValue::binOp(shared_ptr<IValue> other, int type) {
        if (type == PLUS || type == MINUS || type == TIMES || type == DIV)
            return this->arithOp(other, type);
        else
            return this->cmpOp(other, type);
        return IValue::pNullVal;
    }

