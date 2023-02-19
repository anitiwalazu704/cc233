#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Admin{
public:
    string Admin_name;
    string Admin_pwd;
    Admin();
    ~Admin();
    bool Adminlogin();//管理员登录
};

class Menu{
public:
    Menu();
    ~Menu();
    int MainMenu();//打印主菜单
    int AdminMenu();//打印管理员菜单
    int UserMenu();//打印用户菜单


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
    void CreateNode();//创建空表头
    void InitNode();//初始化图书
    void ShowBook(); //打印图书信息
    void AddBook();//添加图书
    void DelBook();//删除图书
    void SeacheBook();//搜索图书
    void ModifyBook();//修改余量
    void SaveBook();//文件备份
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
    void CreateNode();//创建user头
    void InitNode();//初始化用户
    void ShowUser();//打印用户列表
    void AddUser();//注册用户
    bool Userlogin();//判断密码
    void ModifyUser();//修改用户信息
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
    cout << "管理员账号：(默认admin)" << endl;
    getchar();
    getline(cin, s1);
    cout << "管理员密码：(默认为空)" << endl;
    getline(cin, s2);
    if (s1 == Admin_name && s2 == Admin_pwd) {
        system("cls");
        cout << "登录成功，欢迎您管理员！" << endl;
        return true;
    } else {
        system("cls");
        cout << "账号或密码错误" << endl << endl;
        return false;
    }
}


Menu::Menu(){}

Menu::~Menu(){}

int Menu::MainMenu(){
    int  n;
    cout << "\t\t欢迎使用图书管理系统（管理员：admin 密码：回车）\n" << endl;
    cout << "\t -------------------------------------------------------------------"  << endl;
    cout << "\t|              1.管理员登录                  2.用户登录              |" << endl;
    cout << "\t|              3.用户注册                    4.查看用户              |" << endl;
    cout << "\t|              5.退出                                                |" << endl;
    cout << "\t -------------------------------------------------------------------" << endl;
    cout << "请选择：";
    //cin >> n;
    scanf("%d",&n);
    return n;
}

int Menu::AdminMenu(){
    int n;
    system("cls");
    cout << "\t********************    欢迎管理员   ********************************" << endl;
    cout << endl;
    cout << "\t -------------------------------------------------------------------"  << endl;
    cout << "\t|         1.显示所有图书                 2.添加图书                 |" << endl;
    cout << "\t|         3.删除图书                     4.显示所有用户             |" << endl;
    cout << "\t|         5.修改余量                     6.返回主菜单               |" << endl;
    cout << "\t ------------------------------------------------------------------- "  << endl;
    cout << "请选择：";
    cin >> n;
    return n;
}

