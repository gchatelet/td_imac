add_library(force Force.hpp Gravity.hpp Gravity.cpp Explode.hpp Explode.cpp Composite.hpp Composite.cpp)
target_link_libraries(force point2d)