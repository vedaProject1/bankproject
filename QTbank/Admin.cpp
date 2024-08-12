#include "Admin.h"

Admin::Admin() {}
Admin::~Admin() {}
Account Admin::get_user_account()
{
    Account trash(0, 0);
    return trash;
}

void Admin::admin_menu()
{
    int menuNO;
    do {
        //cout << "==========관리자메뉴입니다==========" << endl;
        //cout << "1. 회원조회" << endl;
        //cout << "2. 회원 id 변경" << endl;
        //cout << "3. 회원 pw 변경" << endl;
        //cout << "9. 관리자메뉴종료" << endl;
        //cout << "선택-->";
        //cin >> menuNO;
        switch (menuNO) {
        case 1: //회원조회
            search_user();
            break;

        case 2: { //회원id변경

            break;
        }
        case 9:
            //cout << "관리자 메뉴를 종료합니다." << endl;
            break;
        default:
            //cout << "잘못 선택하셨습니다" << endl;
            break;
        }

    } while (menuNO != 9); //9이면 종료니깐 9면 반복문 탈출
}

void Admin::search_user()
{
    //cout << "조회할 고객의 이름을 입력하세요\n";
    bool check = false;
    string name;
    //cin >> name;
    vector<Person *>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (name == (*it)->get_name()) {
            //cout << (*it)->get_name() << "고객님의 정보입니다\n";
            //cout << "계좌번호 :" << (*it)->get_user_account().get_account_num() << endl;
            //cout << "잔액 :" << (*it)->get_user_account().get_balance() << endl;

            check = true;
        }
    }
    if (check == false)
        cout << "no user";
}


void Admin::search_user(string id){
    bool check = false;
    //cin >> name;
    vector<Person *>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (id == (*it)->get_id()) {
            cout << (*it)->get_name() << "user information\n";
            cout << "account num :" << (*it)->get_user_account().get_account_num() << endl;
            cout << "balance :" << (*it)->get_user_account().get_balance() << endl;

            check = true;
        }
    }

    if (check == false)
        cout << "no user";
}

int Admin::search_user_return_idx(string id){
    bool check = false;
    int idx=0;
    vector<Person *>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {

        if (id == (*it)->get_id()) {
            cout << (*it)->get_name() << "user information\n";
            cout << "account num :" << (*it)->get_user_account().get_account_num() << endl;
            cout << "balance :" << (*it)->get_user_account().get_balance() << endl;
            check = true;
            return idx;

        }
        idx++;
    }

    if (check == false){
        cout << "no user";
        return 1000;
    }
}
