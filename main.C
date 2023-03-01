#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;
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

//extract memory loacation and instruction separately from string 's'		 
int address = stoi(s.substr(0,s.find("")));
string instruction = s.substr(s.find("")+1);

	 
		 
//convert instruction from hex to binary
unsigned int bits=bitset<32>(stoi(instruction,nullptr,16)).to_ulong();
		 
/*
struct bits{
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
};
*/

//set into opcode field
unsigned int opcode=bits & 0xFF;
		 
// Defining every format
struct R_format {
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
    uint32_t rs2 : 5;
    uint32_t funct7 : 7;
} ;	


switch(opcode)
{
	// For R-type Format	
case 0110011:	
        R_format R;
        R.rd=bit.substr((31-11), 5);  
	R.funct3=bit.substr((31-14), 3);
	R.rs1=bit.substr((31-19), 5);
	R.rs2=bit.substr((31-24), 5);
	R.funct7=bit.substr(31, 7);
		
}
//////////////////////////////////////////
	      }
     }
   }
}




