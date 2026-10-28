#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include "Course_Lib/myHist.h"
#include "HW/items.h"

struct Homework
{
    std::string name;
    std::function<void()> func;
};

int main()
{
    std::vector<Homework> menu =
        {
            {"Image Flip", ImageFlip},
            {"Box Filter", BoxFilter},
            {"Median Filter", MedianFilter},
            {"Histogram Equalization", HistogramEqualization},
            {"Histogram Matching", HistogramMatching},
            {"Uniform Noise", UniformNoise},
            {"Salt Pepper Noise", SaltPepperNoise},
            {"Gaussian Noise", GaussianNoise},
            {"Laplacian Enhancement", LaplacianEnhancement},
            {"Connected Component Labeling", ConnectedComponentLabeling}};

    std::cout << "========== DIP Homework ==========\n";

    while (true)
    {
        size_t choice;

        std::cout << "\n0. Exit\n";

        for (size_t i = 0; i < menu.size(); ++i)
        {
            std::cout << i + 1 << ". "
                      << menu[i].name << '\n';
        }

        std::cout << "\nSelect: ";
        std::cin >> choice;

        if (choice == 0)
            break;

        if (choice > menu.size())
            continue;

        menu[choice - 1].func();
    }

    return 0;
}