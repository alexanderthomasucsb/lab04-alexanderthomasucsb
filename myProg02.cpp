// countDucks.cpp 
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream

using namespace std;


int nonDuckCount = 0;

void processLine(string thisLine, int &duckCount) {
  
  int pos = thisLine.find("duck");
  if (pos != string::npos){
    duckCount = duckCount + 1;
  }
  else{
	  nonDuckCount = nonDuckCount +1;
  }
    
}

int main(int argc, char *argv[])
{
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }

  ifstream ifs; // the stream we will use for the input file
  string thisLine;

  int duckCount = 0;
  int animalCount = 0;
  

  ifs.open(argv[1]);

  if (ifs.fail()) {
    cerr << "Could not open file:" << argv[1] << endl;
    exit(2);
  }

  getline(ifs,thisLine);
  while (  !ifs.eof() ) {
    processLine(thisLine, duckCount);
    getline(ifs,thisLine);
  }


  animalCount = duckCount +nonDuckCount;


  cout << "Report for " << argv[1] << ":" << endl;
  cout << "   Animal count:    " << animalCount<<endl;
  cout << "   Duck count:      " << duckCount<<endl;
  cout << "   Non duck count:  " << nonDuckCount<<endl;



  return 0;
}
