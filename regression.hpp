#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<numeric>
#include<string>
#include<cassert>
#include<cmath>

#ifndef regression_H
#define regression_H

//vector array
typedef std::vector<double> array;

//create regression class
class regression {

    protected:
        //pair of variates
        array x, y;
        //amount of pa of variates
        int n{0};
        //coefficients a & b
        double a{0}, b{0};
        //variables for calculating the square of the deviations
        double sx2{0}, sy2{0}, sxy{0};

    public:
        //initialise the protected variables
        regression() {n = 0; a = b = sx2 = sy2 = sxy = 0;};
        //virtual functions
        virtual void input(), output();
        //function to check whether a regression line exists or not
        bool coefficients();
        //correlation coefficients according to Parsen's formula
        void correlation();
};
///////////////////LINEAR REGRESSION////////////////
//function to input data
void regression::input() {

    //open data file for linear regression
    std::ifstream myFile("linear.txt", std::ios::in);

    if (myFile.fail()) {

        std::cout<<"File could not be opened\n";
        exit(1);

    } else {

        //x & y values
        double x1{0}, y1{0};

        while (myFile >> x1 >> y1) {

            //values of x1 and y1 placed in vector called array
            x.push_back(x1);
            y.push_back(y1);
        }
        //amount of pair of variates
        n = x.size();

        std::cout<<n<<" pair of variates were read in successfully\n";
    }
    //success; close file
    myFile.close();
}
//is there a best fit line available?
//false if not, true if there is
bool regression::coefficients() {

    double sx, sy, mean_x, mean_y = 0.0;
    //sum of x & y values
    sx = std::accumulate(x.begin(), x.end(), sx);
    sy = std::accumulate(y.begin(), y.end(), sy);
    //mean of x & y values
    mean_x = sx/n;
    mean_y = sy/n;
    //sum of x & y squared values; using inner_product() function
    sx2 = std::inner_product(x.begin(), x.end(), x.begin(), sx2);
    sy2 = std::inner_product(y.begin(), y.end(), y.begin(), sy2);
    //sum of x*y values
    sxy = std::inner_product(x.begin(), x.end(), y.begin(), sxy);

    //need to calculate the coefficients a & b for the 
    //linear regression formula: y = bx + a
    double denominator = n*sxy - sx*sx;

    if (denominator != 0) {

        //coefficient a and b
        b = (n*sxy - sx*sy)/denominator;
        //a = sx2*sy - sx*sxy/denominator
        a = mean_y - b*mean_x;

        return true;
        
    } else {

        return false;
    }
    
}
void regression::correlation() {
    //calculate Pearson's correlation coefficient
    double correlation_coefficient = sxy/sqrt(sx2*sy2);
    //output
    std::cout<<"Correlation Coefficient: r = "<<correlation_coefficient<<"\n";
}
//function to output data
void regression::output() {

    std::cout<<"Linear Regression Formula: y = a + bx "<<std::endl   
            <<"a = "<<a<<std::endl<<"b = "<<b<<std::endl<<std::endl;
    std::cout<<std::fixed<<std::setw(6)<<"x"<<std::setw(10)<<"y"<<std::setw(10)<<"y_calc"<<std::endl;

    for (int i{0}; i < x.size(); i++) {

        std::cout<<std::setw(6)<<std::setprecision(2)<<x[i]
                 <<std::setw(10)<<std::setprecision(2)<<y[i]
                 <<std::setw(12)<<std::setprecision(6)<<(a + b*x[i])<<std::endl;
    }
}

/////////GAUSSIAN REGRESSION//////////////////////
class GaussianRegression : public regression {

    public:
        GaussianRegression() : regression() {};
        void input(), output();
};
//function to input data
void GaussianRegression::input() {

    //open data file for Gaussian regression
    std::ifstream myFile("exponential.txt", std::ios::in);

    if (myFile.fail()) {

        std::cout<<"File could not be opened\n";
        exit(1);

    } else {

        //x & y values
        double x1{0}, y1{0};

        while (myFile >> x1 >> y1) {

            //ensure y1 is greater than 0
            assert(y1 > 0);
            //y = a*exp(bx)
            //linearise above to give:
            //ln(y) = ln(a) + bx
            y1 = log(y1);
            //values of x1 and y1 placed in vector called array
            x.push_back(x1);
            y.push_back(y1);
        }
        //amount of pair of variates
        n = x.size();

        std::cout<<n<<" pair of variates were read in successfully\n";
    }
    //success; close file
    myFile.close();
}

//function to output data
void GaussianRegression::output() {

    std::cout<<"Gaussian Regression Formula: y = a*exp(bx) "<<std::endl<<
            "Linear form of the Gaussian/Exponential Regression Equation: ln(y) = ln(a) + bx"<<std::endl 
            <<"ln(a) = "<<a<<std::endl<<"b = "<<b<<std::endl<<std::endl;
    std::cout<<std::fixed<<std::setw(6)<<"x"<<std::setw(10)<<"y"<<std::setw(10)<<"y_calc"<<std::endl;

    for (int i{0}; i < x.size(); i++) {

        std::cout<<std::setw(6)<<std::setprecision(2)<<x[i]
                 <<std::setw(10)<<std::setprecision(2)<<exp(y[i])
                 <<std::setw(12)<<std::setprecision(6)<<exp(a + b*x[i])<<std::endl;
    }
}


#endif

