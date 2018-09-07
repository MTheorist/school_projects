#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("File.txt",ios::in); 
	char a[20];
	int count=0;
	if(fin){
		while(!fin.eof()){
			fin >> a;
			count++;
		}
		cout<<"Number of words are : "<<count;
	}
	else{
		cout<<"The file does not exist.";
		cout<<"\nTerminating the program.";
		Sleep(1000);
		exit(0);
	}
	fin.close();
	return 0;
}
