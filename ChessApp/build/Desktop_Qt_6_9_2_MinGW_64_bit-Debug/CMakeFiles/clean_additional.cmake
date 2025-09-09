# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ChessApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ChessApp_autogen.dir\\ParseCache.txt"
  "ChessApp_autogen"
  )
endif()
