//
// Created by lee on 2024. 8. 10..
//

#include "AccountLogger.h"

#include <QtCore>

AccountLogger AccountLogger::logger;

AccountLogger& AccountLogger::getLogger() {
    return logger;
}

int AccountLogger::get_size() {
    return logVector.size();
}

void AccountLogger::set_log(AccountLog *log) {
    logVector.push_back(log);
}

void AccountLogger::show_all_log() {
    for(AccountLog * log :logVector) {
        qDebug() << log->show_log();
    }
}
