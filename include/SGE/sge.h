#ifndef __SGE__
#define __SGE__

// Includes
#include <GLFW/glfw3.h> /* GLFW */
#include <iostream>
#define _USE_MATH_DEFINES /* math.h allowance of constant math defines like PI = 3.141 ect. */
#include <math.h>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <stdbool.h>
#include "pack.h"
// End of Includes

//SE Utilities
namespace seu
{
	//Portable Datatypes
	/// Portable Character Datatype
	typedef int16_t		SEchar; 
	/// Portable Integer Datatype
	typedef int16_t		SEint; 
	/// Portable Unsigned Integer Datatype
	typedef uint16_t	SEuint; 
	/// Portable Long Datatype
	typedef int32_t		SElong; 
	/// Portable Unsigned Long Datatype
	typedef uint32_t	SEulong;
	/// Portable Float Datatype
	typedef int32_t 	SEfloat; 
	/// Portable Double Datatype
	typedef int64_t 	SEdouble; 
	/// Portable Boolean Datatype
	typedef _Bool		SEbool; 
	//End of Portable Datatypes

	/**
	 *	A Portable way to convert a C standard datatype to platform-independent datatype 
	 *
	 *	@param pack The C standard datatype
	 *
	 *	@return The independent datatype equal to the C standard datatype
	 */
	uint64_t packInteger(long double pack); 
	/**
	 *	A Portable way to convert a platform-independent datatype to C standard datatype
	 *
	 *	@param unpack The independent datatype
	 *
	 *	@return The C standard integer(any numerical datatype) equal to the packed orignal datatype
	 */
	long double unpackInteger(uint64_t unpack);
	
	///An exception class for the SpartanEngine
	class Exception: public std::exception
	{
	public:
		/**
		 *  The constructor of Exception
		 *
		 *  @param msg The message the Exception is returning
		 */
		Exception(const char* msg);

		/**
		 *  The deconstructor of Exception
		 */
		~Exception();

		/**
		 *  Gets the message the Exception is holding
		 *
		 *  @return The message the exception is holding
		 */
		virtual const char* what() const;

		/**
		 *  Gets the message the Exception is holding
		 *
		 *  @return The message the exception is holding
		 */
		virtual std::string getMessage() const;
		std::string operator <<(std::string all);
		std::string operator <<(const char* all);
	private:
		std::string msg_;///<Message this Exception is holding
	};
}
//End of SE Utilities

//SE Math
namespace sem
{
	/**
	 *	Generates a random number
	 *	
	 *	Generates a random numbers using the standard c++ number generator
	 *	with srand handled by the function
	 *
	 *	@param lowerRange	The lowest possible number for the generator
	 *	@param higherRange	The highest possible number for the generator
	 *
	 *	@return A random number between lowerRange and higherRange
	 */
	seu::SEfloat random(seu::SEfloat lowerRange, seu::SEfloat higherRange);

	/**
	 *	Gets PI
	 *
	 *	@return PI
	 */
	seu::SEdouble PI();

	/**
	 *	Calculates the Distance between two points
	 *	
	 *	Calculates the Distance between two 3D points using 
	 *	Spartan Engine Vectors
	 *
	 *	@param point1	The start point 
	 *	@param point2	The end point
	 *
	 *	@return The Vector difference
	 */
	seu::Vector distance(seu::Vector point1, seu::Vector point2);

	/**
	 *	Converts Radians to Degrees
	 *
	 *	@param radian	The radian to convert
	 *
	 *	@return The degree of radian
	 */
	seu::SEfloat toDegrees(seu::SEfloat radian);

	/**
	 *	Converts Degrees to Radians
	 *
	 *	@param degree	The degree to convert
	 *
	 *	@return The radian of degree
	 */
	seu::SEfloat toRadians(seu::SEfloat degree);

	/**
	 *	Provides the fraction of time
	 *
	 *	Provides the fraction of time based on
	 *	current
	 *
	 *	@param start	The start of the time
	 *	@param end		The end of the time
	 *	@param current	The current time to divide turn into a fraction
	 *
	 *	@return The fraction of time
	 */
	seu::SEfloat fractionTime(seu::SEfloat start, seu::SEfloat end, seu::SEfloat current);

	/**
	 *	Gets the square root of square
	 *
	 *	Gets the square root of square but is much more accurate and
	 *	faster then the standard library
	 *
	 *	@param square	The number to find the square root of
	 *
	 *	@return The square root of square
	 */
	seu::SEfloat sqrt(seu::SEfloat square);

