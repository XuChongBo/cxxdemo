import os
import sys
from pyplusplus import module_builder

mb = module_builder.module_builder_t( files=['chg.h'] ,gccxml_path='/usr/local/bin/gccxml')
mb.build_code_creator( module_name='libchg_py' )

mb.code_creator.user_defined_directories.append( os.path.abspath('.') )

mb.write_module( os.path.join( os.path.abspath('.'), 'chg_py.cc' ) )
