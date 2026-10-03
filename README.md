# Personal Organizer (LifeSync)

A personal organizer application designed to efficiently manage daily tasks, schedule time-sensitive events, and save version-controlled notes using optimized data structures[cite: 10, 11].

## Features & Data Structures

* **Task Management:**
  * Add, remove, and search tasks by title or category[cite: 10, 11].
  * Displays tasks sorted by priority level[cite: 10, 11].
  * **Under the Hood:** Implemented using a Linked List[cite: 11].

* **Event Scheduling:**
  * Add upcoming events with specific times and descriptions[cite: 11, 16].
  * View or remove the nearest upcoming event[cite: 11].
  * **Under the Hood:** Implemented using a Min-Heap to automatically keep events sorted chronologically[cite: 11].

* **Note-Taking System:**
  * Create, view, and update notes[cite: 10, 11].
  * Undo functionality to revert to previous versions of a note[cite: 10, 11].
  * **Under the Hood:** Uses a Hash Map for fast retrieval and a Stack for version control/undo support[cite: 11].

## System Overview
1. Main Menu:
2. Task Manager
3. Event Scheduler
4. Note Taking
5. Exit

   ## Getting Started

### Prerequisites

* Any standard C/C++ compiler (such as GCC, MSVC, or Clang)[cite: 20].

### Compilation & Execution

```bash
# 1. Clone the repository
git clone [https://github.com/your-username/LifeSync-Organizer.git](https://github.com/your-username/LifeSync-Organizer.git)
cd LifeSync-Organizer

# 2. Compile the source code
g++ main.cpp -o LifeSync

# 3. Run the executable
./LifeSync
