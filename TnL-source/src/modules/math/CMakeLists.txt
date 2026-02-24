set(LIBNAME math)

set(${LIBNAME}_SOURCES
	Ballistic.cc
	Collide.cc
	Feedback.cc
	Interval.cc
	Line.cc
	Polynomial.cc
	Rendezvous.cc
	Solve.cc
	Vector.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	${SIGCPP_INCLUDE_DIRS}
	/usr/include/SDL3
)

