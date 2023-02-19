#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Admin{
public:
    string Admin_name;
    string Admin_pwd;
    Admin();
    ~Admin();
    bool Adminlogin();//����Ա��¼
};

class Menu{
public:
    Menu();
    ~Menu();
    int MainMenu();//��ӡ���˵�
    int AdminMenu();//��ӡ����Ա�˵�
    int UserMenu();//��ӡ�û��˵�


};


class Book{
public:
    struct Nbook
    {
        string book_number;
        string book_name;
        string book_author;
        string book_concern;
        string book_surplus;

        Nbook* next;
    };
    Nbook* head;
    Book();
    ~Book();
    void CreateNode();//�����ձ�ͷ
    void InitNode();//��ʼ��ͼ��
    void ShowBook(); //��ӡͼ����Ϣ
    void AddBook();//���ͼ��
    void DelBook();//ɾ��ͼ��
    void SeacheBook();//����ͼ��
    void ModifyBook();//�޸�����
    void SaveBook();//�ļ�����
};


class User{
public:
    struct Nuser
    {
        string name;
        string old;
        string pwd;

        Nuser* next;
    };

    Nuser* head;
    User();
    ~User();
    void CreateNode();//����userͷ
    void InitNode();//��ʼ���û�
    void ShowUser();//��ӡ�û��б�
    void AddUser();//ע���û�
    bool Userlogin();//�ж�����
    void ModifyUser();//�޸��û���Ϣ
};

Admin::Admin(){
    Admin_name = "admin";
    Admin_pwd = "";
}

Admin::~Admin(){

}

bool Admin::Adminlogin() {
    system("cls");
    string s1, s2;
    cout << "����Ա�˺ţ�(Ĭ��admin)" << endl;
    getchar();
    getline(cin, s1);
    cout << "����Ա���룺(Ĭ��Ϊ��)" << endl;
    getline(cin, s2);
    if (s1 == Admin_name && s2 == Admin_pwd) {
        system("cls");
        cout << "��¼�ɹ�����ӭ������Ա��" << endl;
        return true;
    } else {
        system("cls");
        cout << "�˺Ż��������" << endl << endl;
        return false;
    }
}


Menu::Menu(){}

Menu::~Menu(){}

int Menu::MainMenu(){
    int  n;
    cout << "\t\t��ӭʹ��ͼ�����ϵͳ������Ա��admin ���룺�س���\n" << endl;
    cout << "\t -------------------------------------------------------------------"  << endl;
    cout << "\t|              1.����Ա��¼                  2.�û���¼              |" << endl;
    cout << "\t|              3.�û�ע��                    4.�鿴�û�              |" << endl;
    cout << "\t|              5.�˳�                                                |" << endl;
    cout << "\t -------------------------------------------------------------------" << endl;
    cout << "��ѡ��";
    //cin >> n;
    scanf("%d",&n);
    return n;
}

int Menu::AdminMenu(){
    int n;
    system("cls");
    cout << "\t********************    ��ӭ����Ա   ********************************" << endl;
    cout << endl;
    cout << "\t -------------------------------------------------------------------"  << endl;
    cout << "\t|         1.��ʾ����ͼ��                 2.���ͼ��                 |" << endl;
    cout << "\t|         3.ɾ��ͼ��                     4.��ʾ�����û�             |" << endl;
    cout << "\t|         5.�޸�����                     6.�������˵�               |" << endl;
    cout << "\t ------------------------------------------------------------------- "  << endl;
    cout << "��ѡ��";
    cin >> n;
    return n;
}

int Menu::UserMenu(){
    int n;
    system("cls");
    cout << "\t********************      ��ӭ�û�    ******************************"<< endl;
    cout << endl;
    cout << "\t -------------------------------------------------------------------"<<endl;
    cout << "\t|         1.��ʾ����ͼ��                 2.��������ͼ��             |" << endl;
    cout << "\t|         3.�޸��û���Ϣ                 4.�˳�                     |" << endl;
//    cout << "\t|                                            |" << endl;
    cout << "\t -------------------------------------------------------------------" << endl;
    cout << "��ѡ��";
    cin >> n;
    return n;
}


