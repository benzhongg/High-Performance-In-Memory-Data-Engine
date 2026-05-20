#include <iostream>
#include <query_interface.h>
#include <storage_engine.h>

//how can I write a code that can collapse these 4 methods? or a namespace?
void StorageEngineDMap::insertRecord(const DoubleRecord &record) {
    //so we'll need to check if it exists or not
    auto checkIfExists = storageRecordMap.find(record.id);
    if (checkIfExists == storageRecordMap.end()){
        storageRecordMap.insert({record.id, record});
    }
}

DoubleRecord* StorageEngineDMap::readRecord(const int recordId){
    auto verificationIter = storageRecordMap.find(recordId);
    if (verificationIter != storageRecordMap.end()){
        return &storageRecordMap[recordId];
    } else {
        return nullptr;
    } 
}

void StorageEngineDMap::updateRecord(const DoubleRecord &record) {
    auto verificationIter = storageRecordMap.find(record.id);
    if (verificationIter != storageRecordMap.end()){
        storageRecordMap[record.id] = record;
    }
}


void StorageEngineDMap::deleteRecord(const int recordId){
    //because we're using .erase -> we can either pass in our input param recordId or our verificationIter as it accepts both
    auto verificationIter = storageRecordMap.find(recordId);
    if(verificationIter != storageRecordMap.end()){
        storageRecordMap.erase(verificationIter);
    }
}

void StorageEngineDUMap::insertRecord(const DoubleRecord &record){
    auto containsFlag = storageRecordUMap.find(record.id);
    if(containsFlag == storageRecordUMap.end()){
        storageRecordUMap.insert({record.id, record});
    }
}

DoubleRecord* StorageEngineDUMap::readRecord(const int recordId){
    auto containsFlag = storageRecordUMap.find(recordId);
    if (containsFlag != storageRecordUMap.end()){
        return &storageRecordUMap[recordId];
    } else {
        return nullptr;
    }
}

void StorageEngineDUMap::updateRecord(const DoubleRecord &record){
    auto containsFlag = storageRecordUMap.count(record.id);
    if (containsFlag > 0) {
        storageRecordUMap[record.id] = record;
    }
}

//this delete uses count over an iterator, but comeback to it
void StorageEngineDUMap::deleteRecord(const int recordId){
    auto containsFlag = storageRecordUMap.count(recordId);
    if (containsFlag > 0) {
        storageRecordUMap.erase(recordId);
    }
}