int Menu::UserMenu(){
    int n;
    system("cls");
    cout << "\t********************      欢迎用户    ******************************"<< endl;
    cout << endl;
    cout << "\t -------------------------------------------------------------------"<<endl;
    cout << "\t|         1.显示所有图书                 2.搜索借阅图书             |" << endl;
    cout << "\t|         3.修改用户信息                 4.退出                     |" << endl;
//    cout << "\t|                                            |" << endl;
    cout << "\t -------------------------------------------------------------------" << endl;
    cout << "请选择：";
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
    cout << "\t编号" << "\t" << "书名" << "\t\t" << "作者" << "\t" << "出版社" << "\t\t\t" << "库存" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    if (head->next == nullptr){
        cout << "暂无书籍信息" << endl;
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
    cout << "请录入书名：";
    getline(cin, pnew->book_name);
    cout << "请录入作者名：";
    getline(cin,pnew->book_author);
    cout << "请录入出版社：";
    getline(cin, pnew->book_concern);
    cout << "请录入余量：";
    getline(cin,pnew->book_surplus);
    Insert->next = pnew;
    cout << "录入成功，更新一条信息！"<<endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout << "\t编号" << "\t" << "书名" << "\t\t" << "作者" << "\t" << "出版社" << "\t\t\t" << "库存" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout <<"\t"<<pnew->book_number<<"\t"<< pnew->book_name<<"\t\t" <<pnew->book_author<< "\t"<<pnew->book_concern<<"\t\t"<<pnew->book_surplus<<endl;


}

void Book::DelBook(){
    system("cls");
    getchar();
    string s;
    ShowBook();
    cout << endl << "请输入要删除的书籍编号：" << endl;
    getline(cin,s);
    Nbook* pdel = head;
    while ((pdel->next != nullptr) && (pdel->next->book_number != s))//&&判断顺序为先左
    {
        pdel = pdel->next;
    }
    if (pdel->next != nullptr)
    {
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t编号" << "\t" << "书名" << "\t\t" << "作者" << "\t" << "出版社" << "\t\t\t" << "库存" << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout <<"\t"<<pdel->next->book_number<<"\t"<< pdel->next->book_name<<"\t\t" <<pdel->next->book_author<< "\t"<<pdel->next->book_concern<<"\t\t"<<pdel->next->book_surplus<<endl<<endl;

        Nbook* pnew = pdel->next->next;
        delete pdel->next;
        pdel->next = pnew;
        cout << "删除完成\n" << endl;

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
        cout << "无此书\n" << endl;
    }
}

void Book::SeacheBook(){
    system("cls");
    getchar();
    string s;
    cout << endl << "请输入要搜索的图书编号" << endl;
    getline(cin,s);
    cout << "\t----------------------------------------------------------------------------" << endl;
    cout << "\t编号" << "\t" << "书名" << "\t" << "作者" << "\t" << "出版社" << "\t" << "库存" << endl;
    cout << "\t----------------------------------------------------------------------------" << endl;
    Nbook* pserch = head;
    while (pserch->next != nullptr && pserch->next->book_number != s)//&&判断顺序为先左
    {
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "\t" << pserch->next->book_number<< "\t" << pserch->next->book_name << "\t" << pserch->next->book_author << "\t" << pserch->next->book_concern << "\t" << pserch->next->book_surplus << endl;
    }
    else
    {
        cout << "没有找到此书！"<<endl;
    }
}

void Book::ModifyBook() {
    system("cls");
    getchar();
    string s;
    ShowBook();
    cout << endl << "请输入要修改库存的图书编号" << endl;
    getline(cin,s);
    Nbook* pserch = head;
    while (pserch->next != nullptr && pserch->next->book_number != s)//&&判断顺序为先左
    {
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "请输入库存" << endl;
        getline(cin, s);
        pserch->next->book_surplus = s;
        cout << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t编号" << "\t" << "书名" << "\t" << "作者" << "\t" << "出版社" << "\t" << "库存" << endl;
        cout << "\t----------------------------------------------------------------------------" << endl;
        cout << "\t" << pserch->next->book_number<< "\t" << pserch->next->book_name << "\t" << pserch->next->book_author << "\t" << pserch->next->book_concern << "\t" << pserch->next->book_surplus << endl;

    }
    else
    {
        cout << "没有找到此书！"<<endl;
    }
}

void Book::SaveBook() {
    string filename = "Book.txt";
    fstream books(filename.c_str(), ios_base::out | ios_base::trunc);

    books << "\t----------------------------------------------------------------------------" << endl;
    books << "\t编号" << "\t" << "书名" << "\t\t" << "作者" << "\t\t" << "出版社" << "\t\t\t" << "库存" << endl;
    books << "\t----------------------------------------------------------------------------" << endl;
    if (head->next == nullptr){
        books << "暂无书籍信息" << endl;
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
    cout << "\t用户名" << "\t" << "年龄" << endl;
    cout << "\t------------------------------" << endl;

    if (head->next == nullptr){
        cout << "暂无用户信息" << endl;
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
    cout << "请输入用户姓名：";
    getchar();
    getline(cin, pnew->name);
    cout << "请输入年龄：";
    getline(cin, pnew->old);
    cout << "请输入密码：";
    getline(cin, pnew->pwd);
    insert->next = pnew;
    cout << "恭喜你！注册成功" << endl;
}



bool User::Userlogin(){
    system("cls");
    getchar();
    string s1;
    cout << "用户名：" << endl;
    getline(cin,s1);
    cout << "密码：" << endl;
    string str;
    int size = 50;
    char c;
    int count = 0;
    char *password = new char[size]; // 动态申请空间
    while ((c = getch()) != '\r') {

        if (c == 8) { // 退格
            if (count == 0) {
                continue;
            }
            putchar('\b'); // 回退一格
            putchar(' '); // 输出一个空格将原来的*隐藏
            putchar('\b'); // 再回退一格等待输入
            count--;
        }
        if (count == size - 1) { // 最大长度为size-1
            continue;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
            putchar('*');  // 接收到一个字符后, 打印一个*
            password[count] = c;
            count++;
        }
    }
    password[count] = '\0';
    str = password;
    delete[] password; // 释放空间
    cout << endl;
    Nuser* pserch = head;
    while (pserch->next != nullptr && pserch->next->name != s1)
    {
        pserch = pserch->next;
    }
    if ((pserch->next != nullptr) && (str == pserch->next->pwd)){
        cout << "登录成功！" << endl;
        return true;
    }
    else{
        cout << "登录失败！"<< endl;
        return false;
    }

}

void User::ModifyUser() {
    system("cls");
    getchar();
    string s;
    cout << endl << "请输入要修改的用户名" << endl;
    getline(cin, s);
    Nuser* pserch = head;
    while (pserch->next != nullptr && pserch->next->name != s){
        pserch = pserch->next;
    }
    if (pserch->next != nullptr)
    {
        cout << "请输入新用户名: ";
        getline(cin, pserch->next->name);
        cout << "请输入年龄: ";
        getline(cin, pserch->next->old);
        cout << "是否需要修改密码: (Y/N)" << endl;
        cin >> s;
        if(s == "Y" || s == "y")    {
            cout << "请输入原密码: ";
            cin >> s;
            if(pserch->next != nullptr && pserch->next->pwd == s) {
                cout << "请输入新密码: ";
                string str;
                int size = 50;
                char c;
                int count = 0;
                char *password = new char[size]; // 动态申请空间
                while ((c = getch()) != '\r') {

                    if (c == 8) { // 退格
                        if (count == 0) {
                            continue;
                        }
                        putchar('\b'); // 回退一格
                        putchar(' '); // 输出一个空格将原来的*隐藏
                        putchar('\b'); // 再回退一格等待输入
                        count--;
                    }
                    if (count == size - 1) { // 最大长度为size-1
                        continue;
                    }
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
                        putchar('*');  // 接收到一个字符后, 打印一个*
                        password[count] = c;
                        count++;
                    }
                }
                password[count] = '\0';
                str = password;
                delete[] password; // 释放空间
                pserch->next->pwd = str;
                cout << endl;
            }
            else{
                cout << "旧密码错误，不允许修改密码！ " << endl;
            }
        }
        cout << endl << "修改完成！" << endl;
        cout << "\t------------------------------" << endl;
        cout << "\t用户名" << "\t" << "年龄" << endl;
        cout << "\t------------------------------" << endl;
        cout << "\t" << pserch->next->name << "\t" << pserch->next->old << endl;

    }
    else {
        cout << "没有找到此用户！" << endl;
    }
}


void initial(Book *book, User *user){
    book->InitNode();
    user->InitNode();
}

typedef struct bookInfo{
    vector<string> names{"活着  ","兄弟  ","地心"};
    vector<string> authors{"余华 ","余华 ","凡尔纳"};
    vector<string> concerns{"中国教育出版社","凤凰出版社","外国语出版社"};
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