#ifndef GAME_H
#define GAME_H


#include "SFML/Graphics.hpp"


// game engine's class 
class Game
{
private:



public:
	Game();  // constructor of the game 
	void run(); // function to run the game 


private:
	void processEvents(); // processing events that happen during the game
	void update(sf::Time deltaTime); // updating the game 
	void render(); // rendering the game 
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed); 

private:
	sf::RenderWindow mWindow; 
	sf::CircleShape MPlayer; // our player has a circle shape to start with 
	
	
	bool mIsMovingUp = false;
	bool mIsMovingDown = false; 
	bool mIsMovingLeft = false; 
	bool mIsMovingRight = false; 


	static const float PlayerSpeed;  // this must be float since movement.y and movement.x are float variables 
	static const sf::Time TimePerFrame; 
};



#endif // !GAME_H
