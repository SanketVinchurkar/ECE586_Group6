#include<stdio.h>

int main(int argc, char* argv[])
{

proc sim;

   if(argc == 1)
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
                  istringstream iss(line);
                  string s;
		  int command;
		  string address;
		  unsigned int int_address;
                  int string_count = 0;
                  while (getline(iss, s, ' '))
                     {
                      if(string_count == 0)
                         {
		            command = stoi(s);
                            string_count = 1;
                         }
                      else
                         {
			   address = s;
                         }
                     }
              if(mode=="normal")
              sim.NormalMode=1;
              else if(mode=="silent")
              sim.NormalMode=0;
              if(sim.NormalMode==1)
              {
              cout<<"\n--------------------------------------------------------------------------------------"<<endl;
		      cout<<"Command = "<<command<<" Address = "<<address<<"\n";
		  }
           //   int_address = proc.HexToDec(address);
///////////////  code for riscv starts here////////////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              
		      
               }
     }
     else
    {
   	cout<<"Unable to open any file";
    }
   }
   
   return 0;
  
}
