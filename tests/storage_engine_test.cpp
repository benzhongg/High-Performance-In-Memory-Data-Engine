#include <gtest/gtest.h>
#include "storage_engine.h"
#include "query_interface.h"
#include "query_layer.h"

TEST(StorageEngineGeneralMethodsTest, ReadInsertUpdateDelete){
    StorageEngineDUMap storageA;
    Record<double> testRecord{1, "first", 20.0};
    
    storageA.insertRecord(testRecord);
    SUCCEED();
    
    DoubleRecord* readRecord = storageA.readRecord(1);
    // EXPECT_EQ(testRecord, storageA.readRecord(1));

    // DoubleRecord readRecordUpdated {1, "firstupdated", 23.0};
    // storageA.updateRecord(readRecordUpdated);
    // SUCCEED();

    // storageA.deleteRecord(1);
    // SUCCEED();

    // readRecord = storageA.readRecord(1);
    // EXPECT_EQ(readRecord, nullptr);    

}