# online-libary-mamanagement

# Documentation: School Library System in C++

## 1. Introduction

This program implements a simple *School Library Management System* in C++. It allows an administrator to manage books and users, as well as handle borrowing and returning of books.

The system is *menu-driven*, running in a loop until the administrator chooses to quit.

---

## 2. Features

The system provides the following functionalities:

1. Add a new book to the library.
2. Display all available books.
3. Remove a book by its ID.
4. Borrow a book (if available).
5. Return a borrowed book.
6. Add a new user.
7. Remove a user by ID.
8. Display all registered users.
9. Search for a book by title.
10. Exit the program.

---

## 3. Data Structures Used

The system relies on *arrays* to store data about books and users:

* *Books*

  * ListOfBooks[50] → Stores book titles.
  * BookCategorys[50] → Stores book categories.
  * BookAuthors[50] → Stores book authors.
  * BookBorrowed[50] → Boolean array to mark if a book is borrowed.
  * BookIdData[50] → Stores unique IDs for each book.

* *Users*

  * UsersList[10] → Stores usernames.
  * UserIdList[10] → Stores user IDs.
  * UserAgeList[10] → Stores ages of users.

* *Borrowing Records*

  * borrowedBooks[50] → Stores titles of borrowed books.
  * lendedusers[50] → Stores names of users who borrowed books.

---

## 4. Classes and Responsibilities

### (a) class users

Handles library users.

* *Attributes:*

  * Name, age, User_ID

* *Methods:*

  * Add_User() → Adds a new user (name, age, ID).
  * Remove_User() → Removes a user by ID.
  * Display_user() → Lists all registered users.

---

### (b) class Library

Handles adding, removing, and displaying books.

* *Attributes:*

  * Title, Category, Author, Book_IDo, isBorrowed

* *Methods:*

  * input() → Collects book details from the administrator.
  * adding_book() → Stores a new book in arrays.
  * remove_book() → Removes a book by its ID.
  * Display_Book() → Displays all books in the system.

---

### (c) class Books

Handles borrowing, returning, and searching for books.

* *Attributes:*

  * NumberOfBooks, NumberOfBorrowedBooks, isBorrowed

* *Methods:*

  * borrow_Book() → Allows borrowing a book if it is not already borrowed.
  * return_Book() → Allows returning a borrowed book.
  * Search_Book() → Searches for a book by its title.

---

## 5. Main Menu (main())

The main() function runs a continuous loop while admin_logged_in = true.
It displays a *menu* and asks for an option. Depending on the option chosen, the corresponding class method is executed.

Menu Options:


1. Add Book
2. Show Books
3. Remove Book
4. Borrow Book
5. Return Book
6. Add User
7. Remove User
8. Show Users
9. Search Book
0. Quit


---

## 6. How the System Works

* Administrator logs in (default admin_logged_in = true).
* Books and users are managed using arrays (capacity: 50 books, 10 users).
* Borrowing a book marks it as "borrowed" in BookBorrowed[].
* Returning a book resets its borrowed status.
* Users and books can be searched, added, or removed by ID or title.

---

## 7. Limitations

* Only *50 books* and *10 users* can be stored (fixed array size).
* A book’s borrow status is tracked globally, not linked directly to a specific user (improvement possible).
* No permanent data storage — all data is lost once the program ends.
* Input handling (e.g., cin.ignore()) may skip inputs if not used carefully.

---

## 8. Possible Improvements

* Replace arrays with *vectors* or *linked lists* for dynamic storage.
* Create a *file storage system* (text file or database) so data persists after program exit.
* Improve borrowing system by linking each borrowed book to a specific user ID.
* Add *admin authentication* before accessing the menu.
* Add *due dates, fines, and book availability count*.

---

## 9. Example Usage

*Scenario:*

1. Admin selects *Option 1* → Adds a book with ID 101, Title "C++ Basics".
2. Admin selects *Option 6* → Adds a user named "Alice", ID 1.
3. Admin selects *Option 4* → Alice borrows "C++ Basics".
4. Admin selects *Option 2* → Displays book list showing "C++ Basics" as borrowed.
5. Admin selects *Option 5* → Alice returns the book.
6. Admin selects *Option 0* → Exits program.

---

## 10. Conclusion

This system provides a *basic library management framework* suitable for learning object-oriented programming in C++. While it has limitations (fixed arrays, no permanent storage), it demonstrates essential features like *encapsulation, class design, and menu-driven programs*.