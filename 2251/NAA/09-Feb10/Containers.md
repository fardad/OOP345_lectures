### **Summary of Containers**

| **Container** | **Best For**                          | **Avoid When**                            |
|---------------|---------------------------------------|-------------------------------------------|
| `vector`      | Fast access and sequential data.      | Frequent insertions/removals in the middle.|
| `list`        | Frequent insertions/removals.         | Random access is needed.                  |
| `deque`       | Insert/remove at both ends.           | Memory efficiency is critical.            |
| `set`         | Unique, sorted data.                  | Duplicates are required.                  |
| `map`         | Key-value storage with fast lookups.  | Data without keys.                        |
