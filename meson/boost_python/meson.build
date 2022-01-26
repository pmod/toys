project('test', 'cpp', version : '0.0.1', default_options : ['c_args= -g'])

# note that we need python3-embed.pc, not python3.pc:
# $ pkg-config --libs python3
#
# $ pkg-config --libs python3-embed
# -lpython3.8
python_dep = dependency('python3-embed')
boost_dep = dependency('boost',modules: ['python3'])

src = ['./test.cpp']

lib = shared_library('hello_ext',
            src,
            dependencies : [ python_dep, boost_dep],
            # module must have name hello_ext.so to be found by python3
            name_prefix : '')
