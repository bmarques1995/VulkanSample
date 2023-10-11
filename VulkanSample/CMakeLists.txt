# CMakeList.txt: projeto de CMake para VulkanSample, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
add_executable (VulkanSample "VulkanSample.cpp" "VulkanSample.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanSample PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
