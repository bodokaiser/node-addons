cmd_Release/number.node := ./gyp-mac-tool flock ./Release/linker.lock c++ -shared -Wl,-search_paths_first -mmacosx-version-min=10.5 -arch x86_64 -L./Release -install_name @rpath/number.node  -o Release/number.node Release/obj.target/number/src/number.o -undefined dynamic_lookup