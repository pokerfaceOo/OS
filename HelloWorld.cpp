#include <iostream>

using namespace std;

class Hello {
      public:
             static void ShoutOutLoud(char* str) {
                    cout << "Hello " << str << "!" << endl;
             }
};

int main() {
    Hello::ShoutOutLoud("World");
    system("pause");
    return 0;
}
