#include "ExprHandler.h"
#include "TreeUtils.h"
#include "Chain.h"
#include <iostream>

using std::string;

const auto getTokenType = TreeUtils::getTokenType;
const auto getText = TreeUtils::getText;
const auto getChild = TreeUtils::getChild;
const auto getChildCount = TreeUtils::getChildCount;

int ExprHandler::run(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    MasterChain* chain = MasterChain::getInstance(); 
    int res;
    
    switch (getTokenType(root))
    {
    case INT:
    {
        const char *str = getText(root);
        if (str[0] == '-')
            return -atoi(getText(root));
        else
            return atoi(getText(root));
    }

    case ID:
    {
        string s(getText(root));
        if (!vars->isDefined(s)) {
            return handle_error("variable '" + s + "' is not defined");
        }
        return vars->getVal(s);
    }

    case PLUS:
        return chain->process(getChild(root, 0), this->vars) +
               chain->process(getChild(root, 1), this->vars);

    case MINUS:
        return chain->process(getChild(root, 0), this->vars) -
               chain->process(getChild(root, 1), this->vars);

    case TIMES:
        return chain->process(getChild(root, 0), this->vars) *
               chain->process(getChild(root, 1), this->vars);

    case DIV:
    {
        int den = chain->process(getChild(root, 1), this->vars);
        if (den == 0)
        {
            std::cout << "divide by zero: " << std::endl;
            return -1;
        }

        return chain->process(getChild(root, 0), this->vars) / den;
    }

    case ASSIGN:
    {
        string varname( getText(getChild(root, 0)) );
        if (!vars->isDefined(varname)) {
            return handle_error("variable '" + varname + "' is not defined");
        }
        int &store = vars->getVal(varname);
        store = chain->process(getChild(root, 1), this->vars);
        return store;
    }

    case DEF:
    {
        string varname = getText(getChild(root, 0));
        if (vars->isInCurrent(varname))
        {
            std::cout << "redefined variable \"" << varname << "\"" << std::endl;
            exit(-1);
        }

        if (getChildCount(root) > 1)
        {
            res = chain->process(getChild(root, 1), this->vars);
            vars->addVar(varname, res);
        }
        else
        {
            // by default, initialized with 0
            vars->addVar(varname);
            res = 0;
        }

        return res;
    }

    default:
        return handle_error("unknown handler: " + std::string(getText(root)));
    }

}

IMaster* ExprHandler::ExprFactory::create(Context *ctx) {
    return new ExprHandler(ctx);
}

bool ExprHandler::ExprFactory::isValid(pANTLR3_BASE_TREE tree) {
    int tok = getTokenType(tree);
    return tok == INT ||
            tok == ID ||
            tok == PLUS ||
            tok == MINUS ||
            tok == TIMES ||
            tok == DIV ||
            tok == ASSIGN ||
            tok == DEF;
}
