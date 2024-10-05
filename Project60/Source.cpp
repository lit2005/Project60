#include <iostream>  
#include <cstring>  
using namespace std;
class MyString {
private:
    char* str;  
    int length; 
    static int objectCount;  

public:
    
    MyString() : length(0) {
        str = new char[81]; 
        str[0] = '\0'; 
        objectCount++;
    }

    
    MyString(int size) : length(0) {
        str = new char[size + 1];
        str[0] = '\0';
        objectCount++;
    }

     
    MyString(const char* input) {
        length = strlen(input);
        str = new char[length + 1];
        strcpy(str, input);
        objectCount++;
    }

   
    ~MyString() {
        delete[] str;
        objectCount--;
    }

   
    void input() {
        cout << "Введите строку: ";
        cin.getline(str, 80);  
        length = strlen(str);
    }

     
    void output() const {
        cout << str << endl;
    }

    
    void MyStrcpy(MyString& obj) {
        delete[] str;  
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

   
    bool MyStrStr(const char* subStr) {
        return strstr(str, subStr) != nullptr;
    }

   
    int MyChr(char c) {
        for (int i = 0; i < length; i++) {
            if (str[i] == c) {
                return i; 
            }
        }
        return -1;  
    }

   
    int MyStrLen() {
        return length;
    }

    
    void MyStrCat(MyString& b) {
        char* newStr = new char[length + b.length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;  
        str = newStr;
        length += b.length;
    }

    
    void MyDelChr(char c) {
        char* newStr = new char[length + 1];
        int newLength = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] != c) {
                newStr[newLength++] = str[i];
            }
        }
        newStr[newLength] = '\0';
        delete[] str; 
        str = newStr;
        length = newLength;
    }

 
    int MyStrCmp(MyString& b) {
        if (strcmp(str, b.str) < 0) {
            return -1; 
        }
        else if (strcmp(str, b.str) > 0) {
            return 1; 
        }
        return 0;  
    }

    
    static int getObjectCount() {
        return objectCount;
    }
};

 
int MyString::objectCount = 0;

int main() {
    MyString str1; 
    str1.input();
    str1.output();

    MyString str2("Hello, World!");
    str2.output();

    str1.MyStrcpy(str2);  
    str1.output();

    cout << "Объектов MyString: " << MyString::getObjectCount() << endl;

    return 0;
}