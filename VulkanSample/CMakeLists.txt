# CMakeList.txt: projeto de CMake para VulkanSample, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
set(EXEC_NAME VulkanSample)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX})

find_package(VulkanHeaders CONFIG REQUIRED)
find_package(VulkanLoader CONFIG REQUIRED)
find_package(VulkanUtilityLibraries CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(TP_LIBS Vulkan::Loader Vulkan::LayerSettings glfw)
set(OS_LIBS dxCompiler)


if(WIN32)
  set(OS_LIBS ${OS_LIBS})
elseif(UNIX AND APPLE)
  set(OS_LIBS ${OS_LIBS})
elseif(UNIX AND NOT APPLE)
  set(OS_LIBS ${OS_LIBS})
endif()

list(LENGTH OS_LIBS LIST_COUNT)

if(NOT (${LIST_COUNT} EQUAL 0))
  find_library(OS_TARGET NAMES ${OS_LIBS} REQUIRED)
endif()

add_executable (${EXEC_NAME} "VulkanSample.cpp" "VulkanSample.h" "SpvCompiler.h" "SpvCompiler.cpp" "Window.h" "Window.cpp")
target_include_directories(${EXEC_NAME} PRIVATE "${CMAKE_INSTALL_PREFIX}/include")
target_link_directories(${EXEC_NAME} PRIVATE ${CMAKE_PREFIX_PATH}/lib)
target_link_libraries(${EXEC_NAME} PRIVATE ${TP_LIBS} ${OS_LIBS})

install(TARGETS ${EXEC_NAME}
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")

set_target_properties(${EXEC_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${EXEC_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${EXEC_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${EXEC_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanSample PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
