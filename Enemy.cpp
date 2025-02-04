#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(float startX, float startY, float initialSpeedX)
    : x(startX), y(startY), speedX(initialSpeedX), isAlive(true) {
}

void Enemy::Update() {
    if (isAlive) {
        x += speedX;
        if (x <= 0.0f || x >= 1248.0f) {
            speedX = -speedX;
        }
    }
}

void Enemy::Draw() {
    if (isAlive) {
        Novice::DrawEllipse(static_cast<int>(x), static_cast<int>(y), 16, 16, 0.0f, 0xFF0000FF, kFillModeSolid);
    }
}

bool Enemy::CheckCollision(float bulletX, float bulletY) {
    if (isAlive &&
        bulletX > x - 16 && bulletX < x + 16 &&
        bulletY > y - 16 && bulletY < y + 16) {
        isAlive = false;
        return true;
    }
    return false;
}