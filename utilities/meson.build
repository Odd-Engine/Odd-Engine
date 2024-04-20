inc = include_directories('include')

subdir('include')
subdir('src')

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : utillib,
                 version : '1.0',
                 name : 'libutils',
                 filebase : 'utils',
                 description : 'Utility library')