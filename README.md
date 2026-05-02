# Raylib Game Engine Core (C)

A custom 2D game engine framework built with the Raylib library in C. This project focuses on low-level resource management, tile-based world logic, and modular data structures for RPG-style game development.

---
```
### 1. Overview
The engine provides a foundation for tilemap-based games, featuring automated asset loading,
a 2D camera system, and structured data management for players and items.
It emphasizes memory efficiency and strict control over the graphics pipeline.
```
---
```
### 2. Key Features
- Dynamic Tilemap System: Loads world data and collision logic from external configuration files (map.txt and logic.txt).
- Memory-Optimized Player Architecture: Modular structures for player stats, equipment, and inventory, specifically designed for low memory footprint (e.g., 134 bytes per player instance).
- 2D Camera Management: Smooth target tracking with real-time debug statistics including FPS, frame time, and world coordinates.
- Resource Lifecycle Control: Automated texture batch loading from directories and managed VRAM unloading.
- Custom Type System: Implementation of fixed-width integer aliases (u8, u16, i32, etc.) for cross-platform consistency and code readability.
```
---
```
### 3. Technical Specifications
- Language: C
- Library: Raylib
- Build System: Makefile (supporting TCC and GCC)
- Resolution: 1280x720 (720p)
- Sprite Basis: 16x16 pixel tiles
```
---
```
### 4. Project Structure
- main.c: Entry point, game loop, and core rendering/input logic.
- source/default.h: Global configuration, screen constants, and type definitions.
- source/player.c & source/player.h: Data models for player attributes, equipment IDs, and backpack contents.
- data/textures/: Directory-based asset management for environment and NPC sprites.
- data/settings/: Map layout and logic/collision data files.
```
---
```
### 5. Build and Execution

The project uses a Makefile for compilation. It is optimized for the Tiny C Compiler (TCC) but compatible with others.

Commands:
1. Build executable:
   make raylib

2. Run application:
   make run

3. Clean build files:
   make clean
```
---
```
### 6. Development Goals
- Tile-based collision detection using logic maps.
- Implementation of a modular RPG equipment system.
- Efficient 2D rendering pass with Mode2D integration.
- Frame-rate independent movement using DeltaTime.
```
---
Created by Demichu5
