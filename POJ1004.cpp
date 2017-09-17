#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i;
    double num = 0;
    double bank[12];
    for(i=0; i<12; i++)
    {    
        cin >> bank[i];
        num+=bank[i];
    }
    cout << '$' << (num/12.0) << endl;    
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
