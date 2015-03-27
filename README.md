The LEAK Game Engine
=============

##Description

The main goal of this project is to create a game engine that is open source, both advanced and easy to use and free. If you would like to help, please follow the guidelines below.

##Plans

- NEW: 2D/3D Graphical Engine using OpenGL
- NEW: 2D/3D Audio Engine using CLAM
- NEW: 3D Simplified Physics Engine
- NEW: Radio Multi-Purpose Library
	- Plugin System: addon to features already in the library, engine, or game
	- Mod System: creating new features for the engine or a specific game
	- Entity Handler: handles AI enabled objects, creatures, or characters
	- File Package System: packages game content and reads game content
	- libxml: XML Reading
	- DevIL: Image IO
	- Assimp: Model IO
	- TinyThread++: cross-platform multi-threading
	- GLM: OpenGL's Math Library
	- GLEW: extending OpenGL Functions further
	- Lua: script support for easy game and mod creation - planned for later
	- Asio: basic cross-platform networking - planned for later
	- (possibly) CrystalHD: Windows and Linux Video

##Contrbution Guidelines

You are asked to use camelCase for variables in type declarations

Name variables, functions, function pointers, classes, and (if necessary) namespaces appropriately

Try to keep functions and datatype declarations in namespaces, if reason does not permit namespace use: 

- All functions that are planned to be independent of a namespace must be labelled as leak<Function Name> (must have "leak" prefix)
- All classes that are planned to be independent of a namespace must be labelled as LEAK<Class Name> (must have "LEAK" prefix)

If you must create a new namespace, this new namespace must be Leak::<Namespace Name> (must be in "Leak" namespace)

Use the tabs indent mode and 8 indent size

Do not name items longer then 25 alphanumeric characters (abbreviate if you must)

##Warning

This is not complete, do not expect to work yet. When version 0.1.0 is said finished in the issues then it will be ready for basic use. Expect things like tests and examples. Do not expect optimization until at least version 0.3.0.

##Planned Projects

After Inheritance - An RPG based on the Inheritance Cycle 
