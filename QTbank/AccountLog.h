//
// Created by lee on 2024. 8. 10..
//

#ifndef ACCOUNTLOG_H
#define ACCOUNTLOG_H
#include <string>

class User;

class AccountLog {
public:
    virtual std::string show_log() = 0;
    virtual User* get_loged_user() = 0;
};
#endif //ACCOUNTLOG_H
