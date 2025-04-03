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
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string alphaCaps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < encodeMessage.size(); i++)
        {
            string x = encodeMessage[i];
        }
    }

public:
};

void autoDecode()
{
    string message;
    cout << "Enter encoded message: ";
    cin >> message;
    for (int i; i < message.size(); i++)
    {
    }
}