#Game Design Document

I am trying to create a top-down zombie survival game.

----

##Objects

In this game, I will have five main moving "things":

###The Player
This is the main character that is controlled by the user.
Piloted with WASD and the arrow keys, this character can shoot zombies coming from all directions.
Looks like a normal human from the top-down view.

###The Player's Bullets
These independently travelling entities come from the player's gun. After being shot in one direction, they do not change velocity.
They are destroyed after either a certain timeout duration or after they are off-screen.
Just look like bullets

###The Environment
Stationary Blocks and a background image.

###The Main Crawler Zombie
The main enemy the main character will be facing. This zombie will spawn at a side of the screen, at either the character's x or y location.
They will then proceed to move in one direction (similar to the bullet), and will either stop at a certain point in the screen or run off-screen.
They will be destroyed either by the player or at the edge of the screen.

###The Follower Zombie
This upgraded level zombie will spawn at a random position off-screen, and then will proceed to move in the direction of the player.
Their x and y velocities will just be determined by the direction of the player and their speed multiplier.

##Control

In this game, I will controlling my character with the keyboard exclusively.
The "WASD" keys will be used to move the character around, and the arrow keys will be used to face the character and shoot in a certain direction.
The main character will also be able to execute a burst attack with the space bar to clear the screen of zombies everytime the player's score reaches a certain point (~every ten points).

##Score

The player gains score based on how many zombies are killed. Every main zombie that is killed will each give 1 point to the player.
Every special zombie that is killed (the follower zombie) wil give the player 2 points. The score does not go down at any point.

(Might include multiplier)

##Lives

Players' lives are shown in a corner of the screen.
Players each start with three lives, which are lost when they are hit by or when they hit a zombie.
Each time a player is hit, this will clear the screen of zombies, reset

##Layout

The MainWindow view will show the game in a large CanvasView, and a right-side dock will include the start button, the score, and the lives count.
This dock will also include a temporary output box used to debug the game.
![layout](https://www.evernote.com/shard/s20/res/54e22c87-db91-44c5-ad07-321e4136160c/Snapshot_1.jpg?resizeSmall&width=859 "layout")
