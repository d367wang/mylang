#include "PrintHandler.h"
#include "Chain.h"
#include "visitors.h"
#include <iostream>
#include <types.h>

shared_ptr<IValue> PrintHandler::run(IAST *root) {
        static ToStringVisitor visitor;
        shared_ptr<IValue> res;
        // root for AST of the file
        if (root->getTokenType() == PRINT) {
            res = MasterChain::getInstance()->process(root->getChild(0), this->vars);
            shared_ptr<IValue> iv = res->accept(&visitor);
            shared_ptr<StringValue> sv = static_pointer_cast<StringValue>(iv);
            cout << *sv << endl;
            return res;
        }

        throw runtime_error("unknown handler: " + root->getText());
    }

    IMaster *PrintHandler::PrintFactory::create(shared_ptr<Context> ctx) {
        return new PrintHandler(ctx);
    }

    bool PrintHandler::PrintFactory::isValid(IAST *tree) {
        return tree->getTokenType() == PRINT;
    }

