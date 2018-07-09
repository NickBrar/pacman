#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void move(char dir, int &pacmanIndex, int &xPos, int &yPos, Sprite blank); 

vector<Sprite>Map;

int main(){
    RenderWindow window(VideoMode(600, 600), "Nick's Game");
    window.setKeyRepeatEnabled(false);
 
	// Variables:
	int pacmanIndex = 42;
	int xPos = 65;
	int yPos = 65;
 
    // Sprites: 
	Sprite border, food, pacman, blank;
    Texture borderTex, foodTex, pacmanTex, blankTex;

    if (!borderTex.loadFromFile("border.jpg"))
        cout << "border.png failed";

	if (!foodTex.loadFromFile("food.png"))
		cout << "food.png failed";

	if (!pacmanTex.loadFromFile("pacman.png"))
		cout << "pacman.png failed";

	if (!blankTex.loadFromFile("blank.jpg"))
		cout << "blank.jpg failed";

    border.setTexture(borderTex),border.setScale(Vector2f(0.043, 0.043));
 
    food.setTexture(foodTex), food.setScale(Vector2f(0.0065, 0.0065));
    
    pacman.setTexture(pacmanTex), pacman.setScale(Vector2f(0.01, 0.01));

    blank.setTexture(blankTex), blank.setScale(Vector2f(0.00000001, 0.000000000000025));

    // Load Sprites to Vector: 
    for (int i = 0; i < 20; i++){
        border.setPosition(i * 30, 0);
        Map.push_back(border);
    }

    border.setPosition(0, 30), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 40);
        Map.push_back(food);
    }

    border.setPosition(570, 30), Map.push_back(border);
    border.setPosition(0, 60), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 70);
        Map.push_back(food);
    }

    border.setPosition(570, 60), Map.push_back(border);
    border.setPosition(0, 90), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 100);
        Map.push_back(food);
    }

    border.setPosition(570, 90), Map.push_back(border);
    border.setPosition(0, 120), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 130);
        Map.push_back(food);
    }

    border.setPosition(570, 120), Map.push_back(border);
    border.setPosition(0, 150), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 160);
        Map.push_back(food);
    }

    border.setPosition(570, 150), Map.push_back(border);
    border.setPosition(0, 180), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 190);
        Map.push_back(food);
    }

    border.setPosition(570, 180), Map.push_back(border);
    border.setPosition(0, 210), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 220);
        Map.push_back(food);
    }

    border.setPosition(570, 210), Map.push_back(border);
    border.setPosition(0, 240), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 250);
        Map.push_back(food);
    }

    border.setPosition(570, 240), Map.push_back(border);
    border.setPosition(0, 270), Map.push_back(border);

    for (int i = 0; i < 18; i++){
        food.setPosition(40 + (i * 30), 280);
        Map.push_back(food);
    }

    border.setPosition(570, 270), Map.push_back(border);

    for (int i = 0; i < 20; i++){
        border.setPosition(i * 30, 300);
        Map.push_back(border);
    }
    
    while (window.isOpen()){
        
        Event event;

        Map[pacmanIndex] = pacman;
        pacman.setPosition(xPos, yPos);
         

        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
            else if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::W){
                    move('W', pacmanIndex, xPos, yPos, blank);
                }
                else if (event.key.code == Keyboard::A){
                    move('A', pacmanIndex, xPos, yPos, blank);
                }
                else if (event.key.code == Keyboard::S){
                    move('S', pacmanIndex, xPos, yPos, blank);
                }
                else if (event.key.code == Keyboard::D){
                    move('D', pacmanIndex, xPos, yPos, blank);
                }
            }
        }


        window.clear(Color::Black);
    
        for (int i = 0; i < Map.size(); i++){
            window.draw(Map[i]);
        }
 
        window.display();
    }

    return 0;
}

void move(char dir, int &pacmanIndex, int &xPos, int &yPos, Sprite blank){
    if (dir == 'W'){
        if (pacmanIndex - 20 > 19){
			yPos -= 30;
            pacmanIndex -= 20;
            Map[pacmanIndex + 20] = blank;
        }
    }
    else if (dir == 'A'){
        if ((pacmanIndex - 1) % 20 != 0){
			xPos -= 30;
            pacmanIndex--;
            Map[pacmanIndex + 1] = blank;
        }
    }
    else if (dir == 'S'){
        if (pacmanIndex + 20 < 200){
			yPos += 30;
            pacmanIndex += 20;
            Map[pacmanIndex - 20] = blank;
        }
    }
    else if (dir == 'D'){
        if (pacmanIndex + 1 != 39 && pacmanIndex + 1 != 59 && pacmanIndex + 1 != 79 && pacmanIndex + 1 != 99 && pacmanIndex + 1 
            != 119 && pacmanIndex + 1 != 139 && pacmanIndex + 1 != 159 && pacmanIndex + 1 != 179 && pacmanIndex + 1 != 199){
			xPos += 30;
			pacmanIndex++;
            Map[pacmanIndex - 1] = blank;
        }
    }
    
}
 
