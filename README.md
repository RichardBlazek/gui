# README #

This is an extension of [objsdl](https://bitbucket.org/risa2/objsdl) with some widgets for building GUIs.

### Widgets ###

* Label-Text label
* CentredLabel-Text label with centred text
* Button-Button
* TextInputBox-Box for text input

### Dialog ###
* Very simple
```c
std::vector<std::string> result=gui::Dialog("Login", {{"Enter name ", false}, {"Enter password ", true}}, "Confirm", 120);
```

### How do I get set up? ###

* Simply include gui.h file
```c
#include "gui.h"
```
