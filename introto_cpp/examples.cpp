#include <iostream> //preprocessor directive , that includes the cin cout cerr and more streams utilities
#include <string>
#include <vector>
#include <cassert>




// int main()
// {
//     std:: cout << "Enter two numbers:" << "\n"; // std::cout uses the scope operator
//     int v1, v2;
//     cin >> v1 >> v2;
//     cout << "The sum of " << v1 << " and " << v2
//          << " is " << v1 + v2 << endl; // endl is a manipulator
//     return 0;
// }


using namespace std; // the position of this statments in code block matters cus it only affects code followed to it 

// int main()
// {

//     std::cout << "Enter two numbers:" << std::endl;
//     int c1, c2;
//     std::cin >> c1 >> c2;   
//      std::cout << "The sum of " << c1
// << " and " << c2
// << " is " << c1 + c2
// << std::endl;
//     std::cout << "res " << "is " << c1 * c2 << endl;
//     // flush();
//     return 0;
// }


// in this example we read untile EOF or err soo in ctrl+d or not valid int it will end reading  "std::cin >> value"

// int main()
// {
// int sum = 0, value;
// // read  , calculating a running total of all values read
// while (std::cin >> value)
//     sum += value; // equivalent to sum = sum + value
// if (sum == 0)
// {
//     std::cerr << "no input taken" << endl;
//     return -1;
// }
// std::cout << "value = " << value << endl;
// std::cout << "Sum is: " << sum << std::endl;
// return 0;
// }



// example of refernce :

int main()
{
    int x = 10;
    int y = -1;
    int &x1 = x; //  this is a valid initialization of a nonconst reference of object type int

    ++x;

    x1 = y; // here even after given it another obj its still binded to the first one
    
    std::cout << x1 << std::endl; // here the value of the referenc is incremented also
    ++x1;
    std::cout << x << std::endl; // here the value of the int x is incremented also
    return 0;
}

// we conclude a reference is just an alias of a variable 