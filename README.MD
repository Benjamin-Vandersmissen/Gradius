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
 **TexturePath**   | where to find the texture (relative to root of the game)
 **Speed**         | the speed at which the instance moves
 Depth             | depth at which the instance gets drawn (lower depth first)
 nrFrames          | if the image is an animation, how many frames (caution, make sure each frame has the same size and there are no gaps between the frames)
 Delay             | if the image is an animation, the delay between two frames
 
 **Bolded** items are necessary attributes, otherwise an error will occur.
 
 :heavy_exclamation_mark: the size and hitbox are directly taken from the texture
 - the size is the texture size interpreted in a 200x150 canvas, and then scaled
   - a texture of size 100x75 will occupy a quarter of the screen regardless of resolution
 - the hitbox is the same as the texture
 
 _The following attributes are only used in instances of type PlayerShip or EnemyShip_
 
 Ship Attributes      | Notes
 ---------------------|------
 BulletType           | :heavy_exclamation_mark: if not set, make sure the standard bullet type is present (PlayerBullet). If not set for instances of type EnemyShip, they will die when they try to fire
 DrawLives            | draw the lives above the ship or not, default = false
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


## How To Use Levels ## 

Levels are _.json_ files located in the map /levels. They contain all the properties of a level

Name                   | Notes
-----------------------|------
ResourcePath           | where to search for resources
Resources              | a list of resources that should be loaded in
Entities               | a list of entities, an entity is of the following form : '{"Type": _resourceName_, "Position": [_x_, _y_]'
Border                 | the entities from which the border is created
Speed                  | the speed at which the level scrolls
Length                 | the length of the level

## To Do List / Feature Wishlist ##

### Easy Peasy ###

- make PlayerBullet and EnemyBullet a subclass of a new class Bullet
- make it possible to load the heart icon from disk instead of hardcoding it
- fancier menus
- scrolling background

### Medium ###

- make object size and hitbox more customisable and less reliant on the texture
  - size can be customised with resources
  - hitbox is a polygon instead of a rectangle and customisable in resources
- more / smarter AI
- some kind of boss(es)
  - extra option in level files to end a level if there are no more enemies in the level instead of ending it at a fixed distance

### (Impossibly) Hard ###

- ingame level editor 
  - with a preview / test enviroment
