#include <iostream>
#include <fstream>

using namespace std;

/* TEST COMMENT */


int main() {
  cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";

  /* TEST COMMENT */

  ifstream in;
  ofstream out_stream;
  int flag = 0;
  char character;

  in.open("Comments.cpp");
  out_stream.open("WithoutComments.cpp");

  in.get(character);
  while (!in.eof()) {
    if (character == '/' ) {
      in.get(character);
      if ( character == '*') {
	flag = 1;
      } else {
	in.putback(character);
      }
    }
    else if (character == '*' ) {
      in.get(character);
      if ( character == '/') {
	flag = 0;
	in.get(character);
      } else {
	in.putback(character);
      }
    }
    if (flag) {
      /* IN COMMENT */
      in.get(character);
    } else {
      /* NOT IN COMMENT */
      cout << character;
      out_stream.put(character);
      in.get(character);
    }
    
    
  }

  out_stream.close();
  in.close();
	
  return 0;
}

  
