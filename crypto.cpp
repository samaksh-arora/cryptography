#include <iostream>
#include <vector>
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
                x = 'a' + (x - 'a' + shiftValue + 26) % 26;
            }
            else if (x >= 97 && x <= 122)
            {
                x = 'A' + (x - 'A' + shiftValue + 26) % 26;
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
    void setShiftValue (int value) {
        if (value < 1 || value > 13) {
            cout << "Shift value must be between 1 and 13. \n";
        }
    shiftValue = value;
    }
};

class Rot13Cipher : public caesarCipher {
public: 
    Rot13Cipher() {
        setShiftValue(13);
    }
};

int main()
{
    caeserCipher *cipher = new caeserCipher;
    char y_n;
    cout << "Do you want to encode a new message? (y/n): ";
    cin >> y_n;
    bool choice = (y_n == 'y') ? true : (y_n == 'n') ? false
                                                     : false;

    return 0;
}

void autoDecode()
{
    string message;
    cout << "Enter encoded message: ";
    cin >> message;
    for (int i; i < message.size(); i++)
    {
    }
}
