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
// Function definitions

void displayMenu() {
  
    cout << " _______  _______  _______  _______  _     _  _______  ______    ______   __   __  _______  __    _  _______  _______  _______  ______   " << endl;
    cout << "|       ||   _   ||       ||       || | _ | ||       ||    _ |  |      | |  |_|  ||   _   ||  |  | ||   _   ||       ||       ||    _ |  " << endl;
    cout << "|    _  ||  |_|  ||  _____||  _____|| || || ||   _   ||   | ||  |  _    ||       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___||   | ||  " << endl;
    cout << "|   |_| ||       || |_____ | |_____ |       ||  | |  ||   |_||_ | | |   ||       ||       ||       ||       ||   | __ |   |___ |   |_||_ " << endl;
    cout << "|    ___||       ||_____  ||_____  ||       ||  |_|  ||    __  || |_|   ||       ||       ||  _    ||       ||   ||  ||    ___||    __  |" << endl;
    cout << "|   |    |   _   | _____| | _____| ||   _   ||       ||   |  | ||       || ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ |   |  | |" << endl;
    cout << "|___|    |__| |__||_______||_______||__| |__||_______||___|  |_||______| |_|   |_||__| |__||_|  |__||__| |__||_______||_______||___|  |_|" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create an Account" << endl;
    cout << "3. Exit" << endl;
}
void displayMenu2login() {
    cout << "1. Store Password" << endl;
    cout << "2. Generate Password" << endl;
    cout << "3. Retrieve Password" << endl;
}

string generatePassword(int length) {
    const string CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}|;:,.<>?";
    srand(time(NULL));
    string password;
    for (int i = 0; i < length; ++i) {
        password += CHARACTERS[rand() % CHARACTERS.length()];
    }
    return password;
}

string encrypt(const string& password) {
    string encryptedPwd = password;
    for (size_t i = 0; i < password.length(); ++i) {
        encryptedPwd[i] ^= 0x5A; // XOR with a constant value
    }
    return encryptedPwd;
}

string decrypt(const string& encryptedPwd) {
    string decryptedPwd = encryptedPwd;
    for (size_t i = 0; i < encryptedPwd.length(); ++i) {
        decryptedPwd[i] ^= 0x5A; // XOR with the same constant value
    }
    return decryptedPwd;
}
