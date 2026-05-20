#include <iostream>
#include "query_interface.h"
#include "storage_engine.h"
#include "math_utils.h"

int main(){

    Record<double> testRecord{1, "first", 20.0};
    std::cout << testRecord.id << testRecord.name << testRecord.value << std::endl;

    StorageEngineDUMap storageA;
    storageA.insertRecord(testRecord);
    
    //what is the difference between including a return nullptr for this method?
    //this implementation returns a pointer to an existing record which means it can be modified without using the StorageEngineD interface
    DoubleRecord* readRecord = storageA.readRecord(1);
    std::cout << readRecord->value << std::endl;
    
    // //a secondary problem of this is in the update method, in order to update a record we'll need to either have an existing copy of the same record on hand for input
    // //or we'll update the existing record then have the engine record the update (but this is repetitive since updating the pointer will change it in the db too) 
    DoubleRecord readRecordUpdated {1, "firstupdated", 23.0};
    storageA.updateRecord(readRecordUpdated);

    storageA.deleteRecord(1);
    readRecord = storageA.readRecord(1);    
    std::cout << (readRecord == nullptr ? true : false) << std::endl;

    

    return 0;
}

//expected output
//1first20
//20
//25
//true