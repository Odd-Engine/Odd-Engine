project('main', 'cpp',
  version : '0.1',
  default_options : [
      'warning_level=3',
      'cpp_std=c++14'
    ])
add_global_arguments('-DLOG_LEVEL=1', language : 'cpp')

r = run_command('python', 'scripts/install_wraps.py')
if r.returncode() != 0
  exit
endif

subdir('utilities')
subdir('graphics')

dependency('sfml')

util_includes = include_directories('utilities/include')
graphics_includes = include_directories('graphics/include')
root_includes = include_directories('.')

main = executable('main',
           'main.cpp',
           include_directories : [util_includes, graphics_includes, root_includes],
           link_with : [utillib, graphicslib],
           install : true)

test('main test', main)