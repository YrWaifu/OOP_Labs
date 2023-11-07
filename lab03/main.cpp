#include "include/Vector.hpp"

int main() {
    Vector *array = new Vector;
    std::cout
        << "To interact with programm, type number of the desired option:\n1) add to Array\n2) remove by "
           "index\n3) print array\n4) print geometric center and area of all figures\n5) quit\n";
    size_t option = 0;
    do {
        option = 0;

        std::cin >> option;
        if (option == 1) {
            size_t fig_type = 0;
            std::cout << "Select figure to add:\n1) Triangle\n2) Square\n3) Rectangle\n";
            std::cin >> fig_type;

            try {
                if (fig_type == 1) {
                    Triangle *tr = new Triangle;
                    std::cin >> *tr;
                    array->pushBack(tr);
                }
                if (fig_type == 2) {
                    Square *sq = new Square;
                    std::cin >> *sq;
                    array->pushBack(sq);
                }
                if (fig_type == 3) {
                    Rectangle *rt = new Rectangle;
                    std::cin >> *rt;
                    array->pushBack(rt);
                }
            } catch (std::exception &ex) {
                std::cerr << "Exception in adding new figure: " << ex.what() << std::endl;
            }
        }
        if (option == 2) {
            size_t ind = 0;
            std::cout << "Type index (start from zero): ";
            std::cin >> ind;
            try {
                array->popByIdx(ind);
            } catch (std::exception &ex) {
                std::cerr << "Exception in removing by " << ind << ": " << ex.what() << std::endl;
            }
        }
        if (option == 3) {
            for (size_t i = 0; i < array->getSize(); ++i) {
                std::cout << i + 1 << ") " << array->getVector()[i] << std::endl;
            }
        }
        if (option == 4) {
            long double sum_area = 0;
            try {
                for (size_t i = 0; i < array->getSize(); ++i) {
                    Point pt = Point((array->getVector()[i])->geomCentre());
                    std::cout << i + 1 << ") Geometrical center of figure is: "
                              << "(" << pt.coordX << ", " << pt.coordY << ')' << "; ";
                    std::cout << "Area of figure is: " << *(array->getVector()[i]) << std::endl;
                    sum_area += static_cast<double>(*(array->getVector()[i]));
                }
                std::cout << "Sum area of all figures in array is " << sum_area << std::endl;
            } catch (std::exception &ex) {
                std::cerr << "Exception in calculating: " << ex.what() << std::endl;
            }
        }
        if (option == 5) {
            break;
        }
        // std::cout << "\n1) add to Array\n2) remove by "
        //"index\n3) print array\n4) print geometric center and area of all figures\n5) quit\n";
    } while (option);
}