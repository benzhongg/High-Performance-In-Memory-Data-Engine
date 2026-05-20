#pragma once
#include <string>

template <typename T> 
struct Record {
    int id;
    std::string name;
    T value;
};

//new typedef
//Classic C/C++ -> typedef Record<float> FloatRecord;

//type alias supports alias templates
using DoubleRecord = Record<double>;
using IntRecord = Record<int>;
using StringRecord = Record<std::string>;

//QueryInterface interacts with all types of record
template <typename T>
class QueryInterface{
    
    protected:

    public:
        //pure virtual make functions equal to 0
        //0 means not defined here
        virtual void insertRecord(const Record<T> &record) = 0; //create
        virtual Record<T>* readRecord(const int recordID) = 0; //read
        virtual void updateRecord(const Record<T> &record) = 0; //get
        virtual void deleteRecord(const int recordID) = 0; //get and delete
        //not a pure virtual below
        virtual void init(){

        }
};


