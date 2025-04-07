#include <iostream>
#include <vector>
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
    caeserCipher *cipher = new caeserCipher;
    char y_n;
    cout << "Do you want to encode a new message? (y/n): ";
    cin >> y_n;
    bool choice = (y_n == 'y') ? true : (y_n == 'n') ? false
                                                     : false;


    
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    Decoder decoder;
    decoder.autoDecode(message);
                                                 
    
    return 0;
}


