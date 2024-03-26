#include "default.h"

using namespace std;

void gr2txt(){
    ifstream fin;
    ofstream fout;
    char temp[100];
    fin.open(".\\docs\\USA-road-d.NY.gr");
    fout.open(".\\docs\\USA-road-d.NY.txt");
    if(!fin.is_open())
        cout<<"Unable to open original .gr file, check your directory"<<endl;
    while(fin.getline(temp, 100))
    {
        string out(temp);
        out.erase(0, 2);
        fout << out << endl;
    }
    fin.close();
    fout.close();
}