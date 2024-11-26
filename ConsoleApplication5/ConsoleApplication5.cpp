#include <iostream>
#include <string>
using namespace std;

string encode(string message, string key) {
    string result;
    char* massMessage = new char[message.length()];;
    char* massKey = new char[key.length()];

    for (int letterMessage = 0; letterMessage < message.length(); letterMessage++) {
        massMessage[letterMessage] = message[letterMessage];
    }

    for (int letterKey = 0; letterKey < key.length(); letterKey++) {
        massKey[letterKey] = key[letterKey];
    }

    for (int letter = 0; letter < message.length(); letter++) {
       
        result += static_cast<char>(massMessage[letter] ^ massKey[letter % key.length()]);
    }

    delete[] massMessage;
    delete[] massKey;

    return result;
}

string decode(string encodeMessage, string key) {
    string decodedMessage;
    char* massEncoded = new char[encodeMessage.length()];;
    char* massKey = new char[key.length()];

    for (int letterMessage = 0; letterMessage < encodeMessage.length(); letterMessage++) {
        massEncoded[letterMessage] = encodeMessage[letterMessage];
    }

    for (int letterKey = 0; letterKey < key.length(); letterKey++) {
        massKey[letterKey] = key[letterKey];
    }

    for (int letter = 0; letter < encodeMessage.length(); letter++) {

        decodedMessage += static_cast<char>(massEncoded[letter] ^ massKey[letter % key.length()]);
    }

    delete[] massEncoded;
    delete[] massKey;

    return decodedMessage;
}

int main()
{
    system("chcp 1251");
    string text, key;

    cout << "Введи сообщение" << endl;
    cin >> text;
    cout << "Введи ключ" << endl;
    cin >> key;
    string result = encode(text, key);
    string encodedMessage = decode(result, key);
    cout << "Шифр:" << result << endl;
    cout << "Дешифр:" << encodedMessage << endl;

}
