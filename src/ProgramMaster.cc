#include "ProgramMaster.h"
#include "Chain.h"
#include "Utils.h"

const auto getText = Utils::getText;
const auto getChild = Utils::getChild;


int ProgramMaster::run(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    int res;

    // root for AST of the file
    if (!tok) {
        int cnt;
        cnt = root->getChildCount(root);
        for (int i = 0; i < cnt; i++)
        {
            res = MasterChain::getInstance()->process(getChild(root, i));
        }
        return res;
    }


    //
    switch (tok->type)
    {
    case INT:
    {
        const char *str = getText(root);
        if (str[0] == '-')
            return -atoi(getText(root));
        else
            return atoi(getText(root))
    }

    case ID:
    {
        string s(getText(root));
        return find(s);
    }

    case PLUS:
        return eval(getChild(root, 0)) +
               eval(getChild(root, 1));

    case MINUS:
        return eval(getChild(root, 0)) -
               eval(getChild(root, 1));

    case TIMES:
        return eval(getChild(root, 0)) *
               eval(getChild(root, 1));

    case DIVIDE:
    {
        int den = eval(getChild(root, 1));
        if (den == 0)
        {
            std::cout << "divide by zero: "
                      << std::endl;
            return -1;
        }

        return eval(getChild(root, 0)) / den;
    }

    case ASSIGN:
    {
        string varname = getText(getChild(root, 0));
        int &store = find(varname);
        store = eval(getChild(root, 1));
        return store;
    }

    case VAR:
    {
        string varname = getText(getChild(root, 0));
        if (mmap.count(varname))
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

    case PRINT:
    {
        int res = eval(getChild(root, 0));
        cout << res << endl;
        return res;
    }

    case BLOCK:
    {
        ExprEvaluator inner_block(this);
        int cnt = root->getChildCount(root), res;
        for (int i = 0; i < cnt; i++)
        {
            res = inner_block.eval(getChild(root, i));
        }
        return res;
    }

    default:
        cout << "unknown handler: "
             << getText(root) << endl;
        return -1;
    }

}
