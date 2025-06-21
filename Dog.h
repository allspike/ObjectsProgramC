#include <string>
#include "Bone.h"
// Dog header file
using namespace std;
class Dog {
    // declare our private variables
    private:
        int numberOfLegs;
        string eyeColor;
        string furColor;
        float weight;
        bool isHappy;
        string name;
        Bone *bptr;
    // all of our methods will be public
    public:
        void run(int howFar, int howFast);
        void bark(int numTimes);
        void wag(int numTimes, int howFast);
        void setWeight(float weight);
        void setNumberOfLegs(int numLegs);
        void setHappiness(bool isHappy);
        void addBone();
        void setEyeColor(string eColor);
        void setName(string newName);
        void setFurColor(string fColor);
        void dogSummary();
        Dog(string name);
        ~Dog();
};
