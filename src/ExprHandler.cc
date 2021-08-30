#include "ExprHandler.h"
#include "Chain.h"
#include <string>

using std::string;
using std::shared_ptr;

namespace MYLANG {

    shared_ptr<IValue> ExprHandler::run(IAST *root) {
        MasterChain *chain = MasterChain::getInstance();
        shared_ptr<IValue> res;

        switch (root->getTokenType()) {
            case INT: {
                const string &str = root->getText();
                return std::make_shared<IntValue>(std::stoi(root->getText()));
            }

            case ID: {
                string s(root->getText());
                if (!vars->isDefined(s)) {
                    handle_error("variable '" + s + "' is not defined");
                }
                return vars->getVal(s);
            }

            case DEF: {
                string varname = root->getChild(0)->getText();
                if (vars->isInCurrent(varname)) {
                    std::cout << "redefined variable \"" << varname << "\"" << std::endl;
                    exit(-1);
                }

                if (root->getChildCount() > 1) {
                    res = chain->process(root->getChild(1), this->vars);
                    vars->addVar(varname, res);
                } else {
                    // by default, initialized with 0
                    vars->addVar(varname);
                    res = 0;
                }

                return res;
            }

            // arithmetic binary operation
            case PLUS:
            case MINUS:
            case TIMES:
            case DIV:
            case EQ:
            case NE:
            case GT:
            case GE:
            case LT:
            case LE: {
                shared_ptr<IValue> lop = chain->process(root->getChild(0), this->vars);
                shared_ptr<IValue> rop = chain->process(root->getChild(1), this->vars);
                lop->binOp(rop, root->getTokenType());
            } break;

            case ASSIGN: {
                string varname(root->getChild(0)->getText());
                if (!vars->isDefined(varname)) {
                    throw std::runtime_error("variable '" + varname + "' is not defined");
                }
                res = chain->process(root->getChild(1), this->vars);
                vars->setVal(varname, res);
                return res;
            }

            default:
                throw std::runtime_error("unknown handler: " + std::string(root->getText()));
        }

    }

    IMaster *ExprHandler::ExprFactory::create(shared_ptr<Context> ctx) {
        return new ExprHandler(ctx);
    }

    bool ExprHandler::ExprFactory::isValid(IAST *tree) {
        int tok = tree->getTokenType();
        return tok == INT ||
               tok == ID ||
               tok == PLUS ||
               tok == MINUS ||
               tok == TIMES ||
               tok == DIV ||
               tok == ASSIGN ||
               tok == DEF;
    }



}