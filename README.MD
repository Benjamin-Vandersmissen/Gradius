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
 **Speed**         | the speed at which the instance moves
 Sprite            | the sprite for the entity
 Hitbox            | a sequence of consequent points, _default_ is the bounding box of the image

  **Bolded** items are necessary attributes, otherwise an error will occur.

 _The following attributes are only used in instances of type PlayerShip or EnemyShip_
 
 Ship Attributes      | Notes
 ---------------------|------
 BulletType           | :heavy_exclamation_mark: if not set, make sure the standard bullet type is present (PlayerBullet). If not set for instances of type EnemyShip, they will die when they try to fire
 DrawLives            | draw the lives above the ship or not, _default is false_
 FireCooldown         | the cooldown (in frames) between 2 shots (60fps), _default is 20_
 Lives                | _default is 3_
 ImmunityDuration     | duration of immunity after damage (in frames) _default is 0_
 
 _The following attributes are only used in instances of type EnemyShip_
 
 EnemyShip attributes | Notes
 ---------------------|------
 AI                   | type of AI, default = 0 (no AI)

 _The following attributes are only used in instances of type PlayerBullet or type EnemyBullet_

 Bullet attributes | Notes
 ------------------|------
 Type              | whether the bullet behaves normally ("normal") or is homing ("homing"), _default is "normal"_
 FiredSound        | path to a sound that will be played when the bullet is created
 
## Instances ##

Name          | Description
--------------|------------
PlayerShip    | A controllable Ship
EnemyShip     | A generic enemy
PlayerBullet  | A bullet fired by the player
EnemyBullet   | A bullet fired by an enemy
BorderObstacle| The scrolling border is composed of these (deals 2 damage)
Obstacle      | A generic obstacle (deals 1 damage)
Boss          | A boss

## Sprites ##

Sprites are _.ini_ files located in the folder /sprites. They contain all the properties of a level

Attributes   | Notes
-------------|-------
nrFrames     | The amount of frames a the sprite has
isStrip      | If the image is a strip, _default is false_
**Source**   | The source path of the image
frameWidth   | The width of a frame in a strip, only needed when _isStrip_ = true, _default is width/nrFrames_
frameOffset  | The offset between two frames in a strip, only needed when _isStrip_ = true, default is 0_
Delay        | The delay between two animated frames, 60 = 1 second delay, _default is 0_
Origin       | The origin, _default is (0,0)_

 :heavy_exclamation_mark: the size is directly taken from the texture
 - the size is the texture size interpreted in a 200x150 canvas, and then scaled
   - a texture of size 100x75 will occupy a quarter of the screen regardless of resolution


## How To Use Levels ## 

Levels are _.json_ files located in the map /levels. They contain all the properties of a level

Name                   | Notes
-----------------------|------
ResourcePath           | where to search for resources
Resources              | a list of resources that should be loaded in
Entities               | a list of entities, an entity is of the following form : {"Type": _resourceName_, "Position": [_x_, _y_]}
Border                 | the entities from which the border is created
Speed                  | the speed at which the level scrolls
Length                 | the length of the level


## Available Levels ##
- level
- test

## To Do List / Feature Wishlist ##

### Easy Peasy ###

- ~~make PlayerBullet and EnemyBullet a subclass of a new class Bullet~~
- make it possible to load the heart icon from disk instead of hard-coding it
- fancier menus
- scrolling background
- more customization of levels and the game
- better placement of newly created bullets
- ~~move hitbox initialisation to base Entity resource instead of derived resources~~
- ~~progress bar for level~~

### Medium ###

- ~~make object size and hitbox more customisable and less reliant on the texture~~
  - ~~size can be customised with resources~~
  - ~~hitbox is a polygon instead of a rectangle and customisable in resources~~
- more / smarter AI
- ~~some kind of boss(es)~~
  - extra option in level files to end a level if there are no more enemies in the level instead of ending it at a fixed distance
- ~~sound effects~~
- ~~homing weapons~~
- ~~Sprites instead of Animations, with more options. Will be loaded from a file, to reduce clutter in resource files~~
- A general config

### (Impossibly) Hard ###

- ingame level editor 
  - with a preview / test environment
