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
        //cout << "==========�����ڸ޴��Դϴ�==========" << endl;
        //cout << "1. ȸ����ȸ" << endl;
        //cout << "2. ȸ�� id ����" << endl;
        //cout << "3. ȸ�� pw ����" << endl;
        //cout << "9. �����ڸ޴�����" << endl;
        //cout << "����-->";
        //cin >> menuNO;
        switch (menuNO) {
        case 1: //ȸ����ȸ
            search_user();
            break;

        case 2: { //ȸ��id����

            break;
        }
        case 9:
            //cout << "������ �޴��� �����մϴ�." << endl;
            break;
        default:
            //cout << "�߸� �����ϼ̽��ϴ�" << endl;
            break;
        }

    } while (menuNO != 9); //9�̸� ����ϱ� 9�� �ݺ��� Ż��
}

void Admin::search_user()
{
    //cout << "��ȸ�� ���� �̸��� �Է��ϼ���\n";
    bool check = false;
    string name;
    //cin >> name;
    vector<Person *>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (name == (*it)->get_name()) {
            //cout << (*it)->get_name() << "������ �����Դϴ�\n";
            //cout << "���¹�ȣ :" << (*it)->get_user_account().get_account_num() << endl;
            //cout << "�ܾ� :" << (*it)->get_user_account().get_balance() << endl;

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
