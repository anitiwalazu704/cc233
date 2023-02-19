/*
 * 作者：曹福泰
 */
#include "class.h"
#include <bits/stdc++.h>
void initial(Book* book, User* user);
using namespace std;
const int T = 1;
int main()
{

	Book *book = new Book;
	book->CreateNode();
	User *user = new User;
	user->CreateNode();
	Admin admin;
	Menu menu;

    cout << "是否默认初始化：（Y/N)" << endl;
    string ini_c;
    cin >> ini_c;

    if (ini_c == "y" || ini_c == "Y") {
        initial(book,user);

        book->SaveBook();
    }
    system("cls");
	int  n, N;
	while (T==1)
	{
//        system("cls");
		N = menu.MainMenu();
		if (N == 1)
		{
			n = admin.Adminlogin();
			while (n)
			{
				switch (menu.AdminMenu()){
				case 1:
					book->ShowBook();
                    book->SaveBook();
					break;
				case 2:
					book->AddBook();
                    book->SaveBook();
					break;
				case 3:
					book->DelBook();
                    book->SaveBook();
					break;
				case 4:
					user->ShowUser();
					break;
				case 5:
                    book->ModifyBook();
                    book->SaveBook();
					break;
                case 6:
                    break;
				}
				cout << endl << "0回到主菜单,非0继续！" << endl;
				cin >> n;

                system("cls");
			}
			continue;
		}
		else if (N == 2)
		{
			n = user->Userlogin();
			while (n)
			{
				switch (menu.UserMenu()){
				case 1:
					book->ShowBook();
                    book->SaveBook();
					break;
				case 2:
					book->SeacheBook();
                    book->SaveBook();
					break;
				case 3:
                    user->ModifyUser();
					break;
                case 6:
                    break;
				}
				cout << endl << "0回到主菜单,非0继续！" << endl;
				cin >> n;
                system("cls");
			}
			continue;
		}
		else if (N == 3)
		{
			user->AddUser();
			continue;
		}
        else if (N == 4)
        {
            user->ShowUser();
            continue;
        }
		else{
			return 0;
		}

	}


}
