#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes declaration
void displayMenu();
void displayMenu2login();
string generatePassword(int length);
string encrypt(const string& password);
string decrypt(const string& encryptedPwd);
void registeredPassword(const string& usrname, const string& encryptedPwd);
void storePassword(const string& usrname, const string& encryptedPwd);
bool authenticateUser(const string& usrname, const string& pwd);
string retrieveEncryptedPassword(const string& usrname);
void registerUser();

int main() {
    // Initialize variables
    string usrname, pwd, encryptedPwd, storedPwd;
    int choice;

    // Display menu and get user choice
    do {
        displayMenu();
        cout << "Enter a number: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // sign in
            cout << "Enter username: ";
            cin >> usrname;
            cout << "Enter password: ";
            cin >> pwd;
            if (authenticateUser(usrname, pwd)) {
                cout << "Login successful!" << endl;
                displayMenu2login();
                cout << "Enter your a number: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    // Store passwd
                    cout << "Enter username: ";
                    cin >> usrname;
                    cout << "Enter password: ";
                    cin >> pwd;
                    encryptedPwd = encrypt(pwd);
                    storePassword(usrname, encryptedPwd);
                    cout << "Password stored successfully!" << endl;
                    break;
                case 2:
                    // generate passwd
                    int length;
                    cout << "Enter the length of the password to generate: ";
                    cin >> length;
                    cout << "Generated password: " << generatePassword(length) << endl;
                    break;

                case 3:
                    // Retrieve passwd
                    cout << "Enter username: ";
                    cin >> usrname;
                    storedPwd = retrieveEncryptedPassword(usrname);
                    if (storedPwd != "") {
                        cout << "Stored password: " << decrypt(storedPwd) << endl;
                    }
                    else {
                        cout << "No password found for the given username." << endl;
                    }
                    break;
                }

            }
            else {
                cout << "Invalid username or password. Please try again." << endl;
            }
            break;
        case 2:
            // create an account
            registerUser();
            break;
        case 3:
            // Exit
            cout << "Exiting the password manager application. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
