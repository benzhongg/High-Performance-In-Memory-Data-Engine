#pragma once
#include <storage_engine.h>
#include <functional>

class CustomQuery : public StorageEngineDUMap {
    //input param decision between reference and actual value depend on byte size
    protected:
    
    public:
        DoubleRecord* lowerBound (const int id); 
        DoubleRecord* upperBound (const int id);
        DoubleRecord* getMin ();
        DoubleRecord* getMax ();
        bool exists (const int id);
        const size_t count ();
        DoubleRecord* find (const int id);
        DoubleRecord* find (std::function<bool(const DoubleRecord&)>& search_func);
};