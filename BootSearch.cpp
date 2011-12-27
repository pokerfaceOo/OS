#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
int candIndex = 0;
//int prevFound = 0;

void WriteCandidate(int posEnd) { 
     if(posEnd < 512)
               return;
     cout << candIndex + 1 << " candidate(-s) was founded" << endl;
     char* buf = new char[512];
     fin.seekg(posEnd - 512);
     fin.read(buf, 512);
     ofstream fout;
     //Making the filename of candidate on boot sector
     string filename = "candidate";
     char* tail = new char[sizeof(candIndex) * 2 + 1];
     itoa(candIndex, tail, 10);
     filename += tail;
     char *chr_fname = new char[filename.length()];
     strcpy(chr_fname,filename.data());
     fout.open(chr_fname, ios::binary);
     
     if(fout == NULL)
             throw ios::failure(" can't open file for writing");
     fout.write(buf, 512);
     fout.close();
     //Making the filename of candidate's disasm
     //prevFound = posEnd; 
     //filename = "\"C:\\Program Files\\nasm\\ndisasm\" " + filename + ">disasm";
     filename = "ndisasm " + filename + ">disasm";
     tail = new char[sizeof(candIndex) * 2 + 1];
     itoa(candIndex++, tail, 10);
     filename += tail;
     filename += ".txt";
     chr_fname = new char[filename.length()];
     strcpy(chr_fname,filename.data());
     if(!system(chr_fname)){
                            return;
     }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
            cerr << "Not enough arguments!" << endl;
            return -1;
    } else if (argc > 2) {
            cerr << "Too many arguments!" << endl;
            return -1;
    }      
    try {
    fin.open(argv[1], ios::binary);
    if(fin == NULL)
           throw ios::failure(" can't open image file");
    int prev = 0, tmp;
    char* buf = new char[1];
    while(!fin.eof()) {
                      fin.read(buf, 1);
                      tmp = buf[0];                      
                      if(tmp == char(0xAA) && prev == char(0x55))
                             WriteCandidate(fin.tellg());
                      prev = tmp;
    }
    } catch(ios::failure& exc) {
      cerr << exc.what() << endl;
      return -1;
    } catch(exception& exc) {
      cerr << "Error: " << exc.what() << endl;
      return -1;
    }
    return 0;
}
