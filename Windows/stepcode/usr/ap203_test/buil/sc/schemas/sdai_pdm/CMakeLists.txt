# -----  GENERATED FILE  -----
# -----   Do not edit!   -----

# schema name: pdm_schema
# (short name: sdai_pdm)
# 210 entities, 45 types

# targets, logic, etc are within a set of macros shared by all schemas
include(${SC_CMAKE_DIR}/SC_CXX_schema_macros.cmake)
set(sdai_pdm_file_count 520)

PROJECT(sdai_pdm)
# list headers so they can be installed - entity, type, misc
set(sdai_pdm_entity_hdrs
     entity/SdaiIdentification_role.h                                            entity/SdaiApplied_certification_assignment.h                               
     entity/SdaiCartesian_transformation_operator_3d.h                           entity/SdaiVersioned_action_request.h                                       
     entity/SdaiCertification.h                                                  entity/SdaiQuantified_assembly_component_usage.h                            
     entity/SdaiTime_interval_with_bounds.h                                      entity/SdaiAction_directive.h                                               
     entity/SdaiPlane_angle_unit.h                                               entity/SdaiApplied_organization_assignment.h                                
     entity/SdaiArea_measure_with_unit.h                                         entity/SdaiName_attribute.h                                                 
     entity/SdaiSerial_numbered_effectivity.h                                    entity/SdaiApplied_date_and_time_assignment.h                               
     entity/SdaiAxis2_placement_2d.h                                             entity/SdaiProduct_related_product_category.h                               
     entity/SdaiOrganizational_address.h                                         entity/SdaiApplied_external_identification_assignment.h                     
     entity/SdaiAction_request_assignment.h                                      entity/SdaiLength_measure_with_unit.h                                       
     entity/SdaiTime_interval.h                                                  entity/SdaiDated_effectivity.h                                              
     entity/SdaiDirection.h                                                      entity/SdaiProduct_definition_formation_relationship.h                      
     entity/SdaiApplied_event_occurrence_assignment.h                            entity/SdaiNext_assembly_usage_occurrence.h                                 
     entity/SdaiTime_unit.h                                                      entity/SdaiPerson.h                                                         
     entity/SdaiConversion_based_unit.h                                          entity/SdaiProduct_definition_formation.h                                   
     entity/SdaiRepresentation_item.h                                            entity/SdaiDescriptive_representation_item.h                                
     entity/SdaiApproval.h                                                       entity/SdaiEvent_occurrence_role.h                                          
     entity/SdaiGeometric_representation_context.h                               entity/SdaiApplied_date_assignment.h                                        
     entity/SdaiAction_status.h                                                  entity/SdaiApplication_context.h                                            
     entity/SdaiDate_and_time.h                                                  entity/SdaiApproval_date_time.h                                             
     entity/SdaiApproval_role.h                                                  entity/SdaiProduct_context.h                                                
     entity/SdaiApplication_protocol_definition.h                                entity/SdaiSpecified_higher_usage_occurrence.h                              
     entity/SdaiProduct_definition_formation_with_specified_source.h             entity/SdaiAmount_of_substance_measure_with_unit.h                          
     entity/SdaiDescription_attribute.h                                          entity/SdaiAction_request_solution.h                                        
     entity/SdaiUncertainty_measure_with_unit.h                                  entity/SdaiCartesian_transformation_operator.h                              
     entity/SdaiSolid_angle_unit.h                                               entity/SdaiLuminous_intensity_measure_with_unit.h                           
     entity/SdaiRole_association.h                                               entity/SdaiCoordinated_universal_time_offset.h                              
     entity/SdaiAction_request_status.h                                          entity/SdaiRepresentation_relationship_with_transformation.h                
     entity/SdaiPerson_and_organization_role.h                                   entity/SdaiProperty_definition.h                                            
     entity/SdaiApplied_action_request_assignment.h                              entity/SdaiRelative_event_occurrence.h                                      
     entity/SdaiGlobal_uncertainty_assigned_context.h                            entity/SdaiOrganization_relationship.h                                      
     entity/SdaiAmount_of_substance_unit.h                                       entity/SdaiLot_effectivity.h                                                
     entity/SdaiApplied_contract_assignment.h                                    entity/SdaiCalendar_date.h                                                  
     entity/SdaiPromissory_usage_occurrence.h                                    entity/SdaiApproval_assignment.h                                            
     entity/SdaiConfiguration_item.h                                             entity/SdaiContract_assignment.h                                            
     entity/SdaiValue_representation_item.h                                      entity/SdaiVector.h                                                         
     entity/SdaiProduct_definition_context.h                                     entity/SdaiDocument_file.h                                                  
     entity/SdaiItem_defined_transformation.h                                    entity/SdaiRepresentation.h                                                 
     entity/SdaiAction_method.h                                                  entity/SdaiCharacterized_object.h                                           
     entity/SdaiProduct_category_relationship.h                                  entity/SdaiRepresentation_context.h                                         
     entity/SdaiEvent_occurrence.h                                               entity/SdaiPlane_angle_measure_with_unit.h                                  
     entity/SdaiProduct_definition_relationship.h                                entity/SdaiElectric_current_unit.h                                          
     entity/SdaiRepresentation_map.h                                             entity/SdaiApplication_context_relationship.h                               
     entity/SdaiConfiguration_effectivity.h                                      entity/SdaiContext_dependent_unit.h                                         
     entity/SdaiAlternate_product_relationship.h                                 entity/SdaiDocument_type.h                                                  
     entity/SdaiDocument_reference.h                                             entity/SdaiPlacement.h                                                      
     entity/SdaiEffectivity_relationship.h                                       entity/SdaiApplied_identification_assignment.h                              
     entity/SdaiContract.h                                                       entity/SdaiDimensional_exponents.h                                          
     entity/SdaiEffectivity.h                                                    entity/SdaiDocument.h                                                       
     entity/SdaiOrganizational_project_relationship.h                            entity/SdaiContext_dependent_shape_representation.h                         
     entity/SdaiPerson_and_organization_assignment.h                             entity/SdaiMass_measure_with_unit.h                                         
     entity/SdaiThermodynamic_temperature_unit.h                                 entity/SdaiOrganization_role.h                                              
     entity/SdaiIdentification_assignment.h                                      entity/SdaiProduct_definition_context_role.h                                
     entity/SdaiFunctionally_defined_transformation.h                            entity/SdaiMeasure_with_unit.h                                              
     entity/SdaiApplied_organizational_project_assignment.h                      entity/SdaiAction_property.h                                                
     entity/SdaiElectric_current_measure_with_unit.h                             entity/SdaiDocument_product_equivalence.h                                   
     entity/SdaiProduct.h                                                        entity/SdaiProduct_definition_context_association.h                         
     entity/SdaiShape_aspect_relationship.h                                      entity/SdaiId_attribute.h                                                   
     entity/SdaiDocument_product_association.h                                   entity/SdaiGeneral_property_association.h                                   
     entity/SdaiProperty_definition_representation.h                             entity/SdaiPersonal_address.h                                               
     entity/SdaiDocument_relationship.h                                          entity/SdaiMake_from_usage_option.h                                         
     entity/SdaiRepresentation_relationship.h                                    entity/SdaiShape_representation_relationship.h                              
     entity/SdaiApplied_approval_assignment.h                                    entity/SdaiAssembly_component_usage_substitute.h                            
     entity/SdaiSolid_angle_measure_with_unit.h                                  entity/SdaiDirected_action.h                                                
     entity/SdaiOrganizational_project.h                                         entity/SdaiDate.h                                                           
     entity/SdaiDate_time_role.h                                                 entity/SdaiRatio_unit.h                                                     
     entity/SdaiAction_relationship.h                                            entity/SdaiApplied_document_reference.h                                     
     entity/SdaiNamed_unit.h                                                     entity/SdaiEvent_occurrence_assignment.h                                    
     entity/SdaiDate_role.h                                                      entity/SdaiProduct_definition_shape.h                                       
     entity/SdaiSi_unit.h                                                        entity/SdaiDocument_usage_constraint_assignment.h                           
     entity/SdaiCertification_assignment.h                                       entity/SdaiContract_type.h                                                  
     entity/SdaiDocument_usage_role.h                                            entity/SdaiGeometric_representation_item.h                                  
     entity/SdaiDerived_unit_element.h                                           entity/SdaiProduct_concept.h                                                
     entity/SdaiDerived_unit.h                                                   entity/SdaiAxis2_placement_3d.h                                             
     entity/SdaiConfiguration_design.h                                           entity/SdaiProduct_definition_with_associated_documents.h                   
     entity/SdaiAssembly_component_usage.h                                       entity/SdaiLuminous_intensity_unit.h                                        
     entity/SdaiOrganization.h                                                   entity/SdaiProduct_definition_usage.h                                       
     entity/SdaiCertification_type.h                                             entity/SdaiSecurity_classification.h                                        
     entity/SdaiShape_representation.h                                           entity/SdaiExternal_identification_assignment.h                             
     entity/SdaiApplied_effectivity_assignment.h                                 entity/SdaiOrganization_assignment.h                                        
     entity/SdaiOrganizational_project_assignment.h                              entity/SdaiApproval_status.h                                                
     entity/SdaiCartesian_point.h                                                entity/SdaiDate_and_time_assignment.h                                       
     entity/SdaiPoint.h                                                          entity/SdaiAction_assignment.h                                              
     entity/SdaiEffectivity_assignment.h                                         entity/SdaiProduct_definition.h                                             
     entity/SdaiProduct_concept_context.h                                        entity/SdaiCartesian_transformation_operator_2d.h                           
     entity/SdaiApplied_action_assignment.h                                      entity/SdaiApplied_security_classification_assignment.h                     
     entity/SdaiLength_unit.h                                                    entity/SdaiShape_aspect.h                                                   
     entity/SdaiVolume_measure_with_unit.h                                       entity/SdaiApplication_context_element.h                                    
     entity/SdaiMeasure_representation_item.h                                    entity/SdaiObject_role.h                                                    
     entity/SdaiSecurity_classification_level.h                                  entity/SdaiThermodynamic_temperature_measure_with_unit.h                    
     entity/SdaiApplied_document_usage_constraint_assignment.h                   entity/SdaiApproval_relationship.h                                          
     entity/SdaiDate_assignment.h                                                entity/SdaiApproval_person_organization.h                                   
     entity/SdaiProduct_definition_effectivity.h                                 entity/SdaiDocument_representation_type.h                                   
     entity/SdaiProduct_category.h                                               entity/SdaiTime_interval_based_effectivity.h                                
     entity/SdaiAddress.h                                                        entity/SdaiExecuted_action.h                                                
     entity/SdaiDocument_usage_constraint.h                                      entity/SdaiGeneral_property.h                                               
     entity/SdaiPerson_and_organization.h                                        entity/SdaiRatio_measure_with_unit.h                                        
     entity/SdaiExternal_source.h                                                entity/SdaiAction.h                                                         
     entity/SdaiGeneral_property_relationship.h                                  entity/SdaiLocal_time.h                                                     
     entity/SdaiMass_unit.h                                                      entity/SdaiArea_unit.h                                                      
     entity/SdaiMapped_item.h                                                    entity/SdaiShape_definition_representation.h                                
     entity/SdaiVolume_unit.h                                                    entity/SdaiSecurity_classification_assignment.h                             
     entity/SdaiApplied_person_and_organization_assignment.h                     entity/SdaiFounded_item.h                                                   
     entity/SdaiGlobal_unit_assigned_context.h                                   entity/SdaiTime_measure_with_unit.h                                         
     entity/SdaiAction_property_representation.h                                 entity/SdaiOrganizational_project_role.h                                    
        )