Book::Book(){

}

Book::~Book(){

}

void Book::CreateNode(){
    head = new Nbook;
    head->next = nullptr;
}

void Book::ShowBook(){
    system("cls");
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout << "\t���" << "\t" << "����" << "\t\t" << "����" << "\t" << "������" << "\t\t\t" << "���" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    if (head->next == nullptr){
        cout << "�����鼮��Ϣ" << endl;
    }
    else{
        Nbook* pshow = head;
        while (pshow->next != nullptr)
        {
            pshow = pshow->next;

            cout <<"\t"<<pshow->book_number<<"\t"<< pshow->book_name<<"\t\t" <<pshow->book_author<< "\t"<<pshow->book_concern<<"\t\t"<<pshow->book_surplus<<endl;
        }
    }
}

void Book::AddBook(){
    system("cls");
    Nbook* Insert = head;
    int i = 0;


    while (Insert->next != nullptr)
    {
        Insert = Insert->next;
        i++;
    }
    string ss = to_string(i+1);
    Nbook* pnew = new Nbook;
    pnew->next = nullptr;
    pnew->book_number = ss;

    getchar();
    cout << "��¼��������";
    getline(cin, pnew->book_name);
    cout << "��¼����������";
    getline(cin,pnew->book_author);
    cout << "��¼������磺";
    getline(cin, pnew->book_concern);
    cout << "��¼��������";
    getline(cin,pnew->book_surplus);
    Insert->next = pnew;
    cout << "¼��ɹ�������һ����Ϣ��"<<endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout << "\t���" << "\t" << "����" << "\t\t" << "����" << "\t" << "������" << "\t\t\t" << "���" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout <<"\t"<<pnew->book_number<<"\t"<< pnew->book_name<<"\t\t" <<pnew->book_author<< "\t"<<pnew->book_concern<<"\t\t"<<pnew->book_surplus<<endl;


}

void Book::DelBook(){
    system("cls");
    getchar();
    string s;
    ShowBook();
    cout << endl << "������Ҫɾ�����鼮��ţ�" << endl;
    getline(cin,s);
    Nbook* pdel = head;
    while ((pdel->next != nullptr) && (pdel->next->book_number != s))//&&�ж�˳��Ϊ����
    {
        pdel = pdel->next;
    }
    if (pdel->next != nullptr)
    {
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t���" << "\t" << "����" << "\t\t" << "����" << "\t" << "������" << "\t\t\t" << "���" << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout <<"\t"<<pdel->next->book_number<<"\t"<< pdel->next->book_name<<"\t\t" <<pdel->next->book_author<< "\t"<<pdel->next->book_concern<<"\t\t"<<pdel->next->book_surplus<<endl<<endl;

        Nbook* pnew = pdel->next->next;
        delete pdel->next;
        pdel->next = pnew;
        cout << "ɾ�����\n" << endl;

        Nbook* rename = head;
        int i = 0;
        while(rename->next != nullptr){
            rename = rename->next;
            i++;
            string ss = to_string(i);
            rename->book_number = ss;
        }

    }
    else{
        cout << "�޴���\n" << endl;
    }
}

void Book::SeacheBook(){
    system("cls");
    getchar();
    string s;
    cout << endl << "������Ҫ������ͼ����" << endl;
    getline(cin,s);
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout << "\t���" << "\t" << "����" << "\t" << "����" << "\t" << "������" << "\t" << "���" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    Nbook* pserch = head;
    while (pserch->next != nullptr && pserch->next->book_number != s)//&&�ж�˳��Ϊ����
    {
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "\t" << pserch->next->book_number<< "\t" << pserch->next->book_name << "\t" << pserch->next->book_author << "\t" << pserch->next->book_concern << "\t" << pserch->next->book_surplus << endl;
    }
    else
    {
        cout << "û���ҵ����飡"<<endl;
    }
}

