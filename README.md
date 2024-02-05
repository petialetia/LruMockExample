# C++ template project

Simple c++ project, created as a template for others, more serious projects

## How to use:

* Create an empty c++ project local repository
* `git remote add template https://github.com/petialetia/CppTemplateProject.git`
* `git remote set-url --push template DISABLE`
* `git fetch template`
* `git rebase template/master`

## Detailed description:

Let's start with folders:

* include - .hpp project files
* src - .cpp project files and CMakeLists.txt file to set up building of the project
* tests - files for tests and CMakeLists.txt file to set up building of the tests

There are also 3 scripts:

* requirements_ubuntu.sh - installation of all requirements for Ubuntu platform
* build.sh - building script. By default, builds project, but can build any test case if you provide it name as an argument, example: `./build.sh HelloWorldTests`. Also has `--debug` flag if you want to use sanitizers.
* run.sh - same as build.sh, but it also runs compilation result. All arguments pass to the build.sh, so you can use flag `--debug` or specify target.

[comment]: # TODO: write your own README
