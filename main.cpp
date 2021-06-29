#include <iostream>
#include "Miller.h"
using namespace std;

int main()
{
    // use cols > rows!
    MurtyMiller<double>::WeightMatrix c_ij(3, 5);
    c_ij = MurtyMiller<double>::WeightMatrix::Random(3, 5);

    for ( size_t r = 0; r < c_ij.rows(); ++r )
        for ( size_t c = 0; c < c_ij.cols(); ++c )
            if ( c_ij(r, c) < 0 ) c_ij(r, c) = -c_ij(r, c);

    c_ij /= c_ij.maxCoeff();

    std::cerr << "c_ij = \n" << c_ij << std::endl;

    std::vector<MurtyMiller<double>::Edges> solutions = MurtyMiller<double>::getMBestAssignments(c_ij, 100);

    std::cerr << solutions.size() << " results:" << std::endl;
    for ( const auto & s : solutions )
    {
        for ( const auto & e : s )
            std::cerr << "(" << e.x << ", " << e.y << ") ";
        std::cerr << "sum = " << MurtyMiller<double>::objectiveFunctionValue(s) << std::endl;
    }

    return 0;
}

