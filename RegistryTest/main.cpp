
#include <iostream>

#include "SubSuperIterators.h"
#include <STEPfile.h>
#include <sdai.h>
#include <STEPattribute.h>
#include <ExpDict.h>
#include <Registry.h>
#include <errordesc.h>
#include <Registry.h>

#include <STEPcomplex.h>
#include <SdaiHeaderSchema.h>

#include "schema.h"

//#include <SdaiCONFIG_CONTROL_DESIGN.h>

int main(int, char **)
{

     {
        {

            // The registry contains information about types present in the current schema; SchemaInit is a function in the schema-specific SDAI library
            Registry *registry = new Registry(SchemaInit);

            const EntityDescriptor * ed = registry->FindEntity( "geometric_representation_item" );
            std::string express;
            std::cout << ed->GenerateExpress(express)  << std::endl;

            std::cout << "*** Super Types ***" << std::endl;
            supertypesIterator iter_super(ed);
            const EntityDescriptorList& supertypes = ed->Supertypes();
            for ( ; !iter_super.empty(); iter_super++ ) {
                std::cout << iter_super.current()->GenerateExpress(express)  << std::endl;
            }

            std::cout << "*** Sub Types ***" << std::endl;
            subtypesIterator iter_sub(ed);
            const EntityDescriptorList& subtypes = ed->Subtypes();
            for( ; !iter_sub.empty(); iter_sub++) {
                std::cout << iter_sub.current()->GenerateExpress(express)  << std::endl;
            }

            delete registry;
        }


    }


    return 0;
}
