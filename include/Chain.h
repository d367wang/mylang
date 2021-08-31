#ifndef _CHAIN_H
#define _CHAIN_H

#include "base.h"
#include "ProgramHandler.h"
#include "ExprHandler.h"
#include "IfHandler.h"
#include "PrintHandler.h"

    class MasterChain {
        IFactory *headF;

        MasterChain() {
            // init factory linkedlist
            headF = new PrintHandler::PrintFactory(nullptr);
            headF = new IfHandler::IFFactory(headF);
            headF = new ExprHandler::ExprFactory(headF);
            headF = new ProgramHandler::ProgramFactory(headF);
        }

    public:
        static MasterChain *getInstance();

        shared_ptr<IValue> process(IAST *, shared_ptr<Context> ctx);
    };

#endif
