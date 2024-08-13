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
    User *find_by_id(string id);
public:
    AccountLogger(){};
    static AccountLogger& getLogger();
    void set_log(std::shared_ptr<AccountLog> log);
    void show_all_log();
    int get_size();
    std::vector<std::string> get_all_logs();
    std::vector<std::string> get_all_deposit_logs();
    std::vector<std::string> get_all_withdraw_logs();
    std::vector<std::string> get_all_user_logs(string id);
    void save_all_logs();
    void load_all_logs();
};

#endif //ACCOUNTLOGGER_H
