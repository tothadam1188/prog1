#include <iostream>
#include <string>
#include <fstream>

std::string encrypt(std::string text)
{
    std::string encr_text;
    char key='K';
    for(int i=0; i<text.length();i++)
    {
        char encrypted_char = text[i] ^ key;
        encr_text += encrypted_char;
    }
    return encr_text;
}
int main()
{
    std::string text;
    std::cout << "Text to encrypt: ";
    std::getline(std::cin, text);
    std::string encrypted_text=encrypt(text);
    std::cout << "Encrypted text: "<< encrypted_text << std::endl;

    std::ofstream output_encrypted("encrypted.txt");
    output_encrypted << encrypted_text;
    output_encrypted.close();
    return 0;
}
