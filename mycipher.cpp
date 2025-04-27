#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    int shift = stoi(argv[1]); // Get shift amount from command line
    string full_text, line;

    while (getline(cin, line)) {
        full_text += line;
    }

    string cipher_text;
    for (char c : full_text) {
        if (isalpha(c)) {
            c = toupper(c);
            char shifted = c + shift;
            if (shifted > 'Z') {
                shifted -= 26;
            }
            cipher_text += shifted;
        }
    }

    for (int i = 0; i < cipher_text.length(); i++) {
        cout << cipher_text[i];
        if ((i + 1) % 5 == 0) cout << " ";
        if ((i + 1) % 50 == 0) cout << endl;
    }
    cout << endl;

    return 0;
}

