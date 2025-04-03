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
        int messageSize = encodeMessage.size();
        for (int i = 0; i < messageSize; i++)
        {
            for (int j = 0; j < alpha.size(); j++)
                if (encodeMessage[i] == alpha[j])
                {
                    encodeMessage[i] = alpha[(j + shiftValue) % 26];
                }
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

// void autoDecode()
// {
//     string message;
//     cout << "Enter encoded message: ";
//     cin >> message;
//     for (int i; i < message.size(); i++)
//     {
//     }
// }