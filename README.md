# game-of-life
CPSC 350 game of life

Names:
Tristan Tran,
Sakthi Kasthurirengan

ID Numbers
1822091,
1840119

notes to user:
sleep mode is set for 5 seconds. Kinda slow, but let's you take it all in.
enter mode is really fun. Press enter as fast as you can and you can almost pretend we did GUI.
File mode only prints 1000 generations because we didn't want to leave you with an incomplete file or create a giant monster.
Try all the presets on enter mode and see how fast you can go.


Description:
To summarize, when the program is run it should:
1. Ask the user if they wish to start with a random configuration, or specify a flatfile
configuration. Prompt appropriately depending on the response.
2. Ask the user what kind of boundary mode to run in.
3. Ask the user if they want a brief pause between generations, if they want to have
to press the “enter” key, or if they want to output to a file.
4. Carry out the simulation
5. If the simulation is infinite, just keep running. But if the world becomes empty or
stabilizes, the simulation should halt and ask the user to press “enter” to exit the
program.
6. For file mode, if the simulation does not reach a stable state after 1000 iterations, it will end the program.
7. 5 Presets for different cases of exploder, rocket ship, and tumbler found from bitstorm.org/gameoflife. Used the shapes, but did not get any code from them.
Resources:
-Added the ifndef etc. based on the suggestions of my friend Rio.
-Sleep(), setParam() and cin.get() additions based off answers found on cplusplus forums
-std::stoi() and stof() functions also found on cplusplus
