#pragma once
#include <string>
//DEBUG!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>

class Scene
{
private:
    std::string m_Desc;
    std::string m_Opt[3];
    std::string m_FileOpt[3];
    std::string m_Item;
    std::string m_Enemy;

private:
    const std::string m_Path;

public:
    void ChooseOpt(int opt);
    void LoadScene(std::string file);
    std::string GetItem() const;
    std::string GetOpt(int opt) const;
    std::string GetDesc() const;
    std::string GetEnemy() const;

    void Update(int opt);

    //DEBUG!!!!!!!!!!!!!!!!!!!!!!!
    void DebugOption() const;

    Scene();
    ~Scene();
};

