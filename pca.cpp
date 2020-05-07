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

Eigen::MatrixXd M(64, 2);
Eigen::MatrixXd CV(2, 2);

SLDALE003::PCA::PCA(){

}

void SLDALE003::PCA::readFile(std::string fileName){
    ifstream file(fileName.c_str()); //returns a const char * pointer to the string
    string datasetOne;
    string datasetTwo;
    string location;
    string data1;
    string data2;

    if(file){

        getline(file, datasetOne);
        getline(file, datasetTwo);

        while(!file.eof()){
            getline(file, location);
            locations.push_back(location);

            getline(file, data1);
            firstData.push_back(stod(data1));

            getline(file, data2);
            secondData.push_back(stod(data2));
        }

        for (int i=0; i < firstData.size(); i++){
            M(i, 0) = firstData[i];
            M(i, 1) = secondData[i];
        }

        /* Check Data */
        // cout << datasetOne << endl;
        // cout << datasetTwo << endl;

        // for (int i = 0; i < firstData.size(); i++){
        //     cout << locations[i] << endl;
        //     cout << firstData[i] << endl;
        //     cout << secondData[i] << endl;
        // }

        // cout << M << endl;

    }
}

void SLDALE003::PCA::calculateEigen(){
    Eigen::EigenSolver<Eigen::MatrixXd> es(CV);
    cout << "------------------------\nEigenvalues\n------------------------" << endl;
    cout << es.eigenvalues() << "\n\n";
    cout << "------------------------\nEigenvectors\n------------------------" << endl;
    cout <<  es.eigenvectors() << "\n\n";
}

void SLDALE003::PCA::calculateMeans(){
    double total1 = 0;
    double total2 = 0;
    for(int i=0; i < firstData.size(); i++){
        total1 += firstData[i];
        total2 += secondData[i];
    }

    firstMean = total1/firstData.size();
    secondMean = total2/secondData.size();

    cout << "------------------------\nMeans\n------------------------" << endl;
    cout << "Number of Elements: " << firstData.size() << endl;
    cout << firstMean << endl;
    cout << "Number of Elements: " << secondData.size() << endl;
    cout << secondMean << "\n\n";
    
}

void SLDALE003::PCA::calculateVariances(){
    double total1 = 0;
    double total2 = 0;

    for(int i=0; i < firstData.size(); i++){
        total1 += pow(firstData[i] - firstMean, 2);
        total2 += pow(secondData[i] - secondMean, 2);
    }

    firstVariance = total1/(firstData.size()-1);
    secondVariance = total2/(secondData.size()-1);

    cout << "------------------------\nVariances\n------------------------" << endl;
    cout << firstVariance << endl;
    cout << secondVariance << "\n\n";

}

void SLDALE003::PCA::calculateCovariance(){
    double total = 0;
    
    for(int i=0; i < firstData.size(); i++){
        total += (firstData[i] - firstMean)*(secondData[i] - secondMean);
    }

    covariance = total/(firstData.size()-1);

    CV(0,0) = firstVariance;
    CV(1,0) = covariance;
    CV(0,1) = covariance;
    CV(1,1) = secondVariance;

    cout << "------------------------\nCovariance Matrix\n------------------------" << endl;
    cout << CV << "\n\n";
}

void SLDALE003::PCA::calculateTotalVariance(){
    // Variance (A + B) = Variance A + Variance B + 2*Covariance(A,B)
    totalVariance = firstVariance + secondVariance + 2*(covariance);

    cout << "------------------------\nTotal Variance\n------------------------" << endl;
    cout << totalVariance << "\n\n";
}