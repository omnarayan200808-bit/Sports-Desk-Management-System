
# 🏅➡️ Sports Desk & Tournament Roster System
A modular, high-performance C++ tournament roster management application built using Object-Oriented Programming (OOP) and runtime polymorphism.
---
## 🌟 Key Features
- **Runtime Polymorphism**: Utilizes an abstract base class (`Athlete`) with pure virtual functions (`calculateRating()`, `displaycard()`) to handle diverse sport categories (`Cricketplayer`, `BadmintonPlayer`).
- **Dynamic Heap Memory Management**: Manages athlete records dynamically via `std::vector<Athlete*>` with explicit destructor cleanup to prevent memory leaks.
- **Validation & Safe Streams**: Protected input streams with `cin.fail()`, buffer flushing using `numeric_limits`, and duplicate athlete ID rejection.
- **Persistent Disk Logging**: Real-time receipt and roster serialization/deserialization via C++ file streams (`ofstream` / `ifstream`).
- **Domain-Specific Algorithms**: Automated player classification (Elite, World-Class, Dependable) based on strike rates, wicket ratios, and win percentages.
## 🛠️ How to Compile & Run (macOS / Linux)

bash
```
#Clone the repository
git clone https://github.com/omnarayan200808-bit/Sports-Desk-Management-System.git

# Enter project directory
cd Sports-Desk-Management-System

# Compile using g++ (C++17 standard)
g++ -std=c++17 sports_desk.cpp -o sports_desk

# Run the program
./sports_desk
```
