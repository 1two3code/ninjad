#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

class Animation
{
private:
	std::string fileName;
	char* src;
	sf::Image* img;
	int frameDelay;
	float timeScale;
	int frames;
	int curFrame;
	int sX, sY;
	sf::Sprite* sprite;

public:
	Animation(std::string);
	Animation(int, int, int, int, std::string);
	~Animation();
	void setTimeScale(float);
	void Update(int);
	void setCurFrame(int);
	void WriteToFile(std::string);
	sf::Sprite* getSprite();
};