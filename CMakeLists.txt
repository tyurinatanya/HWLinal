cmake_minimum_required (VERSION 3.8)
set (PROJECT Linal) 
 
project (${PROJECT}) 
set (SOURCES 
	Vector.cpp
	Matrix3.cpp
	main.cpp)

add_executable (${PROJECT} ${SOURCES})
