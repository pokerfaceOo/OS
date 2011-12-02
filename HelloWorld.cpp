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
    return 0;
}
