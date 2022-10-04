#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include <regex>
#include <iostream>


void PrintCartesianPoint(const SDAI_Application_instance* ancestor, const SdaiCartesian_point* cartesian_inst) {

	string expression_str;
	if (cartesian_inst != NULL) {
		RealAggregate_ptr_c aggr_param = cartesian_inst->coordinates_();
		RealNode* iter_realnode = dynamic_cast<RealNode*>(aggr_param->GetHead());

		std::cout << "#" << cartesian_inst->FileId() << ",";
		for (; iter_realnode != NULL; iter_realnode = dynamic_cast<RealNode*>(iter_realnode->next)) {
			std::cout << iter_realnode->asStr(expression_str) << ",";
		}
		std::cout << "#" << ancestor->FileId() << "," << ancestor->EntityName();
		std::cout << std::endl;
	}


}


int main(int argv, char** argc)
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
			STEPfile* sfile = new STEPfile(*registry, *instance_list, "D:\\StepData\\KANA_NK35B10D9_K.stp", false);

			string expression_str;
			char expression_chr[8192];
			for (int i = 0; i < instance_list->InstanceCount(); i++) {
				// Set SDAI_Application_instance by Index
				SDAI_Application_instance* inst = instance_list->GetSTEPentity(i);



				// Check attributes
				STEPattributeList attrlist = inst->attributes;
				AttrListNode* iter_attrnode = dynamic_cast<AttrListNode*>( attrlist.GetHead());

				for (int i = 0; i < attrlist.list_length(); i++) {
					STEPattribute attr = attrlist[i];
					BASE_TYPE basetype = attr.Type();

					const SdaiAxis2_placement_3d* axis2placement_3d_inst_parent = dynamic_cast<const SdaiAxis2_placement_3d*>(inst);

					if (basetype == SELECT_TYPE) {
						const SdaiSelect* selectobj = attr.Select();
						const SdaiAxis2_placement* axis2placement_inst_parent = dynamic_cast<const SdaiAxis2_placement*>(attr.Select());
						if (axis2placement_inst_parent != NULL) {
							PrintCartesianPoint(inst, axis2placement_inst_parent->location_());
						}
					} else if (axis2placement_3d_inst_parent != NULL) {
						continue;
					} else if (basetype == ENTITY_TYPE) {
						const SdaiAxis2_placement_3d* axis2placement_inst = dynamic_cast<const SdaiAxis2_placement_3d*>(attr.Entity());
						const SdaiCartesian_point* cartesian_inst = dynamic_cast<const SdaiCartesian_point*>(attr.Entity());

						if (axis2placement_inst != NULL) {
							PrintCartesianPoint(inst, axis2placement_inst->location_());
						} else if (cartesian_inst != NULL) {
							PrintCartesianPoint(inst, cartesian_inst);
						}
					} else if (basetype == LIST_TYPE || basetype == SET_TYPE || basetype == BAG_TYPE || basetype == ARRAY_TYPE) {
						STEPaggregate* aggrobj = attr.Aggregate();
						if (aggrobj != NULL) {
							EntityNode* org_node = dynamic_cast<EntityNode*>( aggrobj->GetHead());

							for (; org_node != NULL; org_node = dynamic_cast<EntityNode*>(org_node->next )) {
								if (org_node != NULL) {
									const SdaiCartesian_point* cartesian_inst = dynamic_cast<const SdaiCartesian_point*>(org_node->node);
									if (cartesian_inst != NULL) {
										PrintCartesianPoint(inst, cartesian_inst);
									}
								}
							}

						}
						
					}

				}

#if 0
				// Convert : be expected for cartesian_point
				const SdaiCartesian_point* cartesian_inst = dynamic_cast<const SdaiCartesian_point*>(inst);
				if (cartesian_inst == NULL) {
					continue;
				}

				// Get Aggregate_ptr by cartesian_point
				RealAggregate_ptr_c aggr_param = cartesian_inst->coordinates_();
				if (aggr_param == NULL) {
					std::cerr << "#" << inst->FileId() << ",Obtaining Error : Coordinates_" << std::endl;;
					continue;
				}


				// Output 
				RealNode* iter_realnode = dynamic_cast<RealNode*>( aggr_param->GetHead());
				std::cout << "#" << inst->FileId() << ",";
				for (; iter_realnode != NULL; iter_realnode = dynamic_cast<RealNode*>(iter_realnode->next)) {
					std::cout << iter_realnode->asStr(expression_str) << ",";
				}
				if (inst->headMiEntity != NULL) {
					std::cout << inst->EntityName();

				}
				std::cout << std::endl;
#endif		

			}


		}
	}


	return 0;
}
