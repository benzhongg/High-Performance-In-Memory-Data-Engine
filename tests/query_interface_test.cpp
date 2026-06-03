#include <gtest/gtest.h>
#include "query_interface.h"

TEST(RecordCreationTest, AccessingValues){
    Record<double> testRecord{1, "first", 20.0};
    EXPECT_EQ(testRecord.id, 1);
    EXPECT_EQ(testRecord.name, "first");
    EXPECT_EQ(testRecord.value, 20.0);
}

