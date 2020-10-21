// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>

#include <cmath>
#include <math.h>
#include <vector>
#include <random>
#include <tuple>
#include <algorithm>

using namespace std;

std::vector<std::vector<std::vector<double>>> GaborBank(int p, int d, int ih, int iw, double tol) {

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

    // Not sure what to do with arguments, conflicting in R code too
    bank.push_back(gabor());
  }
  
  // implementing reduce, need to check, also very inneficient
  std::vector<double> w;
  for(std::vector<std::vector<std::vector<double>>>::iterator i = bank.begin(); i != bank.end(); ++i) {
    for(std::vector<std::vector<double>>::iterator j = i->begin(); j != i->end(); ++j) {
      for(std::vector<double>::iterator k = j->begin(); k != j->end(); ++k) {
	if ((*k <= tol) && (*k >= tol)) {
	  *k = 0;
	}
      }
    }
  }

  return bank;
}

// namespace py = pybind11;

// PYBIND11_MODULE(GaborBank, m) {
// m.doc() = "GaborBank";
// m.def("GaborBank, &GaborBank", "Function to create bank of gabor filters");
// }
