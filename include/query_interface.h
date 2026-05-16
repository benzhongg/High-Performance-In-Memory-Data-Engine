#pragma once
#include <string>

template <typename T> 
struct Record {
    int id;
    std::string name;
    T value;
};

//interface should be compatible with every record
template <typename T>
class QueryInterface{
    protected:

    public:
        //pure virtual make functions equal to 0
        //0 means not defined here
        virtual void createRecord(const Record &record) = 0; //create
        virtual Record* readRecord() = 0; //read
        virtual void updateRecord(const Record &record) = 0; //get
        virtual void deleteRecord(const Record &record) = 0; //get and delete
        //not a pure virtual below
        virtual void init(){

        }
};

//new typedef
using DoubleRecord = Record<double>;
using IntRecord = Record<int>;
using StringRecord = Record<std::string>;
