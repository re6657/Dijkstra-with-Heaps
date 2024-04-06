#include "default.h"
#include "Fib_Heap.h"
#include "Dijkstra.h"
#include "read_gr_txt.h"

using namespace std;

int main(){
    try{
        Graph t({});
        t.buildGraphFromtxt(".\\docs\\USA-road-d.USA.txt");
        FibHeap h({});
        LARGE_INTEGER t1,t2,tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);
        int d = dijkstra(t, 2245, 102, h);
        QueryPerformanceCounter(&t2);
        double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
        cout << d << endl <<"time = "<<time<<"s"<<endl;
    }catch(const char* msg){
        cout << msg << endl;
    }
    return 0;
}