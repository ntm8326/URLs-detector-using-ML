#include "Entropy.hpp"

float Shannon_entropy(std::string text) {
    int n = text.length();
    int freq[256] = {0};
    for (char i : text) {
        ++freq[i];
    }
    float c = 0;
    float entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            int a = freq[i];
            c += a*log2(a);
        }
    }
    entropy = log2(n) - c/n;
    return entropy;
}