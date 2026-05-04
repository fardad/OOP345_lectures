
### Opening Modes Reference

| Mode          | Description |
|---------------|-------------|
| `ios::in`    | Open for input (reading); file must exist for `ifstream`/`fstream`. |
| `ios::out`   | Open for output (writing); creates file if needed, truncates if exists. |
| `ios::app`   | Append: All writes go to end of file. |
| `ios::trunc` | Truncate file to zero length on open (default for `out`). |
| `ios::ate`   | Start I/O at end after open (but writes can be anywhere). |
| `ios::binary`| Treat as binary: No text conversions (e.g., no `\r\n` on Windows). |

### Common Mode Combinations and Purposes

| Modes                          | Purpose/Example Use Case | Edge Cases (File Exists / Doesn't) |
|--------------------------------|--------------------------|------------------------------------|
| `ios::in`                     | Read from existing file (e.g., load config with `ifstream`). | Exists: Opens for read. / Doesn't: Fails to open (failbit set). |
| `ios::out`                    | Create/overwrite file for writing (e.g., save report with `ofstream`). | Exists: Truncates and opens. / Doesn't: Creates empty file. |
| `ios::app`                    | Append to log file (e.g., add entries without losing old data). | Exists: Opens and seeks to end. / Doesn't: Creates and appends from start. |
| `ios::in \| ios::out`         | Bidirectional access (e.g., edit database file with `fstream`). | Exists: Opens for read/write from start. / Doesn't: Fails unless `out` implied (creates). |
| `ios::binary`                 | Handle raw bytes (e.g., read/write images or structs). | Exists/Doesn't: Same as base mode; no text conversions applied. |
| `ios::out \| ios::trunc`      | Standard write (default for `ofstream`; overwrites file). | Exists: Truncates to empty. / Doesn't: Creates empty file. |
| `ios::in \| ios::out \| ios::trunc` | Bidirectional with overwrite (e.g., reset and edit with `fstream`). | Exists: Truncates then opens for read/write. / Doesn't: Creates empty file for read/write. |
| `ios::in \| ios::out \| ios::app` | Bidirectional append (e.g., read then append with `fstream`). | Exists: Opens for read from start, writes append to end. / Doesn't: Creates, read fails until write (empty), writes append. |

---
