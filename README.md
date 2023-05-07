# HonoursProject

Developed with Unreal Engine 5

Created by Aaron Crawford

Student ID: 1900400

This project will evaulate the use of procedural map generation within competitive multiplayer shooter games, to assess if balanced maps can be created to enhance the player's experience

Prerequisites:
To play this game online you will need to have steam downloaded on your pc (can be found here) - https://store.steampowered.com/about/
You will also need to be signed into a steam account to access the multiplayer features such as search and join a game.

Testing:
For testing via exe file you need two different steam accounts to play the game on two different PCs.

If testing within the editor please follows these steps:
1. Ensure that the main menu level is selected. Which can be found here - Procedural_Generation -> Maps -> Menu -> MainMenu_Level
2. Within the viewport ensure that standalone game is selected (this must be done otherwise it will not work).
3. In multiplayer options within the viewport select the amount of players. Anywhere from 1 - 4 works fine. 
4. In multiplayer options within the viewport ensure net mode is on standalone.

To host, join and play the game follow these steps:
1. Select a player name.
2. Click multiplayer.
3. Click connection to change from LAN to network. (LAN works if playing in the editor otherwise use Online for exe).
4. Click host game.
5. On the other client(s) click search game and wait for a result to appear and click on the result.
6. Once every one has joined the host must ensure that the seamless travel box is ticked otherwise the game will not work.
7. Every player must select a team.
8. Host will select a level at the bottom left either level 1 or level 2 and this will start the game.

Video demo / tutorial can be found here - https://youtu.be/GNySjdQnFsg 

Controls:
W - Move forward
A - Move left
S - Move backward
D - Move right
Q - Switch weapons
E - Plant or defuse bomb (hold for 5 seconds)
Escape - Pause menu
Mouse left click - Shoot
Mouse right click - Aim

References used for this project:
GameDevRaw (2022) UE5 Multiplayer Beginner tutorial – create a full game from scratch. Available at: https://youtube.com/playlist?list=PLzykqv-wgIQXompUswD5iHllUHxGY7w0q (Accessed: February 27 2023).
Nitrogen (2018) Unreal Engine 4 Tutorial – Bomb (Plant and Defuse). Available at: https://youtu.be/4yyM5rW-j9M (Accessed: March 20 2023).
Pub Games (2016) UE4 – Procedural Level Generation. Available at: https://youtu.be/VmRggTwhiew (Accessed: November 23 2023).
White Box Dev (2020) Cellular Automata | Procedural Generation | Game Development Tutorial. Available at: https://youtu.be/slTEz6555Ts (Accessed: February 15 2023).