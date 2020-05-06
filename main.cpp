#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>
#include <stdexcept>
#include <stdio.h>
#include <cmath>
#include <iterator>

#include "pca.h"

using namespace std;

int main(){
    SLDALE003::PCA pca;

    /* Read Input Data */
    std::string inputFileName = "Data.txt";
    pca.readFile(inputFileName);

    /* Eigenvalues for Principal Components 1 and 2 */


    /* Eigenvectors for Principal Components 1 and 2 */



    /* Compute Covariance Matrix */
    pca.calculateMeans();
    pca.calculateVariances();
    pca.calculateCovariance();

    /* Total Variance */
    pca.calculateTotalVariance();

    /* Percentage Proportion of Total Variance do Principal Components 1 and 2 Explain */


    /* Generate Output */


    return 0;
}