set(sdai_pdm_type_hdrs
     type/SdaiCharacterized_definition.h                                         type/SdaiAction_request_item.h                                              
     type/SdaiCharacterized_product_definition.h                                 type/SdaiAxis2_placement.h                                                  
     type/SdaiAction_item.h                                                      type/SdaiExternal_identification_item.h                                     
     type/SdaiRepresented_definition.h                                           type/SdaiEvent_occurrence_item.h                                            
     type/SdaiMeasure_value.h                                                    type/SdaiPerson_organization_select.h                                       
     type/SdaiDate_and_time_item.h                                               type/SdaiAttribute_type.h                                                   
     type/SdaiId_attribute_select.h                                              type/SdaiEffectivity_item.h                                                 
     type/SdaiSecurity_classification_item.h                                     type/SdaiDocument_reference_item.h                                          
     type/SdaiSi_unit_name_var.h                                                 type/SdaiFounded_item_select.h                                              
     type/SdaiSource_item.h                                                      type/SdaiContract_item.h                                                    
     type/SdaiDate_time_or_event_occurrence.h                                    type/SdaiDerived_property_select.h                                          
     type/SdaiVector_or_direction.h                                              type/SdaiApproval_item.h                                                    
     type/SdaiTransformation.h                                                   type/SdaiDate_time_select.h                                                 
     type/SdaiOrganization_item.h                                                type/SdaiProduct_or_formation_or_definition.h                               
     type/SdaiTrimming_select.h                                                  type/SdaiRole_select.h                                                      
     type/SdaiAhead_or_behind_var.h                                              type/SdaiCharacterized_action_definition.h                                  
     type/SdaiDescription_attribute_select.h                                     type/SdaiSource_var.h                                                       
     type/SdaiName_attribute_select.h                                            type/SdaiUnit.h                                                             
     type/SdaiDate_item.h                                                        type/SdaiShape_definition.h                                                 
     type/SdaiSupported_item.h                                                   type/SdaiOrganizational_project_item.h                                      
     type/SdaiPerson_and_organization_item.h                                     type/SdaiSi_prefix_var.h                                                    
     type/SdaiCertification_item.h                                               type/SdaiIdentification_item.h                                              
     type/SdaiConfiguration_design_item.h                                           )

