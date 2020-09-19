// Ruby Hirsch 
// SSID: 1826000
// Assignment #1
// Submission Date: 9/20/20
//
// Description: A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain lowercase alpha and digits 0-9
//
// Command Line Arguments 
//
// -p theplaintextmessage1 - the plaintext (p) message to be encrypted
// -C 2qnyujrw2n62vn11jpna - the cipher (C) text to be decrypted
// -k 9                    - the key (k) shift value
// -E                      - the option to encrypt (E)
// -D                      - the option to decrypt (D) 
//
//Command line arg reference: 
//https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args?view=vs-2019 
// Used modulo formula posted by SheevatsaR on StackoverFlow: 
// https://stackoverflow.com/questions/1082917/mod-of-negative-number-is-melting-my-brain
#include <iostream>
#include <string>
#include <typeinfo>

int main(int argC, char *argV[])
{ 
  if (argC < 6)
  {
    std::cout << "You need to type in more command line arguments.\n";
    std::cout << "If you are confused, please refer to these instructions:" << std::endl;
    std::cout << "-p (example)theplaintextmessage1 is the plaintext (p) message to be encrypted. \n" << "-C (example)2qnyujrw2n62vn11jpna is the cipher (C) text to be decrypted\n" << "-k (example)9 is the key (k) to shift value (the largest value you can shift by is 2147483647(at least on my computer))\n" << "-E is the option to encrypt (E)\n" << "And -D is the option to decrypt (D)"; 
    std::cout << "Goodbye";
    return 0;
  }

  std::string plainText;
  std::string cipherText;
  bool encrypt = false;
  bool decrypt = false;
  long int shiftNum;
  char alphabetDigits[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
  int plainLength = plainText.length();
  std::string encryptedText;
  std::string decryptedText;

  for (int i=1; i < argC; i++)
  { 
    if (std::string(argV[i]) == "-p")
    {
      if (argC > i + 1)
      {
        plainText = std::string(argV[i+1]);
      }
      else 
      {    
        std::cout << "There is no argument after -p, try again." << std::endl;
        return 0;
      }
    continue;
    }
     
    if (std::string(argV[i]) == "-C")
    {
      if (argC > i + 1)
      {
        cipherText = std::string(argV[i+1]);
      }
      else
      { 
        std::cout << "There is no argument after -C ,try again." << std::endl;
        return 0;
      }   
    continue;
    }
     
    if(std::string(argV[i]) == "-k")
     { 
       if (argC > i + 1)
      {
        shiftNum = std::stoi(argV[i+1]);
      }
      else 
      {
        std::cout << "There is no argument after -k, try again" << std::endl;
        return 0;
      }
      continue;
    }

    if (std::string(argV[i]) == "-E")
    {
      encrypt = true;
      continue;
    }
    
    if (std::string(argV[i]) == "-D")
    {
      decrypt = true;
    }
  }

  if (encrypt)
  {
    for (int i=0; i<plainText.length(); i++)
    { 
      for (int j=0; j<36; j++)
      {
        if (plainText[i] == alphabetDigits[j])
        {
          encryptedText = encryptedText + alphabetDigits[((j+shiftNum)%36 + 36) % 36]; 
          // cite: '%' operater is remainder not modulo 
          // used modulo formula posted by SheevatsaR on StackoverFlow 
          // https://stackoverflow.com/questions/1082917/mod-of-negative-number-is-melting-my-brain
         } 
      }
    }
    std::cout << "The program is going to encrypt \n";
    std::cout << "The encrypted text is: " << encryptedText << std::endl;
  }

 if (decrypt) 
  {
    for (int i=0; i<cipherText.length(); i++)
    {
      for (int j=0; j<36; j++)
      { 
        if (cipherText[i] == alphabetDigits[j])
        {
          decryptedText = decryptedText + alphabetDigits[((j-shiftNum)%36 + 36)% 36];  
          // cite: '%' operater is remainder not modulo 
          // used modulo formula posted by SheevatsaR on StackoverFlow 
          // https://stackoverflow.com/questions/1082917/mod-of-negative-number-is-melting-my-brain
        }
      }
    }
    std::cout << "The program is going to decrypt \n";
    std::cout << "The decrypted text is: " << decryptedText << std::endl; 
  }
 std::cout << "Thank you for checking out my program!";  
return 0;
}


