/* strtok example */
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main ()
{
	string s;
	string token;

 	ifstream f;
 	f.open("stall.obj");

 	if(f.is_open()){
 		while(!f.eof()){
 			getline(f, s);
 			istringstream ss(s);
 			cout << s << endl;
 			cout << getline(ss, token, ' ') << endl;
 			cout << ss << endl;
 			cout << token << endl;
break;
 		}
 	}

 	f.close();

  return 0;
}