project('main', 'cpp',
  version : '0.1',
  default_options : [
      'warning_level=3',
      'cpp_std=c++14'
    ])
#add_global_arguments('-DLOG_LEVEL=1', language : 'cpp')

subdir('utilities')
includes = include_directories('utilities/include')

main = executable('main',
           'main.cpp',
           include_directories : includes,
           link_with : utillib,
           install : true)

test('main test', main)