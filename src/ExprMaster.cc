#include "ExprMaster.h"
#include "Utils.h"
#include "Chain.h"
#include <iostream>

const auto getText = Utils::getText;
const auto getChild = Utils::getChild;

int ExprMaster::run(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    MasterChain* chain = MasterChain::getInstance(); 
    int res;
    
    switch (tok->type)
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
        return vars->find(s);
    }

    case PLUS:
        return chain->process(getChild(root, 0)) +
               chain->process(getChild(root, 1));

    case MINUS:
        return chain->process(getChild(root, 0)) -
               chain->process(getChild(root, 1));

    case TIMES:
        return chain->process(getChild(root, 0)) *
               chain->process(getChild(root, 1));

    case DIV:
    {
        int den = chain->process(getChild(root, 1));
        if (den == 0)
        {
            std::cout << "divide by zero: "
                      << std::endl;
            return -1;
        }

        return chain->process(getChild(root, 0)) / den;
    }

    case ASSIGN:
    {
        string varname = getText(getChild(root, 0));
        int &store = vars->find(varname);
        store = chain->process(getChild(root, 1));
        return store;
    }

    case DEF:
    {
        string varname = getText(getChild(root, 0));
        if (vars.count(varname))
        {
            cout << "redefined variable \"" << varname << "\"" << endl;
            exit(-1);
        }

        if (getChild(root, 1) != nullptr)
        {
            mmap[varname] = eval(getChild(root, 1));
        }
        else
        {
            mmap[varname] = 0; // by default, initialized with 0
        }
        return mmap[varname];
    }

    default:
        cout << "unknown handler: "
             << getText(root) << endl;
        return -1;
    }

}