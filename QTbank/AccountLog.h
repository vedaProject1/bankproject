//
// Created by lee on 2024. 8. 10..
//

#ifndef ACCOUNTLOG_H
#define ACCOUNTLOG_H
#include <string>
#include <fstream>
class User;

class AccountLog {
public:
    virtual std::string show_log() = 0;
    virtual User* get_loged_user() = 0;
    virtual void save(std::ofstream & outFile)=0;
};
#endif //ACCOUNTLOG_H
