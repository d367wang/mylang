#ifndef _BASE_H
#define _BASE_H

#include "LangLexer.h"
#include "LangParser.h"
#include "Context.h"
#include "ast.h"
#include <memory>
#include <stdexcept>

using namespace std;

class Context;
class IVisitor;

enum class ValueType {
    INT32, DOUBLE, STR
};

class IValue {
public:
    IValue() {}
    virtual ~IValue() {}

    virtual ValueType getType() = 0;
    virtual shared_ptr<IValue> accept(IVisitor* visitor) = 0;

    shared_ptr<IValue> binOp(shared_ptr<IValue> other, int type);
    virtual shared_ptr<IValue> cmpOp(shared_ptr<IValue> other, int type) = 0;
    virtual shared_ptr<IValue> arithOp(shared_ptr<IValue> other, int type) = 0;

    static const shared_ptr<IValue> pTrueVal, pFalseVal, pNullVal;
};

class IMaster {
protected:
    shared_ptr<Context> vars;
public:
    IMaster(shared_ptr<Context> v) : vars(v) {}

    virtual ~IMaster() {}

    virtual shared_ptr<IValue> run(IAST *root) = 0;

    virtual void handle_error(string msg) {
        throw runtime_error(msg);
    }
};


class IFactory {
public:
    IFactory(IFactory *n) : next(n) {}

    virtual IMaster *create(shared_ptr<Context>) = 0;

    virtual bool isValid(IAST *) = 0;

    IFactory *next;
};


#endif
