#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


bool readHeader(const string filePath, double& S, int& n) {
    // opening the file
    ifstream file;
    file.open(filePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }


    string line;
    string value;

    // getting the first two lines
    while(getline(file,line))
    {
        stringstream   linestream(line);
        string         value;

        getline(linestream, value, ';');

        if (value[0] == 'S') {
            getline(linestream, value, ';');
            S = stod(value);
            continue;
        }
        if (value[0] == 'n'){
            getline(linestream, value, ';');
            n = stoi(value);
            break;
        }
        break;

    }

    file.close();
    return true;
}


bool readBody(const string filePath, int n, double*& w, double*& r) {
    // opening the file
    ifstream file;
    file.open(filePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }

    string line;

    w = new double[n];
    r = new double[n];
    int i = 0;

    while (getline(file, line))
    {
        stringstream linestream(line);

        if (line[0] == 'S' || line[0] == 'n' || line[0] == 'w')
            continue;

        // getting the values from the file
        string value;
        for (int j = 0;  j< 2; j++) {
            getline(linestream, value, ';');
            // if j=0 it is the first column and goes in w otherwise it goes in r
            if (j == 0) {
                w[i] = stod(value);
            }
            else{
                r[i] = stod(value);
            }
                    }

        i++;
    }

    file.close();
    return true;
}


double calculateValue(const int n, const double S, double*& w, double*& r) {
    // v_i = (1+r_i)*w_i*S

    double V = 0;

    for (int i = 0; i < n; i++) {
        V += (1+r[i])* S *w[i];
    }

    return V;
}

double calculateRateOfReturn(const double S, const double V) {
    return V/S -1;
}

bool ExportResult(const string& outputFilePath,const int& n,const double& S,double* const& w,double* const& r,const double V,const double R)

{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2) <<"S = "<< S << ", n = " << n << endl;
    file<< "w = " << ArrayToString(n, w) << endl;
    file<< "r = " << ArrayToString(n, r) << endl;
    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << R << endl;
    file<< "V: " << fixed << setprecision(2) << V << endl;

    // Close File
    file.close();

    return true;
}
