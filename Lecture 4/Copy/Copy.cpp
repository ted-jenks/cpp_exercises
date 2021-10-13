#include <iostream>
#include <fstream>

using namespace std;
	
int main()
{
  char character;
  ifstream in_stream;
  ofstream out_stream;
	
  in_stream.open("Lecture_4");
  out_stream.open("Copy_of_4");
	
  in_stream.get(character);
  while (!in_stream.eof())
    {
      cout << character;
      out_stream.put(character);
      in_stream.get(character);
    }

  out_stream.close();
  in_stream.close();
	
  return 0;
}
