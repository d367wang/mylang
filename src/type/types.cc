#include "types.h"
#include "base.h"
#include "visitor.h"
#include <iostream>

namespace MYLANG {
    static const std::shared_ptr<IValue> pTrueVal(new IntValue(1));
    static const std::shared_ptr<IValue> pFalseVal(new IntValue(0));
    static const std::shared_ptr<IValue> pFalseVal(new StringValue(""));


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
            default: throw std::runtime_error("cperator not supported");
        }
    }

    shared_ptr<IValue> IntValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToIntVisitor visitor;

        // when the other operand has wider type (like double, string, etc), call the
        // other's member function
        if (other->getType() > INT32) return other->arithOp(this);

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
                if (tmp->getValue() == 0) throw std::runtime_error("divde by 0");
                tmp->setValue(getValue() / tmp->getValue()); break;
        }
        return tmp;
    }

    shared_ptr<IValue> IntValue::cmpOp(shared_ptr<IValue> other, int type) {
        if (getType() < other->getType()) {
            return other->cmpOp(this, reverse(type));
        }

        static ToIntVisitor visitor;
        shared_ptr<IntValue> tmp = other->accept(&visitor);
        switch (type) {
            case EQ:
                return tmp->getValue() == getValue() ? pTrueVal : pFalseVal;
            case GT:
                return tmp->getValue() > getValue() ? pTrueVal : pFalseVal;
            default: throw std::runtime_error("cperator not supported");
        }
    }


/*********************  Double ******************************/
    shared_ptr<IValue> DoubleValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToDoubleVisitor visitor;

        // when the other operand has wider type (like double, string, etc), call the
        // other's member function
        if (other->getType() > DOUBLE) return other->arithOp(this);

        shared_ptr<DoubleValue> tmp;
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
                if (tmp->getValue() == 0) throw std::runtime_error("divde by 0");
                tmp->setValue(getValue() / tmp->getValue()); break;
        }
        return tmp;
    }

    shared_ptr<IValue> DoubleValue::cmpOp(shared_ptr<IValue> other, int type) {
        if (getType() < other->getType()) {
            return other->cmpOp(this, reverse(type));
        }

        static ToDoubleVisitor visitor;
        shared_ptr<DoubleValue> tmp = other->accept(&visitor);
        switch (type) {
            case EQ:
                return tmp->getValue() == getValue() ? pTrueVal : pFalseVal;
            case GT:
                return tmp->getValue() > getValue() ? pTrueVal : pFalseVal;
            default: throw std::runtime_error("cperator not supported");
        }
    }


/**************************  String ******************************/

    shared_ptr<IValue> StringValue::arithOp(shared_ptr<IValue> other, int type) {
        static ToDoubleVisitor visitor;

        shared_ptr<StringValue> tmp;
        // when the other operand has equal or wider type (like double, string, etc), call the
        // other's member function
        switch (type) {
            case PLUS:
                tmp = other->accept(&visitor);
                tmp->setValue(getValue() + tmp->getValue()); break;
            case MINUS:
                throw std::runtime_error("string subtraction is not supported ");
            case DIV:
                throw std::runtime_error("string division is not supported ");

            case TIMES:     // special
                // if other is also string, concate it to this string
                StringValue* sv = dynamic_cast<StringValue*>(other.get());
                if (sv != nullptr) {
                    tmp->setValue(tmp->getValue() + getValue());
                    break;
                }

                // if other is int value, duplicate this string n times
                tmp = accept(&visitor); // copy this string to temporary
                for (int i = 1; i < tmp->getValue(); i++) {
                    tmp->setValue(tmp->getValue() + getValue()); // append this string to temporary, n - 1 times
                }
                break;
            default:
                throw std::runtime_error("unexpected operator");
        }
        return tmp;
    }

    shared_ptr<IValue> StringValue::cmpOp(shared_ptr<IValue> other, int type) {
        static ToStringVisitor visitor;
        shared_ptr<StringValue> tmp = other->accept(&visitor);
        switch (type) {
            case EQ:
                return tmp->getValue() == getValue() ? pTrueVal : pFalseVal;
            case GT:
                return tmp->getValue() > getValue() ? pTrueVal : pFalseVal;
            default: throw std::runtime_error("cperator not supported");
        }

    }

    shared_ptr<IValue> IValue::binOp(shared_ptr<IValue> other, int type) {
        if (type == PLUS || type == MINUS || type == TIMES || type == DIV)
            return this->arithOp(other, type);
        else
            return this->cmpOp(other, type)
        return shared_ptr<IValue>();
    }
}
