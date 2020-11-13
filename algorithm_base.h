#ifndef ALGORITHM_BASE_H
#define ALGORITHM_BASE_H
#include<cassert>
class AlgorithmBase {
public:
    AlgorithmBase() {
       assert(mIsHasInstance==false);
       mIsHasInstance = true;
    }
    virtual ~AlgorithmBase() {

    }
protected:
   static bool mIsHasInstance;
};
bool AlgorithmBase::mIsHasInstance = false;

#endif // ALGORITHM_BASE_H
