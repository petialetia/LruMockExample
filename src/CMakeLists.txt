#TODO: change to your building instructions

add_library(HelloWorld STATIC HelloWorld.cpp)

add_executable(TemplateProject TemplateProject.cpp)
target_link_libraries(TemplateProject HelloWorld)
