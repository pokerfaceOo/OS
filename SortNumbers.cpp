#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Numbers {
      private:
      vector<int> numlist;
      
      public:
             
      int ReadFromFile(char * filename) {
          ifstream fin;
          try {
           fin.open(filename);
           if(fin == NULL)
                  throw ifstream::failure(" cannot open the file");
           int tmp;
           while(!fin.eof()) {
                              fin >> tmp;
                              numlist.push_back(tmp);
           }
          }catch (ifstream::failure& exc) {
                 cerr << "Problem in opening or reading file \"" << filename << "\":" << exc.what() << endl;
                 return 0;
          }catch (bad_alloc& exc) {
                 cerr << "Bad memory allocation: " << exc.what() << endl;
                 fin.close();
                 return -1;
          }catch (overflow_error& exc) {
                 cerr << "Overflow: " << exc.what() << endl;
                 fin.close();
                 return -1;
          }catch(exception& exc) {
                 cerr << "Unknown exception: " << exc.what() << endl;
                 fin.close();
                 return 0;
          }
          fin.close();
          return 1;
      }
      
      void SortNumbers() {
           try{
           sort(numlist.begin(), numlist.end());
           }catch(exception& exc) {
                           cerr << "Problem with sort: " << exc.what() << endl;
           }
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
                           case -1:
                                return 0;
                                break;
                           case 0:
                                break;                                
            }
    }
    nums.SortNumbers();
    nums.WriteNumbers(argv[argc-1]);
    
    return 0;
}
