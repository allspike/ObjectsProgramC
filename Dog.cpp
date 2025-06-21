#include "Dog.h"
#include <unistd.h>
#include <iostream>
// Dog Class Constructor
// The constructor name
Dog::Dog(string name): name(name) {
    // set a default of 4 for the number of legs
    numberOfLegs = 4;
    // set isHappy to true by default
    isHappy = true;
    furColor = "brown";
    eyeColor = "blue";
    // set our bone pointer to NULL by default
    bptr = NULL;
    // outputs our desired constructor message
    cout << name << " is alive!" << endl;
}
// destructor method
Dog::~Dog() {
    cout << name << " is no longer with us" << endl;
}
// run method
// takes an int of howFar and howFast
void Dog::run(int howFar, int howFast) {
    // if howFar is out of range, then exit the method without doing anything
    if (howFar < 0 || howFar > 1000) {
        return;
    }
    // if howFast is out of range, then set howFast to 0
    if (howFast < 0 || howFast > 1000) {
        howFast = 0;
    }
    // if the number of legs is out of range, then exit the method without doing anything
    if (numberOfLegs < 3 || numberOfLegs > 4) {
        return;
    }
    // if numberOfLegs is 3 then we change howFast by increasing the delay by 25%
    if (numberOfLegs == 3) {
        howFast += 0.25 * howFast;
    }
    // output message
    cout << name << " is running to catch squirrels on " << numberOfLegs << " legs | run: " << howFar << ", sleep: " << howFast << "ms\n";
    // for loop that prints out a '#' with a delay dependent on howFast
    for (int i = 0; i < howFar; i++) {
        // flush our output so we ensure each character gets printed
        cout.flush();
        cout << '#';
        // usleep function puts a delay that is in microseconds
        usleep(1000 * howFast);
    }
    cout << endl;
    // output message
    cout << name << " is tired now. My tail is dragging." << endl;
}
// bark method
void Dog::bark(int numTimes) {
    cout << "I'm " << name << " and I'm here to say:\n";
    // if weight is less than 100 the dog will yap, otherwise the dog will woof!
    if (weight < 100) {
        for (int i = 0; i < numTimes; i++) {
            cout << "yap!!!\n";
        }
    } else {
        for (int i = 0; i < numTimes; i++) {
            cout << "WOOF!!!\n";
        }
    }
}
// wag method
void Dog::wag(int numTimes, int howFast) {
    // if numTimes is out of range, exit the method without doing anything
    if (numTimes > 1000 || numTimes < 0) {
        return;
    }
    // if howFast is out of range, set it equal to 0
    if (howFast < 0 || howFast > 1000) {
        howFast = 0;
    }
    // check if the dog is happy, if it's happy, we continue the function, otherwise we exit
    if (isHappy) {

        cout << "I'm " << name << ", and I'm happy. I'm wagging my tail! | wags: " << numTimes << ", sleep: " << howFast << "ms" << endl;
        // for loop to iterate over the numTimes they are wagging
        for (int i = 0; i < numTimes; i++) {
            // flush the output to ensure each character is printed
            cout.flush();
            // alternates between left and right wags
            if (i % 2 == 0) {
                // need to print out the exit character \ to ensure that \ is printed correctly
                cout << "\\ ";
                // usleep functions as it does in the run() method
                usleep(howFast * 1000);
            } else {
                cout << "/ ";
                usleep(howFast * 1000);
            }

        }
        cout << endl;
        // after wagging, we set isHappy to false
        isHappy = false;
        // if the bone instance exists, delete the instance
        if (bptr) {
            delete  bptr;
        }
        cout << "I'm " << name << ", and I'm done being happy." << endl;
        cout << "all done." << endl;
    } else {
        return;
    }
}
// set weight method
void Dog::setWeight(float w) {
    // if weight is out of range, throw an error
    if (w <= 0 || w > 200) {
        cout << "Weight must be between 1 and 200. Weight is unchanged.\n";
    } else {
        weight = w;
    }
}
// setNumberOfLegs method
void Dog::setNumberOfLegs(int numLegs) {
    // if numLegs is out of range, numberOfLegs defaults to 4
    if (numLegs <= 0 || numLegs > 4) {
        numberOfLegs = 4;
    } else {
        numberOfLegs = numLegs;
    }
}
// setHappiness method
void Dog::setHappiness(bool isH) {
    isHappy = isH;
}
// addBone method
void Dog::addBone() {
    // sets isHappy to true
    isHappy = true;
    // creates a new instance of the Bone class
    bptr = new Bone;
}
// method to change the eye color of the dog
void Dog::setEyeColor(string eColor) {
    eyeColor = eColor;
}
// method to set the dog name
void Dog::setName(string newName) {
    name = newName;
}
// method to set a fur color
void Dog::setFurColor(string fColor) {
    furColor = fColor;
}
// method to print out the summary of the dog's attributes
void Dog::dogSummary() {
    cout << "Hello! My name is " << name << ". Nice to meet you!\n";
    cout << "I have " << numberOfLegs << " legs. And I weigh " << weight << " pounds. Look at me run!\n";
    cout << "My fur is " << furColor << ". Doesn't it look nice?\n";
    cout << "My eyes are the color " << eyeColor << ". They're always focused on finding bones!\n";
    if (isHappy) {
        cout << "I'm so happy right now, I could just run around in circles!\n";
    } else {
        cout << "I'm not very happy and need a nap.\n";
    }
}
