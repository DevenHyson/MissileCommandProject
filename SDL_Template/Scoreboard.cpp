#include "Scoreboard.h"

Scoreboard::Scoreboard()
	: Scoreboard({ 230, 230, 230 }) {
}

Scoreboard::Scoreboard(SDL_Color color) {
	mColor = color;
	Score(0);
}

Scoreboard::~Scoreboard() {
	ClearBoard();
}

void Scoreboard::Score(int score) {
	ClearBoard();

	std::string str = std::to_string(score);
	unsigned lastIndex = (unsigned)str.length() - 1;

}

void Scoreboard::Render() {
	for (auto digit : mScore) {
		digit->Render();
	}
}

void Scoreboard::ClearBoard() {
	for (auto s : mScore) {
		delete s;
	}

	mScore.clear();
}

