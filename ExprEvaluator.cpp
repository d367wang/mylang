#include "ExprEvaluator.h"
#include <cassert>
#include <string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;
using std::map;


pANTLR3_BASE_TREE ExprEvaluator::getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) (tree->getChild(tree, i));
}
const char* ExprEvaluator::getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}


int ExprEvaluator::find(string key) {
    if (mmap.count(key)) return mmap[key];
    assert(next != nullptr);
    return next->find(key);
}

int ExprEvaluator::eval(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    if (tok != nullptr) {
        switch (tok->type) {
            case INT: {
                const char* str = getText(root);
                if (str[0] == '-')
                return -atoi(getText(root));
                else 
                return atoi(getText(root));
            } 

            case ID: {
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

            case DIVIDE: {
                int den = eval(getChild(root, 1)); 
                if (den == 0) {
                    std::cout << "divide by zero: " 
                    << std::endl;
                    return -1;
                }

                return eval(getChild(root, 0)) / den;
            }

            case ASSIGN: {
                string varname = getText(getChild(root, 0));
                int rval = eval(getChild(root, 1));
                mmap[varname] = rval;
                return rval;
            } 

            case VAR: {
                string varname = getText(getChild(root, 0));
                if (mmap.count(varname)) {
                    cout << "redefine variable \"" << varname << "\"" << endl;
                    return -1;
                } 

                if (getChild(root, 1) != nullptr) {
                    mmap[varname] = eval(getChild(root, 1));  
                } else {
                    mmap[varname] = 0;  // by default, initialized with 0
                }
                return mmap[varname];
            }

            case PRINT: {
                int res = eval(getChild(root, 0)); 
                cout << res << endl;
                return res;
            }

            case BLOCK: {
                ExprEvaluator inner_block(this);
                int cnt = root->getChildCount(root), res;
                for (int i = 0; i < cnt; i++) {
                    res = inner_block.eval(getChild(root, i));
                }
                return res;
            }

            default:
                cout << "unknown handler: " 
                             << getText(root) << endl;
                return -1;
        }

    } else {
        int res, cnt;
        cnt = root->getChildCount(root);
        for (int i = 0; i < cnt; i++) {
            res = eval(getChild(root, i));
        }

        return res;
    }
}

