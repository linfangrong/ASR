import os

compiler = 'g++'

# g++ flags
cpp_flags = ['-fPIC', '-O3', '-std=c++11', '-Wall', '-Werror', '-DMKL_ILP64', '-m64']

mkl_root = '/opt/intel/mkl/lib'

mkl_link_line = [File(mkl_root + '/libmkl_intel_ilp64.a'),
				 File(mkl_root + '/libmkl_sequential.a'),
				 File(mkl_root + '/libmkl_core.a'),
				 '-lpthread', '-lm', '-ldl']

include_paths = [
    '#src',
    '/usr/local/include',
    '/opt/intel/mkl/include'
]

lib_paths = [
    '/usr/lib',
    '/usr/local/lib',
	mkl_root
]

env = Environment(CPPFLAGS=cpp_flags,
                  CPPPATH=include_paths,
                  LIBPATH=lib_paths,
                  LIBS=mkl_link_line)

def UnitTestRunner(env, target, source):
    import subprocess
    import sys
    app = str(source[0].abspath)
    out = subprocess.Popen([app, '/c', '--gtest_color=yes'], stdout=subprocess.PIPE)
    output = out.communicate()[0]
    exit_code = out.wait()

    if out.returncode != 0:
        print(output)
        sys.exit(0)
unitTestRunner = UnitTestRunner
Export('unitTestRunner')
Export('env')

SConscript('src/math/SConscript', variant_dir='build/src/math')
SConscript('src/neural_networks/SConscript', variant_dir='build/src/neural_networks')
SConscript('src/system/SConscript', variant_dir='build/src/system')
SConscript('src/util/SConscript', variant_dir='build/src/util')
SConscript('test/math/SConscript', variant_dir='build/test/math')
SConscript('test/system/SConscript', variant_dir='build/test/system')
SConscript('test/util/SConscript', variant_dir='build/test/util')