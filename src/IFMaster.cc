#include "IFMaster.h"
#include "Utils.h"

const auto getText = Utils::getText;
const auto getChild = Utils::getChild;

int IFMaster::run(pANTLR3_BASE_TREE root) {
    pANTLR3_COMMON_TOKEN tok = root->getToken(root);
    int res;

    if (tok->type == IF)
    {

    }

    cout << "unknown handler: "
         << getText(root) << endl;
    return -1;
}