# so_long - Maze Munch

A 2D Snake-inspired game built with MiniLibX, where the player navigates a maze, collects food, and reaches the exit.

![Language](https://img.shields.io/badge/Language-C-blue)
![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-green)
![School](https://img.shields.io/badge/School-42-orange)

## Project Overview

**so_long** is a 42 School project that challenges you to create a small 2D game using the MiniLibX graphics library. The game combines classic Snake mechanics with maze navigation, requiring the player to collect all food items before reaching the exit.

### Game Concept: "Maze Munch"

Control a snake navigating through a maze filled with apples. The snake grows longer with each apple eaten, making navigation increasingly challenging. Find the gate to escape, but only after collecting all food!

## Project Goals

### Technical Objectives
- **Window management**: Create and manage graphical windows
- **Event handling**: Process keyboard input and window events
- **Image rendering**: Display sprites and handle animations
- **Game loop**: Implement smooth gameplay with proper frame timing
- **Memory management**: Prevent leaks in graphical applications
- **Map parsing**: Read and validate game maps from files

### Learning Outcomes
- Understanding the MiniLibX library
- Working with XPM image format
- Implementing game logic and state management
- Creating responsive user interfaces
- Managing resources (images, windows, memory)
- Debugging graphical applications

## Game Design

### Visual Theme

**Snake Variants**:
- **Green Snake** (`snake_ghead`, `snake_gbody`) - Default skin
- **Yellow Snake** (`snake_yhead`, `snake_ybody`) - Alternative skin
- **Dead Snake** (`snake_gdhead`, `snake_ydhead`) - Game over state

**Environment**:
- **Walls** (`corner`, `hor_left`, `hor_right`, `ver_up`, `ver_down`, `hor_wall`, `ver_wall`)
- **Food** (`food_apple`) - Collectibles that grow the snake
- **Egg** (`egg`) - Special collectible
- **Gate** (`gate0-5`) - Animated exit portal (6 frames)
- **Background** (`background`) - Floor tiles

**Bonus Elements**:
- **Enemies** (`enemy0-4`) - Moving obstacles (5 frames animation)

### Sprite System

All sprites are **126x126 pixels** in XPM format:
- Character sprites (snake heads/bodies)
- Environment tiles (walls, floor)
- Interactive objects (food, gate)
- Animated elements (gate portal, enemies)

```
assets/
├── xpm/                    # All game sprites
│   ├── snake_ghead.xpm    # Snake head (green)
│   ├── snake_gbody.xpm    # Snake body segment
│   ├── food_apple.xpm     # Collectible food
│   ├── gate0-5.xpm        # Animated gate (6 frames)
│   ├── enemy0-4.xpm       # Enemy animation (bonus)
│   └── ...                # Wall pieces, backgrounds
└── maps/
    ├── round1.ber         # Level 1
    ├── round2.ber         # Level 2
    └── ...                # Additional levels
```

## Map System

### Map Format (.ber files)

Maps are rectangular grids using ASCII characters:

```
1111111
111C001
10P0101
1C0C001
1C1CE01
1111111
```

### Map Elements

| Character | Element | Description |
|-----------|---------|-------------|
| `1` | Wall | Impassable barriers |
| `0` | Empty space | Walkable floor |
| `P` | Player start | Snake's initial position |
| `C` | Collectible | Food items (apples) |
| `E` | Exit | Gate to complete the level |
| `M` | Enemy (bonus) | Moving obstacles |

### Map Validation Rules

**Mandatory checks**:
1. **Rectangular**: All rows must have the same length
2. **Closed**: Map must be surrounded by walls (`1`)
3. **Valid characters**: Only `0`, `1`, `P`, `C`, `E` (+ `M` for bonus)
4. **Single player**: Exactly one `P` (player start position)
5. **Single exit**: Exactly one `E` (exit gate)
6. **At least one collectible**: Minimum one `C` (food)
7. **Valid path**: All collectibles and exit must be reachable from start
8. **File extension**: Must be `.ber`
9. **Screen size**: Map dimensions must fit on screen

## Controls

### Mandatory

| Key | Action |
|-----|--------|
| `W` or `↑` | Move Up |
| `A` or `←` | Move Left |
| `S` or `↓` | Move Down |
| `D` or `→` | Move Right |
| `ESC` | Exit game |

### Bonus Features

**Additional controls**:
- Close window button (`X`) to exit
- Move counter displayed on window

**Gameplay enhancements**:
- Snake grows with each food collected
- Collision detection with snake body (game over)
- Enemy movement and collision (bonus)
- Animated gate portal
- On-screen move counter

## Game Mechanics

### Core Gameplay Loop

```
1. Parse and validate map
2. Initialize MLX window and load sprites
3. Display start screen
4. Game loop:
   ├─ Handle keyboard input
   ├─ Update game state
   │  ├─ Move snake
   │  ├─ Check collisions
   │  ├─ Update snake body
   │  └─ Increment move counter
   ├─ Render frame
   │  ├─ Draw background
   │  ├─ Draw walls
   │  ├─ Draw collectibles
   │  ├─ Draw gate
   │  ├─ Draw snake
   │  └─ Draw enemies (bonus)
   └─ Update animations
5. Check win/lose conditions
6. Cleanup and exit
```

### Snake Mechanics

**Growth system**:
```c
Initial: [HEAD]
After food 1: [HEAD] → [BODY]
After food 2: [HEAD] → [BODY] → [BODY]
After food 3: [HEAD] → [BODY] → [BODY] → [BODY]
```

### Animation System

**Gate Portal** (6 frames):
```
Frame 1: gate0.xpm  ┐
Frame 2: gate1.xpm  │
Frame 3: gate2.xpm  │ Loop continuously
Frame 4: gate3.xpm  │ at FPS rate (7000μs)
Frame 5: gate4.xpm  │
Frame 6: gate5.xpm  ┘
```

**Enemy Movement** (bonus, 5 frames):
```
enemy0.xpm → enemy1.xpm → enemy2.xpm → enemy3.xpm → enemy4.xpm
     ↑                                                      ↓
     └──────────────────────────────────────────────────────┘
```

## Project Structure

```
so_long42/
├── includes/
│   ├── so_long.h              # Main header
│   └── so_long_bonus.h        # Bonus header
│
├── srcs/
│   ├── mandatory/
│   │   ├── so_long.c          # Main entry point
│   │   ├── game/
│   │   │   ├── map/
│   │   │   │   ├── ft_buildmap.c      # Map loader
│   │   │   │   ├── ft_checkmap.c      # Map validator
│   │   │   │   └── ft_errormap.c      # Error handling
│   │   │   ├── ft_checkbody.c         # Body collision
│   │   │   ├── ft_checkfood.c         # Food collision
│   │   │   ├── ft_checkgate.c         # Gate collision
│   │   │   ├── ft_checkwall.c         # Wall collision
│   │   │   ├── ft_glogic.c            # Game logic
│   │   │   ├── ft_gw.c                # Game window
│   │   │   ├── ft_hooks.c             # Event handlers
│   │   │   └── ft_moves.c             # Movement logic
│   │   └── utils/
│   │       ├── ft_immutable.c         # Static elements
│   │       ├── ft_items.c             # Dynamic elements
│   │       ├── ft_snake_body.c        # Snake management
│   │       ├── ft_utils.c             # Helper functions
│   │       ├── ft_freegame.c          # Game cleanup
│   │       ├── ft_freeitems.c         # Items cleanup
│   │       └── ft_freestart.c         # Start cleanup
│   │
│   └── bonus/
│       └── [same structure with enemy support]
│
├── assets/
│   ├── maps/
│   │   ├── round1.ber         # Level 1 (7x6)
│   │   ├── round2.ber         # Level 2
│   │   ├── round3.ber         # Level 3
│   │   ├── round4.ber         # Level 4
│   │   └── round5.ber         # Level 5
│   │
│   └── xpm/                   # 31 sprite files (126x126px)
│       ├── begin.xpm          # Start screen
│       ├── congrats.xpm       # Win screen
│       ├── over.xpm           # Game over screen
│       └── [game sprites]
│
├── import/
│   ├── libft/                 # Custom C library
│   └── mlx/                   # MiniLibX library
│
├── Makefile                   # Build system
└── README.md                  # This file
```

**Algorithm**:
```c
1. Read file into 2D array
2. Count rows and columns
3. Verify:
   ├─ All rows same length
   ├─ First/last rows all walls
   ├─ First/last columns all walls
   ├─ Valid characters only
   ├─ Exactly 1 player
   ├─ Exactly 1 exit
   └─ At least 1 collectible
4. Verify all items reachable
```

## Key Implementation Details

### Map Parsing

```c
Steps:
1. Open file with read()
2. Use get_next_line() to read line by line
3. Store each line in char** array
4. Validate during parsing:
   ✓ Count P, E, C
   ✓ Check valid characters
   ✓ Verify rectangular shape
5. After parsing:
   ✓ Check wall enclosure
   ✓ Flood-fill for path validation
```

### Path Validation (Flood-Fill)

```c
Algorithm:
1. Create copy of map
2. Start from player position (P)
3. Recursively mark reachable cells:
   - Replace '0' → 'V' (visited)
   - Replace 'C' → 'V' (collectible found)
   - Replace 'E' → 'V' (exit found)
   - Stop at walls ('1')
4. Check if all C and E were visited
5. Free copy map
```

### Animation Timing

```c
Using usleep(FPS) in game loop:
- FPS = 7000 microseconds (7ms)
- ~142 frames per second
- Frame counter increments each loop
- Gate animation: cycle through 6 frames
- Formula: frame_index = (counter / 10) % 6
```

## 42 Project Requirements

### Mandatory Part

**Technical**:
- Use MiniLibX for graphics
- Window management without crashes
- ESC key and close button exit properly
- Image rendering with XPM files
- Smooth window switching

**Game**:
- Player controlled by WASD or arrow keys
- Player cannot move through walls
- Move counter displayed (printed to stdout)
- Collect all items before exit
- Exit on gate after all collectibles

**Map**:
- Read from `.ber` file
- Rectangular shape
- Surrounded by walls
- Valid path to all collectibles and exit
- Error handling for invalid maps

### Bonus Part

**Enhanced gameplay**:
- Enemy patrols/hazards
- Snake grows with collectibles
- Body collision detection
- Sprite animations (gate, enemies)

**UI improvements**:
- Move counter on window (not just stdout)
- Multiple sprite sets
- Start/win/lose screens

**Technical**:
- Smoother animations
- Better error messages
- Additional maps

## Key Learnings

### Graphics Programming
- Understanding the MiniLibX API
- Working with XPM image format
- Managing multiple windows
- Sprite-based rendering
- Animation techniques

### Game Development
- Game loop architecture
- State management
- Collision detection algorithms
- Entity component systems (snake, items, enemies)
- Input handling and responsiveness

### Memory Management
- Freeing image resources
- Cleaning up MLX instances
- Managing linked lists (snake body)
- Preventing memory leaks in event loops

### Algorithm Implementation
- Linked list manipulation
- Map validation logic
- Frame-based animation

### Software Architecture
- Separating game logic from rendering
- Modular function design
- Data structure organization
- Error handling strategies

## Common Issues & Solutions

### Issue: Map Not Loading
```
Error: "Error\n"
Solution: Check map file path, ensure .ber extension
```

### Issue: Segmentation Fault
```
Common causes:
- NULL pointer dereference in MLX functions
- Invalid image paths
- Map array out of bounds
Solution: Add NULL checks, validate indices
```

### Issue: Window Won't Close
```
Solution: Ensure ft_freegame() is called
Register both ESC key and DestroyNotify event
```

### Issue: Images Not Displaying
```
Solution: Verify XPM file paths
Check image dimensions (126x126)
Ensure mlx_init() called before loading images
```

### Issue: Snake Not Growing
```
Solution: Check ft_addbody() is called
Verify linked list append logic
Ensure body segments properly initialized
```