_This project has been created as part of the 42 curriculum by darmarti_

# so_long

## Description

`so_long` is a small 2D game made for the 42 curriculum with C and MLX42.
The player must collect every object and reach the exit while avoiding walls.
The program validates the map before opening the game window and uses a flood
fill to ensure that all collectibles and the exit are reachable.

![so_long gameplay](./solong.gif)

## Build

Requirements:

- A Unix-like system
- `cc`, `make` and `cmake`
- OpenGL development libraries and GLFW

On Debian/Ubuntu, install the system dependencies with:

```bash
sudo apt install libgl-dev libglx-dev libglfw3-dev
```

The window scale can be changed through the `SCALE` variable in the
`Makefile`. Change its value and rebuild the project to apply it:

```make
SCALE = 6
```

```bash
make re
```

Build from the project directory:

```bash
make
```

Useful targets:

```bash
make clean     # Remove object files and clean dependencies
make fclean    # Remove objects, executable and libft build files
make re        # Rebuild from scratch
make run       # Build and launch the map configured in the Makefile
make play      # Build and launch the valid sample maps
make testmaps  # Check the included valid and invalid maps
make norme     # Run Norminette on the project files
```

## Usage

```bash
./so_long maps/map1.ber
```

If the program is launched from the VS Code Snap environment and aborts with
a GLib error about the `antialiasing` GSettings key, run it with a clean
graphical environment:

```bash
env -i HOME="$HOME" PATH="$PATH" DISPLAY="$DISPLAY" \
    WAYLAND_DISPLAY="$WAYLAND_DISPLAY" XDG_RUNTIME_DIR="$XDG_RUNTIME_DIR" \
    XDG_SESSION_TYPE="$XDG_SESSION_TYPE" \
    XDG_CURRENT_DESKTOP="$XDG_CURRENT_DESKTOP" \
    ./so_long maps/map1.ber
```

This is an environment/schema conflict in the desktop integration, not a map
validation error.

Controls:

- `W`, `A`, `S`, `D`: move up, left, down and right.
- `Escape`: close the game.

The move counter is printed in the terminal. The game ends after all
collectibles have been obtained and the player reaches the exit.

## Map format

Maps must use the `.ber` extension, be rectangular and be surrounded by walls.
They must contain exactly one player, exactly one exit and at least one
collectible. The map must be completable.

| Character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start |
| `C` | Collectible |
| `E` | Exit |

Example:

```text
111111
1P0C01
1C00E1
111111
```

## Implementation

- `file_check.c`, `map_checker.c`: validate the file, dimensions, symbols and
  walls.
- `flood_fill.c`: checks that the map can be completed.
- `image_manager.c`, `game_manager.c`: render and manage the game.
- `hooks.c`, `player_movement.c`: process input and movement.
- `MLX42/`: graphics library used by the project.
- `libft/`: supporting 42 C library.
