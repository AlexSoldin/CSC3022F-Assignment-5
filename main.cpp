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
    string inputFileName = "Data.txt";
    pca.readFile(inputFileName);

    /* Compute Covariance Matrix */
    pca.calculateMeans();
    pca.calculateVariances();
    pca.calculateCovariance();

    /* Total Variance */
    pca.calculateTotalVariance();

    /* Eigenvalues for Principal Components 1 and 2 */
    /* Eigenvectors for Principal Components 1 and 2 */ 
    /* Percentage Proportion of Total Variance do Principal Components 1 and 2 Explain */
    /* Generate Output */
    string outputFileName = "Output.txt";
    pca.generateOutput(outputFileName);

    return 0;
}