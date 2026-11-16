// PROJECTLAB2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif


void HeadLine()
{
    std::cout << "Виконавець: Стахів Єгор, група ІТК-12\n";
    std::cout << "Програма для розрахування математичного прикладу\n";
}


double MathConst(double x, double eps, bool& is_valid) {
    if (x < -0.2 || x > 0.2 || eps <= 0.0) {
        is_valid = false;
        return 0.0;
    }

    is_valid = true;
    double sum = 0.0;
    double term = 1.0;
    int n = 0;

    while (std::abs(term) >= eps && n < 1000) {
        sum += term;
        n++;
        double dn = static_cast<double>(n);
        double factor = (2.0 * dn * (2.0 * dn - 1.0)) / (dn * dn);
        term *= factor * factor * x * x;
    }

    return sum;
}


bool ReadDouble(const std::string& prompt, double& value) {
    std::cout << prompt;
    if (!(std::cin >> value)) {
        std::cout << "wrong input\n";
        return false;
    }

    
    while (std::cin.peek() == ' ' || std::cin.peek() == '\t') {
        std::cin.get();
    }

  
    if (std::cin.peek() != '\n' && std::cin.peek() != EOF) {
        std::cout << "wrong input\n";
        return false;
    }

    return true;
}

int main() {
    
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    std::setlocale(LC_ALL, "Russian");

    HeadLine();

    double x = 0.0;
    double eps = 0.0;
    bool is_valid_domain = false;
    if (ReadDouble("Введіть значення х діапазоном [-0.2 ; 0.2]: ", x) &&
        ReadDouble("Введіть точність eps (eps > 0): ", eps))
    {
        std::cout << "***** do calculations ... done\n";
        std::cout << "for x = " << std::fixed << std::setprecision(5) << x << "\n";
        std::cout << "for eps = " << std::scientific << std::setprecision(4) << eps << "\n";

        double result = MathConst(x, eps, is_valid_domain);
    }







    double result = MathConst(x, eps, is_valid_domain);





    if (!is_valid_domain) {
        std::cout << "result = undefined\n";
    }
    else {
        std::cout << "result = " << std::fixed << std::setprecision(10) << result << "\n";
    }




    std::cout << "The work is done.\n";
    return 0;
}

