#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Numbers {
      private:
      vector<int> numlist;
      
      void ExcDisplay (exception& exc, string msg) {
           cerr << msg << exc.what() << endl;
      }
      
      public:
             
      int ReadFromFile(char * filename) {
          try {
           ifstream fin(filename);
           if(fin == NULL)
                  throw ifstream::failure(" cannot open the file");
           int tmp;
           while(!fin.eof()) {
                              fin >> tmp;
                              numlist.push_back(tmp);
          }
          }catch (ifstream::failure& exc) {
                 string msg = "Problem in opening or reading file \"";
                 msg += filename;
                 msg += "\":";
                 ExcDisplay(exc, msg);
                 return 0;
          }catch (bad_alloc& exc) {
                 ExcDisplay(exc, "Bad memory allocation: ");
                 return -1;
          }catch (overflow_error& exc) {
                 ExcDisplay(exc, "Overflow: ");
                 return -1;
          }catch(exception& exc) {
                 ExcDisplay(exc, "Unknown error: ");
                 return 0;
          }
          return 1;
      }
      
      bool SortNumbers() {
           try{
           sort(numlist.begin(), numlist.end());
           }catch(exception& exc) {
                           cerr << "Problem with sort: " << exc.what() << ". Program was aborted." << endl;
                           return false;
           }
           return true;
      }
      void WriteNumbers(char* filename) {
           ofstream fout;
           try {
               fout.open(filename);
               if(fout == NULL)
                  throw ifstream::failure("file not opened");
               for(vector<int>::iterator it = numlist.begin(); it != numlist.end(); it++)
                                         fout << *it << " ";
           }catch (ifstream::failure& exc) {
                 cerr << "Problem with writing in file \"" << filename << "\" :" << exc.what() << endl;
           }catch (exception& exc) {
                 cerr << "Problem with vector: " << exc.what() << endl;
           }
          fout.close();
      }
};


int main(int argc, char* argv[]) {
    if(argc < 3) {
            cerr << "Not enough arguments!" << endl;
            return -1;
    }
    Numbers nums;
    for(int i = 1; i < argc - 1; i++) {
            int status = nums.ReadFromFile(argv[i]);
            switch(status) {
                           case -1: //Fatal error. Program will not continue.
                                cout << "Program was aborted" << endl;
                                return 0;
                                break;
                           case 0: //Error was founded, but it's not fatal. Program will continue
                                cout << "Program will continue" << endl;
                           case 1: //OK
                                break;                                
            }
    }
    if(nums.SortNumbers())
                          nums.WriteNumbers(argv[argc-1]);
    
    return 0;
}
