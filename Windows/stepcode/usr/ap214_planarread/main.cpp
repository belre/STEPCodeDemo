#include <stdio.h>
#include <stdlib.h>

#include <regex>
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
EntityDescriptor* automotive_design::e_axis2_placement_2d = 0;
EntityDescriptor* automotive_design::e_axis2_placement_3d = 0;

int main(int, char**)
{
    {
        {

            // The registry contains information about types present in the current schema; SchemaInit is a function in the schema-specific SDAI library
            Registry* registry = new Registry(SchemaInit);

            // The InstMgr holds instances that have been created or that have been loaded from a file
            InstMgr* instance_list = new InstMgr();

            // Increment FileId so entities start at #1 instead of #0.
            instance_list->NextFileId();

            // STEPfile takes care of reading and writing Part 21 files
            STEPfile* sfile = new STEPfile(*registry, *instance_list, "D:\\StepData\\BSP35B20-N-12.stp", false);
            //sfile->ReadExchangeFile("/home/okui/stepcode/data/ap214e3/dm1-id-214.stp");
            //sfile->ReadExchangeFile("/home/okui/stepcode/usr/ReadTest/usrdata/" + path);

            return 0;

            for (int i = 0; i < instance_list->InstanceCount(); i++) {
                SDAI_Application_instance* inst = instance_list->GetSTEPentity(i);
                std::cout << dec << i + 1 << std::endl;

                string express;
                const EntityDescriptor* tar_dsc = inst->getEDesc();
                std::cout << tar_dsc->QualifiedName(express) << std::endl;

                STEPattributeList attrlist = inst->attributes;

                const AttrDescriptorList& tar_dsc_attr = tar_dsc->ExplicitAttr();
                AttrDescLinkNode* tar_dsc_attr_node_head = dynamic_cast<AttrDescLinkNode*>(tar_dsc_attr.GetHead());
                if (tar_dsc_attr_node_head != NULL) {

                    int entrycount = attrlist.EntryCount();
                    for (int pos = 0; pos < entrycount; pos++) {
                        std::cout << attrlist[pos].Name() << ",";
                        std::cout << hex << attrlist[pos].NonRefType() << ",";
                        PrimitiveType nonreftype = attrlist[pos].NonRefType();

                        if (nonreftype == STRING_TYPE) {
                            SDAI_String* stringobj;
                            stringobj = attrlist[pos].String();
                            std::cout << stringobj->c_str() << ",";
                        }
                        else if (nonreftype == ENTITY_TYPE) {
                            SDAI_Application_instance* instobj = attrlist[pos].Entity();
                            char express[8192];
                            const char* ptr = instobj->EntityName(express);

                            if (ptr != NULL) {
                                std::cout << ptr << ",";
                            }
                            else {
                                std::cout << "[NULL Instance]" << ",";
                            }
                        }
                        else if (nonreftype == SELECT_TYPE) {
                            SDAI_Select* selobj = attrlist[pos].Select();
                            const TypeDescriptor* seltypeptr = selobj->CurrentUnderlyingType();
                            std::cout << selobj->UnderlyingTypeName().c_str();
                            std::cout << hex << "(" << seltypeptr->NonRefType() << ") : ";

                            SdaiAxis2_placement* instobj = dynamic_cast<SdaiAxis2_placement*>(selobj);
                            if (instobj != NULL) {
                                if (instobj->CurrentUnderlyingType() == automotive_design::e_axis2_placement_2d) {
                                    SdaiAxis2_placement_2d* ptr_2d = (SdaiAxis2_placement_2d_ptr)*instobj;

                                    const SdaiDirection* ref_direction = ptr_2d->ref_direction_();
                                    const RealAggregate* ref_direction_aggr = ref_direction->direction_ratios_();

                                    if (ref_direction_aggr != NULL) {
                                        RealNode* realnode = dynamic_cast<RealNode*>(ref_direction_aggr->GetHead());
                                        for (; realnode != NULL; realnode = dynamic_cast<RealNode*>(realnode->next)) {
                                            STEPnode* org_node = dynamic_cast<STEPnode*>(realnode);
                                            if (org_node != NULL) {
                                                std::cout << org_node->asStr(express) << ",";
                                            }
                                        }
                                    }

                                    const SdaiCartesian_point* ref_cartesian = ptr_2d->location_();
                                    const RealAggregate* ref_cartesian_aggr = ref_cartesian->coordinates_();

                                    if (ref_cartesian_aggr != NULL) {
                                        RealNode* realnode = dynamic_cast<RealNode*>(ref_cartesian_aggr->GetHead());
                                        for (; realnode != NULL; realnode = dynamic_cast<RealNode*>(realnode->next)) {
                                            STEPnode* org_node = dynamic_cast<STEPnode*>(realnode);
                                            if (org_node != NULL) {
                                                std::cout << org_node->asStr(express) << ",";
                                            }
                                        }
                                    }
                                    std::cout << "[axis2_placement_2d]";
                                }
                                if (instobj->CurrentUnderlyingType() == automotive_design::e_axis2_placement_3d) {
                                    SdaiAxis2_placement_3d* ptr_3d = (SdaiAxis2_placement_3d_ptr)*instobj;

                                    const SdaiDirection* ref_direction = ptr_3d->ref_direction_();
                                    const RealAggregate* ref_direction_aggr = ref_direction->direction_ratios_();

                                    if (ref_direction_aggr != NULL) {
                                        RealNode* realnode = dynamic_cast<RealNode*>(ref_direction_aggr->GetHead());
                                        for (; realnode != NULL; realnode = dynamic_cast<RealNode*>(realnode->next)) {
                                            STEPnode* org_node = dynamic_cast<STEPnode*>(realnode);
                                            if (org_node != NULL) {
                                                std::cout << org_node->asStr(express) << ",";
                                            }
                                        }
                                    }

                                    const SdaiDirection* ref_axis = ptr_3d->axis_();
                                    const RealAggregate* ref_axis_aggr = ref_direction->direction_ratios_();

                                    if (ref_axis_aggr != NULL) {
                                        RealNode* realnode = dynamic_cast<RealNode*>(ref_axis_aggr->GetHead());
                                        for (; realnode != NULL; realnode = dynamic_cast<RealNode*>(realnode->next)) {
                                            STEPnode* org_node = dynamic_cast<STEPnode*>(realnode);
                                            if (org_node != NULL) {
                                                std::cout << org_node->asStr(express) << ",";
                                            }
                                        }
                                    }


                                    const SdaiCartesian_point* ref_cartesian = ptr_3d->location_();
                                    const RealAggregate* ref_cartesian_aggr = ref_cartesian->coordinates_();

                                    if (ref_cartesian_aggr != NULL) {
                                        RealNode* realnode = dynamic_cast<RealNode*>(ref_cartesian_aggr->GetHead());
                                        for (; realnode != NULL; realnode = dynamic_cast<RealNode*>(realnode->next)) {
                                            STEPnode* org_node = dynamic_cast<STEPnode*>(realnode);
                                            if (org_node != NULL) {
                                                std::cout << org_node->asStr(express) << ",";
                                            }
                                        }
                                    }

                                    std::cout << "[axis2_placement_3d]";
                                }
                            }

                            //istringstream in( "T" );


                            //STEPentity * temp = ReadEntityRef( in, err, ",)", instances, addFileId );

                            std::cout << "[Select],";
                        }
                        else if (nonreftype == LIST_TYPE || nonreftype == SET_TYPE || nonreftype == AGGREGATE_TYPE || nonreftype == BAG_TYPE || nonreftype == ARRAY_TYPE) {
                            STEPaggregate* aggrobj = attrlist[pos].Aggregate();

                            SingleLinkNode* node = aggrobj->GetHead();
                            string express;

                            for (; node != NULL; node = node->next) {
                                STEPnode* org_node = dynamic_cast<STEPnode*>(node);
                                if (org_node != NULL) {
                                    std::cout << org_node->asStr(express) << ",";
                                }
                            }

                            switch (nonreftype) {
                            case LIST_TYPE:
                                std::cout << "(list)";
                                break;
                            case SET_TYPE:
                                std::cout << "(set)";
                                break;
                            case AGGREGATE_TYPE:
                                std::cout << "(aggregate)";
                                break;
                            case BAG_TYPE:
                                std::cout << "(bag)";
                                break;
                            case ARRAY_TYPE:
                                std::cout << "(array)";
                                break;
                            }

                        }
                        else if (nonreftype == ENUM_TYPE) {
                            SDAI_Enum* enumobj = attrlist[pos].Enum();
                            string express;

                            std::cout << enumobj->asStr(express) << ",";
                        }
                        else if (nonreftype == BOOLEAN_TYPE) {
                            SDAI_BOOLEAN* booleanobj = attrlist[pos].Boolean();

                            string express;
                            std::cout << booleanobj->asStr(express) << ",";
                        }
                        else if (nonreftype == LOGICAL_TYPE) {
                            SDAI_LOGICAL* logicalobj = attrlist[pos].Logical();

                            string express;
                            std::cout << logicalobj->asStr(express) << ",";
                        }
                        else if (nonreftype == UNKNOWN_TYPE) {
                            std::cout << "[??],";
                        }
                        else {
                            std::cout << "[Value],";
                        }
                        std::cout << std::endl;



                    }

                }
            }


        }
    }


    return 0;
}
