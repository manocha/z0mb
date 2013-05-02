#Game Design Document - z0mb

I am trying to create a top-down zombie survival game.

##Objects

In this game, I will have five "thing" - with four moving things:

###The Player
This is the main character that is controlled by the user.
Piloted with WASD and shoots with the arrow keys, this character can shoot zombies coming from all directions.
Looks like a sumo wrestler with an energy beam in his mouth from the top-down view. Lays down a mine with the space key.

###The Coins
These stationary coins are spawned in a random location, one spawned after one is collected. Point value is two. Look like jewels.

###The Player's Bullets
These independently travelling entities come from the player's 'gun'. After being shot in one direction, they do not change velocity.
They are destroyed after they are off-screen.
Just look like bullets - coin-like;

###The Vortex/Mine
Spinning blocks that damage enemies that run into it - disappears after a set amount of time. Looks like two space cubes melded together.
Costs 8 points to operate.

###The Main Crawler Zombie
The main enemy the main character will be facing. This zombie will spawn at either the left or right of the screen, at a random y location.
They will then proceed to move in one direction (similar to the bullet), and will be destroyed when they run off-screen at the other side.
They will be destroyed either by the player or at the edge of the screen. Green.

###The Follower Zombie
This upgraded level zombie will spawn at a random position off-screen, and then will proceed to move in the direction of the player.
Their x and y velocities will just be determined by the direction of the player and their speed multiplier. Yellow with red eyes.

##Control

In this game, I will controlling my character with the keyboard exclusively.
The "WASD" keys will be used to move the character around, and the arrow keys will be used to face the character and shoot in a certain direction.
The main character will also be able to execute a vortex mine with the space bar to clear the screen of zombies that enter.

##Score

The player gains score based on how many zombies are killed. Every main zombie that is killed will each give 1 point to the player.
Every special zombie that is killed (the follower zombie) wil give the player also 1 point. The score goes down at any point by 8 if vortex used.
The game spawns less crawlers and more followers as the score increases.

##Lives

Players' lives are shown in the status bar of the window.
Players each start with four lives, which are lost when they are hit by a zombie.
Each time a player is hit, this will clear the screen of zombies, reset

##Layout

The MainWindow view will show the game in a large CanvasView, and a top menu bar will include the start button, the quit button, and the name entry.
The score, along with the name, is shown in the top-left of the canvas.
![layout](https://www.evernote.com/shard/s20/res/54e22c87-db91-44c5-ad07-321e4136160c/Snapshot_1.jpg?resizeSmall&width=859 "layout")
