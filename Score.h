#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
class ScoreManager {
public:
    void saveScore(int score) {
        std::ofstream file("score.txt");
        if (file.is_open()) {
            file << score;
            file.close();
            std::cout << "Score saved successfully!" << std::endl;
        }
        else {
            std::cout << "Unable to open the file." << std::endl;
        }
    }
};