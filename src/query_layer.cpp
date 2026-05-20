#include "query_layer.h"

DoubleRecord* CustomQuery::lowerBound (const int id) {
    //uses inherited storageclass
    for (auto record : storageRecordUMap) {
        if (record.second.id < id){
            return &record.second;
        } 
    }
}

DoubleRecord* CustomQuery::upperBound (const int id) {
    //uses inherited storageclass
    for (auto record : storageRecordUMap) {
        if (record.second.id > id){
            return &record.second;
        } 
    }
}

DoubleRecord* CustomQuery::getMin () {
    int minId = 10'000;
    for (auto record : storageRecordUMap) {
        if (record.second.id < minId){
            minId = record.second.id;
        }
    }    
    return readRecord(minId);
}

DoubleRecord* CustomQuery::getMax() {
    int maxId = 0;
    for (auto record : storageRecordUMap) {
        if (record.second.id > maxId){
            maxId = record.second.id;
        }
    }
    return readRecord(maxId);
}

bool CustomQuery::exists(const int id) {
    return (readRecord(id) != nullptr ? true : false);
}

const size_t CustomQuery::count() {
    return storageRecordUMap.size();    
}

DoubleRecord* CustomQuery::find(const int id) {
    return readRecord(id);
}
//this function grabs a function pointer as param and we pass each record to the param function
//and if returns true we'll return the pointer
DoubleRecord* CustomQuery::find(std::function<bool(const DoubleRecord&)>& search_func){
    for (auto record : storageRecordUMap) {
        if (search_func(record.second)){
            return &record.second;
        }
    }
    return nullptr;
}
