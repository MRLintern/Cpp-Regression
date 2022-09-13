#include"regression.hpp"

int main() {

    //create instances of regression classes
    regression linear;
    //input
    linear.input();

    if (linear.coefficients()) {

        linear.output();
        linear.correlation();

    } else {

        std::cout<<"Best fit line wasn't found.\n";
        std::cout<<"\n";
    }
    
    //create intance of the Gauss regression class
    GaussianRegression gRegression;
    //input
    gRegression.input();

    if (gRegression.coefficients()) {

        gRegression.output();
        gRegression.correlation();

    } else {

        std::cout<<"Best fit exponential curve not found.\n";
        std::cout<<"\n";
    }
    

    return 0;
}
