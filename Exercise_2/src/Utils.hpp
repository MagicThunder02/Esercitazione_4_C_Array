#pragma once
#include <string>
using namespace std;

// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);

// filePath: path name of the input file
// S: initial sum invested
// n: resulting size of the vectors
// return the result of the reading, true is success, false is error
bool readHeader(const string inputFilePath, double& S, int& n);

// filePath: path name of the input file
// S: initial sum invested
// n: resulting size of the vectors
// return the result of the reading, true is success, false is error
bool readBody(const string inputFilePath, int n,double*& w, double*& r);

// filePath: path name of the input file
// S: initial sum invested
// n: resulting size of the vectors
// w: vector of the weights
// r: vector of the rate of return
double calculateValue(const int n, const double s, double*& w, double*& r);


// filePath: path name of the input file
// S: initial sum invested
// V: Portfolio value
double calculateRateOfReturn(const double S, const double V);

// ExportResult export the result obtained in file
// outputFilePath: path name of the output file
// n: resulting size of the vectors
// w: vector of the weights
// r: vector of the rate of return
// V: Portfolio value
// R: Portfolio rate of return
bool ExportResult(const string& outputFilePath,
                  const int& n,
                  const double& S,
                  double* const& w,
                  double* const& r,
                  const double V,
                  const double R);

