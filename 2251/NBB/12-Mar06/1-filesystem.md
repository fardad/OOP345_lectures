# **C++ Filesystem Library (C++17 and Later)**
### **Introduction**
The `std::filesystem` library, introduced in C++17, provides a robust and platform-independent way to work with the file system. It enables operations like path manipulation, directory traversal, file creation, and metadata retrieval.

### **1. Including the Filesystem Library**
```cpp
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path p = "example.txt";
    std::cout << "Path: " << p << "\n";
}
```
- The `std::filesystem` library is in the `std` namespace.
- We alias it as `fs` for brevity.

---

## **2. Paths and Path Operations**
### **Creating and Manipulating Paths**
```cpp
fs::path p1 = "/home/user/documents";
fs::path p2 = "file.txt";

fs::path fullPath = p1 / p2;  // Combines paths
std::cout << "Full path: " << fullPath << "\n";
```
- The `/` operator joins paths correctly across platforms.

### **Path Components**
```cpp
fs::path p = "/home/user/example.txt";

std::cout << "Filename: " << p.filename() << "\n";
std::cout << "Extension: " << p.extension() << "\n";
std::cout << "Parent path: " << p.parent_path() << "\n";
```
- `.filename()`: Returns `example.txt`
- `.extension()`: Returns `.txt`
- `.parent_path()`: Returns `/home/user`

---

## **3. Checking Files and Directories**
### **Checking if a Path Exists**
```cpp
fs::path p = "example.txt";

if (fs::exists(p)) {
    std::cout << "File exists.\n";
} else {
    std::cout << "File does not exist.\n";
}
```
- `fs::exists(p)`: Returns `true` if the file or directory exists.

### **Checking if a Path is a File or Directory**
```cpp
if (fs::is_regular_file(p)) {
    std::cout << "It's a file.\n";
} else if (fs::is_directory(p)) {
    std::cout << "It's a directory.\n";
}
```
- `fs::is_regular_file(p)`: Returns `true` if it's a file.
- `fs::is_directory(p)`: Returns `true` if it's a directory.

---

## **4. Creating and Removing Files & Directories**
### **Creating a Directory**
```cpp
fs::create_directory("new_folder");
```
- Creates a directory called `new_folder`.

### **Creating Multiple Directories**
```cpp
fs::create_directories("parent/child/grandchild");
```
- Creates multiple directories in one call.

### **Removing a File or Directory**
```cpp
fs::remove("example.txt"); // Deletes file or empty directory
fs::remove_all("parent");  // Recursively deletes directory and contents
```
- `fs::remove(p)`: Removes a file or empty directory.
- `fs::remove_all(p)`: Deletes a directory and all its contents.

---

## **5. Iterating Over a Directory**
```cpp
fs::path dir = "."; // Current directory

for (const auto& entry : fs::directory_iterator(dir)) {
    std::cout << entry.path() << "\n";
}
```
- `fs::directory_iterator`: Iterates over directory contents.

### **Recursive Directory Iteration**
```cpp
for (const auto& entry : fs::recursive_directory_iterator(dir)) {
    std::cout << entry.path() << "\n";
}
```
- `fs::recursive_directory_iterator`: Recursively lists all files.

---

## **6. File Operations**
### **Copying a File**
```cpp
fs::copy("source.txt", "destination.txt", fs::copy_options::overwrite_existing);
```
- Copies `source.txt` to `destination.txt`, replacing if it exists.

### **Renaming or Moving a File**
```cpp
fs::rename("old_name.txt", "new_name.txt");
```
- Renames (or moves) a file.

---

## **7. File Metadata**
### **Getting File Size**
```cpp
fs::path p = "example.txt";

if (fs::exists(p) && fs::is_regular_file(p)) {
    std::cout << "Size: " << fs::file_size(p) << " bytes\n";
}
```
- `fs::file_size(p)`: Returns file size in bytes.


## **8. Permissions**
### **Checking File Permissions**
```cpp
fs::perms p = fs::status("example.txt").permissions();

if ((p & fs::perms::owner_write) != fs::perms::none) {
    std::cout << "Writable by owner.\n";
}
```
- Checks if the owner has write permission.

### **Modifying File Permissions**
```cpp
fs::permissions("example.txt", fs::perms::owner_write, fs::perm_options::remove);
```
- Removes write permission for the owner.

---

## **9. Temporary Files and System Paths**
### **Getting the Current Working Directory**
```cpp
std::cout << "Current path: " << fs::current_path() << "\n";
```
- Returns the current working directory.

### **Getting a Temporary Directory Path**
```cpp
std::cout << "Temp directory: " << fs::temp_directory_path() << "\n";
```
- Returns the system temporary directory path.

---

# **Summary**
| Functionality  | Description |
|--------------|-------------|
| `fs::path` | Represents file/directory paths |
| `fs::exists(p)` | Checks if a path exists |
| `fs::is_regular_file(p)` | Checks if it's a file |
| `fs::is_directory(p)` | Checks if it's a directory |
| `fs::create_directory(p)` | Creates a directory |
| `fs::remove(p)` | Deletes a file or empty directory |
| `fs::remove_all(p)` | Deletes a directory and all contents |
| `fs::copy(src, dest)` | Copies a file |
| `fs::rename(old, new)` | Renames or moves a file |
| `fs::directory_iterator(p)` | Iterates over a directory |
| `fs::recursive_directory_iterator(p)` | Recursively iterates over directories |
| `fs::file_size(p)` | Gets file size in bytes |
| `fs::last_write_time(p)` | Gets last modification time |
| `fs::permissions(p, perms, options)` | Modifies file permissions |
| `fs::current_path()` | Gets current working directory |
| `fs::temp_directory_path()` | Gets system temp directory |
