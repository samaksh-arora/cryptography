#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <algorithm>

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


class Decoder{
    public:
        /**void split(string message) {
            vector<string> splitMessage;
            string temp = "";
            char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
            for (int i=0; i < message.size(); i++){}
                if (message[i]){
    
                }
                
            }
        }
        **/
        int in(char array[], int len, char find) {
            for (int i=0; i<len; i++){
                if (array[i] == find){
                    return i;
                }
            }
            return -1;
        }
        void autoDecode(string inMessage)
        {
            char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
            for (int i; i<inMessage.size(); i++) {
                if (isupper(inMessage[i])) {
                    inMessage[i] = tolower((inMessage[i]));
                }
                else {
                    continue;
                }
            }
            for (int key=1; key < 26; key++)
            {
                int index = 0;
                string message = inMessage;
                for (int i = 0; i < inMessage.size(); i++) {
                    int messageIndex = in(alphabet, 26, inMessage[i]);
                    index = messageIndex+key;
                    if (messageIndex != -1) {
                        message[i] = alphabet[index%26];
                    }
                }
                cout << "Decoded: " << message << " with " << key << " key " << endl;
            }
        }
    };


int main()
{
    caeserCipher *cipher = nullptr;
    char y_n;
    cout << "Do you want to encode a new message? (y/n): ";
    cin >> y_n;
    bool choice = (y_n == 'y') ? true : (y_n == 'n') ? false
                                                     : false;
    while (choice)
    {
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

        if (value != 13)
        {
            cipher = new caeserCipher();
        }
        cipher->setShiftValue(value);
        cout << "Encoded message using caesar cipher " << "(Shift Value " << cipher->getShiftValue() << ") : " << cipher->callEncode(message);
        break;
    }


    
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    Decoder decoder;
    decoder.autoDecode(message);
                                                 
    
    return 0;
}





