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
};

int main()
{
    caeserCipher return 0;
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