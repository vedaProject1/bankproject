//
// Created by lee on 2024. 8. 10..
//

#include "AccountLogger.h"

#include <QtCore>

AccountLogger AccountLogger::logger;

AccountLogger& AccountLogger::getLogger() {
    return logger;
}

void AccountLogger::set_log(shared_ptr<AccountLog> log) {
    logVector.push_back(log);
}

int AccountLogger::get_size() {
    return logVector.size();
}

void AccountLogger::show_all_log() {
    for(shared_ptr<AccountLog> log :logVector) {
        qDebug() << log->show_log();
    }
}