set(sdai_pdm_misc_hdrs
     Sdaiclasses.h   schema.h
     SdaiPDM_SCHEMANames.h
     SdaiPDM_SCHEMA.h
   )

# install all headers
set(all_headers ${sdai_pdm_entity_hdrs} ${sdai_pdm_type_hdrs} ${sdai_pdm_misc_hdrs})
foreach( header_file ${all_headers} )
  set(curr_dir)
  get_filename_component(curr_dir ${header_file} PATH)
  get_filename_component(curr_name ${header_file} NAME)
  if (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_pdm/${curr_dir}" )
  else (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_pdm" )
  endif (curr_dir)
endforeach()
# implementation files - 3 lists

# unity build: #include small .cc files to reduce the number
# of translation units that must be compiled
if(SC_UNITY_BUILD)
  # turns off include statements within type and entity .cc's - the unity T.U.'s include a unity header
  add_definitions( -DSC_SDAI_UNITY_BUILD)
  set(sdai_pdm_entity_impls SdaiPDM_SCHEMA_unity_entities.cc)
  set(sdai_pdm_type_impls SdaiPDM_SCHEMA_unity_types.cc)
else(SC_UNITY_BUILD)
  set(sdai_pdm_entity_impls
     entity/SdaiIdentification_role.cc                                           entity/SdaiApplied_certification_assignment.cc                              
     entity/SdaiCartesian_transformation_operator_3d.cc                          entity/SdaiVersioned_action_request.cc                                      
     entity/SdaiCertification.cc                                                 entity/SdaiQuantified_assembly_component_usage.cc                           
     entity/SdaiTime_interval_with_bounds.cc                                     entity/SdaiAction_directive.cc                                              
     entity/SdaiPlane_angle_unit.cc                                              entity/SdaiApplied_organization_assignment.cc                               
     entity/SdaiArea_measure_with_unit.cc                                        entity/SdaiName_attribute.cc                                                
     entity/SdaiSerial_numbered_effectivity.cc                                   entity/SdaiApplied_date_and_time_assignment.cc                              
     entity/SdaiAxis2_placement_2d.cc                                            entity/SdaiProduct_related_product_category.cc                              
     entity/SdaiOrganizational_address.cc                                        entity/SdaiApplied_external_identification_assignment.cc                    
     entity/SdaiAction_request_assignment.cc                                     entity/SdaiLength_measure_with_unit.cc                                      
     entity/SdaiTime_interval.cc                                                 entity/SdaiDated_effectivity.cc                                             
     entity/SdaiDirection.cc                                                     entity/SdaiProduct_definition_formation_relationship.cc                     
     entity/SdaiApplied_event_occurrence_assignment.cc                           entity/SdaiNext_assembly_usage_occurrence.cc                                
     entity/SdaiTime_unit.cc                                                     entity/SdaiPerson.cc                                                        
     entity/SdaiConversion_based_unit.cc                                         entity/SdaiProduct_definition_formation.cc                                  
     entity/SdaiRepresentation_item.cc                                           entity/SdaiDescriptive_representation_item.cc                               
     entity/SdaiApproval.cc                                                      entity/SdaiEvent_occurrence_role.cc                                         
     entity/SdaiGeometric_representation_context.cc                              entity/SdaiApplied_date_assignment.cc                                       
     entity/SdaiAction_status.cc                                                 entity/SdaiApplication_context.cc                                           
     entity/SdaiDate_and_time.cc                                                 entity/SdaiApproval_date_time.cc                                            
     entity/SdaiApproval_role.cc                                                 entity/SdaiProduct_context.cc                                               
     entity/SdaiApplication_protocol_definition.cc                               entity/SdaiSpecified_higher_usage_occurrence.cc                             
     entity/SdaiProduct_definition_formation_with_specified_source.cc            entity/SdaiAmount_of_substance_measure_with_unit.cc                         
     entity/SdaiDescription_attribute.cc                                         entity/SdaiAction_request_solution.cc                                       
     entity/SdaiUncertainty_measure_with_unit.cc                                 entity/SdaiCartesian_transformation_operator.cc                             
     entity/SdaiSolid_angle_unit.cc                                              entity/SdaiLuminous_intensity_measure_with_unit.cc                          
     entity/SdaiRole_association.cc                                              entity/SdaiCoordinated_universal_time_offset.cc                             
     entity/SdaiAction_request_status.cc                                         entity/SdaiRepresentation_relationship_with_transformation.cc               
     entity/SdaiPerson_and_organization_role.cc                                  entity/SdaiProperty_definition.cc                                           
     entity/SdaiApplied_action_request_assignment.cc                             entity/SdaiRelative_event_occurrence.cc                                     
     entity/SdaiGlobal_uncertainty_assigned_context.cc                           entity/SdaiOrganization_relationship.cc                                     
     entity/SdaiAmount_of_substance_unit.cc                                      entity/SdaiLot_effectivity.cc                                               
     entity/SdaiApplied_contract_assignment.cc                                   entity/SdaiCalendar_date.cc                                                 
     entity/SdaiPromissory_usage_occurrence.cc                                   entity/SdaiApproval_assignment.cc                                           
     entity/SdaiConfiguration_item.cc                                            entity/SdaiContract_assignment.cc                                           
     entity/SdaiValue_representation_item.cc                                     entity/SdaiVector.cc                                                        
     entity/SdaiProduct_definition_context.cc                                    entity/SdaiDocument_file.cc                                                 
     entity/SdaiItem_defined_transformation.cc                                   entity/SdaiRepresentation.cc                                                
     entity/SdaiAction_method.cc                                                 entity/SdaiCharacterized_object.cc                                          
     entity/SdaiProduct_category_relationship.cc                                 entity/SdaiRepresentation_context.cc                                        
     entity/SdaiEvent_occurrence.cc                                              entity/SdaiPlane_angle_measure_with_unit.cc                                 
     entity/SdaiProduct_definition_relationship.cc                               entity/SdaiElectric_current_unit.cc                                         
     entity/SdaiRepresentation_map.cc                                            entity/SdaiApplication_context_relationship.cc                              
     entity/SdaiConfiguration_effectivity.cc                                     entity/SdaiContext_dependent_unit.cc                                        
     entity/SdaiAlternate_product_relationship.cc                                entity/SdaiDocument_type.cc                                                 
     entity/SdaiDocument_reference.cc                                            entity/SdaiPlacement.cc                                                     
     entity/SdaiEffectivity_relationship.cc                                      entity/SdaiApplied_identification_assignment.cc                             
     entity/SdaiContract.cc                                                      entity/SdaiDimensional_exponents.cc                                         
     entity/SdaiEffectivity.cc                                                   entity/SdaiDocument.cc                                                      
     entity/SdaiOrganizational_project_relationship.cc                           entity/SdaiContext_dependent_shape_representation.cc                        
     entity/SdaiPerson_and_organization_assignment.cc                            entity/SdaiMass_measure_with_unit.cc                                        
     entity/SdaiThermodynamic_temperature_unit.cc                                entity/SdaiOrganization_role.cc                                             
     entity/SdaiIdentification_assignment.cc                                     entity/SdaiProduct_definition_context_role.cc                               
     entity/SdaiFunctionally_defined_transformation.cc                           entity/SdaiMeasure_with_unit.cc                                             
     entity/SdaiApplied_organizational_project_assignment.cc                     entity/SdaiAction_property.cc                                               
     entity/SdaiElectric_current_measure_with_unit.cc                            entity/SdaiDocument_product_equivalence.cc                                  
     entity/SdaiProduct.cc                                                       entity/SdaiProduct_definition_context_association.cc                        
     entity/SdaiShape_aspect_relationship.cc                                     entity/SdaiId_attribute.cc                                                  
     entity/SdaiDocument_product_association.cc                                  entity/SdaiGeneral_property_association.cc                                  
     entity/SdaiProperty_definition_representation.cc                            entity/SdaiPersonal_address.cc                                              
     entity/SdaiDocument_relationship.cc                                         entity/SdaiMake_from_usage_option.cc                                        
     entity/SdaiRepresentation_relationship.cc                                   entity/SdaiShape_representation_relationship.cc                             
     entity/SdaiApplied_approval_assignment.cc                                   entity/SdaiAssembly_component_usage_substitute.cc                           
     entity/SdaiSolid_angle_measure_with_unit.cc                                 entity/SdaiDirected_action.cc                                               
     entity/SdaiOrganizational_project.cc                                        entity/SdaiDate.cc                                                          
     entity/SdaiDate_time_role.cc                                                entity/SdaiRatio_unit.cc                                                    
     entity/SdaiAction_relationship.cc                                           entity/SdaiApplied_document_reference.cc                                    
     entity/SdaiNamed_unit.cc                                                    entity/SdaiEvent_occurrence_assignment.cc                                   
     entity/SdaiDate_role.cc                                                     entity/SdaiProduct_definition_shape.cc                                      
     entity/SdaiSi_unit.cc                                                       entity/SdaiDocument_usage_constraint_assignment.cc                          
     entity/SdaiCertification_assignment.cc                                      entity/SdaiContract_type.cc                                                 
     entity/SdaiDocument_usage_role.cc                                           entity/SdaiGeometric_representation_item.cc                                 
     entity/SdaiDerived_unit_element.cc                                          entity/SdaiProduct_concept.cc                                               
     entity/SdaiDerived_unit.cc                                                  entity/SdaiAxis2_placement_3d.cc                                            
     entity/SdaiConfiguration_design.cc                                          entity/SdaiProduct_definition_with_associated_documents.cc                  
     entity/SdaiAssembly_component_usage.cc                                      entity/SdaiLuminous_intensity_unit.cc                                       
     entity/SdaiOrganization.cc                                                  entity/SdaiProduct_definition_usage.cc                                      
     entity/SdaiCertification_type.cc                                            entity/SdaiSecurity_classification.cc                                       
     entity/SdaiShape_representation.cc                                          entity/SdaiExternal_identification_assignment.cc                            
     entity/SdaiApplied_effectivity_assignment.cc                                entity/SdaiOrganization_assignment.cc                                       
     entity/SdaiOrganizational_project_assignment.cc                             entity/SdaiApproval_status.cc                                               
     entity/SdaiCartesian_point.cc                                               entity/SdaiDate_and_time_assignment.cc                                      
     entity/SdaiPoint.cc                                                         entity/SdaiAction_assignment.cc                                             
     entity/SdaiEffectivity_assignment.cc                                        entity/SdaiProduct_definition.cc                                            
     entity/SdaiProduct_concept_context.cc                                       entity/SdaiCartesian_transformation_operator_2d.cc                          
     entity/SdaiApplied_action_assignment.cc                                     entity/SdaiApplied_security_classification_assignment.cc                    
     entity/SdaiLength_unit.cc                                                   entity/SdaiShape_aspect.cc                                                  
     entity/SdaiVolume_measure_with_unit.cc                                      entity/SdaiApplication_context_element.cc                                   
     entity/SdaiMeasure_representation_item.cc                                   entity/SdaiObject_role.cc                                                   
     entity/SdaiSecurity_classification_level.cc                                 entity/SdaiThermodynamic_temperature_measure_with_unit.cc                   
     entity/SdaiApplied_document_usage_constraint_assignment.cc                  entity/SdaiApproval_relationship.cc                                         
     entity/SdaiDate_assignment.cc                                               entity/SdaiApproval_person_organization.cc                                  
     entity/SdaiProduct_definition_effectivity.cc                                entity/SdaiDocument_representation_type.cc                                  
     entity/SdaiProduct_category.cc                                              entity/SdaiTime_interval_based_effectivity.cc                               
     entity/SdaiAddress.cc                                                       entity/SdaiExecuted_action.cc                                               
     entity/SdaiDocument_usage_constraint.cc                                     entity/SdaiGeneral_property.cc                                              
     entity/SdaiPerson_and_organization.cc                                       entity/SdaiRatio_measure_with_unit.cc                                       
     entity/SdaiExternal_source.cc                                               entity/SdaiAction.cc                                                        
     entity/SdaiGeneral_property_relationship.cc                                 entity/SdaiLocal_time.cc                                                    
     entity/SdaiMass_unit.cc                                                     entity/SdaiArea_unit.cc                                                     
     entity/SdaiMapped_item.cc                                                   entity/SdaiShape_definition_representation.cc                               
     entity/SdaiVolume_unit.cc                                                   entity/SdaiSecurity_classification_assignment.cc                            
     entity/SdaiApplied_person_and_organization_assignment.cc                    entity/SdaiFounded_item.cc                                                  
     entity/SdaiGlobal_unit_assigned_context.cc                                  entity/SdaiTime_measure_with_unit.cc                                        
     entity/SdaiAction_property_representation.cc                                entity/SdaiOrganizational_project_role.cc                                   
        )

  set(sdai_pdm_type_impls
     type/SdaiCharacterized_definition.cc                                        type/SdaiAction_request_item.cc                                             
     type/SdaiCharacterized_product_definition.cc                                type/SdaiAxis2_placement.cc                                                 
     type/SdaiAction_item.cc                                                     type/SdaiExternal_identification_item.cc                                    
     type/SdaiRepresented_definition.cc                                          type/SdaiEvent_occurrence_item.cc                                           
     type/SdaiMeasure_value.cc                                                   type/SdaiPerson_organization_select.cc                                      
     type/SdaiDate_and_time_item.cc                                              type/SdaiAttribute_type.cc                                                  
     type/SdaiId_attribute_select.cc                                             type/SdaiEffectivity_item.cc                                                
     type/SdaiSecurity_classification_item.cc                                    type/SdaiDocument_reference_item.cc                                         
     type/SdaiSi_unit_name_var.cc                                                type/SdaiFounded_item_select.cc                                             
     type/SdaiSource_item.cc                                                     type/SdaiContract_item.cc                                                   
     type/SdaiDate_time_or_event_occurrence.cc                                   type/SdaiDerived_property_select.cc                                         
     type/SdaiVector_or_direction.cc                                             type/SdaiApproval_item.cc                                                   
     type/SdaiTransformation.cc                                                  type/SdaiDate_time_select.cc                                                
     type/SdaiOrganization_item.cc                                               type/SdaiProduct_or_formation_or_definition.cc                              
     type/SdaiTrimming_select.cc                                                 type/SdaiRole_select.cc                                                     
     type/SdaiAhead_or_behind_var.cc                                             type/SdaiCharacterized_action_definition.cc                                 
     type/SdaiDescription_attribute_select.cc                                    type/SdaiSource_var.cc                                                      
     type/SdaiName_attribute_select.cc                                           type/SdaiUnit.cc                                                            
     type/SdaiDate_item.cc                                                       type/SdaiShape_definition.cc                                                
     type/SdaiSupported_item.cc                                                  type/SdaiOrganizational_project_item.cc                                     
     type/SdaiPerson_and_organization_item.cc                                    type/SdaiSi_prefix_var.cc                                                   
     type/SdaiCertification_item.cc                                              type/SdaiIdentification_item.cc                                             
     type/SdaiConfiguration_design_item.cc                                          )
endif(SC_UNITY_BUILD)

set( sdai_pdm_misc_impls
     SdaiAll.cc    compstructs.cc    schema.cc
     SdaiPDM_SCHEMA.cc
     SdaiPDM_SCHEMA.init.cc   )

set(schema_target_files ${sdai_pdm_entity_impls} ${sdai_pdm_type_impls} ${sdai_pdm_misc_impls})
SCHEMA_TARGETS("F:/VS2019/XXX-StepCode/Windows/stepcode/data/pdm/pdm_schema_12.exp" "pdm_schema"
                 "${schema_target_files}")
