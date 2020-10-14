#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <cmath>
#include <math.h>
#include <vector>
#include <boost/math/constants/constants.hpp>

using namespace std

class Random {
public:
  int alpha;
  std::vector<std::vector<double>> betax
  std::vector<std::vector<double>> betay
  std::vector<std::vector<double>> f
  std::vector<std::vector<double>> phi
  std::vector<std::vector<double>> x0
  std::vector<std::vector<double>> y0
  std::vector<std::vector<double>> tau
};

std::vector<std::vector<double>> cpprinvgamma(int n, double shape, double scale) {
  std::default_random_engine generator;
  std::gamma_distribution<double> distribution(shape, scale);
  std::vector<double> out;

  // Could do more efficiently than using push_back
  for(int i=0; i < n; ++i) {
    double number = 1/distribution(generator);
    out.push_back(number);
  }
  return out;      
}

std::vector<std::vector<double>> cpprunif(int n, double min, double max) {
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(min, max);
  std::vector<double> out;
  double mean = (min + max)/2;
  double std = sqrt((pow(max-min, 2))/12);
  for(int i=0; i < n; ++i) {
    double number = (distribution(generator) - mean) / std;
    out.push_back(number); 
  }

  return out;
}

Random GaborRandomSampling(int n=1, double galpha=3, double gbeta=1, double igalpha=1, double igbeta=0.5, double iw) {
  Random sampling;
  sampling.alpha = 1;
  sampling.betax = cpprinvgamma(n, igalpha, igbeta);
  sampling.betay = cpprinvgamma(n, igalpha, igbeta);
  sampling.f = cpprunif(n, floor(iw/2), 8*iw);
  sampling.phi = cpprunif(n, 0, 2 * boost::math::constants::pi<T>());
  sampling.x0 = cpprunif(n, -2.5, 2.5);
  sampling.y0 = cpprunif(n, -2.5, 2.5);
  sampling.tau = cpprunif(n, 0, 2 * boost::math::constants::pi<T>());

  return sampling;
}
