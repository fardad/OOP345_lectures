## Compilation Pipeline (Diagram)

```
 Source Code (.cpp + .h)
            │
            ▼
   ┌───────────────────┐
   │   Preprocessor    │
   │ - expands #include│
   │ - replaces macros │
   └───────────────────┘
            │
            ▼
  Translation Unit (.i)
            │
            ▼
   ┌───────────────────┐
   │     Compiler      │
   │ - syntax checks   │
   │ - type checking   │
   │ - produces object │
   └───────────────────┘
            │
            ▼
    Object File (.o/.obj)
            │
            ▼
   ┌───────────────────┐
   │      Linker       │
   │ - combines objs   │
   │ - links libraries │
   │ - resolves symbols│
   └───────────────────┘
            │
            ▼
   Executable Program (.exe / a.out)
            │
            ▼
   ┌───────────────────┐
   │      Loader       │
   │ - loads into RAM  │
   │ - sets up stack   │
   │ - jumps to main() │
   └───────────────────┘
```
