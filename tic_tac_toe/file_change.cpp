#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
	char line[200];
	fstream fin, fout;
	int counter = 0;
	int i = 0;
	
	fin.open( "style_out.txt", ios::in );
	fout.open( "style_2.txt", ios::out | ios::trunc );
	fout << "\t\t\tcase" << "\'" << char('A') << "\'" << ":" << endl;
	
	while( fin.getline( line, 200 ) ) {
		if( line[0] == 'c' ) {
			fout << "\t\t\t\t";
			for( int j = 0; j < strlen( line ); j++ ) {
				if( line[j] == '\\' ) {
					fout << "\\\\";
				}
				else {
					fout << line[j];
				}
			}
			fout << endl;
			if( counter == 0 ) {
				fout << "\t\t\t\tpos_end.X = getX();" << endl;
				fout << "\t\t\t\tpos_end.Y = getY();" << endl;
				counter = 1;
			}
			fout << "\t\t\t\tgotoXY( pos_start.X, getY() + 1, 0 );" << endl;
		}
		else {
			counter = 0;
			fout << "\t\t\t\tpos.X = pos_end.X + 1;" << endl;
			fout << "\t\t\t\tpos.Y = getY() - 1;" << endl;
			fout << "\t\t\t\tgotoXY( pos_end.X + 2, pos_end.Y, 0 );" << endl;
			fout << "\t\t\t\tpos_start.X = getX();"<<endl;
			fout << "\t\t\t\tpos_start.Y = getY();"<<endl;
			fout << "\t\t\t\tbreak;" << endl;
			i++;
			fout << "\t\t\tcase" << "\'" << char('A' + i) << "\'" << ":" << endl;
		}
	}
	
	return 0;
}
