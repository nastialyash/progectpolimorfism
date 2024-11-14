

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class File {
public:
    
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file " << path << endl;
            return;
        }

        cout << "File content in text format:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};
class File2 : public File {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file " << path << endl;
            return;
        }

        cout << "File content in ASCII codes:\n";
        char ch;
        while (file.get(ch)) {
            cout << (int)ch << endl;  
        }
        cout << endl;
        file.close();
    }
};

int main()
{
    const char* filePath = "example.txt";

    File basicFile;
    File2 asciiFile;
    cout << "Basic File Display:" << endl;
    basicFile.Display(filePath);
    cout << endl;

 
    cout << " File2 Display" << endl;
    asciiFile.Display(filePath);
    cout << endl;

}