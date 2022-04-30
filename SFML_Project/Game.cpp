#include "Game.h"


Game::Game()  // mWindow is initialized with the given VideoMode and the name of the window  
	: mWindow(sf::VideoMode(640, 480), "SFML Application") 
	, MPlayer()  // game constructor takes the window and the player as the parameter
{
	MPlayer.setRadius(20.f); 
	MPlayer.setPosition(320.f, 240);
	MPlayer.setFillColor(sf::Color::Cyan); 


}

void Game::run() // main loop of the game, it handles the lifetime of the application, An iteration of the game loop is often called frame or tick 
{
	sf::Clock clock;
	// FPS : Frames per second, measurement of how many loop iterations the game can do during a second 
	while (mWindow.isOpen())  // this returns during the game all the time 
	{
		sf::Time deltatime = clock.restart(); 
		processEvents(); // deal with the player inputs, if we press close button on the 
		update(); // update the game, based on the events that happened and we use the game logic here to render the new position of the game  
		render(); // render the game 
	}
		// when the run doesn't work, we basically jump to this part of code 
}

void Game::processEvents() // this responsbile for processing the events happened during the game 
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltatime)  // updates the game logic of the game 
{
	sf::Vector2f movement(0.f, 0.f); // Vector2f type movement has x and y components, 
	if (mIsMovingUp)
		movement.y -= 1.f;  // interprets the one as a float number
	if (mIsMovingDown)
		movement.y += 1.f;  // interprets the one as a float number
	if (mIsMovingRight)
		movement.x += 1.f;  // interprets the one as a float number
	if (mIsMovingLeft)
		movement.x -= 1.f;  // interprets the one as a float number

	MPlayer.move(movement * deltatime.asSeconds()); // moves the object by a given  offset, this function adds to the current position of the object 




}

void Game::render() // renders our game to the screen 
{
	mWindow.clear();  // clears the window firs t
	mWindow.draw(MPlayer); // draws the player 
	mWindow.display();    // displays the player 



}



void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}