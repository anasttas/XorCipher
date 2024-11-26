#include <iostream>
#include <string>
using namespace std;

string encode(string message, string key) {
    string result;
    int messageLength = message.length();
    int keyLength = key.length();
    char* massMessage = new char[messageLength];
    char* massKey = new char[keyLength];

    for (int letterMessage = 0; letterMessage < messageLength; letterMessage++) {
        massMessage[letterMessage] = message[letterMessage];
    }

    for (int letterKey = 0; letterKey < keyLength; letterKey++) {
        massKey[letterKey] = key[letterKey];
    }

    for (int letter = 0; letter < messageLength; letter++) {
       
        result += static_cast<char>(massMessage[letter] ^ massKey[letter % keyLength]);
    }

    delete[] massMessage;
    delete[] massKey;

    return result;
}

string decode(string encodeMessage, string key) {
    string decodedMessage;
    int encodeLength = encodeMessage.length();
    int keyLength = key.length();
    char* massEncoded = new char[encodeLength];;
    char* massKey = new char[keyLength];

    for (int letterMessage = 0; letterMessage < encodeLength; letterMessage++) {
        massEncoded[letterMessage] = encodeMessage[letterMessage];
    }

    for (int letterKey = 0; letterKey < keyLength; letterKey++) {
        massKey[letterKey] = key[letterKey];
    }

    for (int letter = 0; letter < encodeLength; letter++) {

        decodedMessage += static_cast<char>(massEncoded[letter] ^ massKey[letter % keyLength]);
    }

    delete[] massEncoded;
    delete[] massKey;

    return decodedMessage;
}

int main()
{
    system("chcp 1251");
    string text;
    cout << "Введи сообщение" << endl;
    cin >> text;
    cout << "Введи ключ" << endl;
    string key;
    cin >> key;
    string result = encode(text, key);
    cout << "Шифр:" << result << endl;
    string encodedMessage = decode(result, key);
    cout << "Дешифр:" << encodedMessage << endl;
}
