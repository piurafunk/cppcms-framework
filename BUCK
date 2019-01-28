remote_file(
    name = 'cppcms-src',
    url = 'https://github.com/artyom-beilis/cppcms/archive/v1.2.1.zip',
    sha1 = 'b08f2b4e3282fe7af19d1ea698ffbda424dcbcab',
    type = 'exploded_zip',
)

genrule(
    name = 'cppcms-build',
    cmd = 'mkdir -p $(location :cppcms-src)/cppcms-1.2.1/build && \
           cd $(location :cppcms-src)/cppcms-1.2.1/build && \
           sed -i \'s/^enable_testing()$/#enable_testing()/\' ../CMakeLists.txt ../booster/CMakeLists.txt && \
           cmake -DCMAKE_INSTALL_PREFIX=out .. && \
           make -j \$(nproc) && \
           make install && \
           mkdir -p /src/thirdparty/{lib,include} && rm -rf /src/thirdparty/cppcms && \
           cp -r out /src/thirdparty/cppcms && \
           ln -s /src/thirdparty/cppcms/lib/* /src/thirdparty/lib/',
    out = '.',
)

prebuilt_cxx_library(
    name = 'booster',
    shared_lib = 'thirdparty/cppcms/lib/libbooster.so',
    static_lib = 'thirdparty/cppcms/lib/libbooster.a',
    header_dirs = ['thirdparty/cppcms/include'],
    exported_linker_flags = ['-Lthirdparty/cppcms/lib', '-lbooster']
)

prebuilt_cxx_library(
    name = 'cppcms',
    shared_lib = 'thirdparty/cppcms/lib/libcppcms.so',
    static_lib = 'thirdparty/cppcms/lib/libcppcms.a',
    header_dirs = ['thirdparty/cppcms/include'],
    exported_linker_flags = ['-Lthirdparty/cppcms/lib', '-lcppcms']
)

cxx_binary(
    name = 'dev',
    srcs = glob([
        './src/**/*.cpp',
    ]),
    deps = [
        '//:cppcms', '//:booster',
    ],
    link_style = 'static',
)