void Book::ModifyBook() {
    system("cls");
    getchar();
    string s;
    ShowBook();
    cout << endl << "������Ҫ�޸Ŀ���ͼ����" << endl;
    getline(cin,s);
    Nbook* pserch = head;
    while (pserch->next != nullptr && pserch->next->book_number != s)//&&�ж�˳��Ϊ����
    {
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "��������" << endl;
        getline(cin, s);
        pserch->next->book_surplus = s;
        cout << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t���" << "\t" << "����" << "\t" << "����" << "\t" << "������" << "\t" << "���" << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t" << pserch->next->book_number<< "\t" << pserch->next->book_name << "\t" << pserch->next->book_author << "\t" << pserch->next->book_concern << "\t" << pserch->next->book_surplus << endl;

    }
    else
    {
        cout << "û���ҵ����飡"<<endl;
    }
}

void Book::SaveBook() {
    string filename = "Book.txt";
    fstream books(filename.c_str(), ios_base::out | ios_base::trunc);

    books << "\t----------------------------------------------------------------------------" << endl;
    books << "\t���" << "\t" << "����" << "\t\t" << "����" << "\t\t" << "������" << "\t\t\t" << "���" << endl;
    books << "\t----------------------------------------------------------------------------" << endl;
    if (head->next == nullptr){
        books << "�����鼮��Ϣ" << endl;
    }
    else{
        Nbook* pshow = head;
        while (pshow->next != nullptr)
        {
            pshow = pshow->next;

            books <<"\t"<<pshow->book_number<<"\t"<< pshow->book_name<<"\t\t" <<pshow->book_author<< "\t\t"<<pshow->book_concern<<"\t\t"<<pshow->book_surplus<<endl;
        }
    }
    books.close();

}

User::User(){

}

User::~User(){

}

void User::CreateNode(){
    head = new Nuser;
    head->next = nullptr;
}

void User::ShowUser(){

    system("cls");
    cout << "\t------------------------------" << endl;
    cout << "\t�û���" << "\t" << "����" << endl;
    cout << "\t------------------------------" << endl;

    if (head->next == nullptr){
        cout << "�����û���Ϣ" << endl;
    }
    else{
        Nuser* pshow = head;
        while (pshow->next != nullptr)
        {
            pshow = pshow->next;
            cout << "\t" << pshow->name << "\t" << pshow->old << endl;
        }
        cout<< endl << endl;
    }
}

void User::AddUser(){
    system("cls");
    Nuser* insert = head;
    while (insert->next != nullptr)
    {
        insert = insert->next;
    }
    auto pnew = new Nuser;
    pnew->next = nullptr;
    cout << "�������û�������";
    getchar();
    getline(cin, pnew->name);
    cout << "���������䣺";
    getline(cin, pnew->old);
    cout << "���������룺";
    getline(cin, pnew->pwd);
    insert->next = pnew;
    cout << "��ϲ�㣡ע��ɹ�" << endl;
}



bool User::Userlogin(){
    system("cls");
    getchar();
    string s1;
    cout << "�û�����" << endl;
    getline(cin,s1);
    cout << "���룺" << endl;
    string str;
    int size = 50;
    char c;
    int count = 0;
    char *password = new char[size]; // ��̬����ռ�
    while ((c = getch()) != '\r') {

        if (c == 8) { // �˸�
            if (count == 0) {
                continue;
            }
            putchar('\b'); // ����һ��
            putchar(' '); // ���һ���ո�ԭ����*����
            putchar('\b'); // �ٻ���һ��ȴ�����
            count--;
        }
        if (count == size - 1) { // ��󳤶�Ϊsize-1
            continue;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // ����ֻ�ɰ������ֺ���ĸ
            putchar('*');  // ���յ�һ���ַ���, ��ӡһ��*
            password[count] = c;
            count++;
        }
    }
    password[count] = '\0';
    str = password;
    delete[] password; // �ͷſռ�
    cout << endl;
    Nuser* pserch = head;
    while (pserch->next != nullptr && pserch->next->name != s1)
    {
        pserch = pserch->next;
    }
    if ((pserch->next != nullptr) && (str == pserch->next->pwd)){
        cout << "��¼�ɹ���" << endl;
        return true;
    }
    else{
        cout << "��¼ʧ�ܣ�"<< endl;
        return false;
    }

}

