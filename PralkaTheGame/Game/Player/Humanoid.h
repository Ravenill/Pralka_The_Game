#pragma once

class Humanoid
{
protected:
    int m_HP;
    int m_AP;
    int m_DP;

public:
    Humanoid();
    ~Humanoid();

    virtual void Update();
};