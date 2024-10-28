#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
/*
a + bc - de + f -
g+hi-j+k-l
abc+-def
*/

bool findStr(char* str) {
    int pos = 1; 
    while (str[pos + 1] != '\0') {
        if (str[pos - 1] == '+' && str[pos + 1] == '-') {
            return true;
        }
        pos++;
    }
    return false;
}

char* Change(char* str) {
    size_t newSize = strlen(str) * 4 + 1;
    char* t = new char[newSize];
    int pos1 = 0;
    *t = 0;

    while (true) {
        char* p = nullptr;

        for (int i = pos1 + 1; str[i + 1] != '\0'; i++) {
            if (str[i - 1] == '+' && str[i + 1] == '-') {
                p = &str[i - 1];
                break;
            }
        }

        if (!p) break;

        int pos2 = p - str;
        strncat_s(t, newSize, str + pos1, static_cast<rsize_t>(pos2 - pos1));
        strcat_s(t, newSize, "****"); 
        pos1 = pos2 + 3;
    }

    strcat_s(t, newSize, str + pos1);

    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (findStr(str)) {
        char* dest = Change(str);
        cout << "'+<char>-' found and will be changed" << endl;
        cout << "Original string (param) : " << str << endl;
        cout << "Modified string (result): " << dest << endl;
        delete[] dest;
    }
    else {
        cout << "'+<char>-' pattern not found" << endl;
    }

    return 0;
}
