#include "Game.h"


const float Game::PlayerSpeed = 100.f; 
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f); 


Game::Game()  // mWindow is initialized with the given VideoMode and the name of the window  
	: mWindow(sf::VideoMode(640, 480), "SFML Application")  // we crete the window 
	, mPlayer()  // game constructor takes the window and the player as the parameter
{
	if (!mTexture.loadFromFile("media/textures/doomer.jpg")) //mTexture holds the image 
	{
		// handling the loading error here 

	}
	mPlayer.setTexture(mTexture);  
	mPlayer.setPosition(50.f, 50.f); 


}

void Game::run() // main loop of the game, it handles the lifetime of the application, An iteration of the game loop is often called frame or tick 
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero; // we initialize the time as zero the first time 
	// FPS : Frames per second, measurement of how many loop iterations the game can do during a second 
	while (mWindow.isOpen())  // this returns during the game all the time, this is the game loop  
	{
		processEvents();  // we process the events here 
		timeSinceLastUpdate += clock.restart();  // we increase timeSinceLastUpdate with this statement 
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame; 
			processEvents(); 
			update(TimePerFrame); 
		}
		
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
		movement.y -= PlayerSpeed;  // interprets the one as a float number
	if (mIsMovingDown)
		movement.y += PlayerSpeed;  // interprets the one as a float number
	if (mIsMovingRight)
		movement.x += PlayerSpeed;  // interprets the one as a float number
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed ;  // interprets the one as a float number

	mPlayer.move(movement * deltatime.asSeconds()); // moves the object by a given  offset, this function adds to the current position of the object 




}

void Game::render() // renders our game to the screen 
{
	mWindow.clear();  // clears the window first
	mWindow.draw(mPlayer); // draws the player 
	mWindow.display();    // displays the mWindow with the player 



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