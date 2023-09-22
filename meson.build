project('libutils', 'cpp', version: 'master')

include = include_directories('include')

libutils = library('libutils', [
    'src/utils/strings.cc'
  ], include_directories: include)

main = executable('main.exe', [
    'src/main.cc',
  ], include_directories : include,
  link_with: libutils)

libutils_dep = declare_dependency(
  include_directories : include,
  link_with : libutils)
