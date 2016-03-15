#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>




#define N 20 // Number of 

//Fill a vector with random numbers in the range [lower, upper]
void randomFill( std::vector<int> &V, const int lower, const int upper, const unsigned int seed) {

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V){
        elem = distr(eng);
    }
}

int main( int argc, char * argv[] )
{
    auto arrSz( 0ul );

    if ( argc > 1 )
    {
        std::stringstream( argv[1] ) >> arrSz;
    }
    else
    {
        arrSz = N;
    }

    std::cout << ">>> Required array size is: " << arrSz << std::endl;

    // Store the data.
    std::vector< int > V( arrSz );

    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill( V, -100, 100, r() );
        
    //Printint out the array, just to make sure we've got random integers.
    std::cout << ">>> Vet = [ ";
    for( const auto &e : V )
        std::cout << e << " ";
    std::cout << "]\n";



    std::cout << ">>> STARTING computation that needs timing <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================
    
    // WW SHOULD PUT HERE THE CODE WE WANT TO TIME.   

    //================================================================================
    auto end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    //Store the time difference between start and end
    auto diff = end - start;

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;

    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;
        

    return EXIT_SUCCESS;

}



