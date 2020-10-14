// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>

#include <cmath>
#include <math.h>
#include <vector>
#include <random>
#include <tuple>
#include <algorithm>

using namespace std;

std::vector<std::vector<std::vector<double>>> GaborBank(int p, int d, int ih, int iw) {

  // need to add checks so not dividing by 0
  std::vector<std::vector<std::vector<double>>> bank;
  std::vector<double> gx;
  double xincrem = 5 / (iw - 1);
  std::vector<double> gy;
  double yincrem = 5 / (ih - 1);
  for(int i = -2.5; i <= 2.5; i += xincrem) {
    gx.push_back(i);
  }
  for(int j = 2.5; j >= -2.5; j -= yincrem) {
    gy.push_back(j);
  }

  for(int i = 1; i < gy.size(); i++) {
    auto old_size = gx.size();
    gx.resize(2 * old_size);
    std::copy_n(gx.begin(), old_size, gx.begin() + old_size);
  }

  for(int j = 1; j < gx.size(); j++) {
    auto old_size = gy.size();
    gy.resize(2 * old_size);
    std::copy_n(gy.begin(), old_size, gy.begin() + old_size);
  }

  // need to integrate with Parth's code from here on
  for(int k = 0; k < d; k++) {
    bank.push_back(gabor());
  }

  
  
  return bank;
}

int main(){}
