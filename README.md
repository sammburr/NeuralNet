### Current State

- *05/05/23*

  **X11Engine** taking shape, can hover over one of 9 squares, which will act as an interface for neurons in the future,
  Current *TODO*; implement double buffering.

# X11Engine
For easier implementation of an X11 GUI.

Creating the object.
---
```
X11Engine(
  const char* windowTitle,
  const char* shortWindowTitle,
  unsigned long borderColor,
  unsigned long backgroundColor)
```
Closing the application.
---
When closing an application, calling `delete(engine)` will free system reasources.


Updating the application.
---
```
void pollEvents()
```
Usually called every application tick.

Updates the public field `event` and public struct `windowAttributes` which is of struct `XWindowAttributes`.
