# Gradius #

## Goal ##

The Goal is to reach the end without losing all your lives, collision with enemies or obstacles will result in a loss of lives.

## Controls ##

### In-Game Controls ###

Key        | Action
-----------|-------
**W**      | Move Up
**A**      | Move Left
**S**      | Move Down
**D**      | Move Right
**[SPACE]**| Shoot

### In-menu Controls ###

Key             | Action
----------------|-------
**[ARROW UP]**  | Move Up
**[ARROW DOWN]**| Move Down
**[ENTER]**     | Select

## Loading in Levels ##

:heavy_exclamation_mark: Before loading in a level, make sure the level is present as levels/*levelname*.json

## How To Use Resources ##

Resources are a template for specific instances and are highly customisable.

General Attributes | Notes
-------------------|-------
 **Type**          | type of the instance 
 **Texture Path**  | where to find the texture (relative to root of the game)
 **Speed**         | the speed at which the instance moves
 Depth             | depth at which the instance gets drawn (lower depth first)
 nrFrames          | if the image is an animation, how many frames (caution, make sure each frame has the same size and there are no gaps between the frames)
 Delay             | if the image is an animation, the delay between two frames
 
 **Bolded** items are necessary attributes, otherwise an error will occur.
 
 _The following attributes are only used in instances of type PlayerShip or EnemyShip_
 
 Ship Attributes      | Notes
 ---------------------|------
 BulletType           | :heavy_exclamation_mark: if not set, make sure the standard bullet type is present (PlayerBullet). If not set for instances of type EnemyShip, they will die when they try to fire
 DrawLives            | Draw the lives above the ship or not, default = false
 FireCooldown         | the cooldown (in frames) between 2 shots (60fps), default = 20
 Lives                | default = 3
 ImmunityDuration     | duration of immunity after damage (in frames), default = 60
 
 _The following attributes are only used in instances of type EnemyShip_
 
 EnemyShip attributes | Notes
 ---------------------|------
 AI                   | type of AI, default = 0 (no AI)
 
## Instances ##

Name          | Description
--------------|------------
PlayerShip    | A controllable Ship
EnemyShip     | A generic enemy
PlayerBullet  | A bullet fired by the player
EnemyBullet   | A bullet fired by an enemy
BorderObstacle| The scrolling border is composed of these (deals 2 damage)
Obstacle      | A generic obstacle (deals 1 damage)



