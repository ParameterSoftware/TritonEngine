The Triton Engine
=============

##Description

The goal is to create an open-source cross-platform game engine which is written in modules, most of which only require the util module.

##Plans

- NEW: 2D/3D Graphical Engine using OpenGL
- NEW: 2D/3D Audio Engine
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

##Contrbution Guidelines

You are asked to use camelCase for variables in type declarations

Name variables, functions, function pointers, classes, and namespaces appropriately

Try to keep functions and datatype declarations in namespaces, if reason does not permit namespace use: 

- All functions that are planned to be independent of a namespace must be labelled as tri<Function Name> (must have "tri" prefix)
- All classes that are planned to be independent of a namespace must be labelled as TRI<Class Name> (must have "TRI" prefix)

If you must create a new namespace, this new namespace must be Triton::<Namespace Name> (must be in "Triton" namespace)

Use the tabs indent mode and 8 indent size

Do not name items longer then 25 alphanumeric characters (abbreviate if you must)

##Warning

This is not complete, do not expect this to work yet.
