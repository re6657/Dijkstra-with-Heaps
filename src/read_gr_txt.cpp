#include "default.h"
#include "read_gr_txt.h"

using namespace std;

void gr2txt(){
    ifstream fin;
    ofstream fout;
    char temp[50];
    fin.open(".\\docs\\USA-road-d.USA.gr");
    fout.open(".\\docs\\USA-road-d.USA.txt");
    if(!fin.is_open())
        cout<<"Unable to open original .gr file, check your directory"<<endl;
    while(fin.getline(temp, 50))
    {
        string out(temp);
        out.erase(0, 2);
        fout << out << endl;
    }
    fin.close();
    fout.close();
}
