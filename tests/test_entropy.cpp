//
// Created by AD on 7/27/2026.
//

#include<iostream>
#include<cassert>
#include<cmath>
#include "url_features/Entropy.hpp"

int main() {
    std::string text;
    std::cin >> text;
    std::cout << Entropy::Shannon_entropy(text) << "\n";
    std::cout << Entropy::Shannon_entropy("") << "\n";
}