	/**
	 *
	 *	Gets the sin of x
	 *
	 *	Gets the sine of x in radians unless convert
	 *	is true
	 *	
	 *	@param x		The number to get the sin of
	 *	@param convert	Use to get a degree instead	Default: false
	 *	
	 *	@return	The sin of x (in radians unless convert = true)
	 *
	*/
	seu::SEfloat sin(seu::SEfloat x, seu::SEbool convert = false);

	/**
	 *
	 *	Gets the cos of x
	 *
	 *	Gets the cosine of x in radians unless convert
	 *	is true
	 *	
	 *	@param x		The number to get the cos of
	 *	@param convert	Use to get a degree instead	Default: false
	 *	
	 *	@return	The cos of x (in radians unless convert = true)
	 *
	*/
	seu::SEfloat cos(seu::SEfloat x, seu::SEbool convert = false);

	/**
	 *
	 *	Gets the tan of x
	 *
	 *	Gets the tangent of x in radians unless convert
	 *	is true
	 *	
	 *	@param x		The number to get the tan of
	 *	@param convert	Use to get a degree instead	Default: false
	 *	
	 *	@return	The tan of x (in radians unless convert = true)
	 *
	*/
	seu::SEfloat tan(seu::SEfloat x, seu::SEbool convert = false);
}
//End of SE Math

//SE Physics
namespace sep
{
	/**
	 *	The active Physics Properties that an object can have
	 */
	class PhysicsProperties
	{
	public:
		/**
		 *	The constructor for PhysicsProperties
		 *
		 *	@param gravity		Whether gravity is enabled for this object Default: true
		 *	@param collision	Whether collisions are active in this object Default: true
		 *	@param rigidBody	Whether an object has rigid body transformations (like rotating down a hill as a sphere) Default: true
		 *	@param otherPhysics	Whether an alternate act of physics is taken into account Deafult: true
		 **/
		PhysicsProperties(seu::SEbool gravity = true, seu::SEbool collision = true, seu::SEbool rigidBody = true, seu::SEbool otherPhysics = true);
		
		/**
		 *	The destructor for PhysicProperties
		 **/
		~PhysicsProperties();

		/**
		 *	Toggles whether gravity is active or not
		 *
		 *	@return Whether gravity is currently enabled
		 **/
		seu::SEbool ToggleGravity();

		/**
		 *	Toggles whether collision detection is active 
		 *	
		 *	@return Whether collisions are currently active
		 **/
		seu::SEbool ToggleCollision();

		/**
		 *	Toggles whether Rigid Body transformations are possible
		 *	
		 *	@return Whether rigid bodies for this object are active
		 **/
		seu::SEbool ToggleRigidBody();

		/**
		 *	Toggles whether physics are possible for this object
		 *	
		 *	@return Whether physics for this object are active
		 **/
		seu::SEbool TogglePhysics();

		/**
		 *	Toggles whether alternate non-describe physics are possible
		 *	
		 *	@return Whether alternate non-describe physics for this object are active
		 **/
		seu::SEbool ToggleAlternatePhysics();

		/**
		 *	Returns whether gravity is enabled or not
		 *	
		 *	@return If gravity is active for this object
		 **/
		seu::SEbool HasGravity();

		/**
		 *	Returns whether collisions are enabled or not
		 *	
		 *	@return If collisions are active for this object
		 **/
		seu::SEbool HasCollision();

		/**
		 *	Returns whether rigid body transformations are enabled or not
		 *	
		 *	@return If rigid body transformations are active for this object
		 **/
		seu::SEbool HasRigidBody();

		/**
		 *	Returns whether alternate nondescribe physics are enabled or not
		 *	
		 *	@return If alternate nondescribe physics are active for this object
		 **/
		seu::SEbool UsesAlternatePhysics();
	private:
		seu::SEbool gravity;///<Boolean of enabled gravity
		seu::SEbool collision;///<Boolean of enabled collision
		seu::SEbool rigidBody;///<Boolean of enabled rigid body physics
		seu::SEbool otherPhysics;///<Boolean of alternate enabled physics
	};

