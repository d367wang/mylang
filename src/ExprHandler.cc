#include "ExprHandler.h"
#include "Chain.h"
#include <string>
#include <stdexcept>
#include "types.h"


shared_ptr<IValue> ExprHandler::run(IAST *root) {
    MasterChain *chain = MasterChain::getInstance();
    shared_ptr<IValue> res;

    switch (root->getTokenType()) {
        case INT: {
            const string &str = root->getText();
            int ival = stoi(root->getText());
            shared_ptr<IntValue> p = shared_ptr<IntValue>(new IntValue(ival));
            return static_pointer_cast<IValue>(p);
        }

        case ID: {
            string s(root->getText());
            if (!vars->isDefined(s)) {
                handle_error("variable '" + s + "' is not defined");
            }
            return vars->getVal(s);
        }

        case STRING: {
            const string &str = root->getText();
            shared_ptr<StringValue> p = shared_ptr<StringValue>(new StringValue(str));
            return static_pointer_cast<IValue>(p);
        }

        case DEF: {
            IAST* varTree = root->getChild(0);
            string varname = varTree->getText();
            if (vars->isInCurrent(varname)) {
                throw runtime_error("redefined variable \"" + varname + "\"");
            }

            if (varTree->getChildCount() > 0) {
                res = chain->process(varTree->getChild(0), this->vars);
                vars->addVar(varname, res);
            } else {
                // by default, initialized with 0
                vars->addVar(varname);
                res = IValue::pNullVal;
            }

            return res;
        }

            // arithmetic binary operation
        case PLUS:
        case MINUS:
        case TIMES:
        case DIV: {
            shared_ptr<IValue> lop = chain->process(root->getChild(0), this->vars);
            shared_ptr<IValue> rop = chain->process(root->getChild(1), this->vars);
            return lop.get()->arithOp(rop, root->getTokenType());
        }
        case EQ:
        case NE:
        case GT:
        case GE:
        case LESSTHAN:
        case LE: {
            shared_ptr<IValue> lop = chain->process(root->getChild(0), this->vars);
            shared_ptr<IValue> rop = chain->process(root->getChild(1), this->vars);
            return lop.get()->cmpOp(rop, root->getTokenType());
        }

        case ASSIGN: {
            string varname(root->getChild(0)->getText());
            if (!vars->isDefined(varname)) {
                throw runtime_error("variable '" + varname + "' is not defined");
            }
            res = chain->process(root->getChild(1), this->vars);
            vars->setVal(varname, res);
            return res;
        }

        default:
            throw runtime_error("unknown handler: " + string(root->getText()));
    }

}

IMaster *ExprHandler::ExprFactory::create(shared_ptr<Context> ctx) {
    return new ExprHandler(ctx);
}

bool ExprHandler::ExprFactory::isValid(IAST *tree) {
    int tok = tree->getTokenType();
    return tok == INT ||
           tok == ID ||
            tok == STRING ||
           tok == PLUS ||
           tok == MINUS ||
           tok == TIMES ||
           tok == DIV ||
           tok == ASSIGN ||
           tok == DEF;
}


