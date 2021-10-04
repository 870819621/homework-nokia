//
// Created by c2xu on 2021/9/14.
//

#include <iostream>
#include <memory>

using namespace std;

class CString {
public:
    CString(string str) {
        this->str = new string;
        *(this->str) = str;
        cout << "normal construct" << endl;
    }

    ~CString() {
        if (str != nullptr)
            cout << "destruct :" << *str << endl;
        else
            cout << "destruct :nullptr" << endl;
    }

    CString(const CString &Cstr) {
        this->str = new string;
        *(this->str) = *Cstr.str;
        cout << "copy construct" << endl;
    }

    CString &operator=(const CString &Cstr) {
        if (this != &Cstr) {
            if (this->str == nullptr) {
                this->str = new string;
            }
            *(this->str) = *Cstr.str;
        }
        cout << "nomal assignment" << endl;
        return *this;
    }

    CString(CString &&Cstr) {
        this->str = Cstr.str;
        Cstr.str = nullptr;
        cout << "rvalue copy construct" << endl;
    }

    CString &operator=(CString &&Cstr) {
        if (this != &Cstr) {
            if (Cstr.str != nullptr) {
                this->str = Cstr.str;
                Cstr.str = nullptr;
                cout << "rvalue assignment" << endl;
            }

        }
        return *this;
    }

private:
    string *str;
};

int main() {
    auto str1 = std::make_shared<CString>("aaa");
    auto str2 = std::make_shared<CString>(*str1);
    auto str3 = std::make_shared<CString>(std::move(*str1));
    str3->operator=(*str2);
    str3->operator=(std::move(*str2));
    return 0;
}
