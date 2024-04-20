sources = run_command('python', 'file_globber.py')
utils_sources = sources.stdout().strip().split('\n')

utillib = static_library('utils',
                         utils_sources,
                         include_directories : util_includes,
                         install : true)