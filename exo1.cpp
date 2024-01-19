#include <iostream>

using namespace std;
class Alien {
private:
    int x_coordinate;
    int y_coordinate;
    int health;
public:
    Alien(int xVal, int yVal) {
        x_coordinate = xVal;
        y_coordinate = yVal;
        health = 3;
    }

    int get_health() { return health; }

    void displayStat() {
        cout << "x : " << x_coordinate << endl;
        cout << "y : " << y_coordinate << endl;
        cout << "Health : " << health << endl;

    }

    int hit() {
        health -= 1;

        cout << "****ATTAAAAQUE****" << endl;
        if (health < 0) {
            health = 0;
        }
        return health;
    }

    bool is_alive() {
        if (health <= 0) {
            cout << "****MOOOOOOOOOOORT****" << endl;
            return false;
        } else
            cout << "En vie" << endl;
            return true;
    }

bool teleport(int x_new,int y_new){
        x_coordinate=x_new;
        y_coordinate=y_new;
        cout << "teleportation en cours..." << endl;
        cout << "nouvelles coordonnees (" << x_new << ";" << y_new << ")" << endl;
        return true;
    }

bool collision(Alien& autreAlien) {
    if (autreAlien.x_coordinate == x_coordinate && autreAlien.y_coordinate == y_coordinate) {
        cout << "****Collision****" << endl;
        return true;
    }
    else
    cout << "pas de collision" << endl;
    return false;
};
};



int main(){
    Alien jiren{2, 3};
    Alien freezer{5,7};
    jiren.collision(freezer);
    jiren.displayStat();
    jiren.hit();
    jiren.is_alive();
    jiren.displayStat();
    jiren.hit();
    jiren.hit();
    jiren.is_alive();
    jiren.displayStat();
    jiren.teleport(5,7);
    jiren.displayStat();
    jiren.collision(freezer);


}
