#pragma once

#include "query_interface.h"
#include <unordered_map>
#include <map>

class StorageEngineDMap:public QueryInterface <double> {
    protected:
        std::map<const int, DoubleRecord> storageRecordMap; 
    
    public:
        void insertRecord(const DoubleRecord &record) override;
        DoubleRecord* readRecord(const int recordID) override;
        void updateRecord(const DoubleRecord &record) override;
        void deleteRecord(const int recordID) override;

};

class StorageEngineDUMap:public QueryInterface <double> {
    protected:
        std::unordered_map<int, DoubleRecord> storageRecordUMap;
    
    public:
        void insertRecord(const DoubleRecord &record) override;
        DoubleRecord* readRecord(const int recordID) override;
        void updateRecord(const DoubleRecord &record) override;
        void deleteRecord(const int recordID) override;
};

// class QueryRecordI:public QueryInterface <int> {
//     protected:
//     public:

//         void createRecord(const IntRecord &record) override;
//         IntRecord* readRecord() override; //read
//         void updateRecord(const IntRecord &record) override;
//         void deleteRecord(const IntRecord &record) override;

// };
// class QueryRecordStr:public QueryInterface <std::string> {
//     protected:
//     public:

//         void createRecord(const StringRecord &record) override;
//         StringRecord* readRecord() override; //read
//         void updateRecord(const StringRecord &record) override;
//         void deleteRecord(const StringRecord &record) override;

// };