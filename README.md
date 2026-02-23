# Call of a Hero

[→ YouTube Channel — All Demos](https://www.youtube.com/@andrewson5330)
A voxel game engine rebuilt from scratch in C++ and OpenGL — clean architectural rewrite of [VoxelEngine](https://github.com/Okaimono/cpp-zero-to-hero).

> **Note:** This repository is not intended to be built. It exists to document architectural progress and demonstrate technical growth for portfolio purposes.

## What This Is

After spending months building a 14,000+ line voxel engine from scratch, I started over — same ideas, better structure. This rewrite focuses on clean separation between engine and game layers, dependency injection over singletons, and proper rendering pipeline architecture.

**Current State:** Basic chunk system rendering a grass chunk in an empty void. Foundation is solid, features come next.

**Started:** February 2026

## Demo

[![Refactored Engine Demo](assets/images/refactor.png)](https://www.youtube.com/watch?v=Ava4d2LcwuA)

*Clean engine rewrite — single chunk demo*

## Previous Project

This is a rewrite of my original voxel engine. If you want to see what this architecture is building toward:

**[→ VoxelEngine — the original 14,000+ line build — PLEASE CHECK THIS OUT](https://github.com/Okaimono/cpp-zero-to-hero)**

[![300 FPS Demo](assets/images/50renderdist.png)](https://www.youtube.com/watch?v=X2Rf_YjeDkg)

Notable systems built entirely from scratch:

**`ArmHUD.cpp` — First-person arm rendering system**
This is the one I'm most proud of. No libraries, no tutorials — hand-rolled inverse kinematics using orthonormal basis construction from camera vectors. The arm computes a shoulder, elbow, and wrist chain in world space every frame, oriented to follow the camera. Swing animations are driven by sinusoidal rotation with stateful animation phases. Three completely separate render paths for empty hand, held items, and held blocks, each with their own mesh generation and transformation pipeline.

- **`Creeper.cpp`** — Mob AI with pathfinding and entity systems
- **`PhysicsEngine.cpp`** — Fixed-timestep physics tick with collision detection
- **`WorldGeneration.cpp`** — Chunked terrain generation and spatial partitioning
- **`GUIManager.cpp`** — Custom immediate-mode GUI for inventory, crafting, and HUD

## Gallery

![Render Distance](assets/images/renderdist.png)
![Crafting System](assets/images/craft.png)

## Architecture

The rewrite enforces strict boundaries the original didn't have:

- Engine layer has zero knowledge of game logic
- Dependency injection instead of singletons
- Typed mesh handles for GPU resource management
- Command queue based render batching
- Clean data flow: `Game → RenderPipeline → Renderer → OpenGL`

## Tech

C++17, OpenGL 3.3, GLFW, GLAD, GLM, stb_image

## Note

External dependencies and Mojang textures are not included in either repository. GLAD is bundled in `src/` for simplicity.