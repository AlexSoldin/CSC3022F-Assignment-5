#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>
#include <memory>

#include "Eigen/Dense"

#ifndef PCA_H
#define PCA_H

namespace SLDALE003 {
    class PCA {
        private:
            std::vector<std::string> locations;

            std::vector<double> firstData;
            std::vector<double> secondData;
             
            double firstMean;
            double secondMean;

            double firstVariance;
            double secondVariance;  
            double covariance;      
            double totalVariance;

        public:
            PCA();

            void readFile(std::string fileName);

            void calculateEigen();
            void calculateMeans();
            void calculateVariances();
            void calculateCovariance();
            void calculateTotalVariance();
    };
}

#endif