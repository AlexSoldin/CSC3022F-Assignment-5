# README for CSC3022F Assignment 5

## main.cpp
This is the main driver class of this assignment. This class creates an object of the pca.cpp class and performs Principal Component Analysis on the dataset provided

* Variables
```cpp
    SLDALE003::PCA pca;
```
* Methods
```cpp
    int main();
```

## pca.cpp
This class performs PCA on a given dataset. The dataset is loaded and stored in both vectors and a Eigen Matrix object. The covariance matrix was calculated using first principles. The eigenvalues and eigenvectors were calculated using the Eigen::EigenSolver object.

* Private Variables
```cpp
    std::vector<std::string> locations;
    std::vector<double> firstData;
    std::vector<double> secondData; 
    double firstMean;
    double secondMean;
    double firstVariance;
    double secondVariance;  
    double covariance;      
    double totalVariance;
```
* Methods
```cpp
    PCA();
    void readFile(std::string fileName);
    void calculateMeans();
    void calculateVariances();
    void calculateCovariance();
    void calculateTotalVariance();
    void generateOutput(std::string outputFileName);
```


## pca.h
This class contains all the method calls held in cpa.cpp.

## Makefile
The Makefile compiles and links all necessary files into the main executable. 

The input is of the form: ./main  

Some examples have been commented out in the Makfile. The main commands include:
* make - compiles files
* make run - runs executable according to specific instruction
* make clean - removes executables