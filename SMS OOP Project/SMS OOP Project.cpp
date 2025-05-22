#include <iostream>
#include <vector>
#include <string>
using namespace std;

// This class is used to register and login a user
class User {
public:
    string name, username, password;

    void registerUser() {
        cout << "\n*************************\n";
        cout << "       REGISTER\n";
        cout << "*************************\n";
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        cout << "Registered successfully.\n";
    }

    bool login() {
        string uname, pass;
        cout << "\n*************************\n";
        cout << "         LOGIN\n";
        cout << "*************************\n";
        cout << "Enter username: ";
        getline(cin, uname);
        cout << "Enter password: ";
        getline(cin, pass);
        if (uname == username && pass == password) {
            cout << "Login successful. Welcome " << name << ".\n";
            return true;
        }
        else {
            cout << "Login failed. Try again.\n";
            return false;
        }
    }

    void showProfile() {
        cout << "\n*************************\n";
        cout << "        PROFILE\n";
        cout << "*************************\n";
        cout << "Name: " << name << "\nUsername: " << username << endl;
    }
};

// This class is used to mark and show attendance
class Attendance {
    vector<string> days;
public:
    void mark(string day) {
        days.push_back(day);
        cout << "Attendance marked for " << day << endl;
    }

    void show() {
        cout << "\n*************************\n";
        cout << "       ATTENDANCE\n";
        cout << "*************************\n";
        if (days.empty()) {
            cout << "No attendance yet.\n";
        }
        else {
            for (string d : days)
                cout << "- " << d << endl;
        }
    }
};

// This class is used to add and show assignments
class Assignment {
    vector<string> assigns;
public:
    void add(string task) {
        assigns.push_back(task);
        cout << "Assignment added.\n";
    }

    void show() {
        cout << "\n*************************\n";
        cout << "      ASSIGNMENTS\n";
        cout << "*************************\n";
        if (assigns.empty()) {
            cout << "No assignments yet.\n";
        }
        else {
            for (string t : assigns)
                cout << "- " << t << endl;
        }
    }
};

// This class shows the dashboard after login
class Dashboard {
    Attendance atnd;
    Assignment asgn;
    User& user;

public:
    Dashboard(User& u) : user(u) {}

    void show() {
        int ch;
        do {
            cout << "\n*************************\n";
            cout << "        DASHBOARD\n";
            cout << "*************************\n";
            cout << "1. Profile\n2. Attendance\n3. Assignments\n4. About\n5. Logout\n";
            cout << "Select option: ";
            cin >> ch;

            // Clear wrong input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            cin.ignore();

            if (ch == 1)
                user.showProfile();
            else if (ch == 2) {
                int opt;
                cout << "\n1. Mark Attendance\n2. Show Attendance\nSelect option: ";
                cin >> opt;
                cin.ignore();
                if (opt == 1) {
                    string d;
                    cout << "Enter day/date: ";
                    getline(cin, d);
                    atnd.mark(d);
                }
                else
                    atnd.show();
            }
            else if (ch == 3) {
                int opt;
                cout << "\n1. Add Assignment\n2. Show Assignments\nSelect option: ";
                cin >> opt;
                cin.ignore();
                if (opt == 1) {
                    string task;
                    cout << "Enter assignment: ";
                    getline(cin, task);
                    asgn.add(task);
                }
                else
                    asgn.show();
            }
            else if (ch == 4) {
                cout << "\nThis is a simple student dashboard project using C++ OOP.\n";
            }
            else if (ch != 5) {
                cout << "Invalid option. Try again.\n";
            }

        } while (ch != 5);
    }
};

// Main function to start the program
int main() {
    User u;
    int ch;
    do {
        cout << "\n*************************\n";
        cout << "        MAIN MENU\n";
        cout << "*************************\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Select option: ";
        cin >> ch;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore();

        if (ch == 1)
            u.registerUser();
        else if (ch == 2) {
            if (u.login()) {
                Dashboard d(u);
                d.show();
            }
        }
        else if (ch != 3)
            cout << "Wrong choice. Try again.\n";

    } while (ch != 3);

    cout << "Thank you for using the system.\n";
    return 0;
}
