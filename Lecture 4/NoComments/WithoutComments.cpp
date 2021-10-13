#include <iostream>
#include <fstream>

using namespace std;




int main() {
  cout << "Testing: " << 1622 << " = " << 422 << ".\n\n";

  

  ifstream in_stream;
  ofstream out_stream;
  int flag = 0;
  char character;

  in_stream.open("Comments.cpp");
  out_stream.open("WithoutComments.cpp");

  in_stream.get(character);
  while (!in_stream.eof()) {
    if (character == ''' ) {
      in_stream.get(character);
      if ( character == ''') {
	flag = 1;
      } else {
	in_stream.putback(character);
      }
    }
    else if (character == ''' ) {
      in_stream.get(character);
      if ( character == ''') {
	flag = 0;
	in_stream.get(character);
      } else {
	in_stream.putback(character);
      }
    }
    if (flag) {
      
      in_stream.get(character);
    } else {
      
      cout << character;
      out_stream.put(character);
      in_stream.get(character);
    }
    
    
  }

  out_stream.close();
  in_stream.close();
	
  return 0;
}

  
