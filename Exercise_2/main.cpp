#include "iostream"
#include "Utils.hpp"
using namespace std;

int main()
{

    cout << "Inizio Programma" << endl;

    // istringstream convert(line);
    // convert.clear();
    // line = "6";
    //convert.str(line);

    string fileName = "data.csv"; // file name

    double S = 0;
    int n = 0;

    readHeader(fileName, S, n);

    cout << "S: " << S << endl;
    cout << "n: " << n << endl;

    double* w = nullptr;
    double* r = nullptr;

    readBody(fileName,n, w, r);

    cout << " w= " << ArrayToString(n, w) << endl;
    cout << " r= " << ArrayToString(n, r) << endl;

    double V = calculateValue(n, S, w, r);
    cout << "V: " << V << endl;

    double R = calculateRateOfReturn(S, V);
    cout << "R: " << R << endl;

    string outputFilePath = "resutl.txt";
    bool result = ExportResult(outputFilePath,n,S,w,r,V,R);
    cout << result;

    return 0;

}

