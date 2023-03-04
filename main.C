#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;

// Defining every format
struct R_format {
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
    uint32_t rs2 : 5;
    uint32_t funct7 : 7;
} ;	

struct I_Format {
    uint32_t imm : 12;
    uint32_t rs1 : 5;
    uint32_t funct3 : 3;
    uint32_t rd : 5;
    uint32_t opcode : 7;
};

struct S_Format {
    uint32_t imm4_0 : 5;
    uint32_t funct3 : 3;
    uint32_t rs2 : 5;
    uint32_t rs1 : 5;
    uint32_t imm11_5 : 7;
    uint32_t opcode : 7;
};

struct B_Format {
    uint32_t imm11 : 1;
    uint32_t imm4_1 : 4;
    uint32_t funct3 : 3;
    uint32_t rs2 : 5;
    uint32_t rs1 : 5;
    uint32_t imm10_5 : 6;
    uint32_t imm12 : 1;
    uint32_t opcode : 7;
};

struct U_Format {
    uint32_t imm : 20;
    uint32_t rd : 5;
    uint32_t opcode : 7;
};

struct J_Format {
    uint32_t imm19_12 : 8;
    uint32_t imm11 : 1;
    uint32_t imm10_1 : 10;
    uint32_t imm20 : 1;
    uint32_t rd : 5;
    uint32_t opcode : 7;
};


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
		
	// Implement its instruction depending on funct3 and funct7 (add,sub etc.). Use if-else.	
		
	// For I-format
case 0010011:	
        I_format I;
        I.rd=bit.substr((31-11), 5);  
	I.funct3=bit.substr((31-14), 3);
	I.rs1=bit.substr((31-19), 5);
	I.imm=bit.substr(31, 7);
	// For S-format	
case 0100011:	
        S_format S;
        S.imm4_0=bit.substr((31-11), 5);  
	S.funct3=bit.substr((31-14), 3);
	S.rs1=bit.substr((31-19), 5);
	S.rs2=bit.substr((31-24), 5);
	S.imm11_5=bit.substr(0, 7);
	// For B-format	
case 1100011:	
        B_format B;
        B.imm12=bit.substr((31-7), 1);  
	B.imm10_5=bit.substr((31-14), 3);
	S.rs1=bit.substr((31-19), 5);
	S.rs2=bit.substr((31-24), 5);
	S.imm11_5=bit.substr(0, 7);
	// For U-format
case 0110111:	
        U_format U;
        U.rd=bit.substr((31-11), 5);  
	U.imm=bit.substr(0, 18);
	// For J-format	
case 1101111:	
        J_format J;
        J.imm19_12=bit.substr((31-12), 8);  
	J.imm11=bit.substr((31-11), 1);
	J.imm10_1=bit.substr((31-10), 10);
	J.imm20=bit.substr((31-20), 1);
	J.rd = bit.substr((31-11), 5);
}
//////////////////////////////////////////
	      }
     }
   }
}




