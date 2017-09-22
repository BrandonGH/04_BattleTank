# 04_BattleTank
An open-world head-to-head tank fight with simple AI, terrain, and advanced control system in Unreal 4.

## Concept:
* Tank game.
* You control one tank while AI controls another.
* On the enemy tank team there are AI controlled mortars firing at you.
* There is a multiplayer mode where it is you as a tank vs your friend as a tank (possibly with both sides having AI controlled mortars).
* There will be hill terrain and explosion physics.
* The movement of the tanks will be limited by what is physically possible at the time of input (cant reverse up too steep a hill, can't make barrel look too far up or down, etc).
* Shots will have projectile physics and follow a parabolic curve.
* There will be an indicator to show if a shot is possible.

## Rules:
* The tanks have a health value and being closer to where an explosive shell hits takes more health off you.
* The lose condition is running out of health.
* The win condition is to make all the enemies run out of health.

## Requirements:
* A control system for moving the different parts of the tank with different inputs and disallowing extreme motions which are not physically possible.
* A method of calculating the trajectory of shots.
* A basic AI which follows the same control scheme and limitations as us for a fair game.
* A method of working out if a shot would hit where the player is looking and giving an indication for it.
* A way of calculating health and health loss and displaying it (UI).
* A way to implement explosion physics when a projectile hits something.
* Some basic art assets (tanks, smoke, fire, explosion, projectile, etc).
* Some basic sounds (moving tank, engine, firing, explosion, etc).
