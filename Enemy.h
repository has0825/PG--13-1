#pragma once

class Enemy {
public:
    float x, y;
    float speedX;
    bool isAlive; //敵のフラグ
    static bool allEnemiesDefeated; // 全ての敵が倒れたか

    Enemy(float startX, float startY, float initialSpeedX);

    void Update();
    void Draw();
    bool CheckCollision(float bulletX, float bulletY);
};
