# DSA with C - Learning Guide

## Setup Complete! ✅

Your VS Code is now configured for **Data Structures and Algorithms (DSA)** learning with C.

### Folder Structure
```
DSA with C and C++/
├── .vscode/
│   ├── c_cpp_properties.json    (IntelliSense configuration)
│   ├── tasks.json               (Build/Run tasks)
│   └── launch.json              (Debugging configuration)
├── DSA_Programs/
│   └── 01_array_basics.c        (First program - Array fundamentals)
└── README.md                    (This file)
```

## How to Compile and Run

### Method 1: Using VS Code Tasks (Recommended)
1. Open `01_array_basics.c`
2. Press **Ctrl + Shift + B** to compile
3. Press **Ctrl + Shift + D** then click "Run" to execute with debugging
4. Or use terminal: run the `.exe` file directly

### Method 2: Using Terminal
```bash
cd DSA_Programs
gcc -g 01_array_basics.c -o 01_array_basics.exe
./01_array_basics.exe
```

## Required Tools

Make sure you have **GCC** (MinGW) installed:
- Download from: https://www.mingw-w64.org/
- Add to PATH if not already done

## VS Code Extensions (Recommended)

Install these extensions for better C development:
1. **C/C++** (by Microsoft)
2. **C/C++ Runner** (useful for quick compilation)
3. **Better Comments** (for better code documentation)

## Learning Path

### Phase 1: Fundamentals
- ✅ `01_array_basics.c` - Arrays, search, insertion, deletion

### Phase 2: Sorting Algorithms
- `02_sorting.c` - Bubble sort, selection sort, insertion sort

### Phase 3: Advanced Data Structures
- `03_linked_lists.c` - Singly linked lists
- `04_stack.c` - Stack implementation
- `05_queue.c` - Queue implementation

### Phase 4: Complex Algorithms
- `06_recursion.c` - Recursive problems
- `07_searching.c` - Binary search, hash tables
- `08_trees.c` - Binary trees, BST
- `09_graphs.c` - Graph traversal

## Debugging Tips

1. **Set Breakpoints**: Click on the line number to set a breakpoint
2. **Watch Variables**: Add variables in the Watch panel
3. **Step Through Code**: Use F10 (step over) and F11 (step into)
4. **View Memory**: Right-click variable → "View Memory"

## Keyboard Shortcuts

| Shortcut | Action |
|----------|--------|
| Ctrl + Shift + B | Compile C Program |
| F5 | Start Debugging |
| F10 | Step Over |
| F11 | Step Into |
| Ctrl + K Ctrl + 0 | Fold All |
| Ctrl + K Ctrl + J | Unfold All |

## Tips for Learning DSA

1. **Understand the concept** first before coding
2. **Read the comments** in each program
3. **Trace through the code** manually
4. **Modify and experiment** with the code
5. **Time complexity** - Always think about O(n) notation
6. **Space complexity** - Consider memory usage

## Common Compiler Errors & Fixes

| Error | Fix |
|-------|-----|
| `gcc: command not found` | Install MinGW and add to PATH |
| `undefined reference to main` | Make sure you have `int main()` |
| `-Wunused-variable` warnings | Use all declared variables |
| `segmentation fault` | Check array bounds and pointers |

---

Happy Learning! 🚀 Start with `01_array_basics.c` and follow along with the comments.
