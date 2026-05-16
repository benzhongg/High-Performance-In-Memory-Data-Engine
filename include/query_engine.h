#pragma once

#include "query_interface.h"


class QueryRecord:public QueryInterface <double> {
    protected:
    public:

        void createRecord(const DoubleRecord &record) override;//create
        DoubleRecord* readRecord() override; //read
        void updateRecord(const DoubleRecord &record) override; //get
        void deleteRecord(const DoubleRecord &record) override; //get and delete};

    };