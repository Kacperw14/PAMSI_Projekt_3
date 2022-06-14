#pragma once

class AI 
{
private:
    int currentScore;
    char AIplayer;
    int Xindex, Yindex;
public:
    AI() = default;
    AI(int _score) : currentScore(_score) {}
};