void User::ModifyUser() {
    system("cls");
    getchar();
    string s;
    cout << endl << "������Ҫ�޸ĵ��û���" << endl;
    getline(cin, s);
    Nuser* pserch = head;
    while (pserch->next != nullptr && pserch->next->name != s){
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "���������û���: ";
        getline(cin, pserch->next->name);
        cout << "����������: ";
        getline(cin, pserch->next->old);
        cout << "�Ƿ���Ҫ�޸�����: (Y/N)" << endl;
        cin >> s;
        if(s == "Y" || s == "y")    {
            cout << "������ԭ����: ";
            cin >> s;
            if(pserch->next != nullptr && pserch->next->pwd == s) {
                cout << "������������: ";
                string str;
                int size = 50;
                char c;
                int count = 0;
                char *password = new char[size]; // ��̬����ռ�
                while ((c = getch()) != '\r') {

                    if (c == 8) { // �˸�
                        if (count == 0) {
                            continue;
                        }
                        putchar('\b'); // ����һ��
                        putchar(' '); // ���һ���ո�ԭ����*����
                        putchar('\b'); // �ٻ���һ��ȴ�����
                        count--;
                    }
                    if (count == size - 1) { // ��󳤶�Ϊsize-1
                        continue;
                    }
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // ����ֻ�ɰ������ֺ���ĸ
                        putchar('*');  // ���յ�һ���ַ���, ��ӡһ��*
                        password[count] = c;
                        count++;
                    }
                }
                password[count] = '\0';
                str = password;
                delete[] password; // �ͷſռ�
                pserch->next->pwd = str;
                cout << endl;
            }
            else{
                cout << "��������󣬲������޸����룡 " << endl;
            }
        }
        cout << endl << "�޸���ɣ�" << endl;
        cout << "\t------------------------------" << endl;
        cout << "\t�û���" << "\t" << "����" << endl;
        cout << "\t------------------------------" << endl;
        cout << "\t" << pserch->next->name << "\t" << pserch->next->old << endl;

    }
    else {
        cout << "û���ҵ����û���" << endl;
    }
}


void initial(Book *book, User *user){
    book->InitNode();
    user->InitNode();
}

typedef struct bookInfo{
    vector<string> names{"����  ","�ֵ�  ","����"};
    vector<string> authors{"�໪ ","�໪ ","������"};
    vector<string> concerns{"�й�����������","��˳�����","����������"};
    vector<string> surplus{"16","52","36"};
};

void Book::InitNode() {

    Nbook* Insert = head;
    auto BookInfo = new bookInfo;


    for(int i = 0; i < 3; i++){
        string ss = to_string(i+1);
        while (Insert->next != nullptr)
        {
            Insert = Insert->next;
        }
        auto pnew = new Nbook;
        pnew->next = nullptr;
        pnew->book_number = ss;
        pnew->book_name = BookInfo->names[i];
        pnew->book_author = BookInfo->authors[i];
        pnew->book_concern = BookInfo->concerns[i];
        pnew->book_surplus = BookInfo->surplus[i];
        Insert->next = pnew;
    }
}

void User::InitNode() {
    Nuser* insert = head;
    while (insert->next != nullptr){
        insert = insert->next;
    }
    vector<string> infos{"cc","19","123"};
    auto pnew = new Nuser;
    pnew->name = infos[0];
    pnew->old = infos[1];
    pnew->pwd = infos[2];
    insert->next = pnew;

}