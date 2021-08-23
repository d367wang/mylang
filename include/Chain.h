#ifndef _CHAIN_H
#define _CHAIN_H

#include "base.h"
#include "ProgramMaster.h"
#include "ExprMaster.h"
#include "IFMaster.h"
#include "PrintMaster.h"

class MasterChain {
    IFactory* headF;
    MasterChain() {
        // init factory linkedlist
        headF = new PrintMaster::PrintFactory(nullptr);
        headF = new IFMaster::IFFactory(headF);
        headF = new ExprMaster::ExprFactory(headF);
        headF = new ProgramMaster::ProgramFactory(headF);
    }
public:
    static MasterChain* getInstance();
    int process(pANTLR3_BASE_TREE, Context* ctx);
};

#endif