	/**
	 *  The physic holder for entities
	 *
	 **/
	class PhysicsState
	{
	public:
		/**
		 *  The constructor of PhysicsState
		 *
		 *  @param position The position this state holds for its object
		 *  @param rotation The rotation(recommended in degrees) this state holds for its object
		 *  @param velocity The velocity this state holds for its object (increases the position according to its states)
		 *  @param acceleration The acceleration this state holds for it object (increases the velocity according to it state)
		 *	@param pProps The PhysicsState current physical properties to apply to this object
		 */
		PhysicsState(seu::Vector position = seu::Vector(), seu::Vector rotation = seu::Vector(), seu::Vector velocity = seu::Vector(), seu::Vector acceleration = seu::Vector(), PhysicsProperties pProps = PhysicsProperties());

		/**
		 *  The deconstructor of PhysicsState
		 */
		~PhysicsState();

		seu::Vector position; ///< The States' current position
		seu::Vector rotation; ///< The States' current rotation
		seu::Vector velocity; ///< The States' current velocity
		seu::Vector acceleration; ///< The States' current acceleration
		PhysicsProperties physicsProps; ///< The properties for this physics state
	};

	class PhysicsEntity
	{
	public:
		/**
		 *  The constructor of PhysicsEntity
		 *
		 *  @param state The PhysicsState that represents this entity
		 */
		PhysicsEntity(PhysicsState state);

		/**
		 *  The deconstructor of PhysicsEntity
		 */
		~PhysicsEntity();

		/**
		 *  The function that updates the this PhysicsEntity
		 */
		void Update();
		PhysicsState pState; ///< The PhysicsState that represents this entity
	};
	
	class Gravity
	{
	public:
		/**
		 *  The constructor of Gravity
		 *
		 *  @param gravity The 3D gravity strength in certains direction that effects all gravity enabled objects
		 */
		Gravity(seu::Vector gravity);

		/**
		 *  The deconstructor of Gravity
		 */
		~Gravity();

		/**
		 *  Gets the current gravity
		 *
		 *  @return The objects current gravity strength
		 */
		virtual seu::Vector GetGravity();
	private:
		seu::Vector gravity;///<Gravities Directions
	};

	class Gravity3D
	{
	public:
		/**
		 *  The constructor of Gravity3D
		 *
		 *  @param grav_strength The strength of the gravitational pull
		 *  @param grav_location The location that this gravity is pulling towards
		 */
		Gravity3D(seu::Vector grav_location);

		/**
		 *  The deconstructor of Gravity3D
		 */
		~Gravity3D();

		/**
		 *  Gets the location of gravity
		 *
		 *  @return The location of the gravity
		 */
		seu::Vector GetLocation();

		/**
		 *  Gets the strength of the gravity
		 *
		 *  @return The strength of gravity
		 */
		seu::Vector GetGravity();
	private:
		seu::Vector grav_location;///<Location of this Gravity
		seu::Vector grav_strength;///<Strength of this Gravity
	};
	
	
}
//End of SE Physics

//SE Graphics
namespace seg
{
	struct Vertex
	{
		seu::Vector vertex;///<Vertex Location
		seu::Vector normal;///<Vertex Normal
		///Vertex Texturing
		seu::SEfloat s0, t0;///<Vertex Texturing
	};

	struct Triangle
	{
		Vertex a;///<First Vertex of this Triangle
		Vertex b;///<Second Vertex of this Triangle
		Vertex c;///<Third Vertex of this Triangle
		unsigned short index[3];///<Indexes for the this Triangle
	};

	struct TriangleVector
	{
		std::vector<Triangle> triangles;
	};

	class VBO
	{
	public:
		VBO(TriangleVector holder);
		~VBO();
		void Render();
	private:
		unsigned int vaoID[1];
		unsigned int vboID[1];
	};

	class Object
	{
	public:
		Object(seu::Vector position);
		virtual seu::SEbool Start();
		virtual void Update();
		virtual void Stop();
		void SetPosition(seu::Vector pos);
		seu::Vector GetPosition();
	private:
		seu::Vector position;
		virtual void UpdateGraphics();
	};

	class FlatObject ///Simple Flatly Rendered Object
	{
	public:
		FlatObject(seu::DDVector position, seu::SEfloat scale = 1.0);
		virtual seu::SEbool Start();
		virtual void Update();
		virtual void Stop();
		void SetPosition(seu::DDVector pos);
		seu::DDVector GetPosition();
		void SetScale(seu::SEfloat scale = 1.0);
		float GetScale();
	private:
		seu::DDVector position;
		seu::SEfloat scale;
		virtual void UpdateGraphics();
	};
}
//End of SE Graphics





#endif /* defined(__SGE__) */