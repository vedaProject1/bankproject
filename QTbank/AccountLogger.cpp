//
// Created by lee on 2024. 8. 10..
//

#include "AccountLogger.h"
#include <fstream>
#include <QtCore>

#include "Admin.h"
extern Admin admin;
AccountLogger AccountLogger::logger;

AccountLogger& AccountLogger::getLogger() {
    return logger;
}

void AccountLogger::set_log(std::shared_ptr<AccountLog> log) {
    logVector.push_back(log);
}

int AccountLogger::get_size() {
    return logVector.size();
}

User * AccountLogger::find_by_id(string id) {

   int idx= admin.search_user_return_idx(id);
    if(idx == 1000) return nullptr;
    User *user =dynamic_cast<User *>(admin.user_list[idx]);
    return user;
}

std::vector<std::string> AccountLogger::get_all_logs() {
    std::vector<std::string> result;
    for(std::shared_ptr<AccountLog> log :logVector) {
        result.push_back(log->show_log());
    }
    return result;
}

std::vector<std::string> AccountLogger::get_all_deposit_logs() {

    vector<std::string> result;
    for(shared_ptr<AccountLog> log : logVector) {
        auto depositLog = std::dynamic_pointer_cast<AccountDepositLog>(log);
        // If cast successful, add to result vector
        if (depositLog) {
            result.push_back(depositLog->show_log());
        }
    }
    return result;



}

std::vector<std::string> AccountLogger::get_all_withdraw_logs() {

    vector<std::string> result;
    for(shared_ptr<AccountLog> log : logVector) {
        auto depositLog = std::dynamic_pointer_cast<AccountWithdrawLog>(log);
        // If cast successful, add to result vector
        if (depositLog) {
            result.push_back(depositLog->show_log());
        }
    }
    return result;
}

std::vector<std::string> AccountLogger::get_all_user_logs(string id) {

    User * foundUser = find_by_id(id);

    vector<std::string> result;
    if(foundUser ==nullptr) return result;
    for(shared_ptr<AccountLog> log :logVector) {
        if(log->get_loged_user() == foundUser) {
            result.push_back(log->show_log());
        }
    }
    return result;
}

void AccountLogger::save_all_logs() {

    ofstream outFile("./accountlogs.txt");
    if (!outFile) {
        cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    for(shared_ptr<AccountLog> log :logVector) {
        log->save(outFile);
    }

    qDebug() << "save success";

}

void AccountLogger::load_all_logs() {


    ifstream inFile("./accountlogs.txt");
    if (!inFile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }
    string type , user_id , account_num, amount, balance;




    while (getline(inFile, type) &&
           getline(inFile, user_id) &&
           getline(inFile, account_num) &&
           getline(inFile,amount) &&
           getline(inFile, balance)
           ) {

            int idx =admin.search_user_return_idx(user_id);
            User * user = static_cast<User *>(admin.user_list[idx]);
            std::shared_ptr<Account> account = user->get_user_account_shared(stoll(account_num));

            auto deposit_log = [&]() {
                return make_shared<AccountDepositLog>(user,account,stoll(amount),stod(balance));
            };

            auto withdraw_log = [&]() {
                return make_shared<AccountWithdrawLog>(user,account,stoll(amount),stoll(balance));
            };
            std::map<std::string, std::function<std::shared_ptr<AccountLog>()>> type_map;

            type_map.insert({"W",withdraw_log});
            type_map.insert({"D",deposit_log});

            logVector.push_back(type_map[type]());

    }

    inFile.close();
    //std::cout << "파일로드완료" << std::endl;
    std::cout << "fileload" << std::endl;


}


void AccountLogger::show_all_log() {
    for(std::shared_ptr<AccountLog> log :logVector) {
        qDebug() << log->show_log();
    }
}
