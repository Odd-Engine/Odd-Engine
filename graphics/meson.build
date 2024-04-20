graphics_includes = [include_directories('include'), include_directories('..')]

subdir('include')
subdir('src')

pkg_mod.generate(libraries : graphicslib,
                 version : '1.0',
                 name : 'libgraphics',
                 filebase : 'graphics',
                 description : 'Graphics library')