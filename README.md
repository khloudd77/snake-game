# Snake Game - C++ OOP Implementation

This project is a classic implementation of the Snake Game using the **C++ programming language**. [cite_start]It demonstrates the application of **Object-Oriented Programming (OOP)** principles by encapsulating game entities like the snake and food into distinct, modular classes[cite: 6, 7, 8].

## 🏗️ Design Architecture & Class Diagram
[cite_start]The system follows a modular architecture where the **Game controller** manages individual entities, ensuring data protection and clear logic separation[cite: 25, 26].

### Core Classes:
- [cite_start]**Snake Class:** Maintains the position of the head and tail segments, and handles movement logic[cite: 51, 52].
- [cite_start]**Food Class:** A utility class that handles randomized food generation using `rand()`[cite: 53].
- [cite_start]**Game Class:** The primary engine that manages the game loop, console rendering, and win/loss logic[cite: 54].

[cite_start]*Refer to `snake_game_dec.pdf` for the full UML Class Diagram and technical specifications[cite: 3, 27].*

## 🎮 Implementation Logic (The Game Loop)
[cite_start]The game execution is centralized in the `Game::run()` method, which executes an infinite loop consisting of four phases[cite: 56, 57]:
1. [cite_start]**Draw:** Renders the grid, snake, and food using `SetConsoleCursorPosition` to prevent flickering[cite: 57].
2. [cite_start]**Input:** Captures user keystrokes ('w', 'a', 's', 'd') using `_kbhit()` and `_getch()` without pausing the game[cite: 57].
3. [cite_start]**Logic:** Handles movement, collision detection (walls and tail), and scoring[cite: 57].
4. [cite_start]**Sleep:** A 120ms delay is synchronized to maintain a playable frame rate[cite: 57].

## 🚀 Features & Requirements
- [cite_start]**Continuous Movement:** The snake moves autonomously until a collision occurs[cite: 15].
- [cite_start]**Score System:** Players earn 10 points for each food consumed, which also increases the snake's length[cite: 17].
- [cite_start]**Flicker-Free Interface:** Optimized for a smooth console experience[cite: 21, 57].

## 🛠️ How to Build and Run
1. **Compile:**
   ```bash
   g++ main.cpp Game.cpp Snake.cpp Food.cpp -o snake_game 