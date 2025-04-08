#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

class caeserCipher
{
private:
    int shiftValue;

protected:
    string encode(const string &message)
    {
        string encodeMessage = message;
        int messageSize = encodeMessage.size();
        for (int i = 0; i < messageSize; i++)
        {
            int x = encodeMessage[i];
            if (x >= 65 && x <= 90)
            {
                x = 'A' + (x - 'A' + shiftValue + 26) % 26;
            }
            else if (x >= 97 && x <= 122)
            {
                x = 'a' + (x - 'a' + shiftValue + 26) % 26;
            }
            char newLetter = x;
            encodeMessage[i] = newLetter;
        }
        return encodeMessage;
    }

public:
    caeserCipher()
    {
        shiftValue = 0;
    }
    caeserCipher(int num)
    {
        shiftValue = num;
    }
    void setShiftValue(int value)
    {

        shiftValue = value;
    }
    int getShiftValue()
    {
        return shiftValue;
    }
    string callEncode(string message)
    {
        return encode(message);
    }
    string decode(const string &message)
    {
        string decodeMessage = message;
        int messageSize = decodeMessage.size();
        for (int i = 0; i < messageSize; i++)
        {
            int x = decodeMessage[i];
            if (x >= 65 && x <= 90)
            {
                x = 'A' + (x - 'A' - shiftValue + 26) % 26;
            }
            else if (x >= 97 && x <= 122)
            {
                x = 'a' + (x - 'a' - shiftValue + 26) % 26;
            }
            char newLetter = x;
            decodeMessage[i] = newLetter;
        }
        return decodeMessage;
    }
};

class Rot13Cipher : public caeserCipher
{
public:
    Rot13Cipher() : caeserCipher(13)
    {
    }
};

string autoDecode(const string &message, int shiftValue)
{
    string decodeMessage = message;
    int messageSize = decodeMessage.size();
    for (int i = 0; i < messageSize; i++)
    {
        int x = decodeMessage[i];
        if (x >= 65 && x <= 90)
        {
            x = 'A' + (x - 'A' - shiftValue + 26) % 26;
        }
        else if (x >= 97 && x <= 122)
        {
            x = 'a' + (x - 'a' - shiftValue + 26) % 26;
        }
        char newLetter = x;
        decodeMessage[i] = newLetter;
    }
    return decodeMessage;
}

;
void menu()
{
    cout << '\n'
         << '\n'
         << setfill('-') << setw(9) << "" << "WElCOME TO THE CIPHER PROGRAM FOR GUILD 2" << setw(9) << "" << endl;
    cout << left << "1: ENCODE" << endl;
    cout << left << "2: DECODE" << endl;
    cout << left << "3: AUTO DECODER (ONLY FOR GUILD 2 USE)" << endl;
    cout << left << "4: EXIT" << endl;
}
int main()
{

    int choice;
    menu();
    cout << "Enter Your Choice: ";
    cin >> choice;
    if (cin.fail() || choice < 1 || choice > 4)
    {
        cout << "Invalid input. Please try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    while (choice != 4)
    {

        if (choice == 1)
        {
            caeserCipher *cipher = nullptr;
            string message;
            int value;
            cout << "Enter Message to be encoded: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, message);
            cout << "Enter Shift value (1-13) to encode message accordingly: ";
            cin >> value;
            while (true)
            {
                if (cin.fail() || value < 1 || value > 13)
                {
                    cout << "Invalid input. Shift value must be between 1 and 13. Please try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> value;
                }
                else
                {
                    break;
                }
            }

            if (value == 13)
            {
                cipher = new Rot13Cipher();
                cout << "Encoded message using Rot13cipher " << "(Shift Value " << cipher->getShiftValue() << ") : " << cipher->callEncode(message) << endl;
            }
            else if (value != 13)
            {
                cipher = new caeserCipher();
                cipher->setShiftValue(value);
                cout << "Encoded message using caesar cipher " << "(Shift Value " << cipher->getShiftValue() << ") : " << cipher->callEncode(message) << endl;
            }

            delete cipher;
        }
        else if (choice == 2)
        {

            string message;
            int value;
            cout << "Enter Message to be decoded: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, message);
            while (true)
            {

                cout << "Guess correct Shift value (1-13) to decode message accordingly: ";
                cin >> value;
                while (true)
                {
                    if (cin.fail() || value < 1 || value > 13)
                    {
                        cout << "Invalid input. Shift value must be between 1 and 13. Please try again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> value;
                    }
                    else
                    {
                        break;
                    }
                }
                caeserCipher *cipher = nullptr;
                if (value == 13)
                {
                    cipher = new Rot13Cipher();
                    cout << "Decoded message using Rot13cipher " << "(Shift Value " << cipher->getShiftValue() << ") : " << cipher->decode(message) << endl;
                }
                else if (value != 13)
                {
                    cipher = new caeserCipher();
                    cipher->setShiftValue(value);
                    cout << "Decoded message using caesar cipher " << "(Shift Value " << cipher->getShiftValue() << ") : " << cipher->decode(message) << endl;
                }
                char user;
                cout << "Is the decoded message correct? (y/n): ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> user;
                if (user == 'y')
                {
                    cout << "CONGRATULATIONS YOU SUCCESFULLY DECODED THE MESSAGE!" << endl;
                    delete cipher;
                    break;
                }
                else if (user == 'n')
                {
                    cout << "Would you like to try again? (y/n): ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> user;
                    if (user == 'y')
                    {
                        delete cipher;
                        continue;
                    }
                    else
                    {
                        delete cipher;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid input. Please enter y or n." << endl;
                }

                delete cipher;
            }
        }
        else if (choice == 3)
        {
            string message;
            cout << "Enter Encrypted Message: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, message);
            for (int i = 1; i < 14; i++)
            {
                cout << "Message with Shift Value " << i << ": " << autoDecode(message, i) << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "GOOD BYEEEE! THANK YOU FOR PLAYING" << endl;
        }
        menu();
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 4)
        {
            cout << "Invalid input. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
    }

    return 0;
}
