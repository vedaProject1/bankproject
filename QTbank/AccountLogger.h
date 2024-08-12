//
// Created by lee on 2024. 8. 10..
//

#ifndef ACCOUNTLOGGER_H
#define ACCOUNTLOGGER_H
#include <string>
#include <vector>
#include "AccountLog.h"
using namespace  std;
#include<memory>


class AccountLogger {

    static AccountLogger logger;
    std::vector<std::shared_ptr<AccountLog>> logVector;
public:
    AccountLogger(){};
    static AccountLogger& getLogger();
    void set_log(std::shared_ptr<AccountLog> log);
    void show_all_log();
    int get_size();
};

#endif //ACCOUNTLOGGER_H
