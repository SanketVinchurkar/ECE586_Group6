#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;;
int main(int argc, char* argv[])
{

   if(argc < 2)
   {
	cout<<"Please provide trace path and mode";
   }
   else
   {
     string path = argv[1];
     string mode = argv[2];

 

     cout <<"\n\n\n Execution mode = "<<mode<<"\n\n\n";

     ifstream my_file(path);
     if(my_file.is_open())
     {
	 string line;
	 while(getline(my_file, line))
              {
		  string s;
                  istringstream iss(line);
		  while (getline(iss, s))
		  {
			  cout<<s<<"\n";
		  }
///////////////////////////////////////////
		 
		 
		 
//////////////////////////////////////////
	      }
     }
   }
}




