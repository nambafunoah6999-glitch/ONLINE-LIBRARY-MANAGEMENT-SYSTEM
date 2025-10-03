#include <iostream>

using namespace std;


string ListOfBooks[50];
string BookCategorys[50];
string BookAuthors[50];
bool BookBorrowed[50];
int BookIdData[50];
string UsersList[10];
int UserIdList[10];
int UserAgeList[10];
int Indexing = 0;
int UserIndexing = 0;
string borrowedBooks[50];
string lendedusers[50];
int browed_ID = 0;
int browed_count = 0;
bool admin_logged_in = true;


class users
{
public:
    string Name;
    int age, User_ID;

    void Add_User()
    {
        cout << "Enter UserName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter User Id: ";
        cin >> User_ID;

        if (UserIndexing < 10) {
            UserIdList[UserIndexing] = User_ID;
            UsersList[UserIndexing] = Name;
            UserAgeList[UserIndexing] = age;
            UserIndexing++;
        } else {
            cout << "User list is full!" << endl;
            cout<<"\n";
        }
    }
    void Remove_User()
    {
        int remove_id;
        cout << "Enter the User ID to remove: ";
        cin >> remove_id;
        for (int x = 0; x < UserIndexing; x++)
        {
            if (UserIdList[x] == remove_id)
            {
                for (int y = x; y < UserIndexing - 1; y++)
                {
                    UsersList[y] = UsersList[y + 1];
                    UserIdList[y] = UserIdList[y + 1];
                    UserAgeList[y] = UserAgeList[y + 1];
                }
                UserIndexing--;
                cout << "User with ID " << remove_id << " has been removed." << endl;
                cout<<"\n";
            }
        }
        cout << "User ID not found." << endl;
    }
    void Display_user()
    {
        for (int x = 0; x < UserIndexing; x++)
        {
            cout << "Name: " << UsersList[x] << " Age: " << UserAgeList[x] << " Id: " << UserIdList[x] << endl;
            cout<<"\n";
        }
    }


}user;

class Library
{
public:
    string Title, Category, Author;
    signed int Book_IDo;
    bool isBorrowed = false;
    int browed_count = 0;


    void input()
    {
        cout << "Enter the Book ID: ";
        cin >> Book_IDo;
        cin.ignore();
        cout << "Enter the Book Title: ";
        getline(cin, Title);
        cout << "Enter the Book Category: ";
        getline(cin, Category);
        cout << "Enter the Book Author: ";
        getline(cin, Author);
    }
    void adding_book()
    {
        input();
        if (Indexing < 10) {
            ListOfBooks[Indexing] = Title;
            BookIdData[Indexing] = Book_IDo;
            BookCategorys[Indexing] = Category;
            BookAuthors[Indexing] = Author;
            BookBorrowed[Indexing] = isBorrowed;
            Indexing++;
        } else {
            cout << "Book list is full!" << endl;
            cout<<"\n";
        }
    }
    void remove_book()
    {
        int remove_id;
        cout << "Enter the Book ID to remove: ";
        cin >> remove_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdData[x] == remove_id)
            {
                for (int y = x; y < Indexing - 1; y++)
                {
                    ListOfBooks[y] = ListOfBooks[y + 1];
                    BookIdData[y] = BookIdData[y + 1];
                    BookCategorys[y] = BookCategorys[y + 1];
                    BookAuthors[y] = BookAuthors[y + 1];
                    BookBorrowed[y] = BookBorrowed[y + 1];
                }
                Indexing--;
                cout << "Book with ID " << remove_id << " has been removed." << endl;
                cout<<"\n";
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }
    void Display_Book()
    {
        for (int x = 0; x < Indexing; x++)
        {
            cout << "Name: " << ListOfBooks[x] << " Category: " << BookCategorys[x] << " Id: " << BookIdData[x] << " Aurthor: " << BookAuthors[x] << endl;
        }
    }

} library;

class Books
{
public:
    int NumberOfBooks, NumberOfBorrowedBooks;
    bool isBorrowed;

     void borrow_Book()
    {
        int borrow_id;
        cout << "Enter the Book ID to borrow: ";
        cin >> borrow_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdData[x] == borrow_id)
            {
                if (!isBorrowed)
                {
                    isBorrowed = true;
                    browed_count++;
                    cout << "You have borrowed: " << ListOfBooks[x] << endl;
                    borrowedBooks[browed_ID] = ListOfBooks[x];
                    lendedusers[browed_ID] = user.Name;
                    browed_ID++;
                }
                else
                {
                    cout << "Sorry, this book is already borrowed." << endl;
                    cout<<"\n";
                }
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }
    void return_Book()
    {
        int return_id;
        cout << "Enter the Book ID to return: ";
        cin >> return_id;
        for (int x = 0; x < Indexing; x++)
        {
            if (BookIdData[x] == return_id)
            {
                if (isBorrowed)
                {
                    isBorrowed = false;
                    cout << "You have returned: " << ListOfBooks[x] << endl;
                    cout<<"\n";
                }
                else
                {
                    cout << "This book was not borrowed." << endl;
                    cout<<"\n";
                }
                return;
            }
        }
        cout << "Book ID not found." << endl;
        cout<<"\n";
    }

    void Search_Book()
    {
        string search_title;
        cout << "Enter the Book Title to search: ";
        cin.ignore();
        getline(cin, search_title);
        for (int x = 0; x < Indexing; x++)
        {
            if (ListOfBooks[x] == search_title)
            {
                cout << "Book found: " << ListOfBooks[x] << " Category: " << BookCategorys[x] << " Id: " << BookIdData[x] << " Aurthor: " << BookAuthors[x] << endl;
                cout <<"\n";
            }
        }
        cout << "Book not found." << endl;
        cout <<"\n";
    }



}book;

int main ()
{
	while (admin_logged_in)
	{
		cout<<"\t\t\t############################################ \n";
		cout<<"\t\t\t########### School Library System ########## \n";
		cout<<"\t\t\t############################################ \n";
		cout<<"\t\t\t########## 1: Add Book            ########## \n";
		cout<<"\t\t\t########## 2: Show Books          ########## \n";
		cout<<"\t\t\t########## 3: Remove Book         ########## \n";
		cout<<"\t\t\t########## 4: Borrow Book         ########## \n";
		cout<<"\t\t\t########## 5: Return Book         ########## \n";
		cout<<"\t\t\t########## 6: Add User            ########## \n";
		cout<<"\t\t\t########## 7: Remove User         ########## \n";
		cout<<"\t\t\t########## 8: Show Users          ########## \n";
		cout<<"\t\t\t########## 9: Search Book         ########## \n";
		cout<<"\t\t\t########## 0: Quit                ########## \n";
		cout<<"\t\t\t############################################ \n";
		cout<<"\t\t\t############################################ \n";

		int option;
		cout<<">>>>> ";
		cin>>option;

		if(option == 1)
		{
            library.adding_book();
		}else if(option == 2)
		{
            library.Display_Book();
		}else if (option == 3)
		{
		    library.remove_book();
		}else if (option == 4)
		{
		    book.borrow_Book();
		}else if(option == 5)
		{
		    book.return_Book();
		}else if(option == 6)
		{
		    user.Add_User();
		}
		else if(option == 7)
        {
            user.Remove_User();
        }else if(option == 8)
        {
            user.Display_user();
        }else if(option == 0)
        {
            admin_logged_in = false;
            break;
        }else if(option == 9)
        {
            book.Search_Book();
        }
        else
        {
            cout<<"Enter valid values! \n";

        }
	}

	return 0;
}
